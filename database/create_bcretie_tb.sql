--Script para la creación de tablas de la DB BockCheck RETIE

--Se deben eliminar las tablas existentes

drop table tblCITIES cascade;
drop table tblDOCUMENTS cascade;
drop table tblPROPDOCUMENTS cascade;
drop table tblINSPECTIONS cascade;
drop table tblINSPECTIONDESIGNERS cascade;
drop table tblINSPECTORS cascade;
drop table tblINSPDETAILS cascade;
drop table tblAUDITORS cascade;
drop table tblCONSTRUCTORS cascade;
drop table tblDESIGNERS cascade;
drop table tblPROCESSES cascade;
drop table tblPROPOSALS cascade;
drop table tblQUOTATIONS cascade;
drop table tblRECORDS cascade;
drop table tblSORECORDS cascade;
drop table tblSERVICEORDERS cascade;
drop table tblMOVEMENTS cascade;
drop table tblSODOCUMENTS cascade;
drop table tblSTATES cascade;
drop table tblSUBPROCESSES cascade;
drop table tblTHIRDPARTIES cascade;
drop table tblUSERS cascade;
drop table tblUSES cascade;
drop table tblQUOTPROCESSES cascade;
drop table tblDICTUMS cascade;
drop table tblSUBDICTUMS cascade;
drop table tblSOTRACKING cascade;
drop table tblREQUIREMENTS cascade;
drop table tblDICTUMREQS cascade;
drop table tblDICTUMUSES cascade;
drop table tblDICTUMPROCS cascade;
drop table tblSUBDICTUMREQS cascade;
drop table tblGENDICTUMS cascade;
drop table tblTRANSMDICTUMS cascade;
drop table tblTRANSFDICTUMS cascade;
drop table tblDISTDICTUMS cascade;
drop table tblALINTDICTUMS cascade;
drop table tblALEXTDICTUMS cascade;
drop table tblEVENTTYPE cascade;
drop table tblEVENTS cascade;

--Elimino secuencias
drop sequence seq_city_id cascade;
drop sequence seq_document_id cascade;
drop sequence seq_propdocument_id cascade;
drop sequence seq_inspection_id cascade;
drop sequence seq_inspection_designer_id cascade;
drop sequence seq_inspector_id cascade;
drop sequence seq_insp_detail_id cascade;
drop sequence seq_so_id cascade;
drop sequence seq_mov_id cascade;
drop sequence seq_so_document_id cascade;
drop sequence seq_process_id cascade;
drop sequence seq_prop_id cascade;
drop sequence seq_quot_id cascade;
drop sequence seq_record_id cascade;
drop sequence seq_so_record_id cascade;
drop sequence seq_state_id cascade;
drop sequence seq_subproc_id cascade;
drop sequence seq_thrd_id cascade;
drop sequence seq_user_id cascade;
drop sequence seq_use_id cascade;
drop sequence seq_auditor_id cascade;
drop sequence seq_constructor_id cascade;
drop sequence seq_designer_id cascade;
drop sequence seq_quotproc_id cascade;
drop sequence seq_dictum_id cascade;
drop sequence seq_subdictum_id cascade;
drop sequence seq_trck_id cascade;
drop sequence seq_requirement_id cascade;
drop sequence seq_dictum_req_id cascade;
drop sequence seq_dictum_use_id cascade;
drop sequence seq_dictum_proc_id cascade;
drop sequence seq_subdictum_req_id cascade;
drop sequence seq_gendictum_id cascade;
drop sequence seq_transmdictum_id cascade;
drop sequence seq_transfdictum_id cascade;
drop sequence seq_distdictum_id cascade;
drop sequence seq_alintdictum_id cascade;
drop sequence seq_alextdictum_id cascade;
drop sequence seq_event_type_id cascade;

-- Creación de secuencias que generan los consecutivos
create sequence seq_auditor_id
  start with 1
  increment by 1
  maxvalue 9999
  minvalue 1;

create sequence seq_constructor_id
  start with 1
  increment by 1
  maxvalue 9999
  minvalue 1;

create sequence seq_designer_id
  start with 1
  increment by 1
  maxvalue 9999
  minvalue 1;

create sequence seq_state_id
  start with 1
  increment by 1
  maxvalue 99
  minvalue 1;

create sequence seq_city_id
  start with 1
  increment by 1
  maxvalue 9999
  minvalue 1;

create sequence seq_use_id
  start with 1
  increment by 1
  maxvalue 50
  minvalue 1;

create sequence seq_process_id
  start with 1
  increment by 1
  maxvalue 20
  minvalue 1;

create sequence seq_subproc_id
  start with 1
  increment by 1
  maxvalue 50
  minvalue 1;

