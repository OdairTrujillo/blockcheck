#include "dbhandler.h"
#include "userlib/bcnamespace.h"
#include "userlib/outsideactions.h"


// NOTE: Crear conexion con el servidor de base de datos
bool DbHandler::createConnection(void)
{
    OutsideActions confs;
    if (!confs.readSqlServerConf()) {
        QMessageBox::critical(0, ("Error de lectura"),
                              ("No se puede leer el archivo de configuración de BlockCheck \n"
                                           "revise que el archivo blockcheck.conf exista en la carpeta del \n"
                                           "programa y tenga permisos para leer y escribir en él."));
    } else {
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName(confs.sqlServerIP);
        db.setPort(confs.sqlServerPort);
        db.setDatabaseName(confs.databaseName);
        db.setUserName("bc_user");
        db.setPassword("bc_password");

        if (!db.open()) {
            QMessageBox::critical(0, ("No se puede abrir la base de datos"),
                                  ("Sucedió que: \n" + db.lastError().text().toUtf8()), QMessageBox::Cancel);
              qDebug() << "Drivers existentes: " << QSqlDatabase::drivers();
            return false;
        } else
            return true;
    }
    return false;
}

// NOTE: Cerrar conexion con el servidor de base de datos
void DbHandler::closeConnection(void)
{
    OutsideActions outside;
    outside.readSqlServerConf();

    QSqlDatabase::removeDatabase(QSqlDatabase::connectionNames().at(0));

}

bool DbHandler::getLogin(QString user, QString password, QStringList &userData)
{
    QSqlQuery queryGetLogin;
    queryGetLogin.prepare("SELECT user_name, user_passwd, user_lname, user_charge, user_level FROM tblUSERS "
                                  "WHERE user_name=:user_name AND user_passwd=:user_passwd");

    queryGetLogin.bindValue(":user_name", user);
    queryGetLogin.bindValue(":user_passwd", password);

    if (!queryGetLogin.exec()) {
        qDebug() << "Error en queryGetLogin :" + queryGetLogin.lastError().text();
        qDebug() << queryGetLogin.lastQuery();
        return false;
    }
    else {
        while (queryGetLogin.next()) {
            userData.append(queryGetLogin.value(0).toString());
            userData.append(queryGetLogin.value(1).toString());
            userData.append(queryGetLogin.value(2).toString());
            userData.append(queryGetLogin.value(3).toString());
            userData.append(queryGetLogin.value(4).toString());
        }
        if (userData.size() == 0) // No encontró usuario
            return false;
        else
            return true;
    }
}

/*

INSERCIONES
----------------------------------------------------------------------------------------------------------

*/

