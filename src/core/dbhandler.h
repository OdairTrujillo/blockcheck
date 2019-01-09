#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QtWidgets>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

class DbHandler : public QObject
{

    Q_OBJECT

public:
    DbHandler(void);

    static bool createConnection(void);
    static void closeConnection(void);
    static bool insertLogReg(const QStringList logData);
    static bool insertQuotation(const QStringList thirdData, QStringList &quotData, QStringList processesIds, bool &isUniqueViolation);
    static bool insertQuotation(const QString thrdNit, QStringList &quotData, QStringList processesIds);
    static bool insertProposal(QStringList &propData, QStringList documentsIds, bool &isUniqueViolation);
    static bool insertServiceOrder(QStringList &soData, bool &isUniqueViolation);
    static bool insertQuotProcesses(const QString quotId, const QString processId);
    static bool insertPropDocuments(const QString propId, const QString documentId);
    static bool insertSoDocuments(const QString soId, const QString documentId);
    static bool insertSoRecords(const QString soId, const QString recordsId);
    static bool insertSoTracking(const QStringList soTrackingData);
    static bool insertThrdPay(const QStringList payThrdData);
    static bool insertUserPay(const QStringList payUserData);
    static bool insertInspectorPay(const QStringList payInspectorData);
    static bool insertRecordFoil(QString newRecordFoil);
    static bool insertInspection(const QStringList inspectionData, QString &inspectionId, QStringList inspectionDesignersIds);
    static bool insertInspectionDesigners(const QString inspectionId, const QString designerId);
    static bool insertDictum(QStringList dictumData, QStringList extraData, QList<QStringList> reqResults, QString &dictumId,
                             bool &isPkViolation, QString &dictumCode, QStringList &usedData, QList<QStringList> dictumUseData,
                             QStringList dictumProcIds);
    static bool insertDictumReqs(const QString dictumId, const QString reqId, const QString reqMeets, const QString reqNoMeets);
    static bool insertSubDictum(QStringList subDictumData, QList<QStringList> reqResults, QString indexPos);
    static bool insertSubDictumReqs(const QString subDictumId, const QString reqId, const QString reqMeets, const QString reqNoMeets);
    static bool insertSoEngObservations(const QString soId, QString soEngObserv);
    static bool insertUser(QStringList userData);
    static bool insertInspector(QStringList inspectorData);
    static bool insertInspDetail(QStringList inspDetailData);
    static bool insertDesigner(QStringList designerData);
    static bool insertConstructor(QStringList constructorData);
    static bool insertAuditor(QStringList auditorData);
    static bool insertDictumUses(const QString dictumId, const QString useId, const QString useSname);
    static bool insertDictumProcs(const QString dictumId, const QString processId);

    static bool updateQuotation(const QStringList quotData, QStringList procsIds);
    static bool updateThrdData(const QStringList thrdData);
    static bool updateProposal(const QStringList propData, const QStringList documentsIds);
    static bool updateServiceOrder(const QStringList soData);
    static bool updateQuotProcesses(const QString quotId, const QStringList procsIds);
    static bool updatePropDocuments(const QString propId, const QStringList documentsIds);
    static bool updatePropApproval(const QString propId, const QString propState, const QString approvalDetail);
    static bool updateSoDocuments(const QString soId, const QStringList documentsIds);
    static bool updateSoRecords(const QString soId, const QStringList recordsIds);
    static bool updateSoTracking(const QStringList soTrackingData);
    static bool updateSoAccountingState(const QString soId, const QString state, const QString billNumber);
    static bool updateSoDocState(const QString soId, const QString state);
    static bool updateSoEngState(const QString soId, const QString state);
    static bool updateSoEngObservations(const QString soId, QString soEngObserv);
    static bool updateSoAdmObservations(const QString soId, QString soAdmObserv);
    static bool updateInspection(const QStringList inspectionData, QStringList inspectionDesignersIds);
    static bool updateInspectionDesigners(const QString inspectionId, const QStringList inspectionDesignersId);
    static bool updateInspectionState(QString inspectionId, QString state);
    static bool updateDictum(QStringList dictumData, QStringList extraData, QList<QStringList> reqResults,
                             QList<QStringList> dictumUseData, QStringList dictumProcIds);
    static bool updateSubDictum(QStringList subDictumData, QList<QStringList> reqResults);