create sequence seq_document_id
  start with 1
  increment by 1
  maxvalue 500
  minvalue 1;

create sequence seq_propdocument_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;  
  
create sequence seq_quot_id
  start with 1
  increment by 1
  maxvalue 99999999
  minvalue 1;

create sequence seq_quotproc_id
  start with 1
  increment by 1
  maxvalue 99999999999
  minvalue 1;

create sequence seq_prop_id
  start with 1
  increment by 1
  maxvalue 999999999
  minvalue 1;

create sequence seq_so_id
  start with 1
  increment by 1
  maxvalue 999999999
  minvalue 1;
  
create sequence seq_mov_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_so_document_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;    

create sequence seq_inspector_id
  start with 1
  increment by 1
  maxvalue 300
  minvalue 1;
  
create sequence seq_insp_detail_id
  start with 1
  increment by 1
  maxvalue 99999999
  minvalue 1;
  
create sequence seq_inspection_designer_id
  start with 1
  increment by 1
  maxvalue 999999999
  minvalue 1;    

create sequence seq_user_id
  start with 1
  increment by 1
  maxvalue 200
  minvalue 1;

create sequence seq_thrd_id
  start with 1
  increment by 1
  maxvalue 99999999
  minvalue 1;

create sequence seq_inspection_id
  start with 1
  increment by 1
  maxvalue 99999999
  minvalue 1;

create sequence seq_dictum_id
  start with 1
  increment by 1
  maxvalue 99999999
  minvalue 1;

create sequence seq_subdictum_id
  start with 1
  increment by 1
  maxvalue 999999999
  minvalue 1;  
  
create sequence seq_record_id
  start with 1
  increment by 1
  maxvalue 99999
  minvalue 1;
  
create sequence seq_so_record_id
  start with 1
  increment by 1
  maxvalue 999999999
  minvalue 1;
  
create sequence seq_trck_id
  start with 1
  increment by 1
  maxvalue 999999999
  minvalue 1;
  
create sequence seq_requirement_id
  start with 1
  increment by 1
  maxvalue 999999999
  minvalue 1;
  
create sequence seq_dictum_req_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_dictum_use_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
    
create sequence seq_dictum_proc_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_subdictum_req_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_gendictum_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_transmdictum_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_transfdictum_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_distdictum_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_alintdictum_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_alextdictum_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
create sequence seq_event_type_id
  start with 1
  increment by 1
  maxvalue 9999999999
  minvalue 1;
  
--Tabla para Departamentos
create table tblSTATES (
	state_id int DEFAULT nextval('seq_state_id'),
	dane_code varchar(10) default 'sin codigo',
	state_name varchar(20) not null, --Nombre del departamento
	primary key(state_id)
);

--Tabla para ciudades
create table tblCITIES (
	city_id int DEFAULT nextval('seq_city_id'),
	dane_code varchar(10) default 'sin codigo',
	city_name varchar(50) not null, --Nombre de la ciudad
	state_id int not null, --El id del departamento, toda ciudad depende de un departamento
	primary key(city_id)
);

--Para los distintos usos
create table tblUSES (
	use_id int DEFAULT nextval('seq_use_id'),
	use_name varchar(30) not null, --Usos: comercial, residencial, industrial, etc.
	primary key(use_id)
);

--Para los distintos procesos
create table tblPROCESSES (
	process_id int DEFAULT nextval('seq_process_id'),
	process_name varchar(50) not null, --Distribución, generación, transformación, etc.
	primary key(process_id)
);

--Para los distintos subprocesos que servirán para seleccionar el Checklist
create table tblSUBPROCESSES (
	subproc_id int DEFAULT nextval('seq_subproc_id'),
	subproc_name varchar(200) not null, --Nombre del subproceso o checklist
	subproc_path varchar(80) not null, --Ruta a la lista de chequeo en html
	process_id int not null,
	primary key(subproc_id)
);

-- Tabla para terceros
create table tblTHIRDPARTIES (
	thrd_id int DEFAULT nextval('seq_thrd_id'), --Identificador único del tercero 
	thrd_name varchar(100) not null, --Nombre de la empresa
	thrd_nit varchar(60) not null unique, --NIT de la empresa
	thrd_address varchar(100) not null, --Dirección de la empresa
	city_id int not null, --Ciudad
	thrd_representative varchar(60) not null, --Nombre del representante legal
	thrd_mail varchar(40) DEFAULT 'Sin mail',
	thrd_cel varchar(40) not null, --Número de celular
	thrd_tel varchar(40) DEFAULT 'Sin número', --Número de teléfono
	primary key(thrd_id)
); 