// NOTE: Insertar registro de log.
bool DbHandler::insertLogReg(const QStringList logData)
{
    QSqlQuery queryInsertLogReg;

    queryInsertLogReg.prepare("INSERT INTO tblEVENTS (log_date_time, log_user_name, log_detail, quot_id, prop_id, "
                              "so_id, inspection_id, dictum_id, subdictum_id, event_type_id) "
                              "VALUES (:log_date_time, :log_user_name, :log_detail, :quot_id, :prop_id, "
                              ":so_id, :inspection_id, :dictum_id, :subdictum_id, :event_type_id)");

    queryInsertLogReg.bindValue(":log_date_time", logData.at(0));
    queryInsertLogReg.bindValue(":log_user_name", logData.at(1));
    queryInsertLogReg.bindValue(":log_detail", logData.at(2));
    queryInsertLogReg.bindValue(":quot_id", logData.at(3).toInt());
    queryInsertLogReg.bindValue(":prop_id", logData.at(4).toInt());
    queryInsertLogReg.bindValue(":so_id", logData.at(5).toInt());
    queryInsertLogReg.bindValue(":inspection_id", logData.at(6).toInt());
    queryInsertLogReg.bindValue(":dictum_id", logData.at(7).toInt());
    queryInsertLogReg.bindValue(":subdictum_id", logData.at(8).toInt());
    queryInsertLogReg.bindValue(":event_type_id", logData.at(9).toInt());

    if (!queryInsertLogReg.exec()) {
        qDebug() << "Error en queryInsertLogReg: " + queryInsertLogReg.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Ingresar una cotizacion y cliente
//cada qstringlist trae los datos desde las interfaces gráficas
bool DbHandler::insertQuotation(const QStringList thrdData, QStringList &quotData,
                                const QStringList processesIds, int newQuotId, bool &isUniqueViolation)
{
    QSqlQuery queryInsertThirdPartie;

    queryInsertThirdPartie.prepare("INSERT INTO tblTHIRDPARTIES (thrd_nit, thrd_name, thrd_representative, thrd_address, thrd_mail, "
                                   "thrd_cel, thrd_tel, city_id) "
                                   "VALUES (:thrd_nit, :thrd_name, :thrd_representative, :thrd_address, :thrd_mail, "
                                   ":thrd_cel, :thrd_tel, :city_id) RETURNING thrd_id");

    queryInsertThirdPartie.bindValue(":thrd_nit", thrdData.at(1));
    queryInsertThirdPartie.bindValue(":thrd_name", thrdData.at(2));
    queryInsertThirdPartie.bindValue(":thrd_representative", thrdData.at(3));
    queryInsertThirdPartie.bindValue(":thrd_address", thrdData.at(4));
    queryInsertThirdPartie.bindValue(":thrd_mail", thrdData.at(5));
    queryInsertThirdPartie.bindValue(":thrd_cel", thrdData.at(6));
    queryInsertThirdPartie.bindValue(":thrd_tel", thrdData.at(7));
    queryInsertThirdPartie.bindValue(":city_id", thrdData.at(8).toInt());


    if (!queryInsertThirdPartie.exec()) {
        qDebug() << "Error en queryInsertThirdPartie: " + queryInsertThirdPartie.lastError().text();
        // contains devuelve falso o verdadero el error contiene la cadena key que indica violacion de llave
        isUniqueViolation=queryInsertThirdPartie.lastError().text().contains("tblthirdparties_thrd_nit_key", Qt::CaseInsensitive);
        return false;
    } else {
        queryInsertThirdPartie.first(); //Se posiciona en el tercero que fue insertado.
        QSqlQuery queryInsertQuotation;
        queryInsertQuotation.prepare("INSERT INTO tblQUOTATIONS (quot_date, quot_name, quot_scope, quot_contact, quot_address, "
                                     "quot_mail, quot_cel, thrd_id, city_id, use_id, quot_inspect_type) "
                                     "VALUES (:quot_date, :quot_name, :quot_scope, :quot_contact, :quot_address, "
                                     ":quot_mail, :quot_cel, :thrd_id, :city_id, :use_id, :quot_inspect_type) "
                                     "RETURNING quot_id");

        queryInsertQuotation.bindValue(":quot_date", quotData.at(0));
        queryInsertQuotation.bindValue(":quot_name", quotData.at(1));
        queryInsertQuotation.bindValue(":quot_scope", quotData.at(2));
        queryInsertQuotation.bindValue(":quot_contact", quotData.at(3));
        queryInsertQuotation.bindValue(":quot_address", quotData.at(4));
        queryInsertQuotation.bindValue(":quot_mail", quotData.at(5));
        queryInsertQuotation.bindValue(":quot_cel", quotData.at(6));
        queryInsertQuotation.bindValue(":thrd_id", queryInsertThirdPartie.value(0).toInt());
        queryInsertQuotation.bindValue(":city_id", quotData.at(7).toInt());
        queryInsertQuotation.bindValue(":use_id", quotData.at(8).toInt());
        queryInsertQuotation.bindValue(":quot_inspect_type", quotData.at(9));

        if (!queryInsertQuotation.exec()) {
            qDebug() << "Error en queryInsertQuotation: " + queryInsertQuotation.lastError().text();
            return false;
        } else {
            queryInsertQuotation.first();
            newQuotId= queryInsertQuotation.value(0).toInt();
            for (int i=0; i< processesIds.size(); i++)
                DbHandler::insertQuotProcesses(queryInsertQuotation.value(0).toString(), processesIds.at(i));
            return true;
        }
    }
    return false;
}


// NOTE: Insertar cotizacion con cliente existente
bool DbHandler::insertQuotation(const QString thrdNit, QStringList &quotData, int newQuotId, QStringList processesIds)
{
    QSqlQuery queryInsertQuotation;
    queryInsertQuotation.prepare("INSERT INTO tblQUOTATIONS (quot_date, quot_name, quot_scope, quot_contact, quot_address, "
                                 "quot_mail, quot_cel, city_id, use_id, thrd_id, quot_inspect_type) "
                                 "VALUES (:quot_date, :quot_name, :quot_scope, :quot_contact, :quot_address, "
                                 ":quot_mail, :quot_cel, :city_id, :use_id, (SELECT thrd_id FROM tblTHIRDPARTIES WHERE "
                                 "thrd_nit=:thrd_nit), :quot_inspect_type) RETURNING quot_id");

    queryInsertQuotation.bindValue(":quot_date", quotData.at(0));
    queryInsertQuotation.bindValue(":quot_name", quotData.at(1));
    queryInsertQuotation.bindValue(":quot_scope", quotData.at(2));
    queryInsertQuotation.bindValue(":quot_contact", quotData.at(3));
    queryInsertQuotation.bindValue(":quot_address", quotData.at(4));
    queryInsertQuotation.bindValue(":quot_mail", quotData.at(5));
    queryInsertQuotation.bindValue(":quot_cel", quotData.at(6));
    queryInsertQuotation.bindValue(":thrd_nit", thrdNit);
    queryInsertQuotation.bindValue(":city_id", quotData.at(7).toInt());
    queryInsertQuotation.bindValue(":use_id", quotData.at(8).toInt());
    queryInsertQuotation.bindValue(":quot_inspect_type", quotData.at(9));

    if (!queryInsertQuotation.exec()) {
        qDebug() << "Error en queryInsertQuotation: " + queryInsertQuotation.lastError().text();
        return false;
    } else {
        queryInsertQuotation.first();
        newQuotId = queryInsertQuotation.value(0).toInt();
        for (int i=0; i< processesIds.size(); i++) // Para cada Id de proceso se guarda un registro
            insertQuotProcesses(queryInsertQuotation.value(0).toString(), processesIds.at(i));
        return true;
    }
    return false;
}

// NOTE: Funcion para insertar los procesos de una cotizacion
bool DbHandler::insertQuotProcesses(const QString quotId, const QString processId)
{
    QSqlQuery queryInsertQuotProcesses;
    queryInsertQuotProcesses.prepare("INSERT INTO tblQUOTPROCESSES (quot_id, process_id) "
                                     "VALUES (:quot_id, :process_id)");
    queryInsertQuotProcesses.bindValue(":quot_id", quotId.toInt());
    queryInsertQuotProcesses.bindValue(":process_id", processId.toInt());
    if (!queryInsertQuotProcesses.exec()) {
        qDebug() << "Error en queryInsertQuotProcesses: " + queryInsertQuotProcesses.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insercion de propuesta
bool DbHandler::insertProposal(QStringList &propData, QStringList documentsIds,  bool &isUniqueViolation)
{
    QSqlQuery queryInsertProposal;
    queryInsertProposal.prepare("INSERT INTO tblPROPOSALS (prop_date, prop_scope, prop_state, prop_payway, prop_user_perc, prop_observ, "
                                "prop_value, prop_iva, prop_viatical, prop_total_value, quot_id, user_id) "
                                "VALUES (:prop_date, :prop_scope, :prop_state, :prop_payway, :prop_user_perc, :prop_observ, "
                                ":prop_value, :prop_iva, :prop_viatical, :prop_total_value, :quot_id, :inspector_id) "
                                "RETURNING prop_id");

    queryInsertProposal.bindValue(":prop_date", propData.at(0));
    queryInsertProposal.bindValue(":prop_scope", propData.at(1));
    queryInsertProposal.bindValue(":prop_state", propData.at(2));
    queryInsertProposal.bindValue(":prop_payway", propData.at(3));
    queryInsertProposal.bindValue(":prop_user_perc", propData.at(4).toFloat());
    queryInsertProposal.bindValue(":prop_observ", propData.at(5));
    queryInsertProposal.bindValue(":prop_value", propData.at(6));
    queryInsertProposal.bindValue(":prop_iva", propData.at(7));
    queryInsertProposal.bindValue(":prop_viatical", propData.at(8));
    queryInsertProposal.bindValue(":prop_total_value", propData.at(9));
    queryInsertProposal.bindValue(":quot_id", propData.at(10).toInt());
    queryInsertProposal.bindValue(":user_id", propData.at(11).toInt());

    if(!queryInsertProposal.exec()) {
        qDebug() << "Error en la consulta queryInsertProposal: " << queryInsertProposal.lastError().text();
        // contains devuelve falso o verdadero el error contiene la cadena key que indica violacion de llave
        isUniqueViolation=queryInsertProposal.lastError().text().contains("tblproposals_quot_id_key", Qt::CaseInsensitive);
        return false;
    } else {
        queryInsertProposal.first();
        propData.clear();
        propData.append(queryInsertProposal.value(0).toString()); // La posicion 0 contendra el id de propuesta
        // se insertan los documentos relacionados con la propuesta
        for (int i=0; i < documentsIds.size(); i++)
            insertPropDocuments(queryInsertProposal.value(0).toString(), documentsIds.at(i));
        return true;
    }
}

// NOTE: Insertar los documentos de una propuesta
bool DbHandler::insertPropDocuments(const QString propId, const QString documentId)
{
    QSqlQuery queryInsertPropDocuments;
    queryInsertPropDocuments.prepare("INSERT INTO tblPROPDOCUMENTS (prop_id, document_id) "
                                     "VALUES (:prop_id, :document_id)");
    queryInsertPropDocuments.bindValue(":prop_id", propId.toInt());
    queryInsertPropDocuments.bindValue(":document_id", documentId.toInt());
    if (!queryInsertPropDocuments.exec()) {
        qDebug() << "Error en queryInsertPropDocuments: " + queryInsertPropDocuments.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insercion de orden de servicio
bool DbHandler::insertServiceOrder(QStringList &soData, bool &isUniqueViolation)
{
    QSqlQuery queryInsertServiceOrder;

    queryInsertServiceOrder.prepare("INSERT INTO tblSERVICEORDERS (so_date, so_scope, so_observations, so_inspector_perc, "
                                    "so_assign_date, inspector_id, prop_id) "
                                    "VALUES (:so_date, :so_scope, :so_observations, :so_inspector_perc, :so_assign_date, "
                                    ":inspector_id, :prop_id) "
                                    "RETURNING so_id");

    queryInsertServiceOrder.bindValue(":so_date", soData.at(0));
    queryInsertServiceOrder.bindValue(":so_scope", soData.at(1));
    queryInsertServiceOrder.bindValue(":so_observations", soData.at(2));
    queryInsertServiceOrder.bindValue(":so_inspector_perc", soData.at(3).toFloat());
    queryInsertServiceOrder.bindValue(":so_assign_date", soData.at(4));
    queryInsertServiceOrder.bindValue(":inspector_id", soData.at(5).toInt());
    queryInsertServiceOrder.bindValue(":prop_id", soData.at(6).toInt());

    if (!queryInsertServiceOrder.exec()) {
        qDebug() << "Error en la consulta queryInsertServiceOrder: " << queryInsertServiceOrder.lastError().text();
        // contains devuelve falso o verdadero el error contiene la cadena key que indica violacion de llave
        isUniqueViolation=queryInsertServiceOrder.lastError().text().contains("tblserviceorders_prop_id_key", Qt::CaseInsensitive);

        return false;
    } else {
        queryInsertServiceOrder.first();
        soData.clear();
        soData.append(queryInsertServiceOrder.value(0).toString());
        return true;
    }

}

// NOTE: Insertar los documentos de una orden de servicio
bool DbHandler::insertSoDocuments(const QString soId, const QString documentId)
{
    QSqlQuery queryInsertSoDocuments;
    queryInsertSoDocuments.prepare("INSERT INTO tblSODOCUMENTS (so_id, document_id) "
                                     "VALUES (:so_id, :document_id)");
    queryInsertSoDocuments.bindValue(":so_id", soId.toInt());
    queryInsertSoDocuments.bindValue(":document_id", documentId.toInt());
    if (!queryInsertSoDocuments.exec()) {
        qDebug() << "Error en queryInsertSoDocuments: " + queryInsertSoDocuments.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insertar los folios o az's de una orden de servicio
bool DbHandler::insertSoRecords(const QString soId, const QString recordId)
{
    QSqlQuery queryInsertSoRecords;
    queryInsertSoRecords.prepare("INSERT INTO tblSORECORDS (so_id, record_id) "
                                     "VALUES (:so_id, :record_id)");
    queryInsertSoRecords.bindValue(":so_id", soId.toInt());
    queryInsertSoRecords.bindValue(":record_id", recordId.toInt());
    if (!queryInsertSoRecords.exec()) {
        qDebug() << "Error en queryInsertSoRecords: " + queryInsertSoRecords.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insertar el tracking de una orden de servicio
bool DbHandler::insertSoTracking(const QStringList soTrackingData)
{
    QSqlQuery queryInsertSoTracking;
    queryInsertSoTracking.prepare("INSERT INTO tblSOTRACKING (so_id, trck_receipt_date, trck_receiver_name, trck_shipping_date, "
                                  "trck_shipper_name, trck_shipping_name, trck_shipping_company, trck_guide_number, trck_observations, city_id) "
                                  "VALUES (:so_id, :trck_receipt_date, :trck_receiver_name, :trck_shipping_date, :trck_shipper_name, "
                                  ":trck_shipping_name, :trck_shipping_company, :trck_guide_number, :trck_observations, :city_id)");

    queryInsertSoTracking.bindValue(":so_id", soTrackingData.at(0).toInt());
    queryInsertSoTracking.bindValue(":trck_receipt_date", soTrackingData.at(1));
    queryInsertSoTracking.bindValue(":trck_receiver_name", soTrackingData.at(2));
    queryInsertSoTracking.bindValue(":trck_shipping_date", soTrackingData.at(3));
    queryInsertSoTracking.bindValue(":trck_shipper_name", soTrackingData.at(4));
    queryInsertSoTracking.bindValue(":trck_shipping_name", soTrackingData.at(5));
    queryInsertSoTracking.bindValue(":trck_shipping_company", soTrackingData.at(6));
    queryInsertSoTracking.bindValue(":trck_guide_number", soTrackingData.at(7));
    queryInsertSoTracking.bindValue(":trck_observations", soTrackingData.at(8));
    queryInsertSoTracking.bindValue(":city_id", soTrackingData.at(9).toInt());

    if (!queryInsertSoTracking.exec()) {
        qDebug() << "Error en queryInsertSoTracking: " + queryInsertSoTracking.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insertar pago de orden de servicio o tercero
bool DbHandler::insertThrdPay(const QStringList payThrdData)
{
    QSqlQuery queryInsertThrdPay;
    queryInsertThrdPay.prepare("INSERT INTO tblMOVEMENTS (mov_date, mov_type, so_id, mov_documment, "
                               "mov_name, mov_nit, mov_value, mov_observations) VALUES (:mov_date, :mov_type, :so_id, "
                               ":mov_documment, :mov_name, :mov_nit, :mov_value, :mov_observations)");

    queryInsertThrdPay.bindValue(":mov_date", payThrdData.at(0));
    queryInsertThrdPay.bindValue(":mov_type", payThrdData.at(1));
    queryInsertThrdPay.bindValue(":so_id", payThrdData.at(2).toInt());
    queryInsertThrdPay.bindValue(":mov_documment", payThrdData.at(3));
    queryInsertThrdPay.bindValue(":mov_name", payThrdData.at(4));
    queryInsertThrdPay.bindValue(":mov_nit", payThrdData.at(5));
    queryInsertThrdPay.bindValue(":mov_value", payThrdData.at(6).toInt());
    queryInsertThrdPay.bindValue(":mov_observations", payThrdData.at(7));

    if (!queryInsertThrdPay.exec()) {
        qDebug() << "Error en la consulta queryInsertThrdPay: " << queryInsertThrdPay.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insertar pago de usuario o vendedor
bool DbHandler::insertUserPay(const QStringList payUserData)
{
    QSqlQuery queryInsertUserPay;
    queryInsertUserPay.prepare("INSERT INTO tblMOVEMENTS (mov_date, mov_type, so_id, mov_documment, "
                               "mov_name, mov_nit, mov_value, mov_observations) VALUES (:mov_date, :mov_type, :so_id, "
                               ":mov_documment, :mov_name, :mov_nit, :mov_value, :mov_observations)");

    queryInsertUserPay.bindValue(":mov_date", payUserData.at(0));
    queryInsertUserPay.bindValue(":mov_type", payUserData.at(1));
    queryInsertUserPay.bindValue(":so_id", payUserData.at(2).toInt());
    queryInsertUserPay.bindValue(":mov_documment", payUserData.at(3));
    queryInsertUserPay.bindValue(":mov_name", payUserData.at(4));
    queryInsertUserPay.bindValue(":mov_nit", payUserData.at(5));
    queryInsertUserPay.bindValue(":mov_value", payUserData.at(6).toInt());
    queryInsertUserPay.bindValue(":mov_observations", payUserData.at(7));

    if (!queryInsertUserPay.exec()) {
        qDebug() << "Error en la consulta queryInsertUserPay: " << queryInsertUserPay.lastQuery();
        return false;
    } else
        return true;
}

// NOTE: Insertar pago de inspector
bool DbHandler::insertInspectorPay(const QStringList payInspectorData)
{
    QSqlQuery queryInsertInspectorPay;
    queryInsertInspectorPay.prepare("INSERT INTO tblMOVEMENTS (mov_date, mov_type, so_id, mov_documment, "
                                    "mov_name, mov_nit, mov_value, mov_observations) VALUES (:mov_date, :mov_type, :so_id, "
                                    ":mov_documment, :mov_name, :mov_nit, :mov_value, :mov_observations)");

         queryInsertInspectorPay.bindValue(":mov_date", payInspectorData.at(0));
         queryInsertInspectorPay.bindValue(":mov_type", payInspectorData.at(1));
         queryInsertInspectorPay.bindValue(":so_id", payInspectorData.at(2).toInt());
         queryInsertInspectorPay.bindValue(":mov_documment", payInspectorData.at(3));
         queryInsertInspectorPay.bindValue(":mov_name", payInspectorData.at(4));
         queryInsertInspectorPay.bindValue(":mov_nit", payInspectorData.at(5));
         queryInsertInspectorPay.bindValue(":mov_value", payInspectorData.at(6).toInt());
         queryInsertInspectorPay.bindValue(":mov_observations", payInspectorData.at(7));

    if (!queryInsertInspectorPay.exec()) {
        qDebug() << "Error en la consulta queryInsertInspectorPay: " << queryInsertInspectorPay.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insertar Nuevo Folio
bool DbHandler::insertRecordFoil(QString newRecordFoil)
{

    QSqlQuery queryInsertRecordFoil;
    queryInsertRecordFoil.prepare("INSERT INTO tblRECORDS (record_foil) VALUES (:record_foil)");

    queryInsertRecordFoil.bindValue(":record_foil", newRecordFoil);

    if (!queryInsertRecordFoil.exec()) {
        qDebug() << "Error en queryInsertRecordFoil: " + queryInsertRecordFoil.lastError().text();
        return false;
    }
    return true;

}

// NOTE: Insertar inspeccion
bool DbHandler::insertInspection(const QStringList inspectionData, QString &inspectionId, QStringList inspectionDesignersIds)
{
    QSqlQuery queryInsertInspection;
    queryInsertInspection.prepare("INSERT INTO tblINSPECTIONS (inspection_date, inspection_state, inspection_observ, inspection_address, "
                                  "inspection_propietary, city_id, so_id, constructor_id, auditor_id) "
                                  "VALUES (:inspection_date, :inspection_state, :inspection_observ, :inspection_address, "
                                  ":inspection_propietary, :city_id, :so_id, :constructor_id, :auditor_id) "
                                  "RETURNING inspection_id");

    queryInsertInspection.bindValue(":inspection_date", inspectionData.at(0));
    queryInsertInspection.bindValue(":inspection_state", inspectionData.at(1));
    queryInsertInspection.bindValue(":inspection_observ", inspectionData.at(2));
    queryInsertInspection.bindValue(":inspection_address", inspectionData.at(3));
    queryInsertInspection.bindValue(":inspection_propietary", inspectionData.at(4));
    queryInsertInspection.bindValue(":city_id", inspectionData.at(5).toInt());
    queryInsertInspection.bindValue(":so_id", inspectionData.at(6).toInt());
    queryInsertInspection.bindValue(":constructor_id", inspectionData.at(7).toInt());
    queryInsertInspection.bindValue(":auditor_id", inspectionData.at(8).toInt());

    if (!queryInsertInspection.exec()) {
        qDebug() << "Error en queryInsertInspection: " + queryInsertInspection.lastQuery();
        return false;
    } else {
        queryInsertInspection.first();
        inspectionId = queryInsertInspection.value(0).toString();

        for (int i=0; i<inspectionDesignersIds.size();i++)
            insertInspectionDesigners(inspectionId, inspectionDesignersIds.at(i));

        return true;
    }

}

// NOTE: Insertar disenadores para una inspeccion
bool DbHandler::insertInspectionDesigners(const QString inspectionId, const QString designerId)
{
    QSqlQuery queryInsertInspectionDesigner;
    queryInsertInspectionDesigner.prepare("INSERT INTO tblINSPECTIONDESIGNERS (inspection_id, designer_id) "
                                     "VALUES (:inspection_id, :designer_id)");
    queryInsertInspectionDesigner.bindValue(":inspection_id", inspectionId.toInt());
    queryInsertInspectionDesigner.bindValue(":designer_id", designerId.toInt());
    if (!queryInsertInspectionDesigner.exec()) {
        qDebug() << "Error en queryInsertInspectionDesigner: " + queryInsertInspectionDesigner.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insertar dictamen
bool DbHandler::insertDictum(QStringList dictumData, QStringList extraData, QList<QStringList> reqResults, QString &dictumId,
                             bool &isPkViolation, QString &dictumCode, QStringList &usedData, QList<QStringList> dictumUseData,
                             QStringList dictumProcIds)
{
    QSqlQuery queryInsertDictum;
    queryInsertDictum.prepare("INSERT INTO tblDICTUMS (dictum_number, dictum_date, dictum_state, dictum_tech_state, dictum_scope, dictum_observ, "
                              "dictum_inst_rate, dictum_inst_voltage, dictum_inst_resist, dictum_inst_date, process_id, inspection_id) "
                              "VALUES (:dictum_number, :dictum_date, :dictum_state, :dictum_tech_state, :dictum_scope, :dictum_observ, "
                              ":dictum_inst_rate, :dictum_inst_voltage, :dictum_inst_resist, :dictum_inst_date, :process_id, :inspection_id) "
                              "RETURNING dictum_id, dictum_code");

    queryInsertDictum.bindValue(":dictum_number", dictumData.at(0));
    queryInsertDictum.bindValue(":dictum_date", dictumData.at(1));
    queryInsertDictum.bindValue(":dictum_state", dictumData.at(2));
    queryInsertDictum.bindValue(":dictum_tech_state", dictumData.at(3));
    queryInsertDictum.bindValue(":dictum_scope", dictumData.at(4));
    queryInsertDictum.bindValue(":dictum_observ", dictumData.at(5));
    queryInsertDictum.bindValue(":dictum_inst_rate", dictumData.at(6));
    queryInsertDictum.bindValue(":dictum_inst_voltage", dictumData.at(7));
    queryInsertDictum.bindValue(":dictum_inst_resist", dictumData.at(8));
    queryInsertDictum.bindValue(":dictum_inst_date", dictumData.at(9));
    queryInsertDictum.bindValue(":process_id", dictumData.at(10).toInt());
    queryInsertDictum.bindValue(":inspection_id", dictumData.at(11).toInt());

    if (!queryInsertDictum.exec()) {
        isPkViolation=queryInsertDictum.lastError().text().contains("tbldictums_dictum_number_key", Qt::CaseInsensitive);
        if (isPkViolation) {
            QSqlQuery queryGetUsedData;
            queryGetUsedData.prepare("SELECT tblINSPECTIONS.so_id, tblDICTUMS.inspection_id, tblPROCESSES.process_name "
                                     "FROM tblDICTUMS, tblINSPECTIONS, tblPROCESSES "
                                     "WHERE tblPROCESSES.process_id=tblDICTUMS.process_id "
                                     "AND tblINSPECTIONS.inspection_id=tblDICTUMS.inspection_id "
                                     "AND tblDICTUMS.dictum_number=:dictum_number");

            queryGetUsedData.bindValue(":dictum_number", dictumData.at(0));

            if (!queryGetUsedData.exec())
                qDebug() << "Error en queryGetUsedData: " + queryGetUsedData.lastError().text();
            else {
                queryGetUsedData.first();
                usedData.append(queryGetUsedData.value(0).toString()); // so_id
                usedData.append(queryGetUsedData.value(1).toString()); // inspection_id
                usedData.append(queryGetUsedData.value(2).toString()); // process_name
            }
        }
        qDebug()<< "Error en queryInsertDictum: " + queryInsertDictum.lastError().text();
        return false;
    } else {
        queryInsertDictum.first();
        dictumId=queryInsertDictum.value(0).toString();
        dictumCode=queryInsertDictum.value(1).toString();

        QSqlQuery queryInsertExtraData;

        switch (dictumData.at(10).toInt()) { // id del proceso
        case BcProcs::Generacion:
            queryInsertExtraData.prepare("INSERT INTO tblGENDICTUMS (gendictum_se_type, gendictum_ses_number, dictum_id) "
                                         "VALUES (:gendictum_se_type, :gendictum_ses_number, :dictum_id)");

            queryInsertExtraData.bindValue(":gendictum_se_type", extraData.at(0));
            queryInsertExtraData.bindValue(":gendictum_ses_number", extraData.at(1));

            break;

        case BcProcs::Transmision:
            queryInsertExtraData.prepare("INSERT INTO tblTRANSMDICTUMS (transmdictum_line_detail, transmdictum_conf, transmdictum_length, "
                                         "transmdictum_wires_type, transmdictum_material, transmdictum_structs_number, dictum_id) "
                                         "VALUES (:transmdictum_line_detail, :transmdictum_conf, :transmdictum_length, "
                                         ":transmdictum_wires_type, :transmdictum_material, :transmdictum_structs_number, :dictum_id)");

            queryInsertExtraData.bindValue(":transmdictum_line_detail", extraData.at(0));
            queryInsertExtraData.bindValue(":transmdictum_conf", extraData.at(1));
            queryInsertExtraData.bindValue(":transmdictum_length", extraData.at(2));
            queryInsertExtraData.bindValue(":transmdictum_wires_type", extraData.at(3));
            queryInsertExtraData.bindValue(":transmdictum_material", extraData.at(4));
            queryInsertExtraData.bindValue(":transmdictum_structs_number", extraData.at(5));

            break;

        case BcProcs::Transformacion:
            queryInsertExtraData.prepare("INSERT INTO tblTRANSFDICTUMS (transfdictum_se_type, transfdictum_rate, transfdictum_transf_number, dictum_id) "
                                         "VALUES (:transfdictum_se_type, :transfdictum_rate, :transfdictum_transf_number, :dictum_id)");

            queryInsertExtraData.bindValue(":transfdictum_se_type", extraData.at(0));
            queryInsertExtraData.bindValue(":transfdictum_rate", extraData.at(1));
            queryInsertExtraData.bindValue(":transfdictum_transf_number", extraData.at(2));

            break;

        case BcProcs::Distribucion:
            queryInsertExtraData.prepare("INSERT INTO tblDISTDICTUMS (distdictum_conf, distdictum_length, "
                                         "distdictum_wires_type, distdictum_material, distdictum_structs_number, dictum_id) "
                                         "VALUES (:distdictum_conf, :distdictum_length, "
                                         ":distdictum_wires_type, :distdictum_material, :distdictum_structs_number, :dictum_id)");

            queryInsertExtraData.bindValue(":distdictum_conf", extraData.at(0));
            queryInsertExtraData.bindValue(":distdictum_length", extraData.at(1));
            queryInsertExtraData.bindValue(":distdictum_wires_type", extraData.at(2));
            queryInsertExtraData.bindValue(":distdictum_material", extraData.at(3));
            queryInsertExtraData.bindValue(":distdictum_structs_number", extraData.at(4));

            break;

        case BcProcs::AlumbradoExt:
            queryInsertExtraData.prepare("INSERT INTO tblALEXTDICTUMS (alextdictum_luminaries_number, alextdictum_measure_system, "
                                         "alextdictum_porpuse, alextdictum_length, alextdictum_area, dictum_id) "
                                         "VALUES (:alextdictum_luminaries_number, :alextdictum_measure_system, "
                                         ":alextdictum_porpuse, :alextdictum_length, :alextdictum_area, :dictum_id)");

            queryInsertExtraData.bindValue(":alextdictum_luminaries_number", extraData.at(0));
            queryInsertExtraData.bindValue(":alextdictum_measure_system", extraData.at(1));
            queryInsertExtraData.bindValue(":alextdictum_porpuse", extraData.at(2));
            queryInsertExtraData.bindValue(":alextdictum_length", extraData.at(3));
            queryInsertExtraData.bindValue(":alextdictum_area", extraData.at(4));

            break;

        default:
            break;
        }

        queryInsertExtraData.bindValue(":dictum_id", dictumId.toInt());
        // Solo se ejecuta la consulta si no corresponde a uno de estos dos procesos
        if (dictumData.at(10).toInt()!=BcProcs::UsoFinal && dictumData.at(10).toInt() != BcProcs::AlumbradoInt)
            if (!queryInsertExtraData.exec()) {
                qDebug() << "Error en queryInsertExtraData: " + queryInsertExtraData.lastError().text();
                return false;
            }

        for (int i=0; i < reqResults.at(0).size(); i++)
            insertDictumReqs(dictumId, reqResults.at(0).at(i), reqResults.at(1).at(i), reqResults.at(2).at(i));

        for (int i=0; i < dictumUseData.at(0).size(); i++)
            insertDictumUses(dictumId, dictumUseData.at(0).at(i), dictumUseData.at(1).at(i));

        for (int i=0; i < dictumProcIds.size(); i++)
            insertDictumProcs(dictumId, dictumProcIds.at(i));

        return true;
    }
    return false;

}

// NOTE: Insertar los requerimientos de un dictamen
bool DbHandler::insertDictumReqs(const QString dictumId, const QString reqId, const QString reqMeets, const QString reqNoMeets)
{
    QSqlQuery queryInsertDictumReqs;
    queryInsertDictumReqs.prepare("INSERT INTO tblDICTUMREQS (dictum_id, req_id, req_meets, req_no_meets) "
                                     "VALUES (:dictum_id, :req_id, :req_meets, :req_no_meets)");

    queryInsertDictumReqs.bindValue(":dictum_id", dictumId.toInt());
    queryInsertDictumReqs.bindValue(":req_id", reqId.toInt());
    queryInsertDictumReqs.bindValue(":req_meets", reqMeets);
    queryInsertDictumReqs.bindValue(":req_no_meets", reqNoMeets);

    if (!queryInsertDictumReqs.exec()) {
        qDebug() << "Error en queryInsertDictumReqs: " + queryInsertDictumReqs.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insertar usos de un dictamen
bool DbHandler::insertDictumUses(const QString dictumId, const QString useId, const QString useSname)
{
    QSqlQuery queryInsertDictumUses;
    queryInsertDictumUses.prepare("INSERT INTO tblDICTUMUSES (dictum_id, use_id, use_sname) "
                                     "VALUES (:dictum_id, :use_id, :use_sname)");

    queryInsertDictumUses.bindValue(":dictum_id", dictumId.toInt());
    queryInsertDictumUses.bindValue(":use_id", useId.toInt());
    queryInsertDictumUses.bindValue(":use_sname", useSname);

    if (!queryInsertDictumUses.exec()) {
        qDebug() << "Error en queryInsertDictumUses: " + queryInsertDictumUses.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insertar usos de un dictamen
bool DbHandler::insertDictumProcs(const QString dictumId, const QString processId)
{
    QSqlQuery queryInsertDictumProcs;
    queryInsertDictumProcs.prepare("INSERT INTO tblDICTUMPROCS (dictum_id, process_id) "
                                     "VALUES (:dictum_id, :process_id)");

    queryInsertDictumProcs.bindValue(":dictum_id", dictumId.toInt());
    queryInsertDictumProcs.bindValue(":process_id", processId.toInt());

    if (!queryInsertDictumProcs.exec()) {
        qDebug() << "Error en queryInsertDictumProcs: " + queryInsertDictumProcs.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Insertar subdictamen
bool DbHandler::insertSubDictum(QStringList subDictumData, QList<QStringList> reqResults, QString indexPos)
{
    QString subDictumId;

    QSqlQuery queryInsertSubDictum;
    queryInsertSubDictum.prepare("INSERT INTO tblSUBDICTUMS (subdictum_number, subdictum_date, subdictum_state, subdictum_tech_state, subdictum_scope, "
                                 "subdictum_observ, subdictum_type, subdictum_identifier, subdictum_location, subdictum_inst_rate, "
                                 "subdictum_inst_voltage, subdictum_inst_res, dictum_id) "
                              "VALUES (:subdictum_number, :subdictum_date, :subdictum_state, :subdictum_tech_state, :subdictum_scope, :subdictum_observ, "
                              ":subdictum_type, :subdictum_identifier, :subdictum_location, :subdictum_inst_rate, :subdictum_inst_voltage, "
                                 ":subdictum_inst_res, :dictum_id) "
                                 "RETURNING subdictum_id");

    queryInsertSubDictum.bindValue(":subdictum_number", subDictumData.at(0)+"-"+indexPos);
    queryInsertSubDictum.bindValue(":subdictum_date", subDictumData.at(1));
    queryInsertSubDictum.bindValue(":subdictum_state", subDictumData.at(2));
    queryInsertSubDictum.bindValue(":subdictum_tech_state", subDictumData.at(3));
    queryInsertSubDictum.bindValue(":subdictum_scope", subDictumData.at(4));
    queryInsertSubDictum.bindValue(":subdictum_observ", subDictumData.at(5));
    queryInsertSubDictum.bindValue(":subdictum_type", subDictumData.at(6));
    queryInsertSubDictum.bindValue(":subdictum_identifier", subDictumData.at(7));
    queryInsertSubDictum.bindValue(":subdictum_location", subDictumData.at(8));
    queryInsertSubDictum.bindValue(":subdictum_inst_rate", subDictumData.at(9));
    queryInsertSubDictum.bindValue(":subdictum_inst_voltage", subDictumData.at(10));
    queryInsertSubDictum.bindValue(":subdictum_inst_res", subDictumData.at(11));
    queryInsertSubDictum.bindValue(":dictum_id", subDictumData.at(12).toInt());

    if (!queryInsertSubDictum.exec()) {
        qDebug()<< "Error en queryInsertSubDictum: " + queryInsertSubDictum.lastError().text();
        return false;
    } else {
        queryInsertSubDictum.first();
        subDictumId=queryInsertSubDictum.value(0).toString();

        for (int i=0; i < reqResults.at(0).size(); i++)
            insertSubDictumReqs(subDictumId, reqResults.at(0).at(i), reqResults.at(1).at(i), reqResults.at(2).at(i));

        return true;
    }
    return false;

}

// NOTE: Insertar los requerimientos de un subdictamen o consecutivo
bool DbHandler::insertSubDictumReqs(const QString subDictumId, const QString reqId, const QString reqMeets, const QString reqNoMeets)
{
    QSqlQuery queryInsertSubDictumReqs;
    queryInsertSubDictumReqs.prepare("INSERT INTO tblSUBDICTUMREQS (subdictum_id, req_id, req_meets, req_no_meets) "
                                     "VALUES (:subdictum_id, :req_id, :req_meets, :req_no_meets)");

    queryInsertSubDictumReqs.bindValue(":subdictum_id", subDictumId.toInt());
    queryInsertSubDictumReqs.bindValue(":req_id", reqId.toInt());
    queryInsertSubDictumReqs.bindValue(":req_meets", reqMeets);
    queryInsertSubDictumReqs.bindValue(":req_no_meets", reqNoMeets);

    if (!queryInsertSubDictumReqs.exec()) {
        qDebug() << "Error en queryInsertSubDictumReqs: " + queryInsertSubDictumReqs.lastError().text();
        return false;
    } else
        return true;
    return false;
}

// NOTE: Insertar Usuario
bool DbHandler::insertUser(QStringList userData)
{
    QSqlQuery queryInsertUser;
    queryInsertUser.prepare("INSERT INTO tblUSERS (user_name, user_passwd, user_lname, user_charge, user_level, "
                            "user_address, user_mail, user_cel, user_tel, user_available, user_percentage, user_nit) "
                            "VALUES (:user_name, :user_passwd, :user_lname, :user_charge, :user_level, :user_address, "
                            ":user_mail, :user_cel, :user_tel, :user_available, :user_percentage, :user_nit)");

    queryInsertUser.bindValue(":user_name", userData.at(0));
    queryInsertUser.bindValue(":user_passwd", userData.at(1));
    queryInsertUser.bindValue(":user_lname", userData.at(2));
    queryInsertUser.bindValue(":user_charge", userData.at(3));
    queryInsertUser.bindValue(":user_level", userData.at(4).toInt());
    queryInsertUser.bindValue(":user_address", userData.at(5));
    queryInsertUser.bindValue(":user_mail", userData.at(6));
    queryInsertUser.bindValue(":user_cel", userData.at(7));
    queryInsertUser.bindValue(":user_tel", userData.at(8));
    queryInsertUser.bindValue(":user_available", userData.at(9));
    queryInsertUser.bindValue(":user_percentage", userData.at(10).toDouble());
    queryInsertUser.bindValue(":user_nit", userData.at(11));

    if (!queryInsertUser.exec()) {
        qDebug() << "Error en queryInsertUser: " + queryInsertUser.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

// NOTE: Insertar Inspector
bool DbHandler::insertInspector(QStringList inspectorData)
{
    QSqlQuery queryInsertInspector;
    queryInsertInspector.prepare("INSERT INTO tblINSPECTORS (inspector_name, inspector_mp, inspector_address, inspector_mail, "
                                 "inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) "
                                 "VALUES (:inspector_name, :inspector_mp, :inspector_address, :inspector_mail, :inspector_cel, "
                                 ":inspector_tel, :inspector_available, :inspector_percentage, :inspector_nit)");

    queryInsertInspector.bindValue(":inspector_name", inspectorData.at(0));
    queryInsertInspector.bindValue(":inspector_mp", inspectorData.at(1));
    queryInsertInspector.bindValue(":inspector_address", inspectorData.at(2));
    queryInsertInspector.bindValue(":inspector_mail", inspectorData.at(3));
    queryInsertInspector.bindValue(":inspector_cel", inspectorData.at(4));
    queryInsertInspector.bindValue(":inspector_tel", inspectorData.at(5));
    queryInsertInspector.bindValue(":inspector_available", inspectorData.at(6));
    queryInsertInspector.bindValue(":inspector_percentage", inspectorData.at(7).toDouble());
    queryInsertInspector.bindValue(":inspector_nit", inspectorData.at(8));

    if (!queryInsertInspector.exec()) {
        qDebug() << "Error en queryInsertInspector: " + queryInsertInspector.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

// NOTE: Insertar detalles de Inspector
bool DbHandler::insertInspDetail(QStringList inspDetailData)
{
    if (inspDetailData.isEmpty())
        return true;

    QSqlQuery queryInsertInspDetail;

    queryInsertInspDetail.prepare("INSERT INTO tblINSPDETAILS (insp_detail_state, insp_detail_descr, inspector_id) "
                                  "VALUES (:insp_detail_state, :insp_detail_descr, :inspector_id)");

    queryInsertInspDetail.bindValue(":insp_detail_state", inspDetailData.at(0));
    queryInsertInspDetail.bindValue(":insp_detail_descr", inspDetailData.at(1));
    queryInsertInspDetail.bindValue(":inspector_id", inspDetailData.at(2));

    if (!queryInsertInspDetail.exec()) {
        qDebug() << "Error en queryInsertInspDetail: " + queryInsertInspDetail.lastError().text();
        return false;
    } else
        return true;
    return false;
}

// NOTE: Insertar Disenador
bool DbHandler::insertDesigner(QStringList designerData)
{
    QSqlQuery queryInsertDesigner;
    queryInsertDesigner.prepare("INSERT INTO tblDESIGNERS (designer_name, designer_mp, designer_mail, designer_cel, designer_nit) "
                                "VALUES (:designer_name, :designer_mp, :designer_mail, :designer_cel, :designer_nit)");

    queryInsertDesigner.bindValue(":designer_name", designerData.at(0));
    queryInsertDesigner.bindValue(":designer_mp", designerData.at(1));
    queryInsertDesigner.bindValue(":designer_mail", designerData.at(2));
    queryInsertDesigner.bindValue(":designer_cel", designerData.at(3));
    queryInsertDesigner.bindValue(":designer_nit", designerData.at(4));

    if (!queryInsertDesigner.exec()) {
        qDebug() << "Error en queryInsertDesigner: " + queryInsertDesigner.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

// NOTE: Insertar Constructor
bool DbHandler::insertConstructor(QStringList constructorData)
{
    QSqlQuery queryInsertConstructor;
    queryInsertConstructor.prepare("INSERT INTO tblCONSTRUCTORS (constructor_name, constructor_mp, constructor_mail, constructor_cel, constructor_nit) "
                                "VALUES (:constructor_name, :constructor_mp, :constructor_mail, :constructor_cel, :constructor_nit)");

    queryInsertConstructor.bindValue(":constructor_name", constructorData.at(0));
    queryInsertConstructor.bindValue(":constructor_mp", constructorData.at(1));
    queryInsertConstructor.bindValue(":constructor_mail", constructorData.at(2));
    queryInsertConstructor.bindValue(":constructor_cel", constructorData.at(3));
    queryInsertConstructor.bindValue(":constructor_nit", constructorData.at(4));

    if (!queryInsertConstructor.exec()) {
        qDebug() << "Error en queryInsertConstructor: " + queryInsertConstructor.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

// NOTE: Insertar Interventor
bool DbHandler::insertAuditor(QStringList auditorData)
{
    QSqlQuery queryInsertAuditor;
    queryInsertAuditor.prepare("INSERT INTO tblAUDITORS (auditor_name, auditor_mp, auditor_mail, auditor_cel, auditor_nit) "
                                "VALUES (:auditor_name, :auditor_mp, :auditor_mail, :auditor_cel, :auditor_nit)");

    queryInsertAuditor.bindValue(":auditor_name", auditorData.at(0));
    queryInsertAuditor.bindValue(":auditor_mp", auditorData.at(1));
    queryInsertAuditor.bindValue(":auditor_mail", auditorData.at(2));
    queryInsertAuditor.bindValue(":auditor_cel", auditorData.at(3));
    queryInsertAuditor.bindValue(":auditor_nit", auditorData.at(4));

    if (!queryInsertAuditor.exec()) {
        qDebug() << "Error en queryInsertAuditor: " + queryInsertAuditor.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

/*

ACTUALIZACIONES
----------------------------------------------------------------------------------------------------------

*/

// NOTE: Actualizacion de la cotizacion
bool DbHandler::updateQuotation(const QStringList quotData, QStringList procsIds)
{
    QSqlQuery queryUpdateQuotation;
    queryUpdateQuotation.prepare("UPDATE tblQUOTATIONS SET quot_date=:quot_date, quot_name=:quot_name, quot_scope=:quot_scope, "
                                 "quot_contact=:quot_contact, quot_address=:quot_address, quot_mail=:quot_mail, quot_cel=:quot_cel, "
                                 "quot_tel=:quot_tel, quot_inspect_type=:quot_inspect_type, city_id=:city_id, use_id=:use_id "
                                 "WHERE quot_id=:quot_id");
    queryUpdateQuotation.bindValue(":quot_id", quotData.at(0).toInt());
    queryUpdateQuotation.bindValue(":quot_date", quotData.at(1));
    queryUpdateQuotation.bindValue(":quot_name", quotData.at(2));
    queryUpdateQuotation.bindValue(":quot_scope", quotData.at(3));
    queryUpdateQuotation.bindValue(":quot_contact" ,quotData.at(4));
    queryUpdateQuotation.bindValue(":quot_address" ,quotData.at(5));
    queryUpdateQuotation.bindValue(":quot_mail", quotData.at(6));
    queryUpdateQuotation.bindValue(":quot_cel", quotData.at(7));
    queryUpdateQuotation.bindValue(":quot_tel", quotData.at(8));
    queryUpdateQuotation.bindValue(":city_id", quotData.at(9).toInt());
    queryUpdateQuotation.bindValue(":use_id", quotData.at(10).toInt());
    queryUpdateQuotation.bindValue(":quot_inspect_type", quotData.at(11));

    if (!queryUpdateQuotation.exec()) {
        qDebug() << "Error en queryUpdateQuotation: " + queryUpdateQuotation.lastError().text();
        return false;
    } else {
        updateQuotProcesses(quotData.at(0), procsIds);
        return true;
    }
}

// NOTE: Actualizacion de los procesos de la cotizacion
bool DbHandler::updateQuotProcesses(const QString quotId, const QStringList procsIds)
{
    QSqlQuery queryDeleteQuotProcesses;
    queryDeleteQuotProcesses.prepare("DELETE FROM tblQUOTPROCESSES WHERE quot_id=:quot_id");

    queryDeleteQuotProcesses.bindValue(":quot_id", quotId.toInt());
    if (!queryDeleteQuotProcesses.exec()) {
        qDebug() << "Error en queryDeleteQuotProcesses: " + queryDeleteQuotProcesses.lastError().text();
        return false;
    } else {
        for (int i=0; i < procsIds.size(); i++)
            insertQuotProcesses(quotId, procsIds.at(i));
        return true;
    }
}

// NOTE: Actualizar propuesta comercial
bool DbHandler::updateProposal(const QStringList propData, const QStringList documentsIds)
{
    QSqlQuery queryUpdateProposal;

    queryUpdateProposal.prepare("UPDATE tblPROPOSALS SET prop_date=:prop_date, prop_scope=:prop_scope, "
                                "prop_payway=:prop_payway, prop_state=:prop_state, prop_user_perc=:prop_user_perc, "
                                "prop_observ=:prop_observ, user_id=:user_id, prop_value=:prop_value, prop_iva=:prop_iva, "
                                "prop_viatical=:prop_viatical, prop_total_value=:prop_total_value "
                                "WHERE prop_id=:prop_id");

    queryUpdateProposal.bindValue(":prop_id", propData.at(0).toInt());
    queryUpdateProposal.bindValue(":prop_date", propData.at(1));
    queryUpdateProposal.bindValue(":prop_scope", propData.at(2));
    queryUpdateProposal.bindValue(":prop_payway", propData.at(3));
    queryUpdateProposal.bindValue(":prop_state", propData.at(4));
    queryUpdateProposal.bindValue(":prop_user_perc", propData.at(5).toFloat());
    queryUpdateProposal.bindValue(":prop_observ", propData.at(6));
    queryUpdateProposal.bindValue(":user_id", propData.at(7).toInt());
    queryUpdateProposal.bindValue(":prop_value", propData.at(8));
    queryUpdateProposal.bindValue(":prop_iva", propData.at(9));
    queryUpdateProposal.bindValue(":prop_viatical", propData.at(10));
    queryUpdateProposal.bindValue(":prop_total_value", propData.at(11));

    if (!queryUpdateProposal.exec()) {
        qDebug() << "Error en queryUpdateProposal: " + queryUpdateProposal.lastError().text();
        return false;
    } else {
        updatePropDocuments(propData.at(0), documentsIds);
        return true;
    }
}

// NOTE: Actualizacion de los documentos de una propuesta
bool DbHandler::updatePropDocuments(const QString propId, const QStringList documentsIds)
{
    QSqlQuery queryDeletePropDocuments;
    queryDeletePropDocuments.prepare("DELETE FROM tblPROPDOCUMENTS WHERE prop_id=:prop_id");

    queryDeletePropDocuments.bindValue(":prop_id", propId.toInt());

    if (!queryDeletePropDocuments.exec()) {
        qDebug() << "Error en queryDeletePropDocuments: " + queryDeletePropDocuments.lastError().text();
        return false;
    } else {
        for (int i=0; i < documentsIds.size(); i++)
            insertPropDocuments(propId, documentsIds.at(i));
        return true;
    }
}

// NOTE: Actualizar metodo de aprobacion.
bool DbHandler::updatePropApproval(const QString propId, const QString propState, const QString approvalDetail)
{
    QSqlQuery queryUpdatePropApproval;

    queryUpdatePropApproval.prepare("UPDATE tblPROPOSALS SET prop_state=:prop_state, prop_state_detail=:prop_state_detail "
                                   "WHERE prop_id=:prop_id");

    queryUpdatePropApproval.bindValue(":prop_id", propId);
    queryUpdatePropApproval.bindValue(":prop_state", propState);
    queryUpdatePropApproval.bindValue(":prop_state_detail", approvalDetail);

    if (!queryUpdatePropApproval.exec()) {
        qDebug() << "Error en queryUpdatePropApproval: " + queryUpdatePropApproval.lastError().text();
        return false;
    } else
        return true;

    return false;
}

// NOTE: Actualizar orden de servicio
bool DbHandler::updateServiceOrder(const QStringList soData)
{
    QSqlQuery queryUpdateServiceOrder;

    queryUpdateServiceOrder.prepare("UPDATE tblSERVICEORDERS SET so_date=:so_date, so_scope=:so_scope, "
                                    "so_observations=:so_observations, so_inspector_perc=:so_inspector_perc, "
                                    "so_assign_date=:so_assign_date, inspector_id=:inspector_id "
                                    "WHERE so_id=:so_id");

    queryUpdateServiceOrder.bindValue(":so_id", soData.at(0).toInt());
    queryUpdateServiceOrder.bindValue(":so_date", soData.at(1));
    queryUpdateServiceOrder.bindValue(":so_scope", soData.at(2));
    queryUpdateServiceOrder.bindValue(":so_observations", soData.at(3));
    queryUpdateServiceOrder.bindValue(":so_inspector_perc", soData.at(4).toFloat());
    queryUpdateServiceOrder.bindValue(":so_assign_date", soData.at(5));
    queryUpdateServiceOrder.bindValue(":inspector_id", soData.at(6).toInt());

    if (!queryUpdateServiceOrder.exec()) {
        qDebug() << "Error en queryUpdateServiceOrder: " + queryUpdateServiceOrder.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Actualizacion de los documentos de una orden de servicio
bool DbHandler::updateSoDocuments(const QString soId, const QStringList documentsIds)
{
    // La estrategia es borrarlos para insertarlos de nuevo y así no crear una
    // función muy similar a la de inserciones, mejor usar la que hay.
    QSqlQuery queryDeleteSoDocuments;
    queryDeleteSoDocuments.prepare("DELETE FROM tblSODOCUMENTS WHERE so_id=:so_id");

    queryDeleteSoDocuments.bindValue(":so_id", soId.toInt());

    if (!queryDeleteSoDocuments.exec()) {
        qDebug() << "Error en queryDeleteSoDocuments: " + queryDeleteSoDocuments.lastError().text();
        return false;
    } else {
        for (int i=0; i < documentsIds.size(); i++)
            insertSoDocuments(soId, documentsIds.at(i));
        return true;
    }
}

// NOTE: Actualizacion de los folios o az's de una orden de servicio
bool DbHandler::updateSoRecords(const QString soId, const QStringList recordsIds)
{
    // La estrategia es borrarlos para insertarlos de nuevo y así no crear una
    // función muy similar a la de inserciones, mejor usar la que hay.
    QSqlQuery queryDeleteSoRecords;
    queryDeleteSoRecords.prepare("DELETE FROM tblSORECORDS WHERE so_id=:so_id");

    queryDeleteSoRecords.bindValue(":so_id", soId.toInt());

    if (!queryDeleteSoRecords.exec()) {
        qDebug() << "Error en queryDeleteSoRecords: " + queryDeleteSoRecords.lastError().text();
        return false;
    } else {
        for (int i=0; i < recordsIds.size(); i++)
            insertSoRecords(soId, recordsIds.at(i));
        return true;
    }
}

// NOTE: Actualizacion del Tracking de una orden de servicio
bool DbHandler::updateSoTracking(const QStringList soTrackingData)
{
    QSqlQuery queryUpdateSoTracking;
    queryUpdateSoTracking.prepare("UPDATE tblSOTRACKING SET trck_receipt_date=:trck_receipt_date, trck_receiver_name=:trck_receiver_name, "
                                  "trck_shipping_date=:trck_shipping_date, trck_shipper_name=:trck_shipper_name, trck_shipping_name=:trck_shipping_name, "
                                  "trck_shipping_company=:trck_shipping_company, trck_guide_number=:trck_guide_number, trck_observations=:trck_observations, "
                                  "city_id=:city_id WHERE so_id=:so_id");

    queryUpdateSoTracking.bindValue(":so_id", soTrackingData.at(0).toInt());
    queryUpdateSoTracking.bindValue(":trck_receipt_date", soTrackingData.at(1));
    queryUpdateSoTracking.bindValue(":trck_receiver_name", soTrackingData.at(2));
    queryUpdateSoTracking.bindValue(":trck_shipping_date", soTrackingData.at(3));
    queryUpdateSoTracking.bindValue(":trck_shipper_name", soTrackingData.at(4));
    queryUpdateSoTracking.bindValue(":trck_shipping_name", soTrackingData.at(5));
    queryUpdateSoTracking.bindValue(":trck_shipping_company", soTrackingData.at(6));
    queryUpdateSoTracking.bindValue(":trck_guide_number", soTrackingData.at(7));
    queryUpdateSoTracking.bindValue(":trck_observations", soTrackingData.at(8));
    queryUpdateSoTracking.bindValue(":city_id", soTrackingData.at(9).toInt());

    if (!queryUpdateSoTracking.exec()) {
        qDebug() << "Error en queryUpdateSoTracking: " + queryUpdateSoTracking.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Actualizar orden de servicio como abonada
bool DbHandler::updateSoAccountingState(const QString soId, const QString state, const QString billNumber)
{
    QSqlQuery queryUpdateSoAccountingState;
    queryUpdateSoAccountingState.prepare("UPDATE tblSERVICEORDERS SET so_acc_processed=:so_acc_processed, "
                                         "so_bill_number=:so_bill_number "
                                         "WHERE so_id=:so_id");

    queryUpdateSoAccountingState.bindValue(":so_id", soId);
    queryUpdateSoAccountingState.bindValue(":so_acc_processed", state);
    queryUpdateSoAccountingState.bindValue(":so_bill_number", billNumber);

    if (!queryUpdateSoAccountingState.exec()) {
        qDebug() << "Error en la consulta queryUpdateSoAccountingState: " << queryUpdateSoAccountingState.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Actualizar orden de servicio revisada o incompleta
bool DbHandler::updateSoDocState(const QString soId, const QString state)
{
    QSqlQuery queryUpdateSoDocState;
    queryUpdateSoDocState.prepare("UPDATE tblSERVICEORDERS SET so_doc_processed=:so_doc_processed WHERE so_id=:so_id");

    queryUpdateSoDocState.bindValue(":so_id", soId);
    queryUpdateSoDocState.bindValue(":so_doc_processed", state);

    if (!queryUpdateSoDocState.exec()) {
        qDebug() << "Error en la consulta queryUpdateSoDocState: " << queryUpdateSoDocState.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Actualizar orden de servicio revisada o incompleta
bool DbHandler::updateSoEngState(const QString soId, const QString state)
{
    QSqlQuery queryUpdateSoEngState;
    queryUpdateSoEngState.prepare("UPDATE tblSERVICEORDERS SET so_eng_processed=:so_eng_processed WHERE so_id=:so_id");

    queryUpdateSoEngState.bindValue(":so_id", soId);
    queryUpdateSoEngState.bindValue(":so_eng_processed", state);

    if (!queryUpdateSoEngState.exec()) {
        qDebug() << "Error en la consulta queryUpdateSoEngState: " << queryUpdateSoEngState.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Actualizar observaciones de ingenieria en la OS
bool DbHandler::updateSoEngObservations(const QString soId, QString soEngObserv)
{
    QSqlQuery queryUpdateEngObserv;

    queryUpdateEngObserv.prepare("UPDATE tblSERVICEORDERS SET so_eng_observations=:so_eng_observations "
                                 "WHERE so_id=:so_id");

    queryUpdateEngObserv.bindValue(":so_id", soId);
    queryUpdateEngObserv.bindValue(":so_eng_observations", soEngObserv);

    if (!queryUpdateEngObserv.exec()) {
        qDebug() << "Error en queryUpdateEngObserv: " + queryUpdateEngObserv.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Actualizar observaciones de Gerencia en la OS
bool DbHandler::updateSoAdmObservations(const QString soId, QString soAdmObserv)
{
    QSqlQuery queryUpdateAdmObserv;

    queryUpdateAdmObserv.prepare("UPDATE tblSERVICEORDERS SET so_adm_observations=:so_adm_observations "
                                 "WHERE so_id=:so_id");

    queryUpdateAdmObserv.bindValue(":so_id", soId);
    queryUpdateAdmObserv.bindValue(":so_adm_observations", soAdmObserv);

    if (!queryUpdateAdmObserv.exec()) {
        qDebug() << "Error en queryUpdateAdmObserv: " + queryUpdateAdmObserv.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Actualizar inspeccion
bool DbHandler::updateInspection(const QStringList inspectionData, QStringList inspectionDesignersIds)
{
    QSqlQuery queryUpdateInspection;
    queryUpdateInspection.prepare("UPDATE tblINSPECTIONS SET inspection_date=:inspection_date, inspection_state=:inspection_state, "
                                  "inspection_observ=:inspection_observ, inspection_address=:inspection_address, "
                                  "inspection_propietary=:inspection_propietary, city_id=:city_id, so_id=:so_id, "
                                  "constructor_id=:constructor_id, auditor_id=:auditor_id "
                                  "WHERE inspection_id=:inspection_id");

    queryUpdateInspection.bindValue(":inspection_id", inspectionData.at(0).toInt());
    queryUpdateInspection.bindValue(":inspection_date", inspectionData.at(1));
    queryUpdateInspection.bindValue(":inspection_state", inspectionData.at(2));
    queryUpdateInspection.bindValue(":inspection_observ", inspectionData.at(3));
    queryUpdateInspection.bindValue(":inspection_address", inspectionData.at(4));
    queryUpdateInspection.bindValue(":inspection_propietary", inspectionData.at(5));
    queryUpdateInspection.bindValue(":city_id", inspectionData.at(6).toInt());
    queryUpdateInspection.bindValue(":so_id", inspectionData.at(7).toInt());
    queryUpdateInspection.bindValue(":constructor_id", inspectionData.at(8).toInt());
    queryUpdateInspection.bindValue(":auditor_id", inspectionData.at(9).toInt());

    if (!queryUpdateInspection.exec()) {
        qDebug() << "Error en queryUpdateInspection: " + queryUpdateInspection.lastQuery();
        return false;
    } else {
        updateInspectionDesigners(inspectionData.at(0), inspectionDesignersIds);
        return true;
    }

}

// NOTE: Actualizar estado de inspeccion
bool DbHandler::updateInspectionState(QString inspectionId, QString state)
{
    QSqlQuery queryEndInspection;
    queryEndInspection.prepare("UPDATE tblINSPECTIONS SET inspection_state=:inspection_state "
                               "WHERE inspection_id=:inspection_id");

    queryEndInspection.bindValue(":inspection_id", inspectionId);
    queryEndInspection.bindValue(":inspection_state", state);

    if (!queryEndInspection.exec()) {
        qDebug() << "Error en queryEndInspection: " + queryEndInspection.lastError().text();
        return false;
    } else
        return true;
}

// NOTE: Actualizacion de los disenadores de la inspeccion
bool DbHandler::updateInspectionDesigners(const QString inspectionId, const QStringList inspectionDesignersId)
{
    // La estrategia es borrarlos para insertarlos de nuevo y así no crear una
    // función muy similar a la de inserciones, mejor usar la que hay.
    QSqlQuery queryDeleteInspectionDesigners;
    queryDeleteInspectionDesigners.prepare("DELETE FROM tblINSPECTIONDESIGNERS WHERE inspection_id=:inspection_id");

    queryDeleteInspectionDesigners.bindValue(":inspection_id", inspectionId.toInt());

    if (!queryDeleteInspectionDesigners.exec()) {
        qDebug() << "Error en queryDeleteInspectionDesigners: " + queryDeleteInspectionDesigners.lastError().text();
        return false;
    } else {
        for (int i=0; i < inspectionDesignersId.size(); i++)
            insertInspectionDesigners(inspectionId, inspectionDesignersId.at(i));
        return true;
    }
}

// NOTE: Actualizar dictamen
bool DbHandler::updateDictum(QStringList dictumData, QStringList extraData, QList<QStringList> reqResults, QList<QStringList> dictumUseData, QStringList dictumProcIds)
{
    QSqlQuery queryUpdateDictum;
    queryUpdateDictum.prepare("UPDATE tblDICTUMS SET dictum_date=:dictum_date, dictum_state=:dictum_state, "
                              "dictum_tech_state=:dictum_tech_state, dictum_scope=:dictum_scope, dictum_observ=:dictum_observ, "
                              "dictum_inst_rate=:dictum_inst_rate, dictum_inst_voltage=:dictum_inst_voltage, "
                              "dictum_inst_resist=:dictum_inst_resist, dictum_inst_date=:dictum_inst_date "
                              "WHERE dictum_id=:dictum_id");

    queryUpdateDictum.bindValue(":dictum_id", dictumData.at(0).toInt());
    queryUpdateDictum.bindValue(":dictum_date", dictumData.at(1));
    queryUpdateDictum.bindValue(":dictum_state", dictumData.at(2));
    queryUpdateDictum.bindValue(":dictum_tech_state", dictumData.at(3));
    queryUpdateDictum.bindValue(":dictum_scope", dictumData.at(4));
    queryUpdateDictum.bindValue(":dictum_observ", dictumData.at(5));
    queryUpdateDictum.bindValue(":dictum_inst_rate", dictumData.at(6));
    queryUpdateDictum.bindValue(":dictum_inst_voltage", dictumData.at(7));
    queryUpdateDictum.bindValue(":dictum_inst_resist", dictumData.at(8));
    queryUpdateDictum.bindValue(":dictum_inst_date", dictumData.at(9));

    if (!queryUpdateDictum.exec()) {
        qDebug()<< "Error en queryUpdateDictum: " + queryUpdateDictum.lastError().text();
        return false;
    } else {
        QSqlQuery queryDeleteDictumReqs;
        queryDeleteDictumReqs.prepare("DELETE FROM tblDICTUMREQS WHERE dictum_id=:dictum_id");

        queryDeleteDictumReqs.bindValue(":dictum_id", dictumData.at(0).toInt());

        if (!queryDeleteDictumReqs.exec()) {
            qDebug() << "Error en queryDeleteDictumReqs: " + queryDeleteDictumReqs.lastError().text();
            return false;
        } else {

            QSqlQuery queryUpdateExtraData;

            switch (dictumData.at(10).toInt()) {
            case BcProcs::Generacion:
                queryUpdateExtraData.prepare("UPDATE tblGENDICTUMS SET gendictum_se_type=:gendictum_se_type, "
                                             "gendictum_ses_number=:gendictum_ses_number "
                                             "WHERE dictum_id=:dictum_id");

                queryUpdateExtraData.bindValue(":gendictum_se_type", extraData.at(0));
                queryUpdateExtraData.bindValue(":gendictum_ses_number", extraData.at(1));

                break;

            case BcProcs::Transmision:
                queryUpdateExtraData.prepare("UPDATE tblTRANSMDICTUMS SET transmdictum_line_detail=:transmdictum_line_detail, "
                                             "transmdictum_conf=:transmdictum_conf, transmdictum_length=:transmdictum_length, "
                                             "transmdictum_wires_type=:transmdictum_wires_type, transmdictum_material=:transmdictum_material, "
                                             "transmdictum_structs_number=:transmdictum_structs_number "
                                             "WHERE dictum_id=:dictum_id");

                queryUpdateExtraData.bindValue(":transmdictum_line_detail", extraData.at(0));
                queryUpdateExtraData.bindValue(":transmdictum_conf", extraData.at(1));
                queryUpdateExtraData.bindValue(":transmdictum_length", extraData.at(2));
                queryUpdateExtraData.bindValue(":transmdictum_wires_type", extraData.at(3));
                queryUpdateExtraData.bindValue(":transmdictum_material", extraData.at(4));
                queryUpdateExtraData.bindValue(":transmdictum_structs_number", extraData.at(5));

                break;

            case BcProcs::Transformacion:
                queryUpdateExtraData.prepare("UPDATE tblTRANSFDICTUMS SET transfdictum_se_type=:transfdictum_se_type, "
                                             "transfdictum_rate=:transfdictum_rate, transfdictum_transf_number=:transfdictum_transf_number "
                                             "WHERE dictum_id=:dictum_id");

                queryUpdateExtraData.bindValue(":transfdictum_se_type", extraData.at(0));
                queryUpdateExtraData.bindValue(":transfdictum_rate", extraData.at(1));
                queryUpdateExtraData.bindValue(":transfdictum_transf_number", extraData.at(2));

                break;

            case BcProcs::Distribucion:
                queryUpdateExtraData.prepare("UPDATE tblDISTDICTUMS SET distdictum_conf=:distdictum_conf, distdictum_length=:distdictum_length, "
                                             "distdictum_wires_type=:distdictum_wires_type, distdictum_material=:distdictum_material, "
                                             "distdictum_structs_number=:distdictum_structs_number "
                                             "WHERE dictum_id=:dictum_id");

                queryUpdateExtraData.bindValue(":distdictum_conf", extraData.at(0));
                queryUpdateExtraData.bindValue(":distdictum_length", extraData.at(1));
                queryUpdateExtraData.bindValue(":distdictum_wires_type", extraData.at(2));
                queryUpdateExtraData.bindValue(":distdictum_material", extraData.at(3));
                queryUpdateExtraData.bindValue(":distdictum_structs_number", extraData.at(4));

                break;

            case BcProcs::AlumbradoExt:
                queryUpdateExtraData.prepare("UPDATE tblALEXTDICTUMS SET alextdictum_luminaries_number=:alextdictum_luminaries_number, "
                                             "alextdictum_measure_system=:alextdictum_measure_system, alextdictum_porpuse=:alextdictum_porpuse, "
                                             "alextdictum_length=:alextdictum_length, alextdictum_area=:alextdictum_area "
                                             "WHERE dictum_id=:dictum_id");

                queryUpdateExtraData.bindValue(":alextdictum_luminaries_number", extraData.at(0));
                queryUpdateExtraData.bindValue(":alextdictum_measure_system", extraData.at(1));
                queryUpdateExtraData.bindValue(":alextdictum_porpuse", extraData.at(2));
                queryUpdateExtraData.bindValue(":alextdictum_length", extraData.at(3));
                queryUpdateExtraData.bindValue(":alextdictum_area", extraData.at(4));

                break;

            default:
                break;
            }

            queryUpdateExtraData.bindValue(":dictum_id", dictumData.at(0).toInt());
            // Solo se ejecuta la consulta si no corresponde a uno de estos dos procesos
            if (dictumData.at(10).toInt()!=BcProcs::UsoFinal && dictumData.at(10).toInt() != BcProcs::AlumbradoInt)
                if (!queryUpdateExtraData.exec()) {
                    qDebug() << "Error en queryUpdateExtraData: " + queryUpdateExtraData.lastError().text();
                    return false;
                }

            for (int i=0; i < reqResults.at(0).size(); i++)
                insertDictumReqs(dictumData.at(0), reqResults.at(0).at(i), reqResults.at(1).at(i), reqResults.at(2).at(i));

            QSqlQuery queryDeleteDictumUses;
            queryDeleteDictumUses.prepare("DELETE FROM tblDICTUMUSES WHERE dictum_id=:dictum_id");

            queryDeleteDictumUses.bindValue(":dictum_id", dictumData.at(0).toInt());

            if (!queryDeleteDictumUses.exec()) {
                qDebug() << "Error en queryDeleteDictumUses: " + queryDeleteDictumUses.lastError().text();
                return false;
            } else {
                for (int i=0; i < dictumUseData.at(0).size(); i++)
                    insertDictumUses(dictumData.at(0), dictumUseData.at(0).at(i), dictumUseData.at(1).at(i));
            }

            QSqlQuery queryDeleteDictumProcs;
            queryDeleteDictumProcs.prepare("DELETE FROM tblDICTUMPROCS WHERE dictum_id=:dictum_id");

            queryDeleteDictumProcs.bindValue(":dictum_id", dictumData.at(0).toInt());

            if (!queryDeleteDictumProcs.exec()) {
                qDebug() << "Error en queryDeleteDictumProcs: " + queryDeleteDictumProcs.lastError().text();
                return false;
            } else {
                for (int i=0; i < dictumProcIds.size(); i++)
                    insertDictumProcs(dictumData.at(0), dictumProcIds.at(i));
            }
            return true;
        }
    }
    return false;

}

// NOTE: Actualizar subdictamen
bool DbHandler::updateSubDictum(QStringList subDictumData, QList<QStringList> reqResults)
{
    QSqlQuery queryUpdateSubDictum;
    queryUpdateSubDictum.prepare("UPDATE tblSUBDICTUMS SET subdictum_date=:subdictum_date, subdictum_state=:subdictum_state, "
                                 "subdictum_tech_state=:subdictum_tech_state, subdictum_scope=:subdictum_scope, subdictum_observ=:subdictum_observ, "
                                 "subdictum_type=:subdictum_type, subdictum_identifier=:subdictum_identifier, subdictum_location=:subdictum_location, "
                                 "subdictum_inst_rate=:subdictum_inst_rate, subdictum_inst_voltage=:subdictum_inst_voltage, subdictum_inst_res=:subdictum_inst_res "
                                 "WHERE subdictum_id=:subdictum_id");

    queryUpdateSubDictum.bindValue(":subdictum_id", subDictumData.at(0).toInt());
    queryUpdateSubDictum.bindValue(":subdictum_date", subDictumData.at(1));
    queryUpdateSubDictum.bindValue(":subdictum_state", subDictumData.at(2));
    queryUpdateSubDictum.bindValue(":subdictum_tech_state", subDictumData.at(3));
    queryUpdateSubDictum.bindValue(":subdictum_scope", subDictumData.at(4));
    queryUpdateSubDictum.bindValue(":subdictum_observ", subDictumData.at(5));
    queryUpdateSubDictum.bindValue(":subdictum_type", subDictumData.at(6));
    queryUpdateSubDictum.bindValue(":subdictum_identifier", subDictumData.at(7));
    queryUpdateSubDictum.bindValue(":subdictum_location", subDictumData.at(8));
    queryUpdateSubDictum.bindValue(":subdictum_inst_rate", subDictumData.at(9));
    queryUpdateSubDictum.bindValue(":subdictum_inst_voltage", subDictumData.at(10));
    queryUpdateSubDictum.bindValue(":subdictum_inst_res", subDictumData.at(11));

    if (!queryUpdateSubDictum.exec()) {
        qDebug()<< "Error en queryUpdateSubDictum: " + queryUpdateSubDictum.lastError().text();
        return false;
    } else {
        QSqlQuery queryDeleteSubDictumReqs;
        queryDeleteSubDictumReqs.prepare("DELETE FROM tblSUBDICTUMREQS WHERE subdictum_id=:subdictum_id");

        queryDeleteSubDictumReqs.bindValue(":subdictum_id", subDictumData.at(0).toInt());

        if (!queryDeleteSubDictumReqs.exec()) {
            qDebug() << "Error en queryDeleteSubDictumReqs: " + queryDeleteSubDictumReqs.lastError().text();
            return false;
        } else {

            for (int i=0; i < reqResults.at(0).size(); i++)
                insertSubDictumReqs(subDictumData.at(0), reqResults.at(0).at(i), reqResults.at(1).at(i), reqResults.at(2).at(i));
            return true;
        }
    }
    return false;
}

// NOTE: Actualizar Usuario
bool DbHandler::updateUser(QStringList userData)
{
    QSqlQuery queryUpdateUser;
    queryUpdateUser.prepare("UPDATE tblUSERS SET user_name=:user_name, user_passwd=:user_passwd, user_lname=:user_lname, "
                            "user_charge=:user_charge, user_level=:user_level, user_address=:user_address, user_mail=:user_mail, "
                            "user_cel=:user_cel, user_tel=:user_tel, user_available=:user_available, user_percentage=:user_percentage, "
                            "user_nit=:user_nit "
                            "WHERE user_id=:user_id");

    queryUpdateUser.bindValue(":user_id", userData.at(0).toInt());
    queryUpdateUser.bindValue(":user_name", userData.at(1));
    queryUpdateUser.bindValue(":user_passwd", userData.at(2));
    queryUpdateUser.bindValue(":user_lname", userData.at(3));
    queryUpdateUser.bindValue(":user_charge", userData.at(4));
    queryUpdateUser.bindValue(":user_level", userData.at(5).toInt());
    queryUpdateUser.bindValue(":user_address", userData.at(6));
    queryUpdateUser.bindValue(":user_mail", userData.at(7));
    queryUpdateUser.bindValue(":user_cel", userData.at(8));
    queryUpdateUser.bindValue(":user_tel", userData.at(9));
    queryUpdateUser.bindValue(":user_available", userData.at(10));
    queryUpdateUser.bindValue(":user_percentage", userData.at(11).toDouble());
    queryUpdateUser.bindValue(":user_nit", userData.at(12));

    if (!queryUpdateUser.exec()) {
        qDebug() << "Error en queryUpdateUser: " + queryUpdateUser.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

// NOTE: Actualizar Usuario
bool DbHandler::updateInspector(QStringList inspectorData, QStringList inspDetailData)
{
    QSqlQuery queryUpdateInspector;
    queryUpdateInspector.prepare("UPDATE tblINSPECTORS SET inspector_name=:inspector_name, inspector_mp=:inspector_mp,  "
                            "inspector_address=:inspector_address, inspector_mail=:inspector_mail, inspector_cel=:inspector_cel, "
                            "inspector_tel=:inspector_tel, inspector_available=:inspector_available, inspector_percentage=:inspector_percentage, "
                            "inspector_nit=:inspector_nit "
                            "WHERE inspector_id=:inspector_id");

    queryUpdateInspector.bindValue(":inspector_id", inspectorData.at(0).toInt());
    queryUpdateInspector.bindValue(":inspector_name", inspectorData.at(1));
    queryUpdateInspector.bindValue(":inspector_mp", inspectorData.at(2));
    queryUpdateInspector.bindValue(":inspector_address", inspectorData.at(3));
    queryUpdateInspector.bindValue(":inspector_mail", inspectorData.at(4));
    queryUpdateInspector.bindValue(":inspector_cel", inspectorData.at(5));
    queryUpdateInspector.bindValue(":inspector_tel", inspectorData.at(6));
    queryUpdateInspector.bindValue(":inspector_available", inspectorData.at(7));
    queryUpdateInspector.bindValue(":inspector_percentage", inspectorData.at(8).toDouble());
    queryUpdateInspector.bindValue(":inspector_nit", inspectorData.at(9));

    if (!queryUpdateInspector.exec()) {
        qDebug() << "Error en queryUpdateInspector: " + queryUpdateInspector.lastError().text();
        return false;
    } else {
        insertInspDetail(inspDetailData);
        return true;
    }
    return false;
}

// NOTE: Actualizar Disenador
bool DbHandler::updateDesigner(QStringList designerData)
{
    QSqlQuery queryUpdateDesigner;
    queryUpdateDesigner.prepare("UPDATE tblDESIGNERS SET designer_name=:designer_name, designer_mp=:designer_mp, "
                                "designer_mail=:designer_mail, designer_cel=:designer_cel, designer_nit=:designer_nit "
                                "WHERE designer_id=:designer_id");

    queryUpdateDesigner.bindValue(":designer_id", designerData.at(0).toInt());
    queryUpdateDesigner.bindValue(":designer_name", designerData.at(1));
    queryUpdateDesigner.bindValue(":designer_mp", designerData.at(2));
    queryUpdateDesigner.bindValue(":designer_mail", designerData.at(3));
    queryUpdateDesigner.bindValue(":designer_cel", designerData.at(4));
    queryUpdateDesigner.bindValue(":designer_nit", designerData.at(5));

    if (!queryUpdateDesigner.exec()) {
        qDebug() << "Error en queryUpdateDesigner: " + queryUpdateDesigner.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

// NOTE: Actualizar Constructor
bool DbHandler::updateConstructor(QStringList constructorData)
{
    QSqlQuery queryUpdateConstructor;
    queryUpdateConstructor.prepare("UPDATE tblCONSTRUCTORS SET constructor_name=:constructor_name, constructor_mp=:constructor_mp, "
                                "constructor_mail=:constructor_mail, constructor_cel=:constructor_cel, constructor_nit=:constructor_nit "
                                "WHERE constructor_id=:constructor_id");

    queryUpdateConstructor.bindValue(":constructor_id", constructorData.at(0).toInt());
    queryUpdateConstructor.bindValue(":constructor_name", constructorData.at(1));
    queryUpdateConstructor.bindValue(":constructor_mp", constructorData.at(2));
    queryUpdateConstructor.bindValue(":constructor_mail", constructorData.at(3));
    queryUpdateConstructor.bindValue(":constructor_cel", constructorData.at(4));
    queryUpdateConstructor.bindValue(":constructor_nit", constructorData.at(5));

    if (!queryUpdateConstructor.exec()) {
        qDebug() << "Error en queryUpdateConstructor: " + queryUpdateConstructor.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

// NOTE: Actualizar Auditor
bool DbHandler::updateAuditor(QStringList auditorData)
{
    QSqlQuery queryUpdateAuditor;
    queryUpdateAuditor.prepare("UPDATE tblAUDITORS SET auditor_name=:auditor_name, auditor_mp=:auditor_mp, "
                                "auditor_mail=:auditor_mail, auditor_cel=:auditor_cel, auditor_nit=:auditor_nit "
                                "WHERE auditor_id=:auditor_id");

    queryUpdateAuditor.bindValue(":auditor_id", auditorData.at(0).toInt());
    queryUpdateAuditor.bindValue(":auditor_name", auditorData.at(1));
    queryUpdateAuditor.bindValue(":auditor_mp", auditorData.at(2));
    queryUpdateAuditor.bindValue(":auditor_mail", auditorData.at(3));
    queryUpdateAuditor.bindValue(":auditor_cel", auditorData.at(4));
    queryUpdateAuditor.bindValue(":auditor_nit", auditorData.at(5));

    if (!queryUpdateAuditor.exec()) {
        qDebug() << "Error en queryUpdateAuditor: " + queryUpdateAuditor.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

/*

BORRADOS
----------------------------------------------------------------------------------------------------------

*/

// NOTE: Eliminado de cotizacion
// TODO: leer el error de integridad referencial y mostrarlo al usuario
bool DbHandler::deleteQuotation(const QString quotId, bool &isFkViolation)
{
    QSqlQuery queryDeleteQuotation;
    queryDeleteQuotation.prepare("DELETE FROM tblQUOTATIONS WHERE quot_id=:quot_id");

    queryDeleteQuotation.bindValue(":quot_id", quotId.toInt());

    if (!queryDeleteQuotation.exec()) {
        qDebug() << "Error en queryDeleteQuotation: " + queryDeleteQuotation.lastError().text();
        isFkViolation=queryDeleteQuotation.lastError().text().contains("referida desde la tabla", Qt::CaseInsensitive);
        return false;
    } else
        return true;

}

// NOTE: Eliminado de propuesta
// TODO: leer el error de integridad referencial y mostrarlo al usuario
bool DbHandler::deleteProposal(const QString propId, bool &isFkViolation)
{
    QSqlQuery queryDeleteProposal;
    queryDeleteProposal.prepare("DELETE FROM tblPROPOSALS WHERE prop_id=:prop_id");

    queryDeleteProposal.bindValue(":prop_id", propId.toInt());

    if (!queryDeleteProposal.exec()) {
        qDebug() << "Error en queryDeleteProposal: " + queryDeleteProposal.lastError().text();
        isFkViolation=queryDeleteProposal.lastError().text().contains("referida desde la tabla", Qt::CaseInsensitive);
        return false;
    } else
        return true;
}

// NOTE: Eliminado de orden de servicio
// TODO: leer el error de integridad referencial y mostrarlo al usuario
bool DbHandler::deleteServiceOrder(const QString soId, bool &isFkViolation)
{
    QSqlQuery queryDeleteServiceOrder;
    queryDeleteServiceOrder.prepare("DELETE FROM tblSERVICEORDERS WHERE so_id=:so_id");

    queryDeleteServiceOrder.bindValue(":so_id", soId.toInt());

    if (!queryDeleteServiceOrder.exec()) {
        qDebug() << "Error en queryDeleteServiceOrder: " + queryDeleteServiceOrder.lastError().text();
        isFkViolation=queryDeleteServiceOrder.lastError().text().contains("referida desde la tabla", Qt::CaseInsensitive);
        return false;
    } else
        return true;

}

// NOTE: Borrado de Usuario
bool DbHandler::deleteUser(const QString userId, bool &isFkViolation)
{
    QSqlQuery queryDeleteUser;
    queryDeleteUser.prepare("DELETE FROM tblUSERS WHERE user_id=:user_id");

    queryDeleteUser.bindValue(":user_id", userId.toInt());

    if (!queryDeleteUser.exec()) {
        qDebug() << "Error en queryDeleteUser: " + queryDeleteUser.lastError().text();
        isFkViolation=queryDeleteUser.lastError().text().contains("referida desde la tabla", Qt::CaseInsensitive);
        if (isFkViolation)
            return true;
        return false;
    } else
        return true;
}

// NOTE: Borrado de Inspector
bool DbHandler::deleteInspector(const QString inspectorId, bool &isFkViolation)
{
    QSqlQuery queryDeleteInspector;
    queryDeleteInspector.prepare("DELETE FROM tblINSPECTORS WHERE inspector_id=:inspector_id");

    queryDeleteInspector.bindValue(":inspector_id", inspectorId.toInt());

    if (!queryDeleteInspector.exec()) {
        qDebug() << "Error en queryDeleteInspector: " + queryDeleteInspector.lastError().text();
        isFkViolation=queryDeleteInspector.lastError().text().contains("referida desde la tabla", Qt::CaseInsensitive);
        if (isFkViolation)
            return true;
        return false;
    } else
        return true;
}

// NOTE: Borrado de Disenador
bool DbHandler::deleteDesigner(const QString designerId, bool &isFkViolation)
{
    QSqlQuery queryDeleteDesigner;
    queryDeleteDesigner.prepare("DELETE FROM tblDESIGNERS WHERE designer_id=:designer_id");

    queryDeleteDesigner.bindValue(":designer_id", designerId.toInt());

    if (!queryDeleteDesigner.exec()) {
        qDebug() << "Error en queryDeleteDesigner: " + queryDeleteDesigner.lastError().text();
        isFkViolation=queryDeleteDesigner.lastError().text().contains("referida desde la tabla", Qt::CaseInsensitive);
        if (isFkViolation)
            return true;
        return false;
    } else
        return true;
}

// NOTE: Borrado de Constructor
bool DbHandler::deleteConstructor(const QString constructorId, bool &isFkViolation)
{
    QSqlQuery queryDeleteConstructor;
    queryDeleteConstructor.prepare("DELETE FROM tblCONSTRUCTORS WHERE constructor_id=:constructor_id");

    queryDeleteConstructor.bindValue(":constructor_id", constructorId.toInt());

    if (!queryDeleteConstructor.exec()) {
        qDebug() << "Error en queryDeleteConstructor: " + queryDeleteConstructor.lastError().text();
        isFkViolation=queryDeleteConstructor.lastError().text().contains("referida desde la tabla", Qt::CaseInsensitive);
        if (isFkViolation)
            return true;
        return false;
    } else
        return true;

}

// NOTE: Borrado de Auditor
bool DbHandler::deleteAuditor(const QString auditorId, bool &isFkViolation)
{
    QSqlQuery queryDeleteAuditor;
    queryDeleteAuditor.prepare("DELETE FROM tblAUDITORS WHERE auditor_id=:auditor_id");

    queryDeleteAuditor.bindValue(":auditor_id", auditorId.toInt());

    if (!queryDeleteAuditor.exec()) {
        qDebug() << "Error en queryDeleteAuditor: " + queryDeleteAuditor.lastError().text();
        isFkViolation=queryDeleteAuditor.lastError().text().contains("referida desde la tabla", Qt::CaseInsensitive);
        if (isFkViolation)
            return true;
        return false;
    } else
        return true;

}

/*

OBTENCIÓN DE DATOS
----------------------------------------------------------------------------------------------------------
*/

// NOTE: Obtiene un cliente especifico
bool DbHandler::getThirdPartie(QString findString, QStringList &thrdData, QString searchOption)
{

    thrdData.clear();
    QSqlQuery queryGetThirdPartie;
    queryGetThirdPartie.prepare(QString("SELECT thrd_id, thrd_nit, thrd_name, thrd_representative, thrd_address, thrd_mail, thrd_cel, thrd_tel, "
                                "tblSTATES.state_name, tblCITIES.city_name "
                                "FROM tblTHIRDPARTIES, tblCITIES, tblSTATES "
                                "WHERE tblCITIES.city_id = tblTHIRDPARTIES.city_id "
                                "AND tblSTATES.state_id = tblCITIES.state_id "
                                "AND %1 = :find_string").arg(searchOption));
    if (searchOption == "thrd_nit")
        queryGetThirdPartie.bindValue(":find_string", findString);
    else
        queryGetThirdPartie.bindValue(":find_string", findString.toInt());

    if(!queryGetThirdPartie.exec()) {
        qDebug() << "Error en queryGetThirdPartie: " + queryGetThirdPartie.lastError().text();
        return false;
    } else {
        while(queryGetThirdPartie.next()) {
            thrdData.append(queryGetThirdPartie.value(Thrds::Id).toString());
            thrdData.append(queryGetThirdPartie.value(Thrds::Nit).toString());
            thrdData.append(queryGetThirdPartie.value(Thrds::Name).toString());
            thrdData.append(queryGetThirdPartie.value(Thrds::LRep).toString());
            thrdData.append(queryGetThirdPartie.value(Thrds::Addrs).toString());
            thrdData.append(queryGetThirdPartie.value(Thrds::Mail).toString());
            thrdData.append(queryGetThirdPartie.value(Thrds::Cel).toString());
            thrdData.append(queryGetThirdPartie.value(Thrds::Tel).toString());
            thrdData.append(queryGetThirdPartie.value(Thrds::City).toString());
            thrdData.append(queryGetThirdPartie.value(Thrds::State).toString());
        }
        if (thrdData.size()==0) {// Si el StringList es cero no se encontro cliente
            thrdData.append("0");
            qDebug()<< "No se encontraron datos para queryGetThirdPartie";
            return false;
        } else
            return true;
    }
}

// NOTE: Obtiene listado de clientes
bool DbHandler::getThirdParties(QList<QStringList> &thirdsData)
{
    thirdsData.clear();
    QStringList thrdData;
    QSqlQuery queryGetThirdParties;
    queryGetThirdParties.prepare("SELECT thrd_id, thrd_nit, thrd_name, thrd_representative, thrd_address, thrd_mail, thrd_cel, thrd_tel, "
                                "tblCITIES.city_name, tblSTATES.state_name "
                                "FROM (tblTHIRDPARTIES INNER JOIN tblCITIES ON tblCITIES.city_id=tblTHIRDPARTIES.city_id) "
                                "INNER JOIN tblSTATES ON tblSTATES.state_id=tblCITIES.state_id");
    if(!queryGetThirdParties.exec()) {
        qDebug() << "Error en queryGetThirdParties: \n" + queryGetThirdParties.lastError().text();
        return false;
    } else {
        while (queryGetThirdParties.next()) {
            thrdData.append(queryGetThirdParties.value(Thrds::Id).toString());
            thrdData.append(queryGetThirdParties.value(Thrds::Nit).toString());
            thrdData.append(queryGetThirdParties.value(Thrds::Name).toString());
            thrdData.append(queryGetThirdParties.value(Thrds::LRep).toString());
            thrdData.append(queryGetThirdParties.value(Thrds::Addrs).toString());
            thrdData.append(queryGetThirdParties.value(Thrds::Mail).toString());
            thrdData.append(queryGetThirdParties.value(Thrds::Cel).toString());
            thrdData.append(queryGetThirdParties.value(Thrds::Tel).toString());
            thrdData.append(queryGetThirdParties.value(Thrds::City).toString());
            thrdData.append(queryGetThirdParties.value(Thrds::State).toString());

            thirdsData.append(thrdData);//Agrego el cliente a la lista de clientes
            thrdData.clear(); //Limpio el stringList de cliente para volverlo a usar
        }
        if (thrdData.at(0).size()==0) {
            qDebug()<< "No se encontraron datos para queryGetThirdParties";
            return false;
        } else
            return true;
    }
    return false;
 }

// NOTE: Obtener Cotizaciones de un cliente
bool DbHandler::getQuotations(QString findString, QList<QStringList> &quotsData, QString searchOption)
{
    quotsData.clear();
    // Strings correspondientes a cada campo.
    QStringList ids, dates, names, addresses, states, cities, contacts, cels, mails, inspecTypes, useNames, voltageLevels;
    QStringList capacities, phases, projecAreas, areaTypes, networkTypes, networkLongs, boxes, scopes, thrdIds;

    QSqlQuery queryGetQuotations;
    queryGetQuotations.prepare(QString("SELECT quot_id, quot_date, quot_name, quot_address, tblSTATES.state_name, tblCITIES.city_name, quot_contact, "
                                   "quot_cel, quot_mail, quot_inspect_type, tblUSES.use_name, quot_voltage_level, quot_capacity, quot_phases, "
                                   "quot_project_area, quot_area_type, quot_network_type, quot_network_long, quot_boxes, quot_scope, thrd_id "
                                   "FROM tblQUOTATIONS, tblSTATES, tblCITIES, tblUSES "
                                   "WHERE tblCITIES.city_id=tblQUOTATIONS.city_id "
                                   "AND tblSTATES.state_id=tblCITIES.state_id "
                                   "AND tblUSES.use_id=tblQUOTATIONS.use_id "
                                   "AND tblQUOTATIONS.%1 = :find_string "
                                   "ORDER BY tblQUOTATIONS.quot_id ASC").arg(searchOption));

    queryGetQuotations.bindValue(":find_string", findString.toInt());

    if(!queryGetQuotations.exec()) {
        qDebug() << "Error en queryGetQuotations, buscando por " << searchOption << "ocurrio: " << queryGetQuotations.lastError().text();
        qDebug() << "La consulta fue: " << queryGetQuotations.lastQuery().toUtf8();
        return false;
    } else {
        while (queryGetQuotations.next()) {
            ids.append(queryGetQuotations.value(Quots::Id).toString());
            dates.append(queryGetQuotations.value(Quots::Date).toString());
            names.append(queryGetQuotations.value(Quots::Name).toString());
            addresses.append(queryGetQuotations.value(Quots::Addrs).toString());
            states.append(queryGetQuotations.value(Quots::State).toString());
            cities.append(queryGetQuotations.value(Quots::City).toString());
            contacts.append(queryGetQuotations.value(Quots::Ctact).toString());
            cels.append(queryGetQuotations.value(Quots::Cel).toString());
            mails.append(queryGetQuotations.value(Quots::Mail).toString());
            inspecTypes.append(queryGetQuotations.value(Quots::InspTyp).toString());
            useNames.append(queryGetQuotations.value(Quots::Use).toString());
            voltageLevels.append(queryGetQuotations.value(Quots::VLev).toString());
            capacities.append(queryGetQuotations.value(Quots::Capac).toString());
            phases.append(queryGetQuotations.value(Quots::Phase).toString());
            projecAreas.append(queryGetQuotations.value(Quots::PrjArea).toString());
            areaTypes.append(queryGetQuotations.value(Quots::AreaTyp).toString());
            networkTypes.append(queryGetQuotations.value(Quots::NetTyp).toString());
            networkLongs.append(queryGetQuotations.value(Quots::NetTyp).toString());
            boxes.append(queryGetQuotations.value(Quots::Boxes).toString());
            scopes.append(queryGetQuotations.value(Quots::Scope).toString());
            thrdIds.append(queryGetQuotations.value(Quots::Thrd).toString());
        }
        quotsData.append(ids);          // 0
        quotsData.append(dates);        // 1
        quotsData.append(names);        // 2
        quotsData.append(addresses);    // 3
        quotsData.append(states);       // 4
        quotsData.append(cities);       // 5
        quotsData.append(contacts);     // 6
        quotsData.append(cels);         // 7
        quotsData.append(mails);        // 8
        quotsData.append(inspecTypes);  // 9
        quotsData.append(useNames);     // 10
        quotsData.append(voltageLevels);// 11
        quotsData.append(capacities);   // 12
        quotsData.append(phases);       // 13
        quotsData.append(projecAreas);  // 14
        quotsData.append(areaTypes);    // 15
        quotsData.append(networkTypes); // 16
        quotsData.append(networkLongs); // 17
        quotsData.append(boxes);        // 18
        quotsData.append(scopes);       // 19
        quotsData.append(thrdIds);      // 20

        if (quotsData.at(0).size()==0) { // Si size del primer StringList es cero no se econtraron cotizaciones
            // Se hace para no dejar vacio el QList y evitar desbordamiento
            quotsData.append(QStringList("0"));
            qDebug()<< "No se encontraron datos para queryGetQuotations";
            return false;
        }
        else
            return true;
    }
}

// NOTE: Obtener Propuesta
bool DbHandler::getProposals(QString findString, QList<QStringList> &propsData, QString searchOption)
{
    propsData.clear();
    // Strings correspondientes a cada campo.
    QStringList ids, scopes, dates, values, payWays, usersPerc, lNames;
    QStringList ivas, viaticals, totalValues, propValue, approvals, approvalDetails, observs, quotIds;

    QSqlQuery queryGetProposal;
    queryGetProposal.prepare(QString("SELECT prop_id, prop_date, prop_scope, prop_value::money, prop_iva::money, prop_viatical::money, prop_total_value::money, "
                              "tblUSERS.user_lname, prop_user_perc, prop_payway, prop_approval, prop_approval_detail, prop_observ, quot_id "
                              "FROM tblPROPOSALS, tblUSERS "
                              "WHERE tblUSERS.user_id=tblPROPOSALS.user_id "
                              "AND tblPROPOSALS.%1 = :find_string "
                              "ORDER BY tblPROPOSALS.prop_id ASC").arg(searchOption)); //.arg() cambia el %1 por la opción de búsqueda
    queryGetProposal.bindValue(":find_string", findString.toInt());

    if(!queryGetProposal.exec()) {
        qDebug() << "Error en queryGetProposal, buscando por " << searchOption << "ocurrio: " << queryGetProposal.lastError().text();
        qDebug() << "La consulta fue: " << queryGetProposal.lastQuery().toUtf8();
        return false;
    } else {
        while (queryGetProposal.next()) {
            ids.append(queryGetProposal.value(Props::Id).toString());
            dates.append(queryGetProposal.value(Props::Date).toString());
            scopes.append(queryGetProposal.value(Props::Scope).toString());
            values.append(queryGetProposal.value(Props::Value).toString());
            ivas.append(queryGetProposal.value(Props::Iva).toString());
            viaticals.append(queryGetProposal.value(Props::Viat).toString());
            totalValues.append(queryGetProposal.value(Props::TotVal).toString());
            lNames.append(queryGetProposal.value(Props::LName).toString());
            usersPerc.append(queryGetProposal.value(Props::UsPerc).toString());
            payWays.append(queryGetProposal.value(Props::PayWay).toString());
            approvals.append(queryGetProposal.value(Props::Aprov).toString());
            approvalDetails.append(queryGetProposal.value(Props::AprovD).toString());
            observs.append(queryGetProposal.value(Props::Observ).toString());
            quotIds.append(queryGetProposal.value(Props::QuotId).toString());
        }
        propsData.append(ids);          // 0
        propsData.append(dates);        // 1
        propsData.append(scopes);       // 2
        propsData.append(values);       // 3
        propsData.append(ivas);         // 4
        propsData.append(viaticals);    // 5
        propsData.append(totalValues);  // 6
        propsData.append(lNames);       // 7
        propsData.append(usersPerc);    // 8
        propsData.append(payWays);      // 9
        propsData.append(approvals);    // 10
        propsData.append(approvalDetails); // 11
        propsData.append(observs);      //12
        propsData.append(quotIds);      //13

        if (propsData.at(0).size()==0) {
            qDebug()<< "No se encontraron datos para queryGetProposal";
            return false;
        } else
            return true;
    }
   return false;
}

// NOTE: Obtener Orden de servicio por su Id
bool DbHandler::getServiceOrders(QString findString, QList<QStringList> &sosData, QString searchOption)
{
    sosData.clear();
    // Strings correspondientes a cada campo.
    QStringList ids, dates, scopes, observations, accProcessed, docProcessed, engProcessed, propsIds;
    QStringList engObservations, admObservations, inspectorsNames, inspectorsPercs, assignDates, billNumber;

    QSqlQuery queryGetServiceOrders;
    queryGetServiceOrders.prepare(QString("SELECT so_id, so_date, tblINSPECTORS.inspector_name, so_inspector_perc, so_assign_date, "
                                     "so_scope, so_observations, so_eng_observations, so_adm_observations, so_acc_processed, "
                                     "so_doc_processed, so_eng_processed, so_bill_number, prop_id "
                                     "FROM tblSERVICEORDERS, tblINSPECTORS "
                                     "WHERE tblSERVICEORDERS.inspector_id=tblINSPECTORS.inspector_id "
                                     "AND tblSERVICEORDERS.%1 = :find_string").arg(searchOption));

    if (searchOption == "so_id")
        queryGetServiceOrders.bindValue(":find_string", findString.toInt());
    else
        queryGetServiceOrders.bindValue(":find_string", findString);

    if(!queryGetServiceOrders.exec()) {
        qDebug() << "Error en queryGetServiceOrders: " << queryGetServiceOrders.lastError().text();
        return false;
    } else {
        while (queryGetServiceOrders.next()) {
            ids.append(queryGetServiceOrders.value(Sos::Id).toString());
            dates.append(queryGetServiceOrders.value(Sos::Date).toString());
            inspectorsNames.append(queryGetServiceOrders.value(Sos::InspName).toString());
            inspectorsPercs.append(queryGetServiceOrders.value(Sos::InspPerc).toString());
            assignDates.append(queryGetServiceOrders.value(Sos::AssignD).toString());
            scopes.append(queryGetServiceOrders.value(Sos::Scope).toString());
            observations.append(queryGetServiceOrders.value(Sos::Observ).toString());
            engObservations.append(queryGetServiceOrders.value(Sos::EngObserv).toString());
            admObservations.append(queryGetServiceOrders.value(Sos::AdmObserv).toString());
            accProcessed.append(queryGetServiceOrders.value(Sos::AccProc).toString());
            docProcessed.append(queryGetServiceOrders.value(Sos::DocProc).toString());
            engProcessed.append(queryGetServiceOrders.value(Sos::EngProc).toString());
            billNumber.append(queryGetServiceOrders.value(Sos::BillNumb).toString());
            propsIds.append(queryGetServiceOrders.value(Sos::propId).toString());
        }
        sosData.append(ids);             // 0
        sosData.append(dates);           // 1
        sosData.append(inspectorsNames);    // 2
        sosData.append(inspectorsPercs); // 3
        sosData.append(assignDates);     // 4
        sosData.append(scopes);          // 5
        sosData.append(observations);    // 6
        sosData.append(engObservations); // 7
        sosData.append(admObservations); // 8
        sosData.append(accProcessed);    // 9
        sosData.append(docProcessed);    // 10
        sosData.append(engProcessed);    // 11
        sosData.append(billNumber);      // 12
        sosData.append(propsIds);           // 13

        if (sosData.at(0).size()==0) {
            qDebug()<< "No se encontraron datos para queryGetServiceOrders";
            return false;
        } else
            return true;
    }
   return false;
}

// NOTE: Obtiene los valores a pagar de una OS.
bool DbHandler::getSoValues(QString soId, QStringList &soValues)
{
    QSqlQuery querySoValue;

    querySoValue.prepare("select tblPROPOSALS.prop_user_perc*tblPROPOSALS.prop_value AS userValue, "
                         "tblSERVICEORDERS.so_inspector_perc*(tblPROPOSALS.prop_value+tblPROPOSALS.prop_viatical) AS inspValue "
                         "FROM tblPROPOSALS, tblSERVICEORDERS "
                         "WHERE tblPROPOSALS.prop_id=tblSERVICEORDERS.prop_id "
                         "AND tblSERVICEORDERS.so_id=:so_id");

    querySoValue.bindValue(":so_id", soId.toInt());

    if (!querySoValue.exec()) {
        qDebug () << "Error en querySoValue: " + querySoValue.lastError().text();
        return false;
    } else {
        while(querySoValue.next()) {
            soValues.append(querySoValue.value(0).toString());
            soValues.append(querySoValue.value(1).toString());
        }
        return true;
    }

    return false;
}

bool DbHandler::getSoState(QString searchString, QStringList &soState, QStringList &dictums, QString searchOption)
{
    QSqlQuery queryGetSoState, queryGetDictum;

    queryGetSoState.prepare(QString("SELECT tblPROPOSALS.prop_id, tblPROPOSALS.prop_date, tblSERVICEORDERS.so_id, tblSERVICEORDERS.so_date, "
                            "tblQUOTATIONS.quot_scope, tblPROPOSALS.prop_scope, tblSERVICEORDERS.so_scope, tblINSPECTORS.inspector_name, "
                            "tblSERVICEORDERS.so_assign_date, tblSOTRACKING.trck_receipt_date, tblSERVICEORDERS.so_doc_processed, "
                            "tblSERVICEORDERS.so_acc_processed, tblSERVICEORDERS.so_eng_processed, tblSOTRACKING.trck_shipping_date, "
                            "tblSERVICEORDERS.so_adm_observations, tblSERVICEORDERS.so_eng_observations, tblPROPOSALS.prop_total_value::money "
                            "FROM tblTHIRDPARTIES, tblINSPECTORS, tblQUOTATIONS FULL OUTER JOIN tblPROPOSALS ON "
                            "tblQUOTATIONS.quot_id=tblPROPOSALS.quot_id FULL OUTER JOIN tblSERVICEORDERS ON "
                            "tblPROPOSALS.prop_id=tblSERVICEORDERS.prop_id FULL OUTER JOIN tblSOTRACKING ON "
                            "tblSOTRACKING.so_id=tblSERVICEORDERS.so_id "
                            "WHERE tblINSPECTORS.inspector_id=tblSERVICEORDERS.inspector_id "
                            "AND tblTHIRDPARTIES.thrd_id=tblQUOTATIONS.thrd_id "
                            "AND %1=:searchString "
                            "ORDER BY tblPROPOSALS.prop_id DESC").arg(searchOption));
                            // Se ordena por propuesta ya que si se busca por NIT pueden aparecer varias, se muestra la última.

    queryGetSoState.bindValue(":searchString", searchString.toInt());

    if (!queryGetSoState.exec()) {
        qDebug() << "Error en queryGetSoState: " +  queryGetSoState.lastError().text();
        return false;
    } else {
        while (queryGetSoState.next()) {
            soState.append(queryGetSoState.value(0).toString()); // prop_id
            soState.append(queryGetSoState.value(1).toString()); // prop_date
            soState.append(queryGetSoState.value(2).toString()); // so_id
            soState.append(queryGetSoState.value(3).toString()); // so_date
            soState.append(queryGetSoState.value(4).toString()); // quot_scope
            soState.append(queryGetSoState.value(5).toString()); // prop_scope
            soState.append(queryGetSoState.value(6).toString()); // so_scope
            soState.append(queryGetSoState.value(7).toString()); // inspector_name
            soState.append(queryGetSoState.value(8).toString()); // so_assign_date
            soState.append(queryGetSoState.value(9).toString()); // receipt_date
            soState.append(queryGetSoState.value(10).toString()); // doc_processed
            soState.append(queryGetSoState.value(11).toString()); // acc_processed
            soState.append(queryGetSoState.value(12).toString()); // eng_processed
            soState.append(queryGetSoState.value(13).toString()); // shipping_date
            soState.append(queryGetSoState.value(14).toString()); // adm_observations
            soState.append(queryGetSoState.value(15).toString()); // eng_observations
            soState.append(queryGetSoState.value(16).toString()); // prop_tot_value

        }

        if (soState.size()!=0) {

        queryGetDictum.prepare("SELECT tblDICTUMS.dictum_number "
                               "FROM tblDICTUMS, tblINSPECTIONS "
                               "WHERE tblDICTUMS.inspection_id=tblINSPECTIONS.inspection_id "
                               "AND tblINSPECTIONS.so_id=:so_id");

        queryGetDictum.bindValue(":so_id", soState.at(2).toInt());

        if (!queryGetDictum.exec())
            qDebug () << "Error en queryGetDictum: " + queryGetDictum.lastError().text();
        else
            while (queryGetDictum.next())
                dictums.append(queryGetDictum.value(0).toString());
        }

        return true;
        }
    return false;
}



// NOTE: Obtiene los inspectores
// TODO: Revisar los cargos y nivles
bool DbHandler::getInspectors(QList<QStringList> &inspectorsData, QString listCase)
{
    inspectorsData.clear();
    QString queryString;

    if (listCase == "Disponibles")
        queryString="SELECT * FROM tblINSPECTORS WHERE inspector_id != 1 AND inspector_available='Disponible' ORDER BY inspector_name ASC";
    if (listCase == "Todos")
        queryString="SELECT * FROM tblINSPECTORS WHERE inspector_id != 1 ORDER BY inspector_name ASC";

    QStringList inspectorsIds, inspectorsNames, inspectorsAddress, inspectorsMails;
    QStringList inspectorsCels, inspectorsTels, inspectorsAvailables, inspectorsPercentages, inspectorsNits, inspectorsMps;
    QSqlQuery queryGetInspectors;
    queryGetInspectors.prepare(queryString);

    if (!queryGetInspectors.exec()) {
        qDebug() << "Error en la consulta queryGetInspectors: " << queryGetInspectors.lastError().text();
        return false;
    } else {
        while (queryGetInspectors.next()) {
            inspectorsIds.append(queryGetInspectors.value(0).toString());
            inspectorsNames.append(queryGetInspectors.value(1).toString());
            inspectorsMps.append(queryGetInspectors.value(2).toString());
            inspectorsAddress.append(queryGetInspectors.value(3).toString());
            inspectorsMails.append(queryGetInspectors.value(4).toString());
            inspectorsCels.append(queryGetInspectors.value(5).toString());
            inspectorsTels.append(queryGetInspectors.value(6).toString());
            inspectorsAvailables.append(queryGetInspectors.value(7).toString());
            inspectorsPercentages.append(queryGetInspectors.value(8).toString());
            inspectorsNits.append(queryGetInspectors.value(9).toString());
        }
        inspectorsData.append(inspectorsIds); // 0
        inspectorsData.append(inspectorsNames); // 1
        inspectorsData.append(inspectorsMps); // 2
        inspectorsData.append(inspectorsAddress); // 3
        inspectorsData.append(inspectorsMails); // 4
        inspectorsData.append(inspectorsCels); // 5
        inspectorsData.append(inspectorsTels); // 6
        inspectorsData.append(inspectorsAvailables);  // 7
        inspectorsData.append(inspectorsPercentages); // 8
        inspectorsData.append(inspectorsNits); // 9

        if (inspectorsData.at(0).size()==0) {
            qDebug()<< "No se encontraron datos para queryGetInspectors";
            return false;
        } else
            return true;
    }
    return false;
}
bool DbHandler::getInspector(const QString inspectionId, QStringList &inspectorData)
{
    QSqlQuery queryGetInspector;

    queryGetInspector.prepare("SELECT inspector_name, inspector_mp "
                              "FROM tblINSPECTORS, tblPROPOSALS, tblSERVICEORDERS, tblINSPECTIONS "
                              "WHERE tblINSPECTORS.inspector_id=tblSERVICEORDERS.inspector_id "
                              "AND tblSERVICEORDERS.prop_id=tblPROPOSALS.prop_id "
                              "AND tblINSPECTIONS.so_id=tblSERVICEORDERS.so_id "
                              "AND tblINSPECTIONS.inspection_id=:inspection_id");

    queryGetInspector.bindValue(":inspection_id", inspectionId.toInt());

    if (!queryGetInspector.exec()) {
        qDebug() << "Error en queryGetInspector: " + queryGetInspector.lastError().text();
        return false;
    } else {
        while (queryGetInspector.next()) {
            inspectorData.append(queryGetInspector.value(0).toString());
            inspectorData.append(queryGetInspector.value(1).toString());
        }
        if (inspectorData.size() == 0) {
            qDebug() << "No se obtuvieron datos para queryGetInspector con el id: " + inspectionId;
            return false;
        } else
            return true;
    }
    return false;
}


// NOTE: Obtiene los usuarios
bool DbHandler::getUsers(QList<QStringList> &usersData)
{
    usersData.clear();
    QStringList usersIds, usersNames, usersPasswds, usersLnames, usersCharges, usersLevels, usersAddress, usersMails;
    QStringList usersCels, usersTels, usersAvailables, usersPercentages, usersNits;
    QSqlQuery queryGetUsers;
    queryGetUsers.prepare("SELECT * FROM tblUSERS WHERE user_id != 1 ORDER BY user_lname ASC");

    if (!queryGetUsers.exec()) {
        qDebug() << "Error en la consulta queryGetUsers: " << queryGetUsers.lastError().text();
        return false;
    } else {
        while (queryGetUsers.next()) {
            usersIds.append(queryGetUsers.value(0).toString());
            usersNames.append(queryGetUsers.value(1).toString());
            usersPasswds.append(queryGetUsers.value(2).toString());
            usersLnames.append(queryGetUsers.value(3).toString());
            usersCharges.append(queryGetUsers.value(4).toString());
            usersLevels.append(queryGetUsers.value(5).toString());
            usersAddress.append(queryGetUsers.value(6).toString());
            usersMails.append(queryGetUsers.value(7).toString());
            usersCels.append(queryGetUsers.value(8).toString());
            usersTels.append(queryGetUsers.value(9).toString());
            usersAvailables.append(queryGetUsers.value(10).toString());
            usersPercentages.append(queryGetUsers.value(11).toString());
            usersNits.append(queryGetUsers.value(12).toString());
        }
        usersData.append(usersIds); // 0
        usersData.append(usersNames); // 1
        usersData.append(usersPasswds); // 2
        usersData.append(usersLnames); // 3
        usersData.append(usersCharges); // 4
        usersData.append(usersLevels); // 5
        usersData.append(usersAddress); // 6
        usersData.append(usersMails); // 7
        usersData.append(usersCels); // 8
        usersData.append(usersTels); // 9
        usersData.append(usersAvailables); // 10
        usersData.append(usersPercentages); // 11
        usersData.append(usersNits); //12

        if (usersData.at(0).size()==0) {
            qDebug()<< "No se encontraron datos para queryGetUsers";
            return false;
        } else
            return true;
    }
    return false;
}

// NOTE: Obtiene los disenadores
bool DbHandler::getDesigners(QList<QStringList> &designersData, QString order)
{
    designersData.clear();
    QStringList designerIds, designerNames, designerMps, designerMails, designerCels, designerNits;

    QSqlQuery queryGetDesigners;
    queryGetDesigners.prepare("SELECT * FROM tblDESIGNERS ORDER BY :order ASC");

    queryGetDesigners.bindValue(":order", order);

    if (!queryGetDesigners.exec()) {
        qDebug() << "Error en la consulta queryGetDesigners: " << queryGetDesigners.lastError().text();
        return false;
    } else {
        while (queryGetDesigners.next()) {
            designerIds.append(queryGetDesigners.value(0).toString());
            designerNames.append(queryGetDesigners.value(1).toString());
            designerMps.append(queryGetDesigners.value(2).toString());
            designerMails.append(queryGetDesigners.value(3).toString());
            designerCels.append(queryGetDesigners.value(4).toString());
            designerNits.append(queryGetDesigners.value(5).toString());
        }
        designersData.append(designerIds);
        designersData.append(designerNames);
        designersData.append(designerMps);
        designersData.append(designerMails);
        designersData.append(designerCels);
        designersData.append(designerNits);

        if (designersData.at(0).size()==0) {
            qDebug()<< "No se encontraron datos para queryGetDesigners";
            return false;
        } else
            return true;
    }
    return false;
}

// NOTE: Obtiene los constructores
bool DbHandler::getConstructors(QList<QStringList> &constructorsData, QString order)
{
    constructorsData.clear();
    QStringList constructorIds, constructorNames, constructorMps, constructorMails, constructorCels, constructorNits;

    QSqlQuery queryGetConstructors;
    queryGetConstructors.prepare("SELECT * FROM tblCONSTRUCTORS ORDER BY :order ASC");

    queryGetConstructors.bindValue(":order", order);

    if (!queryGetConstructors.exec()) {
        qDebug() << "Error en la consulta queryGetConstructors: " << queryGetConstructors.lastError().text();
        return false;
    } else {
        while (queryGetConstructors.next()) {
            constructorIds.append(queryGetConstructors.value(0).toString());
            constructorNames.append(queryGetConstructors.value(1).toString());
            constructorMps.append(queryGetConstructors.value(2).toString());
            constructorMails.append(queryGetConstructors.value(3).toString());
            constructorCels.append(queryGetConstructors.value(4).toString());
            constructorNits.append(queryGetConstructors.value(5).toString());
        }
        constructorsData.append(constructorIds);
        constructorsData.append(constructorNames);
        constructorsData.append(constructorMps);
        constructorsData.append(constructorMails);
        constructorsData.append(constructorCels);
        constructorsData.append(constructorNits);

        if (constructorsData.at(0).size()==0) {
            qDebug()<< "No se encontraron datos para queryGetConstructors";
            return false;
        } else
            return true;
    }
    return false;
}

// NOTE: Obtiene los auditores
bool DbHandler::getAuditors(QList<QStringList> &auditorsData, QString order)
{
    auditorsData.clear();
    QStringList auditorIds, auditorNames, auditorMps, auditorMails, auditorCels, auditorNits;

    QSqlQuery queryGetAuditors;
    queryGetAuditors.prepare("SELECT * FROM tblAUDITORS ORDER BY :order ASC");

    queryGetAuditors.bindValue(":order", order);

    if (!queryGetAuditors.exec()) {
        qDebug() << "Error en la consulta queryGetAuditors: " << queryGetAuditors.lastError().text();
        return false;
    } else {
        while (queryGetAuditors.next()) {
            auditorIds.append(queryGetAuditors.value(0).toString());
            auditorNames.append(queryGetAuditors.value(1).toString());
            auditorMps.append(queryGetAuditors.value(2).toString());
            auditorMails.append(queryGetAuditors.value(3).toString());
            auditorCels.append(queryGetAuditors.value(4).toString());
            auditorNits.append(queryGetAuditors.value(5).toString());
        }
        auditorsData.append(auditorIds);
        auditorsData.append(auditorNames);
        auditorsData.append(auditorMps);
        auditorsData.append(auditorMails);
        auditorsData.append(auditorCels);
        auditorsData.append(auditorNits);

        if (auditorsData.at(0).size()==0) {
            qDebug()<< "No se encontraron datos para queryGetAuditors";
            return false;
        } else
            return true;
    }
    return false;
}

// NOTE: Obtiene los departamentos
bool DbHandler::getStates(QList<QStringList> &statesData)
{
    statesData.clear();
    QStringList statesIds, daneCodes, statesNames;
    QSqlQuery queryGetStates;
    queryGetStates.prepare("SELECT state_id, dane_code, state_name FROM tblSTATES");
    if (!queryGetStates.exec()) {
        qDebug() << "Error en la consulta queryGetStates: " << queryGetStates.lastError().text();
        return false;
    } else {
        while (queryGetStates.next()) {
            statesIds.append(queryGetStates.value(0).toString());
            daneCodes.append(queryGetStates.value(1).toString());
            statesNames.append(queryGetStates.value(2).toString());
        }
        statesData.append(statesIds);
        statesData.append(daneCodes);
        statesData.append(statesNames);
        return true;
    }
}

// NOTE: Obtiene las ciudades de un departamento
bool DbHandler::getCities(QString state_id, QList<QStringList> &citiesData)
{
    citiesData.clear();
    QStringList citiesIds, daneCodes, citiesNames;
    QSqlQuery queryGetCities;
    queryGetCities.prepare("SELECT city_id, dane_code, city_name FROM tblCITIES WHERE state_id=:state_id");
    queryGetCities.bindValue(":state_id", state_id.toInt());
    if (!queryGetCities.exec()) {
        qDebug() << "Error en la consulta queryGetCities: " << queryGetCities.lastError().text();
        return false;
    } else {
        while (queryGetCities.next()) {
            citiesIds.append(queryGetCities.value(0).toString());
            daneCodes.append(queryGetCities.value(1).toString());
            citiesNames.append(queryGetCities.value(2).toString());
        }
        citiesData.append(citiesIds);
        citiesData.append(daneCodes);
        citiesData.append(citiesNames);
        return true;
    }

}
// NOTE: Obtiene los usos
bool DbHandler::getUses(QList<QStringList> &usesData)
{
    usesData.clear();
    QStringList usesIds, usesNames;
    QSqlQuery queryGetUses;
    queryGetUses.prepare("SELECT use_id, use_name FROM tblUSES");
    if (!queryGetUses.exec()) {
        qDebug() << "Error en la consulta queryGetUses: " << queryGetUses.lastError().text();
        return false;
    } else {
        while (queryGetUses.next()) {
            usesIds.append(queryGetUses.value(0).toString());
            usesNames.append(queryGetUses.value(1).toString());
        }
        usesData.append(usesIds);
        usesData.append(usesNames);
        return true;
    }
}

// NOTE: Obtiene los procesos
bool DbHandler::getProcesses(QList<QStringList> &processesData) {
    processesData.clear();
    QStringList processesIds, processesNames;
    QSqlQuery queryGetProcesses;
    queryGetProcesses.prepare("SELECT process_id, process_name FROM tblPROCESSES");
    if (!queryGetProcesses.exec()) {
        qDebug() << "Error en la consulta queryGetProcesses: " << queryGetProcesses.lastError().text();
        return false;
    } else {
        while (queryGetProcesses.next()) {
            processesIds.append(queryGetProcesses.value(0).toString());
            processesNames.append(queryGetProcesses.value(1).toString());
        }
        processesData.append(processesIds);
        processesData.append(processesNames);
        return true;
    }
}

// NOTE: Obtiene los procesos de una cotizacion
bool DbHandler::getProcesses(QString quot_id, QStringList &procsIds)
{
    procsIds.clear();
    // Se obtienen los procesos involucrados en la cotizacion
    QSqlQuery queryGetProcesses;
    queryGetProcesses.prepare("SELECT process_id FROM tblQUOTPROCESSES "
                              "WHERE quot_id=:quot_id");
    queryGetProcesses.bindValue(":quot_id", quot_id.toInt());

    if(!queryGetProcesses.exec()) {
        qDebug() << "Error en queryGetProcesses: " << queryGetProcesses.lastError().text();
        return false;
    } else
        while (queryGetProcesses.next())
            procsIds.append(queryGetProcesses.value(0).toString());
    return true;

}

// NOTE: Obtiene todos los documentos
bool DbHandler::getDocuments(QList<QStringList> &documentsData, QString documentType)
{
    documentsData.clear();
    QStringList documentsIds, documentsNames, documentsTypes;
    QSqlQuery queryGetDocuments;
    queryGetDocuments.prepare("SELECT document_id, document_name, document_type FROM tblDOCUMENTS "
                              "WHERE document_type=:document_type");
    queryGetDocuments.bindValue(":document_type", documentType);

    if(!queryGetDocuments.exec()) {
        qDebug() << "Error en queryGetDocuments: " << queryGetDocuments.lastError().text();
        return false;
    } else
        while (queryGetDocuments.next()) {
            documentsIds.append(queryGetDocuments.value(0).toString());
            documentsNames.append(queryGetDocuments.value(1).toString());
            documentsTypes.append(queryGetDocuments.value(2).toString());
        }
    documentsData.append(documentsIds);
    documentsData.append(documentsNames);
    documentsData.append(documentsTypes);
    return true;

}

// NOTE: Obtiene los documentos de una propuesta
bool DbHandler::getPropDocuments(QString prop_id, QStringList &propDocsIds)
{
    propDocsIds.clear();
    // Se obtienen los documentos correspondientes a los procesos involucrados
    QSqlQuery queryGetPropDocuments;
    queryGetPropDocuments.prepare("SELECT document_id FROM tblPROPDOCUMENTS "
                              "WHERE prop_id=:prop_id "
                              "ORDER BY document_id");

    queryGetPropDocuments.bindValue(":prop_id", prop_id.toInt());

    if(!queryGetPropDocuments.exec()) {
        qDebug() << "Error en queryGetPropDocuments: " << queryGetPropDocuments.lastError().text();
        return false;
    } else
        while (queryGetPropDocuments.next())
            propDocsIds.append(queryGetPropDocuments.value(0).toString());
    return true;
}

// NOTE: Obtiene los documentos de una orden de servicio
bool DbHandler::getSoDocuments(QString soId, QStringList &soDocsIds)
{
    soDocsIds.clear();
    // Se obtienen los documentos correspondientes a los procesos involucrados
    QSqlQuery queryGetSoDocuments;
    queryGetSoDocuments.prepare("SELECT document_id FROM tblSODOCUMENTS "
                              "WHERE so_id=:so_id "
                              "ORDER BY document_id");

    queryGetSoDocuments.bindValue(":so_id", soId.toInt());

    if(!queryGetSoDocuments.exec()) {
        qDebug() << "Error en queryGetSoDocuments: " << queryGetSoDocuments.lastError().text();
        return false;
    } else
        while (queryGetSoDocuments.next())
           soDocsIds.append(queryGetSoDocuments.value(0).toString());
    return true;
}

// NOTE: Obtiene el tracking de una orden de servicio
bool DbHandler::getSoTracking(QString soId, QStringList &soTrackingData)
{
    soTrackingData.clear();
    QSqlQuery queryGetSoTracking;
    queryGetSoTracking.prepare("SELECT trck_receipt_date, trck_receiver_name, trck_shipping_date, "
                               "trck_shipper_name, trck_shipping_name, trck_shipping_company, "
                               "trck_guide_number, trck_observations, tblSTATES.state_name, tblCITIES.city_name "
                               "FROM tblSOTRACKING, tblCITIES, tblSTATES "
                               "WHERE tblSOTRACKING.city_id=tblCITIES.city_id "
                               "AND tblSTATES.state_id=tblCITIES.state_id "
                               "AND so_id=:so_id");

    queryGetSoTracking.bindValue(":so_id", soId.toInt());

    if(!queryGetSoTracking.exec()) {
        qDebug() << "Error en queryGetSoTracking: " << queryGetSoTracking.lastError().text();
        return false;
    } else {
        while (queryGetSoTracking.next()) {
            soTrackingData.append(queryGetSoTracking.value(0).toString()); // fecha de recibo
            soTrackingData.append(queryGetSoTracking.value(1).toString()); // quién recibe
            soTrackingData.append(queryGetSoTracking.value(2).toString()); // fecha de envio
            soTrackingData.append(queryGetSoTracking.value(3).toString()); // quién envía
            soTrackingData.append(queryGetSoTracking.value(4).toString()); // a quién se envía o recibe
            soTrackingData.append(queryGetSoTracking.value(5).toString()); // empresa de envíos
            soTrackingData.append(queryGetSoTracking.value(6).toString()); // número de guia
            soTrackingData.append(queryGetSoTracking.value(7).toString()); // observaciones
            soTrackingData.append(queryGetSoTracking.value(8).toString()); // depto de envío
            soTrackingData.append(queryGetSoTracking.value(9).toString()); // ciudad de envío
        }
        if (soTrackingData.size()==0){
            qDebug()<< "No se encontraron datos para queryGetSoTracking";
            return false;
        } else
            return true;
    }
    return false;
}

// NOTE: Obtiene los registros del archivo de la empresa
bool DbHandler::getRecords(QList<QStringList> &recordsData)
{
    recordsData.clear();
    QStringList recordsIds, recordsFoils;

    QSqlQuery queryGetRecords;
    queryGetRecords.prepare("SELECT record_id, record_foil FROM tblRECORDS");

    if (!queryGetRecords.exec()) {
        qDebug() << "Error en queryGetRecords: " + queryGetRecords.lastError().text();
        return false;
    } else {
        while (queryGetRecords.next()) {
            recordsIds.append(queryGetRecords.value(0).toString());
            recordsFoils.append(queryGetRecords.value(1).toString());
        }
        recordsData.append(recordsIds);
        recordsData.append(recordsFoils);
        return true;
    }
}

// NOTE: Obtiene el las az's correspondientes a una OS
bool DbHandler::getSoRecords(QString soId, QStringList &soRecordsIds)
{
    soRecordsIds.clear();
    // Se obtienen los procesos involucrados en la cotizacion
    QSqlQuery queryGetSoRecords;
    queryGetSoRecords.prepare("SELECT record_id FROM tblSORECORDS "
                              "WHERE so_id=:so_id");
    queryGetSoRecords.bindValue(":so_id", soId.toInt());

    if(!queryGetSoRecords.exec()) {
        qDebug() << "Error en queryGetSoRecords: " << queryGetSoRecords.lastError().text();
        return false;
    } else
        while (queryGetSoRecords.next())
            soRecordsIds.append(queryGetSoRecords.value(0).toString());
    return true;

}
// NOTE: Obtiene los procesos de una cotizacion
bool DbHandler::getRecord(QString recordFoil, QString &recordId)
{

    QSqlQuery queryGetRecord;
    queryGetRecord.prepare("SELECT record_id FROM tblRECORDS WHERE record_foil=:record_foil");

    queryGetRecord.bindValue(":record_foil", recordFoil);

    if (!queryGetRecord.exec()) {
        qDebug() << "Error en queryGetRecord: " + queryGetRecord.lastError().text();
        return false;
    } else {
        queryGetRecord.first();
        recordId = (queryGetRecord.value(0).toString());
        }
        return true;
}

// NOTE: Obtiene la inspeccion de una orden de servicio
bool DbHandler::getInspections(const QString soId, QList<QStringList> &inspectionsData)
{
    inspectionsData.clear();
    QStringList inspectionIds, inspectionStates, observs, addresses, propietaries, states, cities, inspectionDates;
    QStringList auditors, auditorsMp, constructors, constructorsMp, inspectionDictums, soIds, soAssignDates;

    QSqlQuery queryGetInspections;

    queryGetInspections.prepare("SELECT inspection_id, inspection_date, inspection_state, inspection_observ, inspection_address, "
                                "inspection_propietary, tblSTATES.state_name, tblCITIES.city_name, tblCONSTRUCTORS.constructor_name, "
                                "tblCONSTRUCTORS.constructor_mp, tblAUDITORS.auditor_name, tblAUDITORS.auditor_mp, inspection_dictums, "
                                "tblINSPECTIONS.so_id, tblSERVICEORDERS.so_assign_date "
                                "FROM tblINSPECTIONS, tblSERVICEORDERS, tblSTATES, tblCITIES, tblCONSTRUCTORS, tblAUDITORS "
                                "WHERE tblINSPECTIONS.so_id=tblSERVICEORDERS.so_id "
                                "AND tblCITIES.city_id=tblINSPECTIONS.city_id "
                                "AND tblSTATES.state_id=tblCITIES.state_id "
                                "AND tblCONSTRUCTORS.constructor_id=tblINSPECTIONS.constructor_id "
                                "AND tblAUDITORS.auditor_id=tblINSPECTIONS.auditor_id "
                                "AND tblINSPECTIONS.so_id=:so_id");

    queryGetInspections.bindValue(":so_id", soId.toInt());

    if(!queryGetInspections.exec()) {
        qDebug() << "Error en queryGetInspections: " << queryGetInspections.lastError().text();
        return false;
    } else {
        while (queryGetInspections.next()) {

            inspectionIds.append(queryGetInspections.value(0).toString());
            inspectionDates.append(queryGetInspections.value(1).toString());
            inspectionStates.append(queryGetInspections.value(2).toString());
            observs.append(queryGetInspections.value(3).toString());
            addresses.append(queryGetInspections.value(4).toString());
            propietaries.append(queryGetInspections.value(5).toString());
            states.append(queryGetInspections.value(6).toString());
            cities.append(queryGetInspections.value(7).toString());
            constructors.append(queryGetInspections.value(8).toString());
            constructorsMp.append(queryGetInspections.value(9).toString());
            auditors.append(queryGetInspections.value(10).toString());
            auditorsMp.append(queryGetInspections.value(11).toString());
            inspectionDictums.append(queryGetInspections.value(12).toString());
            soIds.append(queryGetInspections.value(13).toString());
            soAssignDates.append(queryGetInspections.value(14).toString());


        }
    inspectionsData.append(inspectionIds);    // 0
    inspectionsData.append(inspectionDates);  // 1
    inspectionsData.append(inspectionStates); // 2
    inspectionsData.append(observs);          // 3
    inspectionsData.append(addresses);        // 4
    inspectionsData.append(propietaries);     // 5
    inspectionsData.append(states);           // 6
    inspectionsData.append(cities);           // 7
    inspectionsData.append(constructors);     // 8
    inspectionsData.append(constructorsMp);   // 9
    inspectionsData.append(auditors);         // 10
    inspectionsData.append(auditorsMp);       // 11
    inspectionsData.append(inspectionDictums);// 12
    inspectionsData.append(soIds);            // 13
    inspectionsData.append(soAssignDates);    // 14


    if (inspectionsData.at(0).size()==0) {
        qDebug()<< "No se encontraron datos para queryGetInspections";
        return false;
    } else
        return true;
    }
    return false;
}

// NOTE: Obtiene el los disenadores correspondientes a una inspeccion
bool DbHandler::getInspectionDesigners(QString inspectionId, QStringList &inspectionDesignersIds)
{
    inspectionDesignersIds.clear();
    // Se obtienen los procesos involucrados en la cotizacion
    QSqlQuery queryGetInspectionDesigners;
    queryGetInspectionDesigners.prepare("SELECT designer_id FROM tblINSPECTIONDESIGNERS "
                              "WHERE inspection_id=:inspection_id");
    queryGetInspectionDesigners.bindValue(":inspection_id", inspectionId.toInt());

    if(!queryGetInspectionDesigners.exec()) {
        qDebug() << "Error en queryGetInspectionDesigners: " << queryGetInspectionDesigners.lastError().text();
        return false;
    } else
        while (queryGetInspectionDesigners.next())
            inspectionDesignersIds.append(queryGetInspectionDesigners.value(0).toString());
    return true;
}

// NOTE: Obtiene el dictamen general de una inspeccion
bool DbHandler::getDictums(const QString inspectionId, QList<QStringList> &dictumsData, QString processId)
{
    dictumsData.clear();
    QStringList dictumIds, dictumNumbers, dictumDates, dictumStates, dictumTechStates, dictumScopes, dictumObservs;
    QStringList dictumInstRates, dictumInstVoltages, dictumInstResists, dictumInstDates, dictumInstTypes, dictumUrls, processIds, dictumCodes;

    QSqlQuery queryGetDictums;

    queryGetDictums.prepare("SELECT dictum_id, dictum_number, dictum_code, dictum_date, dictum_state, dictum_tech_state, dictum_scope, "
                                 "dictum_observ, dictum_inst_rate, dictum_inst_voltage, dictum_inst_resist, dictum_inst_date, "
                                 "dictum_url, process_id "
                                 "FROM tblDICTUMS "
                                 "WHERE tblDICTUMS.inspection_id=:inspection_id AND tblDICTUMS.process_id=:process_id "
                                 "ORDER BY dictum_id");

    queryGetDictums.bindValue(":inspection_id", inspectionId.toInt());
    queryGetDictums.bindValue(":process_id", processId.toInt());

    if(!queryGetDictums.exec()) {
        qDebug() << "Error en queryGetDictums: " << queryGetDictums.lastError().text();
        return false;
    } else {
        while (queryGetDictums.next()) {
            dictumIds.append(queryGetDictums.value(0).toString());
            dictumNumbers.append(queryGetDictums.value(1).toString());
            dictumCodes.append(queryGetDictums.value(2).toString());
            dictumDates.append(queryGetDictums.value(3).toString());
            dictumStates.append(queryGetDictums.value(4).toString());
            dictumTechStates.append(queryGetDictums.value(5).toString());
            dictumScopes.append(queryGetDictums.value(6).toString());
            dictumObservs.append(queryGetDictums.value(7).toString());
            dictumInstRates.append(queryGetDictums.value(8).toString());
            dictumInstVoltages.append(queryGetDictums.value(9).toString());
            dictumInstResists.append(queryGetDictums.value(10).toString());
            dictumInstDates.append(queryGetDictums.value(11).toString());
            dictumUrls.append(queryGetDictums.value(12).toString());
            processIds.append(queryGetDictums.value(13).toString());

        }

    dictumsData.append(dictumIds);          // 0
    dictumsData.append(dictumNumbers);      // 1
    dictumsData.append(dictumCodes);        // 2
    dictumsData.append(dictumDates);        // 3
    dictumsData.append(dictumStates);       // 4
    dictumsData.append(dictumTechStates);   // 5
    dictumsData.append(dictumScopes);       // 6
    dictumsData.append(dictumObservs);      // 7
    dictumsData.append(dictumInstRates);    // 8
    dictumsData.append(dictumInstVoltages); // 9
    dictumsData.append(dictumInstResists);  // 10
    dictumsData.append(dictumInstDates);    // 11
    dictumsData.append(dictumUrls);         // 12
    dictumsData.append(processIds);         // 13

    if (dictumsData.at(0).size()==0){
        return false;
        qDebug()<< "No se encontraron datos para queryGetDictums";
    } else
        return true;
    }
    return false;
}

// NOTE: Obtener los datos extras de cada proceso
bool DbHandler::getExtraData(const QString dictumId,const QString processId, QStringList &extraData)
{
    QSqlQuery queryGetExtraData;
    int columns=0;

    switch (processId.toInt()) {
    case BcProcs::Generacion:
        queryGetExtraData.prepare("SELECT gendictum_se_type, gendictum_ses_number FROM tblGENDICTUMS "
                                  "WHERE dictum_id=:dictum_id");
        columns=2;
        break;

    case BcProcs::Transmision:
        queryGetExtraData.prepare("SELECT transmdictum_line_detail, transmdictum_conf, transmdictum_length, transmdictum_wires_type, "
                                  "transmdictum_material, transmdictum_structs_number "
                                  "FROM tblTRANSMDICTUMS "
                                  "WHERE dictum_id=:dictum_id");
        columns=6;
        break;

    case BcProcs::Transformacion:
        queryGetExtraData.prepare("SELECT transfdictum_se_type, transfdictum_rate, transfdictum_transf_number "
                                  "FROM tblTRANSFDICTUMS "
                                  "WHERE dictum_id=:dictum_id");
        columns=3;
        break;

    case BcProcs::Distribucion:
        queryGetExtraData.prepare("SELECT distdictum_conf, distdictum_length, distdictum_wires_type, "
                                  "distdictum_material, distdictum_structs_number "
                                  "FROM tblDISTDICTUMS "
                                  "WHERE dictum_id=:dictum_id");
        columns=5;
        break;

    case BcProcs::AlumbradoExt:
        queryGetExtraData.prepare("SELECT alextdictum_luminaries_number, alextdictum_measure_system, alextdictum_porpuse, "
                                  "alextdictum_length, alextdictum_area "
                                  "FROM tblALEXTDICTUMS "
                                  "WHERE dictum_id=:dictum_id");
        columns=5;
        break;

    case BcProcs::UsoFinal:
        return true; // No se hace nada mas.
        break;

    case BcProcs::AlumbradoInt:
        return true; // No se hace nada mas.
        break;

    default:
        break;
    }

    queryGetExtraData.bindValue(":dictum_id", dictumId.toInt());

    if (!queryGetExtraData.exec()) {
        qDebug() << "Error en queryGetExtraData: " + queryGetExtraData.lastError().text();
        return false;
    } else {
        queryGetExtraData.first();  // Se hace de esta manera porque solo devolverá un registro
        for (int i=0; i<columns ;i++) // al usar el for no es necesario saber a que proceso pertenecía.
            extraData.append(queryGetExtraData.value(i).toString());
        if (extraData.size()==0) {
            qDebug() << "No se encontraron datos para queryGetExtraData con: " + dictumId;
            return false;
        } else
            return true;
    }

    return false;

}

// NOTE: Obtiene el los usos de un dictamen
bool DbHandler::getDictumUses(const QString dictumId, QList<QStringList> &dictumUseData)
{
    QStringList dictumUseIds, dictumUseSpecialNames;

    // Se obtienen los usos involucrados en el dictamen
    QSqlQuery queryGetDictumUses;
    queryGetDictumUses.prepare("SELECT use_id, use_special_name FROM tblDICTUMUSES "
                              "WHERE dictum_id=:dictum_id");
    queryGetDictumUses.bindValue(":dictum_id", dictumId.toInt());

    if(!queryGetDictumUses.exec()) {
        qDebug() << "Error en queryGetDictumUses: " << queryGetDictumUses.lastError().text();
        return false;
    } else
        while (queryGetDictumUses.next()) {
            dictumUseIds.append(queryGetDictumUses.value(0).toString());
            dictumUseSpecialNames.append(queryGetDictumUses.value(1).toString());
        }
    dictumUseData.append(dictumUseIds);
    dictumUseData.append(dictumUseSpecialNames);

    if (dictumUseData.at(0).size()==0) {
        qDebug()<< "No se encontraron datos para queryGetDictumUses";
        return false;
    } else
        return true;

    return false;
}

// NOTE: Obtiene el los procesos de un dictamen
bool DbHandler::getDictumProcs(const QString dictumId, QStringList &dictumProcIds)
{
    // Se obtienen los procesos involucrados en el dictamen
    QSqlQuery queryGetDictumProcs;
    queryGetDictumProcs.prepare("SELECT process_id FROM tblDICTUMPROCS "
                              "WHERE dictum_id=:dictum_id");
    queryGetDictumProcs.bindValue(":dictum_id", dictumId.toInt());

    if(!queryGetDictumProcs.exec()) {
        qDebug() << "Error en queryGetDictumProcs: " << queryGetDictumProcs.lastError().text();
        return false;
    } else
        while (queryGetDictumProcs.next())
            dictumProcIds.append(queryGetDictumProcs.value(0).toString());

    if (dictumProcIds.size()==0) {
        qDebug()<< "No se encontraron datos para queryGetDictumProcs";
        return false;
    } else
        return true;

    return false;
}

// NOTE: Obtiene los subdictamenes o consecutivos de un dictamen
bool DbHandler::getSubDictums(const QString dictumId, QList<QStringList> &subDictumsData)
{
    subDictumsData.clear();
    QStringList subDictumIds, subDictumNumbers, subDictumDates, subDictumStates, subDictumTechStates;
    QStringList subDictumScopes, subDictumObservs, subDictumInstType, subDictumInstIdentifier, subDictumInstLocation;
    QStringList subDictumInstRates, subDictumInstVoltages, subDictumInstRes;

    QSqlQuery queryGetSubDictums;

    queryGetSubDictums.prepare("SELECT subdictum_id, subdictum_number, subdictum_date, subdictum_state, subdictum_tech_state, "
                               "subdictum_scope, subdictum_observ, subdictum_type, subdictum_identifier, subdictum_location, "
                               "subdictum_inst_rate, subdictum_inst_voltage, subdictum_inst_res "
                               "FROM tblSUBDICTUMS "
                               "WHERE tblSUBDICTUMS.dictum_id=:dicum_id "
                               "ORDER BY subdictum_id");

    queryGetSubDictums.bindValue(":dictum_id", dictumId.toInt());

    if(!queryGetSubDictums.exec()) {
        qDebug() << "Error en queryGetSubDictums: " << queryGetSubDictums.lastError().text();
        return false;
    } else {
        while (queryGetSubDictums.next()) {
            subDictumIds.append(queryGetSubDictums.value(0).toString());
            subDictumNumbers.append(queryGetSubDictums.value(1).toString());
            subDictumDates.append(queryGetSubDictums.value(2).toString());
            subDictumStates.append(queryGetSubDictums.value(3).toString());
            subDictumTechStates.append(queryGetSubDictums.value(4).toString());
            subDictumScopes.append(queryGetSubDictums.value(5).toString());
            subDictumObservs.append(queryGetSubDictums.value(6).toString());
            subDictumInstType.append(queryGetSubDictums.value(7).toString());
            subDictumInstIdentifier.append(queryGetSubDictums.value(8).toString()) ;
            subDictumInstLocation.append(queryGetSubDictums.value(9).toString());
            subDictumInstRates.append(queryGetSubDictums.value(10).toString());
            subDictumInstVoltages.append(queryGetSubDictums.value(11).toString());
            subDictumInstRes.append(queryGetSubDictums.value(12).toString());
        }
    subDictumsData.append(subDictumIds);           // 0
    subDictumsData.append(subDictumNumbers);       // 1
    subDictumsData.append(subDictumDates);         // 2
    subDictumsData.append(subDictumStates);        // 3
    subDictumsData.append(subDictumTechStates);    // 4
    subDictumsData.append(subDictumScopes);        // 5
    subDictumsData.append(subDictumObservs);       // 6
    subDictumsData.append(subDictumInstType);      // 7
    subDictumsData.append(subDictumInstIdentifier);// 8
    subDictumsData.append(subDictumInstLocation);  // 9
    subDictumsData.append(subDictumInstRates);     // 10
    subDictumsData.append(subDictumInstVoltages);  // 11
    subDictumsData.append(subDictumInstRes);       // 12

    if (subDictumsData.at(0).size()==0){
        return false;
        qDebug()<< "No se encontraron datos para queryGetSubdictums";
    } else
        return true;
    }
    return false;
}

// NOTE: Obtiene los checks de un dictamen
bool DbHandler::getDictumReqs(QString dictum_id, QList<QStringList> &dictumReqsData)
{
    QStringList reqIds, reqMeets, reqNoMeets;

    // Se obtienen los requerimientos marcados correspondientes al dictamen
    QSqlQuery queryGetDictumReqs;
    queryGetDictumReqs.prepare("SELECT req_id, req_meets, req_no_meets FROM tblDICTUMREQS "
                              "WHERE dictum_id = :dictum_id ORDER BY req_id");

    queryGetDictumReqs.bindValue(":dictum_id", dictum_id.toInt());

    if(!queryGetDictumReqs.exec()) {
        qDebug() << "Error en queryGetDictumReqs: " << queryGetDictumReqs.lastError().text();
        return false;
    } else
        while (queryGetDictumReqs.next()) {
           reqIds.append(queryGetDictumReqs.value(0).toString());
           reqMeets.append(queryGetDictumReqs.value(1).toString());
           reqNoMeets.append(queryGetDictumReqs.value(2).toString());
        }
    dictumReqsData.append(reqIds);
    dictumReqsData.append(reqMeets);
    dictumReqsData.append(reqNoMeets);

    if (dictumReqsData.at(0).size() ==0) {
        return false;
        qDebug() << "No se encontraron datos para queryGetDictumReqs";
    } else
        return true;
    return false;
}

// NOTE: Obtiene los checks de un subdictamen o consecutivo
bool DbHandler::getSubDictumReqs(const QString subdictum_id, QList<QStringList> &subDictumReqsData)
{
    QStringList reqIds, reqMeets, reqNoMeets;

    // Se obtienen los requerimientos marcados correspondientes al subdictamen
    QSqlQuery queryGetSubDictumReqs;
    queryGetSubDictumReqs.prepare("SELECT req_id, req_meets, req_no_meets FROM tblSUBDICTUMREQS "
                              "WHERE subdictum_id = :subdictum_id ORDER BY req_id");

    queryGetSubDictumReqs.bindValue(":subdictum_id", subdictum_id.toInt());

    if(!queryGetSubDictumReqs.exec()) {
        qDebug() << "Error en queryGetSubDictumReqs: " << queryGetSubDictumReqs.lastError().text();
        return false;
    } else
        while (queryGetSubDictumReqs.next()) {
           reqIds.append(queryGetSubDictumReqs.value(0).toString());
           reqMeets.append(queryGetSubDictumReqs.value(1).toString());
           reqNoMeets.append(queryGetSubDictumReqs.value(2).toString());
        }
    subDictumReqsData.append(reqIds);
    subDictumReqsData.append(reqMeets);
    subDictumReqsData.append(reqNoMeets);

    if (subDictumReqsData.at(0).size() ==0) {
        return false;
        qDebug() << "No se encontraron datos para queryGetSubDictumReqs";
    } else
        return true;
    return false;
}

// NOTE: Obtiene los requerimietos de un dictamen o consecutivo(subdictamen)
bool DbHandler::getRequirements(const QString processId, QList<QStringList> &requirementsData) {

    QStringList reqIds, reqDescriptions;

    QSqlQuery queryGetRequirements;
    queryGetRequirements.prepare("SELECT req_id, req_description FROM tblREQUIREMENTS "
                              "WHERE process_id=:process_id ORDER BY req_description ASC");

    queryGetRequirements.bindValue(":process_id", processId.toInt());

    if (!queryGetRequirements.exec()) {
        qDebug() << queryGetRequirements.lastError().text();
        return false;
    } else {
        while(queryGetRequirements.next()) {
            reqIds.append(queryGetRequirements.value(0).toString());
            reqDescriptions.append(queryGetRequirements.value(1).toString());
        }
        requirementsData.append(reqIds);
        requirementsData.append(reqDescriptions);

        if (requirementsData.at(0).size()==0) {
            qDebug()<< "No se encontraron datos para queryGetRequirements";
            return false;
        } else
            return true;
    }
    return false;
}

// NOTE: Obtiene los pagos de un cliente para una orden de servicio
bool DbHandler::getThrdPays(const QString thrdNit, const QString soId, QStringList &thrdPaysData)
{
    thrdPaysData.clear();

    QSqlQuery queryGetThrdPays;
    queryGetThrdPays.prepare("SELECT MAX(mov_date), SUM(mov_value), MAX(mov_documment), MAX(mov_observations) "
                             "FROM tblMOVEMENTS WHERE mov_nit=:thrd_nit AND so_id=:so_id");

    queryGetThrdPays.bindValue(":thrd_nit", thrdNit);
    queryGetThrdPays.bindValue(":so_id", soId);

    if(!queryGetThrdPays.exec()) {
        qDebug() << "Error en queryGetThrdPays: " << queryGetThrdPays.lastError().text();
        return false;
    } else {
        while (queryGetThrdPays.next()) {
            thrdPaysData.append(queryGetThrdPays.value(0).toString());
            thrdPaysData.append(queryGetThrdPays.value(1).toString());
            thrdPaysData.append(queryGetThrdPays.value(2).toString());
            thrdPaysData.append(queryGetThrdPays.value(3).toString());
        }
        return true;
    }
}

// NOTE: Obtiene los pagos de un usuario o vendedor para una orden de servicio
bool DbHandler::getUserPays(const QString userNit, const QString soId, QStringList &userPaysData)
{
    userPaysData.clear();

    QSqlQuery queryGetUserPays; // TODO: cambiar max por funcion para obtener ultimo de la consulta
    queryGetUserPays.prepare("SELECT MAX(mov_date), SUM(mov_value), MAX(mov_documment), MAX(mov_observations) "
                             "FROM tblMOVEMENTS WHERE mov_nit=:user_nit AND so_id=:so_id");

    queryGetUserPays.bindValue(":user_nit", userNit);
    queryGetUserPays.bindValue(":so_id", soId);

    if(!queryGetUserPays.exec()) {
        qDebug() << "Error en queryGetUsersPays: " << queryGetUserPays.lastError().text();
        return false;
    } else {
        while (queryGetUserPays.next()) {
            userPaysData.append(queryGetUserPays.value(0).toString());
            userPaysData.append(queryGetUserPays.value(1).toString());
            userPaysData.append(queryGetUserPays.value(2).toString());
            userPaysData.append(queryGetUserPays.value(3).toString());
        }
        return true;
    }
}

// NOTE: Obtiene los pagos de un inspector para una orden de servicio
bool DbHandler::getInspectorPays(const QString inspectorNit, const QString soId, QStringList &inspectorPaysData)
{
    inspectorPaysData.clear();

    QSqlQuery queryGetInspectorPays;
    queryGetInspectorPays.prepare("SELECT MAX(mov_date), SUM(mov_value), MAX(mov_documment), MAX(mov_observations) "
                             "FROM tblMOVEMENTS WHERE mov_nit=:inspector_nit AND so_id=:so_id");

    queryGetInspectorPays.bindValue(":inspector_nit", inspectorNit);
    queryGetInspectorPays.bindValue(":so_id", soId);

    if(!queryGetInspectorPays.exec()) {
        qDebug() << "Error en queryGetInspectorPays: " << queryGetInspectorPays.lastError().text();
        return false;
    } else {
        while (queryGetInspectorPays.next()) {
            inspectorPaysData.append(queryGetInspectorPays.value(0).toString());
            inspectorPaysData.append(queryGetInspectorPays.value(1).toString());
            inspectorPaysData.append(queryGetInspectorPays.value(2).toString());
            inspectorPaysData.append(queryGetInspectorPays.value(3).toString());
        }
        return true;
    }
}

// NOTE: Obtiene los tipos de evento
bool DbHandler::getEventType(QList<QStringList> &eventTypeData)
{
    QStringList eventTypeIds, eventType;

    QSqlQuery queryGetEventType;
    queryGetEventType.prepare("SELECT event_type_id, event_type FROM tblEVENTTYPE");

    if (!queryGetEventType.exec()) {
        qDebug() << "Error en queryGetEventType: " + queryGetEventType.lastError().text();
        return false;
    } else {
        while (queryGetEventType.next()) {
            eventTypeIds.append(queryGetEventType.value(0).toString());
            eventType.append(queryGetEventType.value(1).toString());
        }
        eventTypeData.append(eventTypeIds);
        eventTypeData.append(eventType);
        return true;
    }
}