    static bool updateUser(QStringList userData);
    static bool updateInspector(QStringList inspectorData, QStringList inspDetailData);

    static bool updateDesigner(QStringList designerData);
    static bool updateConstructor(QStringList constructorData);
    static bool updateAuditor(QStringList auditorData);

    static bool deleteQuotation(const QString quotId, bool &isFkViolation);
    static bool deleteProposal(const QString propId, bool &isFkViolation);
    static bool deleteServiceOrder(const QString soId, bool &isFkViolation);
    static bool deleteUser(const QString userId, bool &isFkViolation);
    static bool deleteInspector(const QString inspectorId, bool &isFkViolation);
    static bool deleteDesigner(const QString designerId, bool &isFkViolation);
    static bool deleteConstructor(const QString constructorId, bool &isFkViolation);
    static bool deleteAuditor(const QString auditorId, bool &isFkViolation);

    // Obtención de datos
    static bool getThirdPartie(QString findString, QStringList &thirdData, QString searchOption);
    static bool getThirdParties(QList<QStringList> &thrdsData);
    static bool getQuotations(QString findString, QStringList &thrdData, QList<QStringList> &quotsData, QString searchOption);
    static bool getServiceOrders(QString findString, QList<QStringList> &sosData, QString searchOption);
    static bool getProposals(QString findString, QList<QStringList> &propsData, QString searchOption);
    static bool getProcesses(QString quot_id, QStringList &procsIds);
    static bool getPropDocuments(QString prop_id, QStringList &propDocsIds);
    static bool getDocuments(QList<QStringList> &documentsData, QString documentType);
    static bool getSoDocuments(QString soId, QStringList &soDocsIds);
    static bool getSoRecords(QString soId, QStringList &soRecordsIds);
    static bool getSoTracking(QString soId, QStringList &soTrackingData);
    static bool getThrdPays(const QString userNit, const QString soId, QStringList &thrdPaysData);
    static bool getUserPays(const QString userNit, const QString soId, QStringList &userPaysData);
    static bool getInspectorPays(const QString inspectorNit, const QString soId, QStringList &inspectorPaysData);
    static bool getInspections(const QString soId, QList<QStringList> &inspectionsData);
    static bool getInspectionDesigners(QString inspectionId, QStringList &inspectionDesignersIds);
    static bool getDictums(const QString inspectionId, QList<QStringList> &dictumsData, QString processId);
    static bool getExtraData(const QString dictumId, const QString processId, QStringList &extraData);
    static bool getSubDictums(const QString dictumId, QList<QStringList> &subDictumsData);
    static bool getRequirements(const QString processId, QList<QStringList> &requierementsData);
    static bool getDictumReqs(const QString dictum_id, QList<QStringList> &dictumReqsData);
    static bool getSubDictumReqs(const QString subdictum_id, QList<QStringList> &subDictumReqsData);
    static bool getDictumUses(const QString dictumId, QList<QStringList> &dictumUseData);
    static bool getDictumProcs(const QString dictumId, QStringList &dictumProcIds);
    static bool getInspector(const QString inspectionId, QStringList &inspectorData);
    static bool getSoValues(QString soId, QStringList &soValues);
    static bool getSoState(QString searchString, QStringList &soState, QStringList &dictums, QString searchOption);

    // Devuelven el id junto con el nombre en un QList
    static bool getInspectors(QList<QStringList> &inspectorsData, QString listCase);
    static bool getUsers(QList<QStringList> &usersData);
    static bool getDesigners(QList<QStringList> &designersData, QString order);
    static bool getConstructors(QList<QStringList> &constructorsData, QString order);
    static bool getAuditors(QList<QStringList> &auditorsData, QString order);
    static bool getStates(QList<QStringList> &statesData);
    static bool getCities(QString city_id, QList<QStringList> &citiesData);
    static bool getUses(QList<QStringList> &usesData);
    static bool getProcesses(QList<QStringList> &processesData);
    static bool getRecords(QList<QStringList> &recordsData);
    static bool getRecord(QString recordFoil, QString &recordId);
    static bool getEventType(QList<QStringList> &eventTypeData);

    // Funciones de sistema como login de usuario y registro de actividades
    static bool getLogin(QString user, QString password, QStringList &userData);

    QString updateTime, webServer;

private:
};


#endif // DBHANDLER_H