-- Tabla para solicitudes de cotización
create table tblQUOTATIONS (
	quot_id bigint DEFAULT nextval('seq_quot_id'),
    quot_date date not null,
	quot_name varchar(100) not null,
	quot_address varchar(50) not null,
    city_id int not null,
    quot_contact varchar(50) not null,
	quot_cel varchar(40) not null,
	quot_mail varchar(40) DEFAULT 'Sin e-mail',
	quot_inspect_type varchar(40) not null, -- RETIE, RETILAP
	use_id int not null, --El uso determina el precio de oferta
    quot_voltage_level int not null DEFAULT 0,
    quot_capacity float not null default 0.0,
    quot_phases int not null default 3,
    quot_project_area int not null default 0,
    quot_area_type int default 0,
    quot_network_type int default 0,
    quot_network_long int default 0,
    quot_boxes int default 0,
	quot_scope varchar(1600) not null,
	thrd_id int not null, --La cotización depende de un tercero
	primary key (quot_id)
);

-- Tabla para guardar los procesos de cada cotización
create table tblQUOTPROCESSES (
	quotproc_id bigint DEFAULT nextval('seq_quotproc_id'),
	quot_id bigint not null,
	process_id int not null,
	primary key (quotproc_id)
);

-- Tabla para propuestas
create table tblPROPOSALS (
	prop_id bigint DEFAULT nextval('seq_prop_id'),
	prop_date date not null,
	prop_scope varchar(1600) not null, -- Es alcance puede cambiar entre cotizacion y propuesta
--  La propuesta tiene requerimientos que son documentos exigidos, se guardan en tblPROPDOCUMENTS
	prop_value numeric not null, -- Valor de la propuesta
	prop_iva numeric not null, -- Valor del iva
	prop_viatical numeric not null, -- Valor de los viáticos
	prop_total_value numeric not null, -- Valor total
    user_id int not null, -- Quien vende la propuesta
	prop_payway varchar(40) not null,
    prop_state varchar(60) not null, --Por Aprobar, Aprobada, Rechazada - Lo hace gerencia
	prop_state_detail varchar(400) DEFAULT 'Sin Aprobación', -- Detalle de estado de aprobación por gerencia
    prop_user_perc float DEFAULT 0.1, -- Porcentaje para el vendedor
	prop_observ varchar(400) DEFAULT 'Sin Observaciones', -- Obervaciones generales
	quot_id int not null unique, --Proviene de una cotización pero se puede modificar
	primary key(prop_id)
);

--Para los distintos tipos de documentos exigidos
create table tblDOCUMENTS (
	document_id int DEFAULT nextval('seq_document_id'),
	document_name varchar(200) not null, --Distintos documentos disponibles para seleccionar
	document_type varchar(40) not null, --El tipo de documento como los RETIE 8.1, RETILAP, NORMAS VOLUNTARIAS, o los exigidos por el organismo para el expediente
	primary key(document_id)
);

--Para guardar la selección de documentos de propuesta
create table tblPROPDOCUMENTS (
	propdocument_id int DEFAULT nextval('seq_propdocument_id'),
	prop_id int not null, -- A que propuesta pertenece
	document_id int not null, --Distintos documentos obligatorios para determinados procesos
	primary key(propdocument_id)
);

--Para órdenes de servicio
create table tblSERVICEORDERS (
	so_id bigint DEFAULT  nextval('seq_so_id'),
	so_date date not null,
	inspector_id int not null, --Una orden de servicio debe llevar un inspector
	so_inspector_perc float not null DEFAULT 0.1,
	so_assign_date date not null, -- Fecha de asignación de la inspección
	so_scope varchar(1600) not null, -- El alcance puede cambiar entre propuesta y os
	so_observations varchar(200) not null,
    so_eng_observations varchar(200) default '', -- Observaciones de Ingeniería
    so_adm_observations varchar(200) default '', -- Observaciones de Gerencia
	so_acc_processed varchar(20) default 'Sin Procesar', -- Determina si se ha procesaro contablemente la orden de servicio
	so_doc_processed varchar(20) default 'Sin Procesar', -- Determina si se ha procesaro la carpeta de la orden de servicio
	so_eng_processed varchar(20) default 'Sin Procesar', -- Determina si se ha procesaro en ingeniería la orden de servicio
    so_bill_number varchar(100) default 'Sin Factura', -- Número de la factura
	prop_id bigint not null, --La órden de servicio viene de una propuesta
	primary key(so_id)
);

--Para los guardar la selección de documentos de orden de servicio
create table tblSODOCUMENTS (
	so_document_id int DEFAULT nextval('seq_so_document_id'),
	so_id int not null, -- A que orden de servicio pertenece
	document_id int not null, --Distintos documentos obligatorios según la empresa
	primary key(so_document_id)
);

--Para movimientos contables
create table tblMOVEMENTS (
	mov_id bigint DEFAULT nextval('seq_mov_id'),
	mov_type varchar(50) default 'FACTURA', -- tipo de movimiento, si es factura, pago a inspector o a comercial
	mov_date timestamp  not null, -- fecha del movimiento
	so_id bigint not null, -- a que os pertenece 
	mov_documment varchar(50) default 'Sin comprobante', -- el numero de factura o comprobante
	mov_name varchar(200) default 0, -- el nombre del cliente o del inspector o del comercial
	mov_nit varchar(200) default 0, -- nit del tercero, inspector o comercial.
	mov_value numeric default 0, -- el valor del movimiento
	mov_observations varchar(400) default 'Sin observaciones', -- observaciones
	primary key(mov_id)
);

-- Para los usuarios del software y funcionarios de la empresa
create table tblUSERS (
	user_id int DEFAULT nextval('seq_user_id'),
	user_name varchar(60) not null, --Funcionarios que no son inspectores
	user_passwd varchar(40) not null, -- password
	user_lname varchar(200) not null, --Nombre completo
	user_charge varchar(40) not null,
	user_level int not null,
	user_address varchar(100) not null,
	user_mail varchar(40) not null,
	user_cel varchar(20) not null,
	user_tel varchar(20) DEFAULT 'Sin número',
	user_available varchar(50) not null,
	user_percentage float not null,
	user_nit varchar(200) not null unique,
	primary key(user_id)
);

--Para los inspectores
create table tblINSPECTORS (
	inspector_id int DEFAULT nextval('seq_inspector_id'),
	inspector_name varchar(150) not null,
	inspector_mp varchar(100) not null DEFAULT 'XY-000-11111',
	inspector_address varchar(60) not null,
	inspector_mail varchar(60) not null,
	inspector_cel varchar(50) not null,
	inspector_tel varchar(50) DEFAULT 'Sin número',
	inspector_available varchar(50) not null, --
	inspector_percentage float not null, --Porcentaje por defecto
	inspector_nit varchar(200) not null unique,
	primary key(inspector_id)
);

--Detalle de cambios de estado de los inspectores
create table tblINSPDETAILS (
	insp_detail_id int DEFAULT nextval('seq_insp_detail_id'),
	insp_detail_state varchar(50) not null,
	insp_detail_descr varchar(200) not null,
	inspector_id bigint not null,
	primary key(insp_detail_id)
);

--Tabla para diseñadores
create table tblDESIGNERS (
	designer_id int DEFAULT nextval('seq_designer_id'),
	designer_name varchar(100) not null,
	designer_mp varchar(50) not null,
	designer_mail varchar(60) DEFAULT 'Sin e-mail',
	designer_cel varchar(30) DEFAULT 'Sin número',
	designer_nit varchar(60) default 'Sin Nit',
	primary key(designer_id)
);

--Tabla para diseñadores
create table tblCONSTRUCTORS (
	constructor_id int DEFAULT nextval('seq_constructor_id'),
	constructor_name varchar(100) not null,
	constructor_mp varchar(50) not null,
	constructor_mail varchar(60) DEFAULT 'Sin e-mail',
	constructor_cel varchar(30) DEFAULT 'Sin número',
	constructor_nit varchar(60) DEFAULT 'Sin Nit',
	primary key(constructor_id)
);

--Tabla para diseñadores
create table tblAUDITORS (
	auditor_id int DEFAULT nextval('seq_auditor_id'),
	auditor_name varchar(100) not null,
	auditor_mp varchar(50) not null,
	auditor_mail varchar(60) DEFAULT 'Sin mail',
	auditor_cel varchar(30) DEFAULT 'Sin número',
	auditor_nit varchar(60) DEFAULT 'Sin Nit',
	primary key(auditor_id)
);

-- Para las inspecciones como tal, puede que lleven datos modificados entonces se crean los campos necesarios
create table tblINSPECTIONS (
	inspection_id bigint DEFAULT nextval('seq_inspection_id')*10000 + date_part('year', now()),
	inspection_date date not null, -- fecha en que se realizó la inspección
	inspection_state varchar(50), --Se describe en que estado está Finalizada, No Dictaminada
	inspection_observ varchar(200), --Observaciones a los documentos.
	inspection_address varchar(100) DEFAULT 'Sin Dirección',
	inspection_propietary varchar(100) DEFAULT 'Sin Propietario',
	inspection_dictums varchar(20) DEFAULT 'Sin Dictamen', -- Indica si tiene dictamen creado.
	city_id int DEFAULT null,
	so_id bigint not null unique, --Proviene de una órden de servicio
	constructor_id int DEFAULT null, -- El constructor
	auditor_id int DEFAULT null, --El interventor
	primary key(inspection_id)
);

--Para guardar los diseñadores de una inspección
create table tblINSPECTIONDESIGNERS (
	inspection_designer_id int DEFAULT nextval('seq_inspection_designer_id'),
	inspection_id int not null, -- A que inspección pertenece
	designer_id int not null, -- Distintos diseñadores
	primary key(inspection_designer_id)
);

-- ----------------------------
-- Definicion de funcion  "randomuniqueid" - Usada en el identificador único de dictámenes
-- ----------------------------

CREATE OR REPLACE FUNCTION randomUniqueId() RETURNS bigint AS $$
DECLARE
    -- SET THE KEY SIZE (IN CHARACTERS)
    idSize constant  integer := 10;
    sizeMultiplicator constant bigint := 10 ^ idSize;
    loopLimit  bigint := sizeMultiplicator * 4;
    randomNumber bigint;
    canIUseIt boolean := false;
BEGIN
    -- LOOP UNTIL FIND AN UNIQUE RANDOM NUMBER OR FILL THE LOOP LIMIT
    WHILE ( not ( canIUseIt ) and ( loopLimit > 0) ) 
    LOOP
        -- CALCULATE A TEN DIGITS RANDOM NUMBER
        randomNumber := CAST ( ( random() * sizeMultiplicator ) AS bigint );
        -- VALIDATE THAT THE NUMBER WON'T START WITH 0
        IF ( (randomNumber >= sizeMultiplicator / 10 ) and ( randomNumber < sizeMultiplicator ) ) THEN
            -- CHECK THAN RANDOM NUMBER NOT EXISTS ON TABLE
            -- IMPORTANT!!! CHANGE WITH TABLE AND FIELD TO SEARCH FOR A DUPLICATATION
            PERFORM dictum_code FROM tblDICTUMS WHERE dictum_code = randomNumber;
            IF NOT FOUND THEN
                canIUseIt = true;
            END IF;
        END IF;
        loopLimit = loopLimit - 1;
    END LOOP;
    -- IF LOOP ENDS WITH A UNIQUE RANDOM NUMBER RETURNS THE NUMBER CONCATENATED WITH A VERIFICATION NUMBER  ELSE RAISE AN EXCEPTION
    IF ( canIUseIt ) THEN
        RETURN CAST ( ( CAST ( randomNumber AS text ) || CAST (verificationNumber( CAST (randomNumber AS text ) ) AS text  ) ) AS  bigint);
    ELSE
        RAISE EXCEPTION 'No se puede calcular Random Unique ID en la tabla tblDICTUMS';
    END IF;

END;
$$ LANGUAGE plpgsql;

-- ----------------------------
-- Definición de función  "verificationNumber" - sin uso por ahora
-- ----------------------------

CREATE OR REPLACE FUNCTION verificationNumber(id text) RETURNS integer AS $$
DECLARE
    auxValue integer := 0;
    verifyArray constant integer[] :=ARRAY [5,4,3,2,7,6,5,4,3,2,1];
    verificationNumber integer := 0;
BEGIN
    -- ASK FOR ID LENGTH EQUAL TO 10 DIGITS. THE ALGORITHM WORKS ONLY FOR
    IF ( LENGTH( id ) <> 10 ) THEN
        RAISE EXCEPTION 'No se puede calcular el número de Verificación. El ID debe tener 10 dígitos';
    ELSE

        -- LOOP ON THE TEN DIGITS AND MULTIPLY WITH THE SAME POSITION ON virifyArray
        FOR digit IN 1..10 LOOP
            auxValue = auxValue + ( CAST(SUBSTR(id, digit, 1) AS int) * verifyArray[digit] );
        END LOOP;

        -- CALCULATE THE VERIFICATION NUMBER
        verificationNumber = 11 - (auxValue % 11);

        -- REPLACE THE TWO DIGITS  VERIFICATION NUMBER
        IF( verificationNumber = 11 ) THEN
            RETURN 0;
        ELSEIF ( verificationNumber = 10 ) THEN
            RETURN 9;
        ELSE
            RETURN verificationNumber;
        END IF;

    END IF;

END;
$$ LANGUAGE plpgsql;

-- ----------------------------
-- La siguiente tabla usa una función para generar el código de verificación único
-- ----------------------------

-- Tabla para dictámenes
create table tblDICTUMS (
	dictum_id bigint DEFAULT nextval('seq_dictum_id'),
	dictum_number varchar(200) not null UNIQUE, -- por ejemplo RIG-IE-10001
	dictum_code int8 NOT NULL DEFAULT randomUniqueId(),
	dictum_date date not null, -- fecha de expedición
	dictum_state varchar(20) not null DEFAULT 'En Proceso', --Se describe en que estado está, Sin Procesar, En Proceso, Finalizada.
	dictum_tech_state varchar(20), -- Si está conforme, no conforme.
	dictum_scope varchar(1600) DEFAULT 'Sin Alcance',
	dictum_observ varchar(200), --Observaciones con respecto a las no conformidades.
	dictum_inst_rate varchar(20),
	dictum_inst_voltage varchar(20),
	dictum_inst_resist varchar(20),
	dictum_inst_date date,
	dictum_url varchar(300) DEFAULT 'http://', --La ruta a la carpeta donde está guardado el dictámen o la ruta al servidor.
	process_id bigint not null, -- cada dictamen se hace por separado para cada proceso
	inspection_id bigint not null, --Proviene de una órden de servicio
	primary key(dictum_id)
);

-- Tabla para tipos de instalación para dictamen
create table tblDICTUMUSES (
	dictum_use_id bigint DEFAULT nextval('seq_dictum_use_id'),
	dictum_id bigint not null, -- dictamen al que pertenece
	use_id bigint not null, -- identificador del tipo de instalación o proceso
	use_special_name varchar(50) DEFAULT '', -- nombre de instalación especial en caso que el use_id corresponda a instalaciones especiales
	primary key(dictum_use_id)
);

-- Tabla para procesos asociados de dictamen
create table tblDICTUMPROCS (
	dictum_proc_id bigint DEFAULT nextval('seq_dictum_proc_id'),
	dictum_id bigint not null, -- dictamen al que pertenece
	process_id bigint not null, -- identificador del proceso
	primary key(dictum_proc_id)
);

-- Tabla para consecutivos de dictámenes
create table tblSUBDICTUMS (
	subdictum_id bigint DEFAULT nextval('seq_subdictum_id'),
	subdictum_number varchar(200) not null UNIQUE, -- por ejemplo RIG-IE-10001-1
	subdictum_date date not null, -- fecha de expedición
	subdictum_state varchar(20) not null DEFAULT 'Sin Procesar', --Se describe en que estado está, Sin Procesar, En Proceso, Finalizada.
	subdictum_tech_state varchar(20) not null, --Se describe en que estado está, no conforme, conforme, etc.
	subdictum_scope varchar(1600) DEFAULT 'Sin Alcance',
	subdictum_observ varchar(200), --Observaciones con respecto a las no conformidades.
	subdictum_type varchar(50),
	subdictum_identifier varchar(50),
	subdictum_location varchar(50),
	subdictum_inst_rate varchar(20),
	subdictum_inst_voltage varchar(20),
	subdictum_inst_res varchar(20),
	dictum_id bigint not null, --Proviene de un dictamen
	primary key(subdictum_id)
);

-- Tabla para detalles de dictamen de generación
create table tblGENDICTUMS (
	gendictum_id bigint DEFAULT nextval('seq_gendictum_id'),
	gendictum_se_type varchar(50) not null, -- Tipo de subestación
	gendictum_ses_number varchar(20), -- Número de subestaciones
	dictum_id bigint not null, --Proviene de un dictamen
	primary key(gendictum_id)
);

-- Tabla para detalles de dictamen de generación
create table tblTRANSMDICTUMS (
	transmdictum_id bigint DEFAULT nextval('seq_transmdictum_id'),
	transmdictum_line_detail varchar(300) not null, --descripción completa de la línea
	transmdictum_conf varchar(100) not null, -- configuración de la línea.
	transmdictum_length varchar(50) not null, -- longitud de la línea
	transmdictum_wires_type varchar(50) not null, -- Tipo de conductores, ACSR, etc.
	transmdictum_material varchar(100) not null, -- Material de las estructuras
	transmdictum_structs_number varchar(50) not null, --  Número de estructuras.
	dictum_id bigint not null, --Proviene de un dictamen
	primary key(transmdictum_id)
);

-- Tabla para detalles de dictamen de generación
create table tblTRANSFDICTUMS (
	transfdictum_id bigint DEFAULT nextval('seq_transfdictum_id'),
	transfdictum_se_type varchar(100) not null, -- Encapsulada, de patio, etc
	transfdictum_rate varchar(50) not null, -- Capacidad
	transfdictum_transf_number varchar(20) not null, -- Cantidad de transformadores
	dictum_id bigint not null, --Proviene de un dictamen
	primary key(transfdictum_id)
);

-- Tabla para detalles de dictamen de generación
create table tblDISTDICTUMS (
	distdictum_id bigint DEFAULT nextval('seq_distdictum_id'),
	distdictum_conf varchar(200) not null, -- configuración de la línea.
	distdictum_length varchar(50) not null, -- longitud de la línea
	distdictum_wires_type varchar(50) not null, -- Tipo de conductores, ACSR, etc.
	distdictum_material varchar(100) not null, -- Material de las estructuras
	distdictum_structs_number varchar(50) not null, --  Número de estructuras.	
	dictum_id bigint not null, --Proviene de un dictamen
	primary key(distdictum_id)
);

-- Tabla para detalles de dictamen de generación
create table tblALINTDICTUMS (
	alintdictum_id bigint DEFAULT nextval('seq_alintdictum_id'),
	dictum_id bigint not null, --Proviene de un dictamen
	primary key(alintdictum_id)
);

-- Tabla para detalles de dictamen de generación
create table tblALEXTDICTUMS (
	alextdictum_id bigint DEFAULT nextval('seq_alextdictum_id'),
	alextdictum_luminaries_number varchar(20)  not null, -- número de luminarias
	alextdictum_measure_system varchar(20) not null, -- sistema de medida de energía si o no
	alextdictum_porpuse varchar(100) not null, -- Parque, vías, etc.
	alextdictum_length varchar(50) not null, -- 860m
	alextdictum_area varchar(50) not null, -- 6020m^2
	dictum_id bigint not null, --Proviene de un dictamen
	primary key(alextdictum_id)
);

-- Tabla para requerimientos
create table tblREQUIREMENTS (
	req_id bigint DEFAULT nextval('seq_requirement_id'),
	req_description varchar(200) not null, -- descripción de el requerimiento
	process_id bigint not null, -- casos en los que aplica el requerimiento, causibinario también
	primary key(req_id)
);

-- Tabla para requerimientos del dictamen
create table tblDICTUMREQS (
	dictum_req_id bigint DEFAULT nextval('seq_dictum_req_id'),
	dictum_id bigint not null, -- dictamen al que pertenece
	req_id bigint not null, -- identificador del requerimiento
	req_meets varchar(20) not null DEFAULT '', -- si cumplió en el dictamen
	req_no_meets varchar(20) not null DEFAULT '', -- si no cumplió en el dictamen
	primary key(dictum_req_id)
);

-- Tabla para requerimientos del consecutivos o subdictámenes
create table tblSUBDICTUMREQS (
	subdictum_req_id bigint DEFAULT nextval('seq_subdictum_req_id'),
	subdictum_id bigint not null, -- subdictamen al que pertenece
	req_id bigint not null, -- identificador del requerimiento
	req_meets varchar(20) not null DEFAULT '', -- si cumplió o no en el dictamen
	req_no_meets varchar(20) not null DEFAULT 'X', -- si no cumplió en el dictamen
	primary key(subdictum_req_id)
);

create table tblRECORDS (
	record_id bigint DEFAULT nextval('seq_record_id'),
	record_foil varchar(20), --En que parte del archivo está guardado
	primary key(record_id)
);

--Para los guardar la selección de az's o folios de orden de servicio
create table tblSORECORDS (
	so_record_id int DEFAULT nextval('seq_so_record_id'),
	so_id int not null, -- A que orden de servicio pertenece
	record_id int not null, --Distintos folios
	primary key(so_record_id)
);

--Para los guardar los datos de tracking (envíos, recepciones, responsable) de orden de servicio
create table tblSOTRACKING (
	trck_id bigint DEFAULT nextval('seq_trck_id'),
	so_id bigint unique not null, -- A que orden de servicio pertenece
	trck_receipt_date date not null, --Fecha de recepción
	trck_receiver_name varchar(50) not null, -- Quién recibe
	trck_shipping_date date, --Fecha de envío
	trck_shipper_name varchar(50), -- Quién envía
	trck_shipping_name varchar(50), -- A quién fue entregado el envío o para quién va
	trck_shipping_company varchar(50), -- Empresa de envíos
	trck_guide_number varchar(50), -- número de guía
	trck_observations varchar(200), -- que se envía (factura, dictamen, carpeta) u observaciones en general
	city_id int default 1121, -- Ciudad de envío
	primary key(trck_id)
);

--Diferentes tipos de evento
create table tblEVENTTYPE (
	event_type_id bigint DEFAULT nextval('seq_event_type_id'),
	event_type varchar(100) not null, -- Quién recibe
	primary key(event_type_id)
);

--Eventos
create table tblEVENTS (
	log_date_time timestamp not null,
	log_user_name varchar(100) not null,
	log_detail varchar(200) not null,
	quot_id int DEFAULT 0,
	prop_id int DEFAULT 0,
	so_id int DEFAULT 0,
	inspection_id int DEFAULT 0,
	dictum_id int DEFAULT 0,
	subdictum_id int DEFAULT 0,
	event_type_id int not null
);


--Creación de las relaciones entre tablas, o referencias
alter table tblCITIES
add constraint fk_states foreign key (state_id) references tblSTATES; --fk_state (foreign key state) nombre de la relación

alter table tblTHIRDPARTIES
add constraint fk_city foreign key (city_id) references tblCITIES;

alter table tblINSPDETAILS
add constraint fk_inspector foreign key (inspector_id) references tblINSPECTORS;

alter table tblSUBPROCESSES
add constraint fk_process foreign key (process_id) references tblPROCESSES;

alter table tblQUOTATIONS
add constraint fk_thirdpartie foreign key (thrd_id) references tblTHIRDPARTIES ON DELETE CASCADE ON UPDATE CASCADE,
add constraint fk_city foreign key (city_id) references tblCITIES,
add constraint fk_use foreign key (use_id) references tblUSES;

alter table tblQUOTPROCESSES
add constraint fk_quotation foreign key (quot_id) references tblQUOTATIONS ON DELETE CASCADE;

alter table tblPROPOSALS
add constraint fk_quotation foreign key (quot_id) references tblQUOTATIONS ON DELETE CASCADE,
add constraint fk_user foreign key (user_id) references tblUSERS;

alter table tblPROPDOCUMENTS
add constraint fk_proposal foreign key (prop_id) references tblPROPOSALS ON DELETE CASCADE;

alter table tblSERVICEORDERS
add constraint fk_proposal foreign key (prop_id) references tblPROPOSALS ON DELETE CASCADE,
add constraint fk_inspector foreign key (inspector_id) references tblINSPECTORS;

alter table tblMOVEMENTS
add constraint fk_serviceorder foreign key (so_id) references tblSERVICEORDERS ON DELETE CASCADE;

alter table tblSODOCUMENTS
add constraint fk_serviceorder foreign key (so_id) references tblSERVICEORDERS ON DELETE CASCADE;

alter table tblSORECORDS
add constraint fk_serviceorder foreign key (so_id) references tblSERVICEORDERS ON DELETE CASCADE,
add constraint fk_record foreign key (record_id) references tblRECORDS ON DELETE CASCADE;

alter table tblSOTRACKING
add constraint fk_serviceorder foreign key (so_id) references tblSERVICEORDERS ON DELETE CASCADE;

alter table tblINSPECTIONS
add constraint fk_so foreign key (so_id) references tblSERVICEORDERS,
add constraint fk_city foreign key (city_id) references tblCITIES,
add constraint fk_constructor foreign key (constructor_id) references tblCONSTRUCTORS,
add constraint fk_auditor foreign key (auditor_id) references tblAUDITORS;

alter table tblINSPECTIONDESIGNERS
add constraint fk_inspection foreign key (inspection_id) references tblINSPECTIONS ON DELETE CASCADE,
add constraint fk_designer foreign key (designer_id) references tblDESIGNERS;

alter table tblDICTUMS
add constraint fk_inspection foreign key (inspection_id) references tblINSPECTIONS ON DELETE CASCADE;

alter table tblSUBDICTUMS
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE;

alter table tblDICTUMREQS
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE;

alter table tblDICTUMUSES
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE,
add constraint fk_use foreign key (use_id) references tblUSES;

alter table tblDICTUMPROCS
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE,
add constraint fk_process foreign key (process_id) references tblPROCESSES;

alter table tblSUBDICTUMREQS
add constraint fk_subdictum foreign key (subdictum_id) references tblSUBDICTUMS ON DELETE CASCADE;

alter table tblGENDICTUMS
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE;

alter table tblTRANSMDICTUMS
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE;

alter table tblTRANSFDICTUMS
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE;

alter table tblDISTDICTUMS
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE;

alter table tblALINTDICTUMS
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE;

alter table tblALEXTDICTUMS
add constraint fk_dictum foreign key (dictum_id) references tblDICTUMS ON DELETE CASCADE;

alter table tblEVENTS
add constraint fk_event_type foreign key (event_type_id) references tblEVENTTYPE ON DELETE CASCADE;

--Creación de algunos índices para acelerar búsquedas
create index idx_thrd_name on tblTHIRDPARTIES (thrd_name ASC);
create index idx_thrd_representative on tblTHIRDPARTIES (thrd_representative ASC);
create index idx_so_date on tblSERVICEORDERS (so_date);
create index idx_quot_name on tblQUOTATIONS (quot_name);
create index idx_dictum_number on tblDICTUMS (dictum_number);
create index idx_subdictum_number on tblSUBDICTUMS (subdictum_number);


