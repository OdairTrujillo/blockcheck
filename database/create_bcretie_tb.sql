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
  
-- Tabla para terceros
create table tblTHIRDPARTIES (
	thrd_id int DEFAULT nextval('seq_thrd_id'), --Identificador único del tercero 
	thrd_nit varchar(60) not null unique, --NIT de la empresa
	thrd_name varchar(100) not null, --Nombre de la empresa
	thrd_representative varchar(60) not null, --Nombre del representante legal
	thrd_cc varchar(50), --Cedula del representante legal
	thrd_address varchar(100) not null, --Dirección de la empresa
	thrd_mail varchar(40) DEFAULT 'Sin mail',
	thrd_cel varchar(40) not null, --Número de celular
	thrd_tel varchar(40) DEFAULT 'Sin número', --Número de teléfono
	city_id int not null, --Ciudad
	primary key(thrd_id)
); --Sin llave primaria incorporada en la tabla

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

--Para los distintos tipos de documentos exigidos
create table tblDOCUMENTS (
	document_id int DEFAULT nextval('seq_document_id'),
	document_name varchar(200) not null, --Distintos documentos disponibles para seleccionar
	document_type varchar(40) not null, --El tipo de documento como los RETIE 8.1, RETILAP, NORMAS VOLUNTARIAS, o los exigidos por RIG en la carpeta
	primary key(document_id)
);

--Para los guardar la selección de documentos de propuesta
create table tblPROPDOCUMENTS (
	propdocument_id int DEFAULT nextval('seq_propdocument_id'),
	prop_id int not null, -- A que propuesta pertenece
	document_id int not null, --Distintos documentos obligatorios para determinados procesos
	primary key(propdocument_id)
);

--Tabla para cotizaciones
create table tblQUOTATIONS (
	quot_id bigint DEFAULT nextval('seq_quot_id'),
	quot_date date not null,
	quot_name varchar(100) not null,
	quot_scope varchar(1600) not null,
	quot_contact varchar(50) not null,
	quot_address varchar(50) not null,
	quot_mail varchar(40) DEFAULT 'Sin e-mail',
	quot_cel varchar(40) not null,
	quot_tel varchar(40) not null,
	quot_inspect_type varchar(40) not null, -- RETIE, RETILAP o NORMAS VOLUNTARIAS
	thrd_id int not null, --La cotización depende de un tercero
	city_id int not null,
	use_id int not null, --El uso sirve para saber cuanto facturar
	primary key (quot_id)
);

--Tabla para guardar los procesos de cada cotización
create table tblQUOTPROCESSES (
	quotproc_id bigint DEFAULT nextval('seq_quotproc_id'),
	quot_id bigint not null,
	process_id int not null,
	primary key (quotproc_id)
);

--Tabla para propuestas
create table tblPROPOSALS (
	prop_id bigint DEFAULT nextval('seq_prop_id')*10000 + date_part('year', now()),
	prop_date date not null,
	prop_scope varchar(1600) not null, -- Es alcance puede cambiar entre cotizacion y propuesta
	prop_state varchar(60) not null, --Por Aprobar, Aprobada
	prop_payway varchar(40) not null,
	prop_user_perc float, -- Porcentaje para el vendedor
	prop_approval varchar(400) DEFAULT 'Sin Aprobación', -- método de aprobación
	prop_observ varchar(400) DEFAULT 'Sin Observaciones', -- método de aprobación
	prop_value numeric not null, -- Valor de la propuesta
	prop_iva numeric not null, -- Valor del iva
	prop_viatical numeric not null, -- Valor de los viáticos
	prop_total_value numeric not null, -- Valor total
	quot_id int not null unique, --proviene de una cotización pero se puede modificar
	user_id int not null, -- Quién valida la propuesta
	primary key(prop_id)
);

--Para órdenes de servicio
create table tblSERVICEORDERS (
	so_id bigint DEFAULT  nextval('seq_so_id')*10000 + date_part('year', now()),
	so_date date not null,
	so_scope varchar(1600) not null, -- El alcance puede cambiar entre propuesta y os
	so_observations varchar(200) not null,
	so_acc_processed varchar(20) default 'Sin Procesar', -- Determina si se ha procesaro contablemente la orden de servicio
	so_doc_processed varchar(20) default 'Sin Procesar', -- Determina si se ha procesaro la carpeta de la orden de servicio
	so_eng_processed varchar(20) default 'Sin Procesar', -- Determina si se ha procesaro en ingeniería la orden de servicio
        so_eng_observations varchar(200) default '', -- Observaciones de Ingeniería
        so_adm_observations varchar(200) default '', -- Observaciones de Gerencia
	so_inspector_perc float not null, -- Porcentaje para el inspector
	so_assign_date date not null, -- Fecha de asignación de la inspección
        so_bill_number varchar(100) default 'Sin Factura', -- Número de la factura
	inspector_id int not null, --Una orden de servicio debe llevar un inspector
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

-- ----------------------------
-- Definition of function  "randomuniqueid"
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
-- Definition of function  "randomuniqueid"
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
create index idx_thrd_cc on tblTHIRDPARTIES (thrd_cc);
create index idx_thrd_name on tblTHIRDPARTIES (thrd_name ASC);
create index idx_thrd_representative on tblTHIRDPARTIES (thrd_representative ASC);
create index idx_so_date on tblSERVICEORDERS (so_date);
create index idx_quot_name on tblQUOTATIONS (quot_name);
create index idx_dictum_number on tblDICTUMS (dictum_number);
create index idx_subdictum_number on tblSUBDICTUMS (subdictum_number);

--INSERCIÓN DE ALGUNOS DATOS
-- Inserción de los departamentos
INSERT INTO tblstates VALUES (1, '05', 'ANTIOQUIA');
INSERT INTO tblstates VALUES (2, '08', 'ATLANTICO');
INSERT INTO tblstates VALUES (3, '11', 'BOGOTA');
INSERT INTO tblstates VALUES (4, '13', 'BOLIVAR');
INSERT INTO tblstates VALUES (5, '15', 'BOYACA');
INSERT INTO tblstates VALUES (6, '17', 'CALDAS');
INSERT INTO tblstates VALUES (7, '18', 'CAQUETA');
INSERT INTO tblstates VALUES (8, '19', 'CAUCA');
INSERT INTO tblstates VALUES (9, '20', 'CESAR');
INSERT INTO tblstates VALUES (10, '23', 'CORDOBA');
INSERT INTO tblstates VALUES (11, '25', 'CUNDINAMARCA');
INSERT INTO tblstates VALUES (12, '27', 'CHOCO');
INSERT INTO tblstates VALUES (13, '41', 'HUILA');
INSERT INTO tblstates VALUES (14, '44', 'LA GUAJIRA');
INSERT INTO tblstates VALUES (15, '47', 'MAGDALENA');
INSERT INTO tblstates VALUES (16, '50', 'META');
INSERT INTO tblstates VALUES (17, '52', 'NARIÑO');
INSERT INTO tblstates VALUES (18, '54', 'N. DE SANTANDER');
INSERT INTO tblstates VALUES (19, '63', 'QUINDIO');
INSERT INTO tblstates VALUES (20, '66', 'RISARALDA');
INSERT INTO tblstates VALUES (21, '68', 'SANTANDER');
INSERT INTO tblstates VALUES (22, '70', 'SUCRE');
INSERT INTO tblstates VALUES (23, '73', 'TOLIMA');
INSERT INTO tblstates VALUES (24, '76', 'VALLE DEL CAUCA');
INSERT INTO tblstates VALUES (25, '81', 'ARAUCA');
INSERT INTO tblstates VALUES (26, '85', 'CASANARE');
INSERT INTO tblstates VALUES (27, '86', 'PUTUMAYO');
INSERT INTO tblstates VALUES (28, '88', 'SAN ANDRES');
INSERT INTO tblstates VALUES (29, '91', 'AMAZONAS');
INSERT INTO tblstates VALUES (30, '94', 'GUAINIA');
INSERT INTO tblstates VALUES (31, '95', 'GUAVIARE');
INSERT INTO tblstates VALUES (32, '97', 'VAUPES');
INSERT INTO tblstates VALUES (33, '99', 'VICHADA');
INSERT INTO tblstates VALUES (34, 'NONE', 'SIN DPTO');

-- Inserción de los municipios

INSERT INTO tblcities VALUES (1, '05001', 'MEDELLIN', 1);
INSERT INTO tblcities VALUES (2, '05002', 'ABEJORRAL', 1);
INSERT INTO tblcities VALUES (3, '05004', 'ABRIAQUI', 1);
INSERT INTO tblcities VALUES (4, '05021', 'ALEJANDRIA', 1);
INSERT INTO tblcities VALUES (5, '05030', 'AMAGA', 1);
INSERT INTO tblcities VALUES (6, '05031', 'AMALFI', 1);
INSERT INTO tblcities VALUES (7, '05034', 'ANDES', 1);
INSERT INTO tblcities VALUES (8, '05036', 'ANGELOPOLIS', 1);
INSERT INTO tblcities VALUES (9, '05038', 'ANGOSTURA', 1);
INSERT INTO tblcities VALUES (10, '05040', 'ANORI', 1);
INSERT INTO tblcities VALUES (11, '05042', 'SANTAFE DE ANTIOQUIA', 1);
INSERT INTO tblcities VALUES (12, '05044', 'ANZA', 1);
INSERT INTO tblcities VALUES (13, '05045', 'APARTADO', 1);
INSERT INTO tblcities VALUES (14, '05051', 'ARBOLETES', 1);
INSERT INTO tblcities VALUES (15, '05055', 'ARGELIA', 1);
INSERT INTO tblcities VALUES (16, '05059', 'ARMENIA', 1);
INSERT INTO tblcities VALUES (17, '05079', 'BARBOSA', 1);
INSERT INTO tblcities VALUES (18, '05086', 'BELMIRA', 1);
INSERT INTO tblcities VALUES (19, '05088', 'BELLO', 1);
INSERT INTO tblcities VALUES (20, '05091', 'BETANIA', 1);
INSERT INTO tblcities VALUES (21, '05093', 'BETULIA', 1);
INSERT INTO tblcities VALUES (22, '05101', 'CIUDAD BOLIVAR', 1);
INSERT INTO tblcities VALUES (23, '05107', 'BRICEÑO', 1);
INSERT INTO tblcities VALUES (24, '05113', 'BURITICA', 1);
INSERT INTO tblcities VALUES (25, '05120', 'CACERES', 1);
INSERT INTO tblcities VALUES (26, '05125', 'CAICEDO', 1);
INSERT INTO tblcities VALUES (27, '05129', 'CALDAS', 1);
INSERT INTO tblcities VALUES (28, '05134', 'CAMPAMENTO', 1);
INSERT INTO tblcities VALUES (29, '05138', 'CAÑASGORDAS', 1);
INSERT INTO tblcities VALUES (30, '05142', 'CARACOLI', 1);
INSERT INTO tblcities VALUES (31, '05145', 'CARAMANTA', 1);
INSERT INTO tblcities VALUES (32, '05147', 'CAREPA', 1);
INSERT INTO tblcities VALUES (33, '05148', 'EL CARMEN DE VIBORAL', 1);
INSERT INTO tblcities VALUES (34, '05150', 'CAROLINA', 1);
INSERT INTO tblcities VALUES (35, '05154', 'CAUCASIA', 1);
INSERT INTO tblcities VALUES (36, '05172', 'CHIGORODO', 1);
INSERT INTO tblcities VALUES (37, '05190', 'CISNEROS', 1);
INSERT INTO tblcities VALUES (38, '05197', 'COCORNA', 1);
INSERT INTO tblcities VALUES (39, '05206', 'CONCEPCION', 1);
INSERT INTO tblcities VALUES (40, '05209', 'CONCORDIA', 1);
INSERT INTO tblcities VALUES (41, '05212', 'COPACABANA', 1);
INSERT INTO tblcities VALUES (42, '05234', 'DABEIBA', 1);
INSERT INTO tblcities VALUES (43, '05237', 'DON MATIAS', 1);
INSERT INTO tblcities VALUES (44, '05240', 'EBEJICO', 1);
INSERT INTO tblcities VALUES (45, '05250', 'EL BAGRE', 1);
INSERT INTO tblcities VALUES (46, '05264', 'ENTRERRIOS', 1);
INSERT INTO tblcities VALUES (47, '05266', 'ENVIGADO', 1);
INSERT INTO tblcities VALUES (48, '05282', 'FREDONIA', 1);
INSERT INTO tblcities VALUES (49, '05284', 'FRONTINO', 1);
INSERT INTO tblcities VALUES (50, '05306', 'GIRALDO', 1);
INSERT INTO tblcities VALUES (51, '05308', 'GIRARDOTA', 1);
INSERT INTO tblcities VALUES (52, '05310', 'GOMEZ PLATA', 1);
INSERT INTO tblcities VALUES (53, '05313', 'GRANADA', 1);
INSERT INTO tblcities VALUES (54, '05315', 'GUADALUPE', 1);
INSERT INTO tblcities VALUES (55, '05318', 'GUARNE', 1);
INSERT INTO tblcities VALUES (56, '05321', 'GUATAPE', 1);
INSERT INTO tblcities VALUES (57, '05347', 'HELICONIA', 1);
INSERT INTO tblcities VALUES (58, '05353', 'HISPANIA', 1);
INSERT INTO tblcities VALUES (59, '05360', 'ITAGUI', 1);
INSERT INTO tblcities VALUES (60, '05361', 'ITUANGO', 1);
INSERT INTO tblcities VALUES (61, '05364', 'JARDIN', 1);
INSERT INTO tblcities VALUES (62, '05368', 'JERICO', 1);
INSERT INTO tblcities VALUES (63, '05376', 'LA CEJA', 1);
INSERT INTO tblcities VALUES (64, '05380', 'LA ESTRELLA', 1);
INSERT INTO tblcities VALUES (65, '05390', 'LA PINTADA', 1);
INSERT INTO tblcities VALUES (66, '05400', 'LA UNION', 1);
INSERT INTO tblcities VALUES (67, '05411', 'LIBORINA', 1);
INSERT INTO tblcities VALUES (68, '05425', 'MACEO', 1);
INSERT INTO tblcities VALUES (69, '05440', 'MARINILLA', 1);
INSERT INTO tblcities VALUES (70, '05467', 'MONTEBELLO', 1);
INSERT INTO tblcities VALUES (71, '05475', 'MURINDO', 1);
INSERT INTO tblcities VALUES (72, '05480', 'MUTATA', 1);
INSERT INTO tblcities VALUES (73, '05483', 'NARIÑO', 1);
INSERT INTO tblcities VALUES (74, '05490', 'NECOCLI', 1);
INSERT INTO tblcities VALUES (75, '05495', 'NECHI', 1);
INSERT INTO tblcities VALUES (76, '05501', 'OLAYA', 1);
INSERT INTO tblcities VALUES (77, '05541', 'PEÐOL', 1);
INSERT INTO tblcities VALUES (78, '05543', 'PEQUE', 1);
INSERT INTO tblcities VALUES (79, '05576', 'PUEBLORRICO', 1);
INSERT INTO tblcities VALUES (80, '05579', 'PUERTO BERRIO', 1);
INSERT INTO tblcities VALUES (81, '05585', 'PUERTO NARE', 1);
INSERT INTO tblcities VALUES (82, '05591', 'PUERTO TRIUNFO', 1);
INSERT INTO tblcities VALUES (83, '05604', 'REMEDIOS', 1);
INSERT INTO tblcities VALUES (84, '05607', 'RETIRO', 1);
INSERT INTO tblcities VALUES (85, '05615', 'RIONEGRO', 1);
INSERT INTO tblcities VALUES (86, '05628', 'SABANALARGA', 1);
INSERT INTO tblcities VALUES (87, '05631', 'SABANETA', 1);
INSERT INTO tblcities VALUES (88, '05642', 'SALGAR', 1);
INSERT INTO tblcities VALUES (89, '05647', 'SAN ANDRES DE CUERQUIA', 1);
INSERT INTO tblcities VALUES (90, '05649', 'SAN CARLOS', 1);
INSERT INTO tblcities VALUES (91, '05652', 'SAN FRANCISCO', 1);
INSERT INTO tblcities VALUES (92, '05656', 'SAN JERONIMO', 1);
INSERT INTO tblcities VALUES (93, '05658', 'SAN JOSE DE LA MONTAÑA', 1);
INSERT INTO tblcities VALUES (94, '05659', 'SAN JUAN DE URABA', 1);
INSERT INTO tblcities VALUES (95, '05660', 'SAN LUIS', 1);
INSERT INTO tblcities VALUES (96, '05664', 'SAN PEDRO', 1);
INSERT INTO tblcities VALUES (97, '05665', 'SAN PEDRO DE URABA', 1);
INSERT INTO tblcities VALUES (98, '05667', 'SAN RAFAEL', 1);
INSERT INTO tblcities VALUES (99, '05670', 'SAN ROQUE', 1);
INSERT INTO tblcities VALUES (100, '05674', 'SAN VICENTE', 1);
INSERT INTO tblcities VALUES (101, '05679', 'SANTA BARBARA', 1);
INSERT INTO tblcities VALUES (102, '05686', 'SANTA ROSA DE OSOS', 1);
INSERT INTO tblcities VALUES (103, '05690', 'SANTO DOMINGO', 1);
INSERT INTO tblcities VALUES (104, '05697', 'EL SANTUARIO', 1);
INSERT INTO tblcities VALUES (105, '05736', 'SEGOVIA', 1);
INSERT INTO tblcities VALUES (106, '05756', 'SONSON', 1);
INSERT INTO tblcities VALUES (107, '05761', 'SOPETRAN', 1);
INSERT INTO tblcities VALUES (108, '05789', 'TAMESIS', 1);
INSERT INTO tblcities VALUES (109, '05790', 'TARAZA', 1);
INSERT INTO tblcities VALUES (110, '05792', 'TARSO', 1);
INSERT INTO tblcities VALUES (111, '05809', 'TITIRIBI', 1);
INSERT INTO tblcities VALUES (112, '05819', 'TOLEDO', 1);
INSERT INTO tblcities VALUES (113, '05837', 'TURBO', 1);
INSERT INTO tblcities VALUES (114, '05842', 'URAMITA', 1);
INSERT INTO tblcities VALUES (115, '05847', 'URRAO', 1);
INSERT INTO tblcities VALUES (116, '05854', 'VALDIVIA', 1);
INSERT INTO tblcities VALUES (117, '05856', 'VALPARAISO', 1);
INSERT INTO tblcities VALUES (118, '05858', 'VEGACHI', 1);
INSERT INTO tblcities VALUES (119, '05861', 'VENECIA', 1);
INSERT INTO tblcities VALUES (120, '05873', 'VIGIA DEL FUERTE', 1);
INSERT INTO tblcities VALUES (121, '05885', 'YALI', 1);
INSERT INTO tblcities VALUES (122, '05887', 'YARUMAL', 1);
INSERT INTO tblcities VALUES (123, '05890', 'YOLOMBO', 1);
INSERT INTO tblcities VALUES (124, '05893', 'YONDO', 1);
INSERT INTO tblcities VALUES (125, '05895', 'ZARAGOZA', 1);
INSERT INTO tblcities VALUES (126, '08001', 'BARRANQUILLA', 2);
INSERT INTO tblcities VALUES (127, '08078', 'BARANOA', 2);
INSERT INTO tblcities VALUES (128, '08137', 'CAMPO DE LA CRUZ', 2);
INSERT INTO tblcities VALUES (129, '08141', 'CANDELARIA', 2);
INSERT INTO tblcities VALUES (130, '08296', 'GALAPA', 2);
INSERT INTO tblcities VALUES (131, '08372', 'JUAN DE ACOSTA', 2);
INSERT INTO tblcities VALUES (132, '08421', 'LURUACO', 2);
INSERT INTO tblcities VALUES (133, '08433', 'MALAMBO', 2);
INSERT INTO tblcities VALUES (134, '08436', 'MANATI', 2);
INSERT INTO tblcities VALUES (135, '08520', 'PALMAR DE VARELA', 2);
INSERT INTO tblcities VALUES (136, '08549', 'PIOJO', 2);
INSERT INTO tblcities VALUES (137, '08558', 'POLONUEVO', 2);
INSERT INTO tblcities VALUES (138, '08560', 'PONEDERA', 2);
INSERT INTO tblcities VALUES (139, '08573', 'PUERTO COLOMBIA', 2);
INSERT INTO tblcities VALUES (140, '08606', 'REPELON', 2);
INSERT INTO tblcities VALUES (141, '08634', 'SABANAGRANDE', 2);
INSERT INTO tblcities VALUES (142, '08638', 'SABANALARGA', 2);
INSERT INTO tblcities VALUES (143, '08675', 'SANTA LUCIA', 2);
INSERT INTO tblcities VALUES (144, '08685', 'SANTO TOMAS', 2);
INSERT INTO tblcities VALUES (145, '08758', 'SOLEDAD', 2);
INSERT INTO tblcities VALUES (146, '08770', 'SUAN', 2);
INSERT INTO tblcities VALUES (147, '08832', 'TUBARA', 2);
INSERT INTO tblcities VALUES (148, '08849', 'USIACURI', 2);
INSERT INTO tblcities VALUES (149, '11001', 'BOGOTA, D.C.', 3);
INSERT INTO tblcities VALUES (150, '13001', 'CARTAGENA', 4);
INSERT INTO tblcities VALUES (151, '13006', 'ACHI', 4);
INSERT INTO tblcities VALUES (152, '13030', 'ALTOS DEL ROSARIO', 4);
INSERT INTO tblcities VALUES (153, '13042', 'ARENAL', 4);
INSERT INTO tblcities VALUES (154, '13052', 'ARJONA', 4);
INSERT INTO tblcities VALUES (155, '13062', 'ARROYOHONDO', 4);
INSERT INTO tblcities VALUES (156, '13074', 'BARRANCO DE LOBA', 4);
INSERT INTO tblcities VALUES (157, '13140', 'CALAMAR', 4);
INSERT INTO tblcities VALUES (158, '13160', 'CANTAGALLO', 4);
INSERT INTO tblcities VALUES (159, '13188', 'CICUCO', 4);
INSERT INTO tblcities VALUES (160, '13212', 'CORDOBA', 4);
INSERT INTO tblcities VALUES (161, '13222', 'CLEMENCIA', 4);
INSERT INTO tblcities VALUES (162, '13244', 'EL CARMEN DE BOLIVAR', 4);
INSERT INTO tblcities VALUES (163, '13248', 'EL GUAMO', 4);
INSERT INTO tblcities VALUES (164, '13268', 'EL PEÑON', 4);
INSERT INTO tblcities VALUES (165, '13300', 'HATILLO DE LOBA', 4);
INSERT INTO tblcities VALUES (166, '13430', 'MAGANGUE', 4);
INSERT INTO tblcities VALUES (167, '13433', 'MAHATES', 4);
INSERT INTO tblcities VALUES (168, '13440', 'MARGARITA', 4);
INSERT INTO tblcities VALUES (169, '13442', 'MARIA LA BAJA', 4);
INSERT INTO tblcities VALUES (170, '13458', 'MONTECRISTO', 4);
INSERT INTO tblcities VALUES (171, '13468', 'MOMPOS', 4);
INSERT INTO tblcities VALUES (172, '13490', 'NOROSI', 4);
INSERT INTO tblcities VALUES (173, '13473', 'MORALES', 4);
INSERT INTO tblcities VALUES (174, '13549', 'PINILLOS', 4);
INSERT INTO tblcities VALUES (175, '13580', 'REGIDOR', 4);
INSERT INTO tblcities VALUES (176, '13600', 'RIO VIEJO', 4);
INSERT INTO tblcities VALUES (177, '13620', 'SAN CRISTOBAL', 4);
INSERT INTO tblcities VALUES (178, '13647', 'SAN ESTANISLAO', 4);
INSERT INTO tblcities VALUES (179, '13650', 'SAN FERNANDO', 4);
INSERT INTO tblcities VALUES (180, '13654', 'SAN JACINTO', 4);
INSERT INTO tblcities VALUES (181, '13655', 'SAN JACINTO DEL CAUCA', 4);
INSERT INTO tblcities VALUES (182, '13657', 'SAN JUAN NEPOMUCENO', 4);
INSERT INTO tblcities VALUES (183, '13667', 'SAN MARTIN DE LOBA', 4);
INSERT INTO tblcities VALUES (184, '13670', 'SAN PABLO', 4);
INSERT INTO tblcities VALUES (185, '13673', 'SANTA CATALINA', 4);
INSERT INTO tblcities VALUES (186, '13683', 'SANTA ROSA', 4);
INSERT INTO tblcities VALUES (187, '13688', 'SANTA ROSA DEL SUR', 4);
INSERT INTO tblcities VALUES (188, '13744', 'SIMITI', 4);
INSERT INTO tblcities VALUES (189, '13760', 'SOPLAVIENTO', 4);
INSERT INTO tblcities VALUES (190, '13780', 'TALAIGUA NUEVO', 4);
INSERT INTO tblcities VALUES (191, '13810', 'TIQUISIO', 4);
INSERT INTO tblcities VALUES (192, '13836', 'TURBACO', 4);
INSERT INTO tblcities VALUES (193, '13838', 'TURBANA', 4);
INSERT INTO tblcities VALUES (194, '13873', 'VILLANUEVA', 4);
INSERT INTO tblcities VALUES (195, '13894', 'ZAMBRANO', 4);
INSERT INTO tblcities VALUES (196, '15001', 'TUNJA', 5);
INSERT INTO tblcities VALUES (197, '15022', 'ALMEIDA', 5);
INSERT INTO tblcities VALUES (198, '15047', 'AQUITANIA', 5);
INSERT INTO tblcities VALUES (199, '15051', 'ARCABUCO', 5);
INSERT INTO tblcities VALUES (200, '15087', 'BELEN', 5);
INSERT INTO tblcities VALUES (201, '15090', 'BERBEO', 5);
INSERT INTO tblcities VALUES (202, '15092', 'BETEITIVA', 5);
INSERT INTO tblcities VALUES (203, '15097', 'BOAVITA', 5);
INSERT INTO tblcities VALUES (204, '15104', 'BOYACA', 5);
INSERT INTO tblcities VALUES (205, '15106', 'BRICEÑO', 5);
INSERT INTO tblcities VALUES (206, '15109', 'BUENAVISTA', 5);
INSERT INTO tblcities VALUES (207, '15114', 'BUSBANZA', 5);
INSERT INTO tblcities VALUES (208, '15131', 'CALDAS', 5);
INSERT INTO tblcities VALUES (209, '15135', 'CAMPOHERMOSO', 5);
INSERT INTO tblcities VALUES (210, '15162', 'CERINZA', 5);
INSERT INTO tblcities VALUES (211, '15172', 'CHINAVITA', 5);
INSERT INTO tblcities VALUES (212, '15176', 'CHIQUINQUIRA', 5);
INSERT INTO tblcities VALUES (213, '15180', 'CHISCAS', 5);
INSERT INTO tblcities VALUES (214, '15183', 'CHITA', 5);
INSERT INTO tblcities VALUES (215, '15185', 'CHITARAQUE', 5);
INSERT INTO tblcities VALUES (216, '15187', 'CHIVATA', 5);
INSERT INTO tblcities VALUES (217, '15189', 'CIENEGA', 5);
INSERT INTO tblcities VALUES (218, '15204', 'COMBITA', 5);
INSERT INTO tblcities VALUES (219, '15212', 'COPER', 5);
INSERT INTO tblcities VALUES (220, '15215', 'CORRALES', 5);
INSERT INTO tblcities VALUES (221, '15218', 'COVARACHIA', 5);
INSERT INTO tblcities VALUES (222, '15223', 'CUBARA', 5);
INSERT INTO tblcities VALUES (223, '15224', 'CUCAITA', 5);
INSERT INTO tblcities VALUES (224, '15226', 'CUITIVA', 5);
INSERT INTO tblcities VALUES (225, '15232', 'CHIQUIZA', 5);
INSERT INTO tblcities VALUES (226, '15236', 'CHIVOR', 5);
INSERT INTO tblcities VALUES (227, '15238', 'DUITAMA', 5);
INSERT INTO tblcities VALUES (228, '15244', 'EL COCUY', 5);
INSERT INTO tblcities VALUES (229, '15248', 'EL ESPINO', 5);
INSERT INTO tblcities VALUES (230, '15272', 'FIRAVITOBA', 5);
INSERT INTO tblcities VALUES (231, '15276', 'FLORESTA', 5);
INSERT INTO tblcities VALUES (232, '15293', 'GACHANTIVA', 5);
INSERT INTO tblcities VALUES (233, '15296', 'GAMEZA', 5);
INSERT INTO tblcities VALUES (234, '15299', 'GARAGOA', 5);
INSERT INTO tblcities VALUES (235, '15317', 'GUACAMAYAS', 5);
INSERT INTO tblcities VALUES (236, '15322', 'GUATEQUE', 5);
INSERT INTO tblcities VALUES (237, '15325', 'GUAYATA', 5);
INSERT INTO tblcities VALUES (238, '15332', 'GsICAN', 5);
INSERT INTO tblcities VALUES (239, '15362', 'IZA', 5);
INSERT INTO tblcities VALUES (240, '15367', 'JENESANO', 5);
INSERT INTO tblcities VALUES (241, '15368', 'JERICO', 5);
INSERT INTO tblcities VALUES (242, '15377', 'LABRANZAGRANDE', 5);
INSERT INTO tblcities VALUES (243, '15380', 'LA CAPILLA', 5);
INSERT INTO tblcities VALUES (244, '15401', 'LA VICTORIA', 5);
INSERT INTO tblcities VALUES (245, '15403', 'LA UVITA', 5);
INSERT INTO tblcities VALUES (246, '15407', 'VILLA DE LEYVA', 5);
INSERT INTO tblcities VALUES (247, '15425', 'MACANAL', 5);
INSERT INTO tblcities VALUES (248, '15442', 'MARIPI', 5);
INSERT INTO tblcities VALUES (249, '15455', 'MIRAFLORES', 5);
INSERT INTO tblcities VALUES (250, '15464', 'MONGUA', 5);
INSERT INTO tblcities VALUES (251, '15466', 'MONGUI', 5);
INSERT INTO tblcities VALUES (252, '15469', 'MONIQUIRA', 5);
INSERT INTO tblcities VALUES (253, '15476', 'MOTAVITA', 5);
INSERT INTO tblcities VALUES (254, '15480', 'MUZO', 5);
INSERT INTO tblcities VALUES (255, '15491', 'NOBSA', 5);
INSERT INTO tblcities VALUES (256, '15494', 'NUEVO COLON', 5);
INSERT INTO tblcities VALUES (257, '15500', 'OICATA', 5);
INSERT INTO tblcities VALUES (258, '15507', 'OTANCHE', 5);
INSERT INTO tblcities VALUES (259, '15511', 'PACHAVITA', 5);
INSERT INTO tblcities VALUES (260, '15514', 'PAEZ', 5);
INSERT INTO tblcities VALUES (261, '15516', 'PAIPA', 5);
INSERT INTO tblcities VALUES (262, '15518', 'PAJARITO', 5);
INSERT INTO tblcities VALUES (263, '15522', 'PANQUEBA', 5);
INSERT INTO tblcities VALUES (264, '15531', 'PAUNA', 5);
INSERT INTO tblcities VALUES (265, '15533', 'PAYA', 5);
INSERT INTO tblcities VALUES (266, '15537', 'PAZ DE RIO', 5);
INSERT INTO tblcities VALUES (267, '15542', 'PESCA', 5);
INSERT INTO tblcities VALUES (268, '15550', 'PISBA', 5);
INSERT INTO tblcities VALUES (269, '15572', 'PUERTO BOYACA', 5);
INSERT INTO tblcities VALUES (270, '15580', 'QUIPAMA', 5);
INSERT INTO tblcities VALUES (271, '15599', 'RAMIRIQUI', 5);
INSERT INTO tblcities VALUES (272, '15600', 'RAQUIRA', 5);
INSERT INTO tblcities VALUES (273, '15621', 'RONDON', 5);
INSERT INTO tblcities VALUES (274, '15632', 'SABOYA', 5);
INSERT INTO tblcities VALUES (275, '15638', 'SACHICA', 5);
INSERT INTO tblcities VALUES (276, '15646', 'SAMACA', 5);
INSERT INTO tblcities VALUES (277, '15660', 'SAN EDUARDO', 5);
INSERT INTO tblcities VALUES (278, '15664', 'SAN JOSE DE PARE', 5);
INSERT INTO tblcities VALUES (279, '15667', 'SAN LUIS DE GACENO', 5);
INSERT INTO tblcities VALUES (280, '15673', 'SAN MATEO', 5);
INSERT INTO tblcities VALUES (281, '15676', 'SAN MIGUEL DE SEMA', 5);
INSERT INTO tblcities VALUES (282, '15681', 'SAN PABLO DE BORBUR', 5);
INSERT INTO tblcities VALUES (283, '15686', 'SANTANA', 5);
INSERT INTO tblcities VALUES (284, '15690', 'SANTA MARIA', 5);
INSERT INTO tblcities VALUES (285, '15693', 'SANTA ROSA DE VITERBO', 5);
INSERT INTO tblcities VALUES (286, '15696', 'SANTA SOFIA', 5);
INSERT INTO tblcities VALUES (287, '15720', 'SATIVANORTE', 5);
INSERT INTO tblcities VALUES (288, '15723', 'SATIVASUR', 5);
INSERT INTO tblcities VALUES (289, '15740', 'SIACHOQUE', 5);
INSERT INTO tblcities VALUES (290, '15753', 'SOATA', 5);
INSERT INTO tblcities VALUES (291, '15755', 'SOCOTA', 5);
INSERT INTO tblcities VALUES (292, '15757', 'SOCHA', 5);
INSERT INTO tblcities VALUES (293, '15759', 'SOGAMOSO', 5);
INSERT INTO tblcities VALUES (294, '15761', 'SOMONDOCO', 5);
INSERT INTO tblcities VALUES (295, '15762', 'SORA', 5);
INSERT INTO tblcities VALUES (296, '15763', 'SOTAQUIRA', 5);
INSERT INTO tblcities VALUES (297, '15764', 'SORACA', 5);
INSERT INTO tblcities VALUES (298, '15774', 'SUSACON', 5);
INSERT INTO tblcities VALUES (299, '15776', 'SUTAMARCHAN', 5);
INSERT INTO tblcities VALUES (300, '15778', 'SUTATENZA', 5);
INSERT INTO tblcities VALUES (301, '15790', 'TASCO', 5);
INSERT INTO tblcities VALUES (302, '15798', 'TENZA', 5);
INSERT INTO tblcities VALUES (303, '15804', 'TIBANA', 5);
INSERT INTO tblcities VALUES (304, '15806', 'TIBASOSA', 5);
INSERT INTO tblcities VALUES (305, '15808', 'TINJACA', 5);
INSERT INTO tblcities VALUES (306, '15810', 'TIPACOQUE', 5);
INSERT INTO tblcities VALUES (307, '15814', 'TOCA', 5);
INSERT INTO tblcities VALUES (308, '15816', 'TOGsI', 5);
INSERT INTO tblcities VALUES (309, '15820', 'TOPAGA', 5);
INSERT INTO tblcities VALUES (310, '15822', 'TOTA', 5);
INSERT INTO tblcities VALUES (311, '15832', 'TUNUNGUA', 5);
INSERT INTO tblcities VALUES (312, '15835', 'TURMEQUE', 5);
INSERT INTO tblcities VALUES (313, '15837', 'TUTA', 5);
INSERT INTO tblcities VALUES (314, '15839', 'TUTAZA', 5);
INSERT INTO tblcities VALUES (315, '15842', 'UMBITA', 5);
INSERT INTO tblcities VALUES (316, '15861', 'VENTAQUEMADA', 5);
INSERT INTO tblcities VALUES (317, '15879', 'VIRACACHA', 5);
INSERT INTO tblcities VALUES (318, '15897', 'ZETAQUIRA', 5);
INSERT INTO tblcities VALUES (319, '17001', 'MANIZALES', 6);
INSERT INTO tblcities VALUES (320, '17013', 'AGUADAS', 6);
INSERT INTO tblcities VALUES (321, '17042', 'ANSERMA', 6);
INSERT INTO tblcities VALUES (322, '17050', 'ARANZAZU', 6);
INSERT INTO tblcities VALUES (323, '17088', 'BELALCAZAR', 6);
INSERT INTO tblcities VALUES (324, '17174', 'CHINCHINA', 6);
INSERT INTO tblcities VALUES (325, '17272', 'FILADELFIA', 6);
INSERT INTO tblcities VALUES (326, '17380', 'LA DORADA', 6);
INSERT INTO tblcities VALUES (327, '17388', 'LA MERCED', 6);
INSERT INTO tblcities VALUES (328, '17433', 'MANZANARES', 6);
INSERT INTO tblcities VALUES (329, '17442', 'MARMATO', 6);
INSERT INTO tblcities VALUES (330, '17444', 'MARQUETALIA', 6);
INSERT INTO tblcities VALUES (331, '17446', 'MARULANDA', 6);
INSERT INTO tblcities VALUES (332, '17486', 'NEIRA', 6);
INSERT INTO tblcities VALUES (333, '17495', 'NORCASIA', 6);
INSERT INTO tblcities VALUES (334, '17513', 'PACORA', 6);
INSERT INTO tblcities VALUES (335, '17524', 'PALESTINA', 6);
INSERT INTO tblcities VALUES (336, '17541', 'PENSILVANIA', 6);
INSERT INTO tblcities VALUES (337, '17614', 'RIOSUCIO', 6);
INSERT INTO tblcities VALUES (338, '17616', 'RISARALDA', 6);
INSERT INTO tblcities VALUES (339, '17653', 'SALAMINA', 6);
INSERT INTO tblcities VALUES (340, '17662', 'SAMANA', 6);
INSERT INTO tblcities VALUES (341, '17665', 'SAN JOSE', 6);
INSERT INTO tblcities VALUES (342, '17777', 'SUPIA', 6);
INSERT INTO tblcities VALUES (343, '17867', 'VICTORIA', 6);
INSERT INTO tblcities VALUES (344, '17873', 'VILLAMARIA', 6);
INSERT INTO tblcities VALUES (345, '17877', 'VITERBO', 6);
INSERT INTO tblcities VALUES (346, '18001', 'FLORENCIA', 7);
INSERT INTO tblcities VALUES (347, '18029', 'ALBANIA', 7);
INSERT INTO tblcities VALUES (348, '18094', 'BELEN DE LOS ANDAQUIES', 7);
INSERT INTO tblcities VALUES (349, '18150', 'CARTAGENA DEL CHAIRA', 7);
INSERT INTO tblcities VALUES (350, '18205', 'CURILLO', 7);
INSERT INTO tblcities VALUES (351, '18247', 'EL DONCELLO', 7);
INSERT INTO tblcities VALUES (352, '18256', 'EL PAUJIL', 7);
INSERT INTO tblcities VALUES (353, '18410', 'LA MONTAÑITA', 7);
INSERT INTO tblcities VALUES (354, '18460', 'MILAN', 7);
INSERT INTO tblcities VALUES (355, '18479', 'MORELIA', 7);
INSERT INTO tblcities VALUES (356, '18592', 'PUERTO RICO', 7);
INSERT INTO tblcities VALUES (357, '18610', 'SAN JOSE DEL FRAGUA', 7);
INSERT INTO tblcities VALUES (358, '18753', 'SAN VICENTE DEL CAGUAN', 7);
INSERT INTO tblcities VALUES (359, '18756', 'SOLANO', 7);
INSERT INTO tblcities VALUES (360, '18785', 'SOLITA', 7);
INSERT INTO tblcities VALUES (361, '18860', 'VALPARAISO', 7);
INSERT INTO tblcities VALUES (362, '19001', 'POPAYAN', 8);
INSERT INTO tblcities VALUES (363, '19022', 'ALMAGUER', 8);
INSERT INTO tblcities VALUES (364, '19050', 'ARGELIA', 8);
INSERT INTO tblcities VALUES (365, '19075', 'BALBOA', 8);
INSERT INTO tblcities VALUES (366, '19100', 'BOLIVAR', 8);
INSERT INTO tblcities VALUES (367, '19110', 'BUENOS AIRES', 8);
INSERT INTO tblcities VALUES (368, '19130', 'CAJIBIO', 8);
INSERT INTO tblcities VALUES (369, '19137', 'CALDONO', 8);
INSERT INTO tblcities VALUES (370, '19142', 'CALOTO', 8);
INSERT INTO tblcities VALUES (371, '19212', 'CORINTO', 8);
INSERT INTO tblcities VALUES (372, '19256', 'EL TAMBO', 8);
INSERT INTO tblcities VALUES (373, '19290', 'FLORENCIA', 8);
INSERT INTO tblcities VALUES (374, '19300', 'GUACHENE', 8);
INSERT INTO tblcities VALUES (375, '19318', 'GUAPI', 8);
INSERT INTO tblcities VALUES (376, '19355', 'INZA', 8);
INSERT INTO tblcities VALUES (377, '19364', 'JAMBALO', 8);
INSERT INTO tblcities VALUES (378, '19392', 'LA SIERRA', 8);
INSERT INTO tblcities VALUES (379, '19397', 'LA VEGA', 8);
INSERT INTO tblcities VALUES (380, '19418', 'LOPEZ', 8);
INSERT INTO tblcities VALUES (381, '19450', 'MERCADERES', 8);
INSERT INTO tblcities VALUES (382, '19455', 'MIRANDA', 8);
INSERT INTO tblcities VALUES (383, '19473', 'MORALES', 8);
INSERT INTO tblcities VALUES (384, '19513', 'PADILLA', 8);
INSERT INTO tblcities VALUES (385, '19517', 'PAEZ', 8);
INSERT INTO tblcities VALUES (386, '19532', 'PATIA', 8);
INSERT INTO tblcities VALUES (387, '19533', 'PIAMONTE', 8);
INSERT INTO tblcities VALUES (388, '19548', 'PIENDAMO', 8);
INSERT INTO tblcities VALUES (389, '19573', 'PUERTO TEJADA', 8);
INSERT INTO tblcities VALUES (390, '19585', 'PURACE', 8);
INSERT INTO tblcities VALUES (391, '19622', 'ROSAS', 8);
INSERT INTO tblcities VALUES (392, '19693', 'SAN SEBASTIAN', 8);
INSERT INTO tblcities VALUES (393, '19698', 'SANTANDER DE QUILICHAO', 8);
INSERT INTO tblcities VALUES (394, '19701', 'SANTA ROSA', 8);
INSERT INTO tblcities VALUES (395, '19743', 'SILVIA', 8);
INSERT INTO tblcities VALUES (396, '19760', 'SOTARA', 8);
INSERT INTO tblcities VALUES (397, '19780', 'SUAREZ', 8);
INSERT INTO tblcities VALUES (398, '19785', 'SUCRE', 8);
INSERT INTO tblcities VALUES (399, '19807', 'TIMBIO', 8);
INSERT INTO tblcities VALUES (400, '19809', 'TIMBIQUI', 8);
INSERT INTO tblcities VALUES (401, '19821', 'TORIBIO', 8);
INSERT INTO tblcities VALUES (402, '19824', 'TOTORO', 8);
INSERT INTO tblcities VALUES (403, '19845', 'VILLA RICA', 8);
INSERT INTO tblcities VALUES (404, '20001', 'VALLEDUPAR', 9);
INSERT INTO tblcities VALUES (405, '20011', 'AGUACHICA', 9);
INSERT INTO tblcities VALUES (406, '20013', 'AGUSTIN CODAZZI', 9);
INSERT INTO tblcities VALUES (407, '20032', 'ASTREA', 9);
INSERT INTO tblcities VALUES (408, '20045', 'BECERRIL', 9);
INSERT INTO tblcities VALUES (409, '20060', 'BOSCONIA', 9);
INSERT INTO tblcities VALUES (410, '20175', 'CHIMICHAGUA', 9);
INSERT INTO tblcities VALUES (411, '20178', 'CHIRIGUANA', 9);
INSERT INTO tblcities VALUES (412, '20228', 'CURUMANI', 9);
INSERT INTO tblcities VALUES (413, '20238', 'EL COPEY', 9);
INSERT INTO tblcities VALUES (414, '20250', 'EL PASO', 9);
INSERT INTO tblcities VALUES (415, '20295', 'GAMARRA', 9);
INSERT INTO tblcities VALUES (416, '20310', 'GONZALEZ', 9);
INSERT INTO tblcities VALUES (417, '20383', 'LA GLORIA', 9);
INSERT INTO tblcities VALUES (418, '20400', 'LA JAGUA DE IBIRICO', 9);
INSERT INTO tblcities VALUES (419, '20443', 'MANAURE', 9);
INSERT INTO tblcities VALUES (420, '20517', 'PAILITAS', 9);
INSERT INTO tblcities VALUES (421, '20550', 'PELAYA', 9);
INSERT INTO tblcities VALUES (422, '20570', 'PUEBLO BELLO', 9);
INSERT INTO tblcities VALUES (423, '20614', 'RIO DE ORO', 9);
INSERT INTO tblcities VALUES (424, '20621', 'LA PAZ', 9);
INSERT INTO tblcities VALUES (425, '20710', 'SAN ALBERTO', 9);
INSERT INTO tblcities VALUES (426, '20750', 'SAN DIEGO', 9);
INSERT INTO tblcities VALUES (427, '20770', 'SAN MARTIN', 9);
INSERT INTO tblcities VALUES (428, '20787', 'TAMALAMEQUE', 9);
INSERT INTO tblcities VALUES (429, '23001', 'MONTERIA', 10);
INSERT INTO tblcities VALUES (430, '23068', 'AYAPEL', 10);
INSERT INTO tblcities VALUES (431, '23079', 'BUENAVISTA', 10);
INSERT INTO tblcities VALUES (432, '23090', 'CANALETE', 10);
INSERT INTO tblcities VALUES (433, '23162', 'CERETE', 10);
INSERT INTO tblcities VALUES (434, '23168', 'CHIMA', 10);
INSERT INTO tblcities VALUES (435, '23182', 'CHINU', 10);
INSERT INTO tblcities VALUES (436, '23189', 'CIENAGA DE ORO', 10);
INSERT INTO tblcities VALUES (437, '23300', 'COTORRA', 10);
INSERT INTO tblcities VALUES (438, '23350', 'LA APARTADA', 10);
INSERT INTO tblcities VALUES (439, '23417', 'LORICA', 10);
INSERT INTO tblcities VALUES (440, '23419', 'LOS CORDOBAS', 10);
INSERT INTO tblcities VALUES (441, '23464', 'MOMIL', 10);
INSERT INTO tblcities VALUES (442, '23466', 'MONTELIBANO', 10);
INSERT INTO tblcities VALUES (443, '23500', 'MOÑITOS', 10);
INSERT INTO tblcities VALUES (444, '23555', 'PLANETA RICA', 10);
INSERT INTO tblcities VALUES (445, '23570', 'PUEBLO NUEVO', 10);
INSERT INTO tblcities VALUES (446, '23574', 'PUERTO ESCONDIDO', 10);
INSERT INTO tblcities VALUES (447, '23580', 'PUERTO LIBERTADOR', 10);
INSERT INTO tblcities VALUES (448, '23586', 'PURISIMA', 10);
INSERT INTO tblcities VALUES (449, '23660', 'SAHAGUN', 10);
INSERT INTO tblcities VALUES (450, '23670', 'SAN ANDRES SOTAVENTO', 10);
INSERT INTO tblcities VALUES (451, '23672', 'SAN ANTERO', 10);
INSERT INTO tblcities VALUES (452, '23675', 'SAN BERNARDO DEL VIENTO', 10);
INSERT INTO tblcities VALUES (453, '23678', 'SAN CARLOS', 10);
INSERT INTO tblcities VALUES (454, '23686', 'SAN PELAYO', 10);
INSERT INTO tblcities VALUES (455, '23807', 'TIERRALTA', 10);
INSERT INTO tblcities VALUES (456, '23855', 'VALENCIA', 10);
INSERT INTO tblcities VALUES (457, '25001', 'AGUA DE DIOS', 11);
INSERT INTO tblcities VALUES (458, '25019', 'ALBAN', 11);
INSERT INTO tblcities VALUES (459, '25035', 'ANAPOIMA', 11);
INSERT INTO tblcities VALUES (460, '25040', 'ANOLAIMA', 11);
INSERT INTO tblcities VALUES (461, '25053', 'ARBELAEZ', 11);
INSERT INTO tblcities VALUES (462, '25086', 'BELTRAN', 11);
INSERT INTO tblcities VALUES (463, '25095', 'BITUIMA', 11);
INSERT INTO tblcities VALUES (464, '25099', 'BOJACA', 11);
INSERT INTO tblcities VALUES (465, '25120', 'CABRERA', 11);
INSERT INTO tblcities VALUES (466, '25123', 'CACHIPAY', 11);
INSERT INTO tblcities VALUES (467, '25126', 'CAJICA', 11);
INSERT INTO tblcities VALUES (468, '25148', 'CAPARRAPI', 11);
INSERT INTO tblcities VALUES (469, '25151', 'CAQUEZA', 11);
INSERT INTO tblcities VALUES (470, '25154', 'CARMEN DE CARUPA', 11);
INSERT INTO tblcities VALUES (471, '25168', 'CHAGUANI', 11);
INSERT INTO tblcities VALUES (472, '25175', 'CHIA', 11);
INSERT INTO tblcities VALUES (473, '25178', 'CHIPAQUE', 11);
INSERT INTO tblcities VALUES (474, '25181', 'CHOACHI', 11);
INSERT INTO tblcities VALUES (475, '25183', 'CHOCONTA', 11);
INSERT INTO tblcities VALUES (476, '25200', 'COGUA', 11);
INSERT INTO tblcities VALUES (477, '25214', 'COTA', 11);
INSERT INTO tblcities VALUES (478, '25224', 'CUCUNUBA', 11);
INSERT INTO tblcities VALUES (479, '25245', 'EL COLEGIO', 11);
INSERT INTO tblcities VALUES (480, '25258', 'EL PEÑON', 11);
INSERT INTO tblcities VALUES (481, '25260', 'EL ROSAL', 11);
INSERT INTO tblcities VALUES (482, '25269', 'FACATATIVA', 11);
INSERT INTO tblcities VALUES (483, '25279', 'FOMEQUE', 11);
INSERT INTO tblcities VALUES (484, '25281', 'FOSCA', 11);
INSERT INTO tblcities VALUES (485, '25286', 'FUNZA', 11);
INSERT INTO tblcities VALUES (486, '25288', 'FUQUENE', 11);
INSERT INTO tblcities VALUES (487, '25290', 'FUSAGASUGA', 11);
INSERT INTO tblcities VALUES (488, '25293', 'GACHALA', 11);
INSERT INTO tblcities VALUES (489, '25295', 'GACHANCIPA', 11);
INSERT INTO tblcities VALUES (490, '25297', 'GACHETA', 11);
INSERT INTO tblcities VALUES (491, '25299', 'GAMA', 11);
INSERT INTO tblcities VALUES (492, '25307', 'GIRARDOT', 11);
INSERT INTO tblcities VALUES (493, '25312', 'GRANADA', 11);
INSERT INTO tblcities VALUES (494, '25317', 'GUACHETA', 11);
INSERT INTO tblcities VALUES (495, '25320', 'GUADUAS', 11);
INSERT INTO tblcities VALUES (496, '25322', 'GUASCA', 11);
INSERT INTO tblcities VALUES (497, '25324', 'GUATAQUI', 11);
INSERT INTO tblcities VALUES (498, '25326', 'GUATAVITA', 11);
INSERT INTO tblcities VALUES (499, '25328', 'GUAYABAL DE SIQUIMA', 11);
INSERT INTO tblcities VALUES (500, '25335', 'GUAYABETAL', 11);
INSERT INTO tblcities VALUES (501, '25339', 'GUTIERREZ', 11);
INSERT INTO tblcities VALUES (502, '25368', 'JERUSALEN', 11);
INSERT INTO tblcities VALUES (503, '25372', 'JUNIN', 11);
INSERT INTO tblcities VALUES (504, '25377', 'LA CALERA', 11);
INSERT INTO tblcities VALUES (505, '25386', 'LA MESA', 11);
INSERT INTO tblcities VALUES (506, '25394', 'LA PALMA', 11);
INSERT INTO tblcities VALUES (507, '25398', 'LA PEÑA', 11);
INSERT INTO tblcities VALUES (508, '25402', 'LA VEGA', 11);
INSERT INTO tblcities VALUES (509, '25407', 'LENGUAZAQUE', 11);
INSERT INTO tblcities VALUES (510, '25426', 'MACHETA', 11);
INSERT INTO tblcities VALUES (511, '25430', 'MADRID', 11);
INSERT INTO tblcities VALUES (512, '25436', 'MANTA', 11);
INSERT INTO tblcities VALUES (513, '25438', 'MEDINA', 11);
INSERT INTO tblcities VALUES (514, '25473', 'MOSQUERA', 11);
INSERT INTO tblcities VALUES (515, '25483', 'NARIÑO', 11);
INSERT INTO tblcities VALUES (516, '25486', 'NEMOCON', 11);
INSERT INTO tblcities VALUES (517, '25488', 'NILO', 11);
INSERT INTO tblcities VALUES (518, '25489', 'NIMAIMA', 11);
INSERT INTO tblcities VALUES (519, '25491', 'NOCAIMA', 11);
INSERT INTO tblcities VALUES (520, '25506', 'VENECIA', 11);
INSERT INTO tblcities VALUES (521, '25513', 'PACHO', 11);
INSERT INTO tblcities VALUES (522, '25518', 'PAIME', 11);
INSERT INTO tblcities VALUES (523, '25524', 'PANDI', 11);
INSERT INTO tblcities VALUES (524, '25530', 'PARATEBUENO', 11);
INSERT INTO tblcities VALUES (525, '25535', 'PASCA', 11);
INSERT INTO tblcities VALUES (526, '25572', 'PUERTO SALGAR', 11);
INSERT INTO tblcities VALUES (527, '25580', 'PULI', 11);
INSERT INTO tblcities VALUES (528, '25592', 'QUEBRADANEGRA', 11);
INSERT INTO tblcities VALUES (529, '25594', 'QUETAME', 11);
INSERT INTO tblcities VALUES (530, '25596', 'QUIPILE', 11);
INSERT INTO tblcities VALUES (531, '25599', 'APULO', 11);
INSERT INTO tblcities VALUES (532, '25612', 'RICAURTE', 11);
INSERT INTO tblcities VALUES (533, '25645', 'SAN ANTONIO DEL TEQUENDAMA', 11);
INSERT INTO tblcities VALUES (534, '25649', 'SAN BERNARDO', 11);
INSERT INTO tblcities VALUES (535, '25653', 'SAN CAYETANO', 11);
INSERT INTO tblcities VALUES (536, '25658', 'SAN FRANCISCO', 11);
INSERT INTO tblcities VALUES (537, '25662', 'SAN JUAN DE RIO SECO', 11);
INSERT INTO tblcities VALUES (538, '25718', 'SASAIMA', 11);
INSERT INTO tblcities VALUES (539, '25736', 'SESQUILE', 11);
INSERT INTO tblcities VALUES (540, '25740', 'SIBATE', 11);
INSERT INTO tblcities VALUES (541, '25743', 'SILVANIA', 11);
INSERT INTO tblcities VALUES (542, '25745', 'SIMIJACA', 11);
INSERT INTO tblcities VALUES (543, '25754', 'SOACHA', 11);
INSERT INTO tblcities VALUES (544, '25758', 'SOPO', 11);
INSERT INTO tblcities VALUES (545, '25769', 'SUBACHOQUE', 11);
INSERT INTO tblcities VALUES (546, '25772', 'SUESCA', 11);
INSERT INTO tblcities VALUES (547, '25777', 'SUPATA', 11);
INSERT INTO tblcities VALUES (548, '25779', 'SUSA', 11);
INSERT INTO tblcities VALUES (549, '25781', 'SUTATAUSA', 11);
INSERT INTO tblcities VALUES (550, '25785', 'TABIO', 11);
INSERT INTO tblcities VALUES (551, '25793', 'TAUSA', 11);
INSERT INTO tblcities VALUES (552, '25797', 'TENA', 11);
INSERT INTO tblcities VALUES (553, '25799', 'TENJO', 11);
INSERT INTO tblcities VALUES (554, '25805', 'TIBACUY', 11);
INSERT INTO tblcities VALUES (555, '25807', 'TIBIRITA', 11);
INSERT INTO tblcities VALUES (556, '25815', 'TOCAIMA', 11);
INSERT INTO tblcities VALUES (557, '25817', 'TOCANCIPA', 11);
INSERT INTO tblcities VALUES (558, '25823', 'TOPAIPI', 11);
INSERT INTO tblcities VALUES (559, '25839', 'UBALA', 11);
INSERT INTO tblcities VALUES (560, '25841', 'UBAQUE', 11);
INSERT INTO tblcities VALUES (561, '25843', 'VILLA DE SAN DIEGO DE UBATE', 11);
INSERT INTO tblcities VALUES (562, '25845', 'UNE', 11);
INSERT INTO tblcities VALUES (563, '25851', 'UTICA', 11);
INSERT INTO tblcities VALUES (564, '25862', 'VERGARA', 11);
INSERT INTO tblcities VALUES (565, '25867', 'VIANI', 11);
INSERT INTO tblcities VALUES (566, '25871', 'VILLAGOMEZ', 11);
INSERT INTO tblcities VALUES (567, '25873', 'VILLAPINZON', 11);
INSERT INTO tblcities VALUES (568, '25875', 'VILLETA', 11);
INSERT INTO tblcities VALUES (569, '25878', 'VIOTA', 11);
INSERT INTO tblcities VALUES (570, '25885', 'YACOPI', 11);
INSERT INTO tblcities VALUES (571, '25898', 'ZIPACON', 11);
INSERT INTO tblcities VALUES (572, '25899', 'ZIPAQUIRA', 11);
INSERT INTO tblcities VALUES (573, '27001', 'QUIBDO', 12);
INSERT INTO tblcities VALUES (574, '27006', 'ACANDI', 12);
INSERT INTO tblcities VALUES (575, '27025', 'ALTO BAUDO', 12);
INSERT INTO tblcities VALUES (576, '27050', 'ATRATO', 12);
INSERT INTO tblcities VALUES (577, '27073', 'BAGADO', 12);
INSERT INTO tblcities VALUES (578, '27075', 'BAHIA SOLANO', 12);
INSERT INTO tblcities VALUES (579, '27077', 'BAJO BAUDO', 12);
INSERT INTO tblcities VALUES (580, '27099', 'BOJAYA', 12);
INSERT INTO tblcities VALUES (581, '27135', 'EL CANTON DEL SAN PABLO', 12);
INSERT INTO tblcities VALUES (582, '27150', 'CARMEN DEL DARIEN', 12);
INSERT INTO tblcities VALUES (583, '27160', 'CERTEGUI', 12);
INSERT INTO tblcities VALUES (584, '27205', 'CONDOTO', 12);
INSERT INTO tblcities VALUES (585, '27245', 'EL CARMEN DE ATRATO', 12);
INSERT INTO tblcities VALUES (586, '27250', 'EL LITORAL DEL SAN JUAN', 12);
INSERT INTO tblcities VALUES (587, '27361', 'ISTMINA', 12);
INSERT INTO tblcities VALUES (588, '27372', 'JURADO', 12);
INSERT INTO tblcities VALUES (589, '27413', 'LLORO', 12);
INSERT INTO tblcities VALUES (590, '27425', 'MEDIO ATRATO', 12);
INSERT INTO tblcities VALUES (591, '27430', 'MEDIO BAUDO', 12);
INSERT INTO tblcities VALUES (592, '27450', 'MEDIO SAN JUAN', 12);
INSERT INTO tblcities VALUES (593, '27491', 'NOVITA', 12);
INSERT INTO tblcities VALUES (594, '27495', 'NUQUI', 12);
INSERT INTO tblcities VALUES (595, '27580', 'RIO IRO', 12);
INSERT INTO tblcities VALUES (596, '27600', 'RIO QUITO', 12);
INSERT INTO tblcities VALUES (597, '27615', 'RIOSUCIO', 12);
INSERT INTO tblcities VALUES (598, '27660', 'SAN JOSE DEL PALMAR', 12);
INSERT INTO tblcities VALUES (599, '27745', 'SIPI', 12);
INSERT INTO tblcities VALUES (600, '27787', 'TADO', 12);
INSERT INTO tblcities VALUES (601, '27800', 'UNGUIA', 12);
INSERT INTO tblcities VALUES (602, '27810', 'UNION PANAMERICANA', 12);
INSERT INTO tblcities VALUES (603, '41001', 'NEIVA', 13);
INSERT INTO tblcities VALUES (604, '41006', 'ACEVEDO', 13);
INSERT INTO tblcities VALUES (605, '41013', 'AGRADO', 13);
INSERT INTO tblcities VALUES (606, '41016', 'AIPE', 13);
INSERT INTO tblcities VALUES (607, '41020', 'ALGECIRAS', 13);
INSERT INTO tblcities VALUES (608, '41026', 'ALTAMIRA', 13);
INSERT INTO tblcities VALUES (609, '41078', 'BARAYA', 13);
INSERT INTO tblcities VALUES (610, '41132', 'CAMPOALEGRE', 13);
INSERT INTO tblcities VALUES (611, '41206', 'COLOMBIA', 13);
INSERT INTO tblcities VALUES (612, '41244', 'ELIAS', 13);
INSERT INTO tblcities VALUES (613, '41298', 'GARZON', 13);
INSERT INTO tblcities VALUES (614, '41306', 'GIGANTE', 13);
INSERT INTO tblcities VALUES (615, '41319', 'GUADALUPE', 13);
INSERT INTO tblcities VALUES (616, '41349', 'HOBO', 13);
INSERT INTO tblcities VALUES (617, '41357', 'IQUIRA', 13);
INSERT INTO tblcities VALUES (618, '41359', 'ISNOS', 13);
INSERT INTO tblcities VALUES (619, '41378', 'LA ARGENTINA', 13);
INSERT INTO tblcities VALUES (620, '41396', 'LA PLATA', 13);
INSERT INTO tblcities VALUES (621, '41483', 'NATAGA', 13);
INSERT INTO tblcities VALUES (622, '41503', 'OPORAPA', 13);
INSERT INTO tblcities VALUES (623, '41518', 'PAICOL', 13);
INSERT INTO tblcities VALUES (624, '41524', 'PALERMO', 13);
INSERT INTO tblcities VALUES (625, '41530', 'PALESTINA', 13);
INSERT INTO tblcities VALUES (626, '41548', 'PITAL', 13);
INSERT INTO tblcities VALUES (627, '41551', 'PITALITO', 13);
INSERT INTO tblcities VALUES (628, '41615', 'RIVERA', 13);
INSERT INTO tblcities VALUES (629, '41660', 'SALADOBLANCO', 13);
INSERT INTO tblcities VALUES (630, '41668', 'SAN AGUSTIN', 13);
INSERT INTO tblcities VALUES (631, '41676', 'SANTA MARIA', 13);
INSERT INTO tblcities VALUES (632, '41770', 'SUAZA', 13);
INSERT INTO tblcities VALUES (633, '41791', 'TARQUI', 13);
INSERT INTO tblcities VALUES (634, '41797', 'TESALIA', 13);
INSERT INTO tblcities VALUES (635, '41799', 'TELLO', 13);
INSERT INTO tblcities VALUES (636, '41801', 'TERUEL', 13);
INSERT INTO tblcities VALUES (637, '41807', 'TIMANA', 13);
INSERT INTO tblcities VALUES (638, '41872', 'VILLAVIEJA', 13);
INSERT INTO tblcities VALUES (639, '41885', 'YAGUARA', 13);
INSERT INTO tblcities VALUES (640, '44001', 'RIOHACHA', 14);
INSERT INTO tblcities VALUES (641, '44035', 'ALBANIA', 14);
INSERT INTO tblcities VALUES (642, '44078', 'BARRANCAS', 14);
INSERT INTO tblcities VALUES (643, '44090', 'DIBULLA', 14);
INSERT INTO tblcities VALUES (644, '44098', 'DISTRACCION', 14);
INSERT INTO tblcities VALUES (645, '44110', 'EL MOLINO', 14);
INSERT INTO tblcities VALUES (646, '44279', 'FONSECA', 14);
INSERT INTO tblcities VALUES (647, '44378', 'HATONUEVO', 14);
INSERT INTO tblcities VALUES (648, '44420', 'LA JAGUA DEL PILAR', 14);
INSERT INTO tblcities VALUES (649, '44430', 'MAICAO', 14);
INSERT INTO tblcities VALUES (650, '44560', 'MANAURE', 14);
INSERT INTO tblcities VALUES (651, '44650', 'SAN JUAN DEL CESAR', 14);
INSERT INTO tblcities VALUES (652, '44847', 'URIBIA', 14);
INSERT INTO tblcities VALUES (653, '44855', 'URUMITA', 14);
INSERT INTO tblcities VALUES (654, '44874', 'VILLANUEVA', 14);
INSERT INTO tblcities VALUES (655, '47001', 'SANTA MARTA', 15);
INSERT INTO tblcities VALUES (656, '47030', 'ALGARROBO', 15);
INSERT INTO tblcities VALUES (657, '47053', 'ARACATACA', 15);
INSERT INTO tblcities VALUES (658, '47058', 'ARIGUANI', 15);
INSERT INTO tblcities VALUES (659, '47161', 'CERRO SAN ANTONIO', 15);
INSERT INTO tblcities VALUES (660, '47170', 'CHIBOLO', 15);
INSERT INTO tblcities VALUES (661, '47189', 'CIENAGA', 15);
INSERT INTO tblcities VALUES (662, '47205', 'CONCORDIA', 15);
INSERT INTO tblcities VALUES (663, '47245', 'EL BANCO', 15);
INSERT INTO tblcities VALUES (664, '47258', 'EL PIÑON', 15);
INSERT INTO tblcities VALUES (665, '47268', 'EL RETEN', 15);
INSERT INTO tblcities VALUES (666, '47288', 'FUNDACION', 15);
INSERT INTO tblcities VALUES (667, '47318', 'GUAMAL', 15);
INSERT INTO tblcities VALUES (668, '47460', 'NUEVA GRANADA', 15);
INSERT INTO tblcities VALUES (669, '47541', 'PEDRAZA', 15);
INSERT INTO tblcities VALUES (670, '47545', 'PIJIÑO DEL CARMEN', 15);
INSERT INTO tblcities VALUES (671, '47551', 'PIVIJAY', 15);
INSERT INTO tblcities VALUES (672, '47555', 'PLATO', 15);
INSERT INTO tblcities VALUES (673, '47570', 'PUEBLOVIEJO', 15);
INSERT INTO tblcities VALUES (674, '47605', 'REMOLINO', 15);
INSERT INTO tblcities VALUES (675, '47660', 'SABANAS DE SAN ANGEL', 15);
INSERT INTO tblcities VALUES (676, '47675', 'SALAMINA', 15);
INSERT INTO tblcities VALUES (677, '47692', 'SAN SEBASTIAN DE BUENAVISTA', 15);
INSERT INTO tblcities VALUES (678, '47703', 'SAN ZENON', 15);
INSERT INTO tblcities VALUES (679, '47707', 'SANTA ANA', 15);
INSERT INTO tblcities VALUES (680, '47720', 'SANTA BARBARA DE PINTO', 15);
INSERT INTO tblcities VALUES (681, '47745', 'SITIONUEVO', 15);
INSERT INTO tblcities VALUES (682, '47798', 'TENERIFE', 15);
INSERT INTO tblcities VALUES (683, '47960', 'ZAPAYAN', 15);
INSERT INTO tblcities VALUES (684, '47980', 'ZONA BANANERA', 15);
INSERT INTO tblcities VALUES (685, '50001', 'VILLAVICENCIO', 16);
INSERT INTO tblcities VALUES (686, '50006', 'ACACIAS', 16);
INSERT INTO tblcities VALUES (687, '50110', 'BARRANCA DE UPIA', 16);
INSERT INTO tblcities VALUES (688, '50124', 'CABUYARO', 16);
INSERT INTO tblcities VALUES (689, '50150', 'CASTILLA LA NUEVA', 16);
INSERT INTO tblcities VALUES (690, '50223', 'CUBARRAL', 16);
INSERT INTO tblcities VALUES (691, '50226', 'CUMARAL', 16);
INSERT INTO tblcities VALUES (692, '50245', 'EL CALVARIO', 16);
INSERT INTO tblcities VALUES (693, '50251', 'EL CASTILLO', 16);
INSERT INTO tblcities VALUES (694, '50270', 'EL DORADO', 16);
INSERT INTO tblcities VALUES (695, '50287', 'FUENTE DE ORO', 16);
INSERT INTO tblcities VALUES (696, '50313', 'GRANADA', 16);
INSERT INTO tblcities VALUES (697, '50318', 'GUAMAL', 16);
INSERT INTO tblcities VALUES (698, '50325', 'MAPIRIPAN', 16);
INSERT INTO tblcities VALUES (699, '50330', 'MESETAS', 16);
INSERT INTO tblcities VALUES (700, '50350', 'LA MACARENA', 16);
INSERT INTO tblcities VALUES (701, '50370', 'URIBE', 16);
INSERT INTO tblcities VALUES (702, '50400', 'LEJANIAS', 16);
INSERT INTO tblcities VALUES (703, '50450', 'PUERTO CONCORDIA', 16);
INSERT INTO tblcities VALUES (704, '50568', 'PUERTO GAITAN', 16);
INSERT INTO tblcities VALUES (705, '50573', 'PUERTO LOPEZ', 16);
INSERT INTO tblcities VALUES (706, '50577', 'PUERTO LLERAS', 16);
INSERT INTO tblcities VALUES (707, '50590', 'PUERTO RICO', 16);
INSERT INTO tblcities VALUES (708, '50606', 'RESTREPO', 16);
INSERT INTO tblcities VALUES (709, '50680', 'SAN CARLOS DE GUAROA', 16);
INSERT INTO tblcities VALUES (710, '50683', 'SAN JUAN DE ARAMA', 16);
INSERT INTO tblcities VALUES (711, '50686', 'SAN JUANITO', 16);
INSERT INTO tblcities VALUES (712, '50689', 'SAN MARTIN', 16);
INSERT INTO tblcities VALUES (713, '50711', 'VISTAHERMOSA', 16);
INSERT INTO tblcities VALUES (714, '52001', 'PASTO', 17);
INSERT INTO tblcities VALUES (715, '52019', 'ALBAN', 17);
INSERT INTO tblcities VALUES (716, '52022', 'ALDANA', 17);
INSERT INTO tblcities VALUES (717, '52036', 'ANCUYA', 17);
INSERT INTO tblcities VALUES (718, '52051', 'ARBOLEDA', 17);
INSERT INTO tblcities VALUES (719, '52079', 'BARBACOAS', 17);
INSERT INTO tblcities VALUES (720, '52083', 'BELEN', 17);
INSERT INTO tblcities VALUES (721, '52110', 'BUESACO', 17);
INSERT INTO tblcities VALUES (722, '52203', 'COLON', 17);
INSERT INTO tblcities VALUES (723, '52207', 'CONSACA', 17);
INSERT INTO tblcities VALUES (724, '52210', 'CONTADERO', 17);
INSERT INTO tblcities VALUES (725, '52215', 'CORDOBA', 17);
INSERT INTO tblcities VALUES (726, '52224', 'CUASPUD', 17);
INSERT INTO tblcities VALUES (727, '52227', 'CUMBAL', 17);
INSERT INTO tblcities VALUES (728, '52233', 'CUMBITARA', 17);
INSERT INTO tblcities VALUES (729, '52240', 'CHACHAGsI', 17);
INSERT INTO tblcities VALUES (730, '52250', 'EL CHARCO', 17);
INSERT INTO tblcities VALUES (731, '52254', 'EL PEÑOL', 17);
INSERT INTO tblcities VALUES (732, '52256', 'EL ROSARIO', 17);
INSERT INTO tblcities VALUES (733, '52258', 'EL TABLON DE GOMEZ', 17);
INSERT INTO tblcities VALUES (734, '52260', 'EL TAMBO', 17);
INSERT INTO tblcities VALUES (735, '52287', 'FUNES', 17);
INSERT INTO tblcities VALUES (736, '52317', 'GUACHUCAL', 17);
INSERT INTO tblcities VALUES (737, '52320', 'GUAITARILLA', 17);
INSERT INTO tblcities VALUES (738, '52323', 'GUALMATAN', 17);
INSERT INTO tblcities VALUES (739, '52352', 'ILES', 17);
INSERT INTO tblcities VALUES (740, '52354', 'IMUES', 17);
INSERT INTO tblcities VALUES (741, '52356', 'IPIALES', 17);
INSERT INTO tblcities VALUES (742, '52378', 'LA CRUZ', 17);
INSERT INTO tblcities VALUES (743, '52381', 'LA FLORIDA', 17);
INSERT INTO tblcities VALUES (744, '52385', 'LA LLANADA', 17);
INSERT INTO tblcities VALUES (745, '52390', 'LA TOLA', 17);
INSERT INTO tblcities VALUES (746, '52399', 'LA UNION', 17);
INSERT INTO tblcities VALUES (747, '52405', 'LEIVA', 17);
INSERT INTO tblcities VALUES (748, '52411', 'LINARES', 17);
INSERT INTO tblcities VALUES (749, '52418', 'LOS ANDES', 17);
INSERT INTO tblcities VALUES (750, '52427', 'MAGsI', 17);
INSERT INTO tblcities VALUES (751, '52435', 'MALLAMA', 17);
INSERT INTO tblcities VALUES (752, '52473', 'MOSQUERA', 17);
INSERT INTO tblcities VALUES (753, '52480', 'NARIÑO', 17);
INSERT INTO tblcities VALUES (754, '52490', 'OLAYA HERRERA', 17);
INSERT INTO tblcities VALUES (755, '52506', 'OSPINA', 17);
INSERT INTO tblcities VALUES (756, '52520', 'FRANCISCO PIZARRO', 17);
INSERT INTO tblcities VALUES (757, '52540', 'POLICARPA', 17);
INSERT INTO tblcities VALUES (758, '52560', 'POTOSI', 17);
INSERT INTO tblcities VALUES (759, '52565', 'PROVIDENCIA', 17);
INSERT INTO tblcities VALUES (760, '52573', 'PUERRES', 17);
INSERT INTO tblcities VALUES (761, '52585', 'PUPIALES', 17);
INSERT INTO tblcities VALUES (762, '52612', 'RICAURTE', 17);
INSERT INTO tblcities VALUES (763, '52621', 'ROBERTO PAYAN', 17);
INSERT INTO tblcities VALUES (764, '52678', 'SAMANIEGO', 17);
INSERT INTO tblcities VALUES (765, '52683', 'SANDONA', 17);
INSERT INTO tblcities VALUES (766, '52685', 'SAN BERNARDO', 17);
INSERT INTO tblcities VALUES (767, '52687', 'SAN LORENZO', 17);
INSERT INTO tblcities VALUES (768, '52693', 'SAN PABLO', 17);
INSERT INTO tblcities VALUES (769, '52694', 'SAN PEDRO DE CARTAGO', 17);
INSERT INTO tblcities VALUES (770, '52696', 'SANTA BARBARA', 17);
INSERT INTO tblcities VALUES (771, '52699', 'SANTACRUZ', 17);
INSERT INTO tblcities VALUES (772, '52720', 'SAPUYES', 17);
INSERT INTO tblcities VALUES (773, '52786', 'TAMINANGO', 17);
INSERT INTO tblcities VALUES (774, '52788', 'TANGUA', 17);
INSERT INTO tblcities VALUES (775, '52835', 'SAN ANDRES DE TUMACO', 17);
INSERT INTO tblcities VALUES (776, '52838', 'TUQUERRES', 17);
INSERT INTO tblcities VALUES (777, '52885', 'YACUANQUER', 17);
INSERT INTO tblcities VALUES (778, '54001', 'CUCUTA', 18);
INSERT INTO tblcities VALUES (779, '54003', 'ABREGO', 18);
INSERT INTO tblcities VALUES (780, '54051', 'ARBOLEDAS', 18);
INSERT INTO tblcities VALUES (781, '54099', 'BOCHALEMA', 18);
INSERT INTO tblcities VALUES (782, '54109', 'BUCARASICA', 18);
INSERT INTO tblcities VALUES (783, '54125', 'CACOTA', 18);
INSERT INTO tblcities VALUES (784, '54128', 'CACHIRA', 18);
INSERT INTO tblcities VALUES (785, '54172', 'CHINACOTA', 18);
INSERT INTO tblcities VALUES (786, '54174', 'CHITAGA', 18);
INSERT INTO tblcities VALUES (787, '54206', 'CONVENCION', 18);
INSERT INTO tblcities VALUES (788, '54223', 'CUCUTILLA', 18);
INSERT INTO tblcities VALUES (789, '54239', 'DURANIA', 18);
INSERT INTO tblcities VALUES (790, '54245', 'EL CARMEN', 18);
INSERT INTO tblcities VALUES (791, '54250', 'EL TARRA', 18);
INSERT INTO tblcities VALUES (792, '54261', 'EL ZULIA', 18);
INSERT INTO tblcities VALUES (793, '54313', 'GRAMALOTE', 18);
INSERT INTO tblcities VALUES (794, '54344', 'HACARI', 18);
INSERT INTO tblcities VALUES (795, '54347', 'HERRAN', 18);
INSERT INTO tblcities VALUES (796, '54377', 'LABATECA', 18);
INSERT INTO tblcities VALUES (797, '54385', 'LA ESPERANZA', 18);
INSERT INTO tblcities VALUES (798, '54398', 'LA PLAYA', 18);
INSERT INTO tblcities VALUES (799, '54405', 'LOS PATIOS', 18);
INSERT INTO tblcities VALUES (800, '54418', 'LOURDES', 18);
INSERT INTO tblcities VALUES (801, '54480', 'MUTISCUA', 18);
INSERT INTO tblcities VALUES (802, '54498', 'OCAÑA', 18);
INSERT INTO tblcities VALUES (803, '54518', 'PAMPLONA', 18);
INSERT INTO tblcities VALUES (804, '54520', 'PAMPLONITA', 18);
INSERT INTO tblcities VALUES (805, '54553', 'PUERTO SANTANDER', 18);
INSERT INTO tblcities VALUES (806, '54599', 'RAGONVALIA', 18);
INSERT INTO tblcities VALUES (807, '54660', 'SALAZAR', 18);
INSERT INTO tblcities VALUES (808, '54670', 'SAN CALIXTO', 18);
INSERT INTO tblcities VALUES (809, '54673', 'SAN CAYETANO', 18);
INSERT INTO tblcities VALUES (810, '54680', 'SANTIAGO', 18);
INSERT INTO tblcities VALUES (811, '54720', 'SARDINATA', 18);
INSERT INTO tblcities VALUES (812, '54743', 'SILOS', 18);
INSERT INTO tblcities VALUES (813, '54800', 'TEORAMA', 18);
INSERT INTO tblcities VALUES (814, '54810', 'TIBU', 18);
INSERT INTO tblcities VALUES (815, '54820', 'TOLEDO', 18);
INSERT INTO tblcities VALUES (816, '54871', 'VILLA CARO', 18);
INSERT INTO tblcities VALUES (817, '54874', 'VILLA DEL ROSARIO', 18);
INSERT INTO tblcities VALUES (818, '63001', 'ARMENIA', 19);
INSERT INTO tblcities VALUES (819, '63111', 'BUENAVISTA', 19);
INSERT INTO tblcities VALUES (820, '63130', 'CALARCA', 19);
INSERT INTO tblcities VALUES (821, '63190', 'CIRCASIA', 19);
INSERT INTO tblcities VALUES (822, '63212', 'CORDOBA', 19);
INSERT INTO tblcities VALUES (823, '63272', 'FILANDIA', 19);
INSERT INTO tblcities VALUES (824, '63302', 'GENOVA', 19);
INSERT INTO tblcities VALUES (825, '63401', 'LA TEBAIDA', 19);
INSERT INTO tblcities VALUES (826, '63470', 'MONTENEGRO', 19);
INSERT INTO tblcities VALUES (827, '63548', 'PIJAO', 19);
INSERT INTO tblcities VALUES (828, '63594', 'QUIMBAYA', 19);
INSERT INTO tblcities VALUES (829, '63690', 'SALENTO', 19);
INSERT INTO tblcities VALUES (830, '66001', 'PEREIRA', 20);
INSERT INTO tblcities VALUES (831, '66045', 'APIA', 20);
INSERT INTO tblcities VALUES (832, '66075', 'BALBOA', 20);
INSERT INTO tblcities VALUES (833, '66088', 'BELEN DE UMBRIA', 20);
INSERT INTO tblcities VALUES (834, '66170', 'DOSQUEBRADAS', 20);
INSERT INTO tblcities VALUES (835, '66318', 'GUATICA', 20);
INSERT INTO tblcities VALUES (836, '66383', 'LA CELIA', 20);
INSERT INTO tblcities VALUES (837, '66400', 'LA VIRGINIA', 20);
INSERT INTO tblcities VALUES (838, '66440', 'MARSELLA', 20);
INSERT INTO tblcities VALUES (839, '66456', 'MISTRATO', 20);
INSERT INTO tblcities VALUES (840, '66572', 'PUEBLO RICO', 20);
INSERT INTO tblcities VALUES (841, '66594', 'QUINCHIA', 20);
INSERT INTO tblcities VALUES (842, '66682', 'SANTA ROSA DE CABAL', 20);
INSERT INTO tblcities VALUES (843, '66687', 'SANTUARIO', 20);
INSERT INTO tblcities VALUES (844, '68001', 'BUCARAMANGA', 21);
INSERT INTO tblcities VALUES (845, '68013', 'AGUADA', 21);
INSERT INTO tblcities VALUES (846, '68020', 'ALBANIA', 21);
INSERT INTO tblcities VALUES (847, '68051', 'ARATOCA', 21);
INSERT INTO tblcities VALUES (848, '68077', 'BARBOSA', 21);
INSERT INTO tblcities VALUES (849, '68079', 'BARICHARA', 21);
INSERT INTO tblcities VALUES (850, '68081', 'BARRANCABERMEJA', 21);
INSERT INTO tblcities VALUES (851, '68092', 'BETULIA', 21);
INSERT INTO tblcities VALUES (852, '68101', 'BOLIVAR', 21);
INSERT INTO tblcities VALUES (853, '68121', 'CABRERA', 21);
INSERT INTO tblcities VALUES (854, '68132', 'CALIFORNIA', 21);
INSERT INTO tblcities VALUES (855, '68147', 'CAPITANEJO', 21);
INSERT INTO tblcities VALUES (856, '68152', 'CARCASI', 21);
INSERT INTO tblcities VALUES (857, '68160', 'CEPITA', 21);
INSERT INTO tblcities VALUES (858, '68162', 'CERRITO', 21);
INSERT INTO tblcities VALUES (859, '68167', 'CHARALA', 21);
INSERT INTO tblcities VALUES (860, '68169', 'CHARTA', 21);
INSERT INTO tblcities VALUES (861, '68176', 'CHIMA', 21);
INSERT INTO tblcities VALUES (862, '68179', 'CHIPATA', 21);
INSERT INTO tblcities VALUES (863, '68190', 'CIMITARRA', 21);
INSERT INTO tblcities VALUES (864, '68207', 'CONCEPCION', 21);
INSERT INTO tblcities VALUES (865, '68209', 'CONFINES', 21);
INSERT INTO tblcities VALUES (866, '68211', 'CONTRATACION', 21);
INSERT INTO tblcities VALUES (867, '68217', 'COROMORO', 21);
INSERT INTO tblcities VALUES (868, '68229', 'CURITI', 21);
INSERT INTO tblcities VALUES (869, '68235', 'EL CARMEN DE CHUCURI', 21);
INSERT INTO tblcities VALUES (870, '68245', 'EL GUACAMAYO', 21);
INSERT INTO tblcities VALUES (871, '68250', 'EL PEÑON', 21);
INSERT INTO tblcities VALUES (872, '68255', 'EL PLAYON', 21);
INSERT INTO tblcities VALUES (873, '68264', 'ENCINO', 21);
INSERT INTO tblcities VALUES (874, '68266', 'ENCISO', 21);
INSERT INTO tblcities VALUES (875, '68271', 'FLORIAN', 21);
INSERT INTO tblcities VALUES (876, '68276', 'FLORIDABLANCA', 21);
INSERT INTO tblcities VALUES (877, '68296', 'GALAN', 21);
INSERT INTO tblcities VALUES (878, '68298', 'GAMBITA', 21);
INSERT INTO tblcities VALUES (879, '68307', 'GIRON', 21);
INSERT INTO tblcities VALUES (880, '68318', 'GUACA', 21);
INSERT INTO tblcities VALUES (881, '68320', 'GUADALUPE', 21);
INSERT INTO tblcities VALUES (882, '68322', 'GUAPOTA', 21);
INSERT INTO tblcities VALUES (883, '68324', 'GUAVATA', 21);
INSERT INTO tblcities VALUES (884, '68327', 'GsEPSA', 21);
INSERT INTO tblcities VALUES (885, '68344', 'HATO', 21);
INSERT INTO tblcities VALUES (886, '68368', 'JESUS MARIA', 21);
INSERT INTO tblcities VALUES (887, '68370', 'JORDAN', 21);
INSERT INTO tblcities VALUES (888, '68377', 'LA BELLEZA', 21);
INSERT INTO tblcities VALUES (889, '68385', 'LANDAZURI', 21);
INSERT INTO tblcities VALUES (890, '68397', 'LA PAZ', 21);
INSERT INTO tblcities VALUES (891, '68406', 'LEBRIJA', 21);
INSERT INTO tblcities VALUES (892, '68418', 'LOS SANTOS', 21);
INSERT INTO tblcities VALUES (893, '68425', 'MACARAVITA', 21);
INSERT INTO tblcities VALUES (894, '68432', 'MALAGA', 21);
INSERT INTO tblcities VALUES (895, '68444', 'MATANZA', 21);
INSERT INTO tblcities VALUES (896, '68464', 'MOGOTES', 21);
INSERT INTO tblcities VALUES (897, '68468', 'MOLAGAVITA', 21);
INSERT INTO tblcities VALUES (898, '68498', 'OCAMONTE', 21);
INSERT INTO tblcities VALUES (899, '68500', 'OIBA', 21);
INSERT INTO tblcities VALUES (900, '68502', 'ONZAGA', 21);
INSERT INTO tblcities VALUES (901, '68522', 'PALMAR', 21);
INSERT INTO tblcities VALUES (902, '68524', 'PALMAS DEL SOCORRO', 21);
INSERT INTO tblcities VALUES (903, '68533', 'PARAMO', 21);
INSERT INTO tblcities VALUES (904, '68547', 'PIEDECUESTA', 21);
INSERT INTO tblcities VALUES (905, '68549', 'PINCHOTE', 21);
INSERT INTO tblcities VALUES (906, '68572', 'PUENTE NACIONAL', 21);
INSERT INTO tblcities VALUES (907, '68573', 'PUERTO PARRA', 21);
INSERT INTO tblcities VALUES (908, '68575', 'PUERTO WILCHES', 21);
INSERT INTO tblcities VALUES (909, '68615', 'RIONEGRO', 21);
INSERT INTO tblcities VALUES (910, '68655', 'SABANA DE TORRES', 21);
INSERT INTO tblcities VALUES (911, '68669', 'SAN ANDRES', 21);
INSERT INTO tblcities VALUES (912, '68673', 'SAN BENITO', 21);
INSERT INTO tblcities VALUES (913, '68679', 'SAN GIL', 21);
INSERT INTO tblcities VALUES (914, '68682', 'SAN JOAQUIN', 21);
INSERT INTO tblcities VALUES (915, '68684', 'SAN JOSE DE MIRANDA', 21);
INSERT INTO tblcities VALUES (916, '68686', 'SAN MIGUEL', 21);
INSERT INTO tblcities VALUES (917, '68689', 'SAN VICENTE DE CHUCURI', 21);
INSERT INTO tblcities VALUES (918, '68705', 'SANTA BARBARA', 21);
INSERT INTO tblcities VALUES (919, '68720', 'SANTA HELENA DEL OPON', 21);
INSERT INTO tblcities VALUES (920, '68745', 'SIMACOTA', 21);
INSERT INTO tblcities VALUES (921, '68755', 'SOCORRO', 21);
INSERT INTO tblcities VALUES (922, '68770', 'SUAITA', 21);
INSERT INTO tblcities VALUES (923, '68773', 'SUCRE', 21);
INSERT INTO tblcities VALUES (924, '68780', 'SURATA', 21);
INSERT INTO tblcities VALUES (925, '68820', 'TONA', 21);
INSERT INTO tblcities VALUES (926, '68855', 'VALLE DE SAN JOSE', 21);
INSERT INTO tblcities VALUES (927, '68861', 'VELEZ', 21);
INSERT INTO tblcities VALUES (928, '68867', 'VETAS', 21);
INSERT INTO tblcities VALUES (929, '68872', 'VILLANUEVA', 21);
INSERT INTO tblcities VALUES (930, '68895', 'ZAPATOCA', 21);
INSERT INTO tblcities VALUES (931, '70001', 'SINCELEJO', 22);
INSERT INTO tblcities VALUES (932, '70110', 'BUENAVISTA', 22);
INSERT INTO tblcities VALUES (933, '70124', 'CAIMITO', 22);
INSERT INTO tblcities VALUES (934, '70204', 'COLOSO', 22);
INSERT INTO tblcities VALUES (935, '70215', 'COROZAL', 22);
INSERT INTO tblcities VALUES (936, '70221', 'COVEÑAS', 22);
INSERT INTO tblcities VALUES (937, '70230', 'CHALAN', 22);
INSERT INTO tblcities VALUES (938, '70233', 'EL ROBLE', 22);
INSERT INTO tblcities VALUES (939, '70235', 'GALERAS', 22);
INSERT INTO tblcities VALUES (940, '70265', 'GUARANDA', 22);
INSERT INTO tblcities VALUES (941, '70400', 'LA UNION', 22);
INSERT INTO tblcities VALUES (942, '70418', 'LOS PALMITOS', 22);
INSERT INTO tblcities VALUES (943, '70429', 'MAJAGUAL', 22);
INSERT INTO tblcities VALUES (944, '70473', 'MORROA', 22);
INSERT INTO tblcities VALUES (945, '70508', 'OVEJAS', 22);
INSERT INTO tblcities VALUES (946, '70523', 'PALMITO', 22);
INSERT INTO tblcities VALUES (947, '70670', 'SAMPUES', 22);
INSERT INTO tblcities VALUES (948, '70678', 'SAN BENITO ABAD', 22);
INSERT INTO tblcities VALUES (949, '70702', 'SAN JUAN DE BETULIA', 22);
INSERT INTO tblcities VALUES (950, '70708', 'SAN MARCOS', 22);
INSERT INTO tblcities VALUES (951, '70713', 'SAN ONOFRE', 22);
INSERT INTO tblcities VALUES (952, '70717', 'SAN PEDRO', 22);
INSERT INTO tblcities VALUES (953, '70742', 'SAN LUIS DE SINCE', 22);
INSERT INTO tblcities VALUES (954, '70771', 'SUCRE', 22);
INSERT INTO tblcities VALUES (955, '70820', 'SANTIAGO DE TOLU', 22);
INSERT INTO tblcities VALUES (956, '70823', 'TOLU VIEJO', 22);
INSERT INTO tblcities VALUES (957, '73001', 'IBAGUE', 23);
INSERT INTO tblcities VALUES (958, '73024', 'ALPUJARRA', 23);
INSERT INTO tblcities VALUES (959, '73026', 'ALVARADO', 23);
INSERT INTO tblcities VALUES (960, '73030', 'AMBALEMA', 23);
INSERT INTO tblcities VALUES (961, '73043', 'ANZOATEGUI', 23);
INSERT INTO tblcities VALUES (962, '73055', 'ARMERO', 23);
INSERT INTO tblcities VALUES (963, '73067', 'ATACO', 23);
INSERT INTO tblcities VALUES (964, '73124', 'CAJAMARCA', 23);
INSERT INTO tblcities VALUES (965, '73148', 'CARMEN DE APICALA', 23);
INSERT INTO tblcities VALUES (966, '73152', 'CASABIANCA', 23);
INSERT INTO tblcities VALUES (967, '73168', 'CHAPARRAL', 23);
INSERT INTO tblcities VALUES (968, '73200', 'COELLO', 23);
INSERT INTO tblcities VALUES (969, '73217', 'COYAIMA', 23);
INSERT INTO tblcities VALUES (970, '73226', 'CUNDAY', 23);
INSERT INTO tblcities VALUES (971, '73236', 'DOLORES', 23);
INSERT INTO tblcities VALUES (972, '73268', 'ESPINAL', 23);
INSERT INTO tblcities VALUES (973, '73270', 'FALAN', 23);
INSERT INTO tblcities VALUES (974, '73275', 'FLANDES', 23);
INSERT INTO tblcities VALUES (975, '73283', 'FRESNO', 23);
INSERT INTO tblcities VALUES (976, '73319', 'GUAMO', 23);
INSERT INTO tblcities VALUES (977, '73347', 'HERVEO', 23);
INSERT INTO tblcities VALUES (978, '73349', 'HONDA', 23);
INSERT INTO tblcities VALUES (979, '73352', 'ICONONZO', 23);
INSERT INTO tblcities VALUES (980, '73408', 'LERIDA', 23);
INSERT INTO tblcities VALUES (981, '73411', 'LIBANO', 23);
INSERT INTO tblcities VALUES (982, '73443', 'MARIQUITA', 23);
INSERT INTO tblcities VALUES (983, '73449', 'MELGAR', 23);
INSERT INTO tblcities VALUES (984, '73461', 'MURILLO', 23);
INSERT INTO tblcities VALUES (985, '73483', 'NATAGAIMA', 23);
INSERT INTO tblcities VALUES (986, '73504', 'ORTEGA', 23);
INSERT INTO tblcities VALUES (987, '73520', 'PALOCABILDO', 23);
INSERT INTO tblcities VALUES (988, '73547', 'PIEDRAS', 23);
INSERT INTO tblcities VALUES (989, '73555', 'PLANADAS', 23);
INSERT INTO tblcities VALUES (990, '73563', 'PRADO', 23);
INSERT INTO tblcities VALUES (991, '73585', 'PURIFICACION', 23);
INSERT INTO tblcities VALUES (992, '73616', 'RIOBLANCO', 23);
INSERT INTO tblcities VALUES (993, '73622', 'RONCESVALLES', 23);
INSERT INTO tblcities VALUES (994, '73624', 'ROVIRA', 23);
INSERT INTO tblcities VALUES (995, '73671', 'SALDAÑA', 23);
INSERT INTO tblcities VALUES (996, '73675', 'SAN ANTONIO', 23);
INSERT INTO tblcities VALUES (997, '73678', 'SAN LUIS', 23);
INSERT INTO tblcities VALUES (998, '73686', 'SANTA ISABEL', 23);
INSERT INTO tblcities VALUES (999, '73770', 'SUAREZ', 23);
INSERT INTO tblcities VALUES (1000, '73854', 'VALLE DE SAN JUAN', 23);
INSERT INTO tblcities VALUES (1001, '73861', 'VENADILLO', 23);
INSERT INTO tblcities VALUES (1002, '73870', 'VILLAHERMOSA', 23);
INSERT INTO tblcities VALUES (1003, '73873', 'VILLARRICA', 23);
INSERT INTO tblcities VALUES (1004, '76001', 'CALI', 24);
INSERT INTO tblcities VALUES (1005, '76020', 'ALCALA', 24);
INSERT INTO tblcities VALUES (1006, '76036', 'ANDALUCIA', 24);
INSERT INTO tblcities VALUES (1007, '76041', 'ANSERMANUEVO', 24);
INSERT INTO tblcities VALUES (1008, '76054', 'ARGELIA', 24);
INSERT INTO tblcities VALUES (1009, '76100', 'BOLIVAR', 24);
INSERT INTO tblcities VALUES (1010, '76109', 'BUENAVENTURA', 24);
INSERT INTO tblcities VALUES (1011, '76111', 'GUADALAJARA DE BUGA', 24);
INSERT INTO tblcities VALUES (1012, '76113', 'BUGALAGRANDE', 24);
INSERT INTO tblcities VALUES (1013, '76122', 'CAICEDONIA', 24);
INSERT INTO tblcities VALUES (1014, '76126', 'CALIMA', 24);
INSERT INTO tblcities VALUES (1015, '76130', 'CANDELARIA', 24);
INSERT INTO tblcities VALUES (1016, '76147', 'CARTAGO', 24);
INSERT INTO tblcities VALUES (1017, '76233', 'DAGUA', 24);
INSERT INTO tblcities VALUES (1018, '76243', 'EL AGUILA', 24);
INSERT INTO tblcities VALUES (1019, '76246', 'EL CAIRO', 24);
INSERT INTO tblcities VALUES (1020, '76248', 'EL CERRITO', 24);
INSERT INTO tblcities VALUES (1021, '76250', 'EL DOVIO', 24);
INSERT INTO tblcities VALUES (1022, '76275', 'FLORIDA', 24);
INSERT INTO tblcities VALUES (1023, '76306', 'GINEBRA', 24);
INSERT INTO tblcities VALUES (1024, '76318', 'GUACARI', 24);
INSERT INTO tblcities VALUES (1025, '76364', 'JAMUNDI', 24);
INSERT INTO tblcities VALUES (1026, '76377', 'LA CUMBRE', 24);
INSERT INTO tblcities VALUES (1027, '76400', 'LA UNION', 24);
INSERT INTO tblcities VALUES (1028, '76403', 'LA VICTORIA', 24);
INSERT INTO tblcities VALUES (1029, '76497', 'OBANDO', 24);
INSERT INTO tblcities VALUES (1030, '76520', 'PALMIRA', 24);
INSERT INTO tblcities VALUES (1031, '76563', 'PRADERA', 24);
INSERT INTO tblcities VALUES (1032, '76606', 'RESTREPO', 24);
INSERT INTO tblcities VALUES (1033, '76616', 'RIOFRIO', 24);
INSERT INTO tblcities VALUES (1034, '76622', 'ROLDANILLO', 24);
INSERT INTO tblcities VALUES (1035, '76670', 'SAN PEDRO', 24);
INSERT INTO tblcities VALUES (1036, '76736', 'SEVILLA', 24);
INSERT INTO tblcities VALUES (1037, '76823', 'TORO', 24);
INSERT INTO tblcities VALUES (1038, '76828', 'TRUJILLO', 24);
INSERT INTO tblcities VALUES (1039, '76834', 'TULUA', 24);
INSERT INTO tblcities VALUES (1040, '76845', 'ULLOA', 24);
INSERT INTO tblcities VALUES (1041, '76863', 'VERSALLES', 24);
INSERT INTO tblcities VALUES (1042, '76869', 'VIJES', 24);
INSERT INTO tblcities VALUES (1043, '76890', 'YOTOCO', 24);
INSERT INTO tblcities VALUES (1044, '76892', 'YUMBO', 24);
INSERT INTO tblcities VALUES (1045, '76895', 'ZARZAL', 24);
INSERT INTO tblcities VALUES (1046, '81001', 'ARAUCA', 25);
INSERT INTO tblcities VALUES (1047, '81065', 'ARAUQUITA', 25);
INSERT INTO tblcities VALUES (1048, '81220', 'CRAVO NORTE', 25);
INSERT INTO tblcities VALUES (1049, '81300', 'FORTUL', 25);
INSERT INTO tblcities VALUES (1050, '81591', 'PUERTO RONDON', 25);
INSERT INTO tblcities VALUES (1051, '81736', 'SARAVENA', 25);
INSERT INTO tblcities VALUES (1052, '81794', 'TAME', 25);
INSERT INTO tblcities VALUES (1053, '85001', 'YOPAL', 26);
INSERT INTO tblcities VALUES (1054, '85010', 'AGUAZUL', 26);
INSERT INTO tblcities VALUES (1055, '85015', 'CHAMEZA', 26);
INSERT INTO tblcities VALUES (1056, '85125', 'HATO COROZAL', 26);
INSERT INTO tblcities VALUES (1057, '85136', 'LA SALINA', 26);
INSERT INTO tblcities VALUES (1058, '85139', 'MANI', 26);
INSERT INTO tblcities VALUES (1059, '85162', 'MONTERREY', 26);
INSERT INTO tblcities VALUES (1060, '85225', 'NUNCHIA', 26);
INSERT INTO tblcities VALUES (1061, '85230', 'OROCUE', 26);
INSERT INTO tblcities VALUES (1062, '85250', 'PAZ DE ARIPORO', 26);
INSERT INTO tblcities VALUES (1063, '85263', 'PORE', 26);
INSERT INTO tblcities VALUES (1064, '85279', 'RECETOR', 26);
INSERT INTO tblcities VALUES (1065, '85300', 'SABANALARGA', 26);
INSERT INTO tblcities VALUES (1066, '85315', 'SACAMA', 26);
INSERT INTO tblcities VALUES (1067, '85325', 'SAN LUIS DE PALENQUE', 26);
INSERT INTO tblcities VALUES (1068, '85400', 'TAMARA', 26);
INSERT INTO tblcities VALUES (1069, '85410', 'TAURAMENA', 26);
INSERT INTO tblcities VALUES (1070, '85430', 'TRINIDAD', 26);
INSERT INTO tblcities VALUES (1071, '85440', 'VILLANUEVA', 26);
INSERT INTO tblcities VALUES (1072, '86001', 'MOCOA', 27);
INSERT INTO tblcities VALUES (1073, '86219', 'COLON', 27);
INSERT INTO tblcities VALUES (1074, '86320', 'ORITO', 27);
INSERT INTO tblcities VALUES (1075, '86568', 'PUERTO ASIS', 27);
INSERT INTO tblcities VALUES (1076, '86569', 'PUERTO CAICEDO', 27);
INSERT INTO tblcities VALUES (1077, '86571', 'PUERTO GUZMAN', 27);
INSERT INTO tblcities VALUES (1078, '86573', 'LEGUIZAMO', 27);
INSERT INTO tblcities VALUES (1079, '86749', 'SIBUNDOY', 27);
INSERT INTO tblcities VALUES (1080, '86755', 'SAN FRANCISCO', 27);
INSERT INTO tblcities VALUES (1081, '86757', 'SAN MIGUEL', 27);
INSERT INTO tblcities VALUES (1082, '86760', 'SANTIAGO', 27);
INSERT INTO tblcities VALUES (1083, '86865', 'VALLE DEL GUAMUEZ', 27);
INSERT INTO tblcities VALUES (1084, '86885', 'VILLAGARZON', 27);
INSERT INTO tblcities VALUES (1085, '88001', 'SAN ANDRES', 28);
INSERT INTO tblcities VALUES (1086, '88564', 'PROVIDENCIA', 28);
INSERT INTO tblcities VALUES (1087, '91001', 'LETICIA', 29);
INSERT INTO tblcities VALUES (1088, '91263', 'EL ENCANTO', 29);
INSERT INTO tblcities VALUES (1089, '91405', 'LA CHORRERA', 29);
INSERT INTO tblcities VALUES (1090, '91407', 'LA PEDRERA', 29);
INSERT INTO tblcities VALUES (1091, '91430', 'LA VICTORIA', 29);
INSERT INTO tblcities VALUES (1092, '91460', 'MIRITI - PARANA', 29);
INSERT INTO tblcities VALUES (1093, '91530', 'PUERTO ALEGRIA', 29);
INSERT INTO tblcities VALUES (1094, '91536', 'PUERTO ARICA', 29);
INSERT INTO tblcities VALUES (1095, '91540', 'PUERTO NARIÑO', 29);
INSERT INTO tblcities VALUES (1096, '91669', 'PUERTO SANTANDER', 29);
INSERT INTO tblcities VALUES (1097, '91798', 'TARAPACA', 29);
INSERT INTO tblcities VALUES (1098, '94001', 'INIRIDA', 30);
INSERT INTO tblcities VALUES (1099, '94343', 'BARRANCO MINAS', 30);
INSERT INTO tblcities VALUES (1100, '94663', 'MAPIRIPANA', 30);
INSERT INTO tblcities VALUES (1101, '94883', 'SAN FELIPE', 30);
INSERT INTO tblcities VALUES (1102, '94884', 'PUERTO COLOMBIA', 30);
INSERT INTO tblcities VALUES (1103, '94885', 'LA GUADALUPE', 30);
INSERT INTO tblcities VALUES (1104, '94886', 'CACAHUAL', 30);
INSERT INTO tblcities VALUES (1105, '94887', 'PANA PANA', 30);
INSERT INTO tblcities VALUES (1106, '94888', 'MORICHAL', 30);
INSERT INTO tblcities VALUES (1107, '95001', 'SAN JOSE DEL GUAVIARE', 31);
INSERT INTO tblcities VALUES (1108, '95015', 'CALAMAR', 31);
INSERT INTO tblcities VALUES (1109, '95025', 'EL RETORNO', 31);
INSERT INTO tblcities VALUES (1110, '95200', 'MIRAFLORES', 31);
INSERT INTO tblcities VALUES (1111, '97001', 'MITU', 32);
INSERT INTO tblcities VALUES (1112, '97161', 'CARURU', 32);
INSERT INTO tblcities VALUES (1113, '97511', 'PACOA', 32);
INSERT INTO tblcities VALUES (1114, '97666', 'TARAIRA', 32);
INSERT INTO tblcities VALUES (1115, '97777', 'PAPUNAUA', 32);
INSERT INTO tblcities VALUES (1116, '97889', 'YAVARATE', 32);
INSERT INTO tblcities VALUES (1117, '99001', 'PUERTO CARREÑO', 33);
INSERT INTO tblcities VALUES (1118, '99524', 'LA PRIMAVERA', 33);
INSERT INTO tblcities VALUES (1119, '99624', 'SANTA ROSALIA', 33);
INSERT INTO tblcities VALUES (1120, '99773', 'CUMARIBO', 33);
INSERT INTO tblcities VALUES (1121, 'NONE', 'SIN CIUDAD', 34);

insert into tblUSERS (user_name, user_passwd, user_lname, user_charge, user_level, user_address, user_mail, user_cel, user_tel, user_available, user_percentage, user_nit) 
	    values ('none', 'none', 'none', 'none',0, 'none','none', 'none', 'none', 'none', 0, '0');

insert into tblUSERS (user_name, user_passwd, user_lname, user_charge, user_level, user_address, user_mail, user_cel, user_tel, user_available, user_percentage, user_nit) 
	    values ('leonardo', '123', 'Leonardo Moreno', 'Comercial', 2, 'none','none', 'none', 'none', 'Disponible', 0.20, '21815238');

insert into tblUSERS (user_name, user_passwd, user_lname, user_charge, user_level, user_address, user_mail, user_cel, user_tel, user_available, user_percentage, user_nit) 
	    values ('angelica', '123', 'Angelica Cristina Sierra', 'Documentos', 2, 'none','none', 'none', 'none', 'Disponible', 0.20, '111');
	    
insert into tblUSERS (user_name, user_passwd, user_lname, user_charge, user_level, user_address, user_mail, user_cel, user_tel, user_available, user_percentage, user_nit) 
	    values ('andres', '123', 'Andres Bazurto', 'Comercial', 2, 'none', 'none', 'none', 'none', 'Disponible', 0.20, '112');
	    
insert into tblUSERS (user_name, user_passwd, user_lname, user_charge, user_level, user_address, user_mail, user_cel, user_tel, user_available, user_percentage, user_nit) 
	    values ('luza', '123', 'Luz Angela Barrera', 'Comercial', 2, 'none', 'none', 'none', 'none', 'Disponible', 0.20, '113');
	    
insert into tblUSERS (user_name, user_passwd, user_lname, user_charge, user_level, user_address, user_mail, user_cel, user_tel, user_available, user_percentage, user_nit) 
	    values ('sandra', '123', 'Sandra Milena Hernandez', 'Contabilidad', 2, 'none', 'none', 'none', 'none', 'Disponible', 0.20, '114');

insert into tblUSERS (user_name, user_passwd, user_lname, user_charge, user_level, user_address, user_mail, user_cel, user_tel, user_available, user_percentage, user_nit) 
	    values ('edwin', '123', 'Edwin José Trujillo', 'Ingeniería', 2, 'none', 'none', 'none', 'none', 'Disponible', 0.20, '115');

insert into tblUSERS (user_name, user_passwd, user_lname, user_charge, user_level, user_address, user_mail, user_cel, user_tel, user_available, user_percentage, user_nit) 
	    values ('cayetano', '123', 'Cayetano Rugeles Manitlla', 'Gerencia', 2, 'none', 'none', 'none', 'none', 'Disponible', 0.20, '116');	

	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit)
	    values ('none','none', 'none', 'none', 'none', 'none', 0, '0');
			   
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Alex Dario Lasso Hidalgo','Nariño', 'none', 'none', 'none', 'Disponible', 0.25, '91815338');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Alfonso Ramirez Gonzalez','Santander', 'none', 'none', 'none', 'Disponible', 0.25, '235');	    

insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Carlos Mauricio Salgado','Caldas', 'none', 'none', 'none', 'Disponible', 0.25, '234');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Diego Ceron', 'Cauca', 'none', 'none', 'none', 'Disponible', 0.25, '233');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Fernando sanchez','Tolima', 'none', 'none', 'none', 'Disponible', 0.25, '232');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Fernando cardona','Bogotá', 'none', 'none', 'none', 'Disponible', 0.25, '231');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Ingrid Ospina','Bogotá', 'none', 'none', 'none', 'Disponible', 0.25, '230');

insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Jaime lopez quintero','Bogotá', 'none', 'none', 'none', 'Disponible', 0.25, '221');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Javier Augusto Osorio Cristancho','Boyacá', 'none', 'none', 'none', 'Disponible', 0.25, '220');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('John Alexander silvara','Amazonas', 'none', 'none', 'none', 'Disponible', 0.25, '219');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Juan carlos noreña','Antioquia', 'none', 'none', 'none', 'Disponible', 0.25, '218');	
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Lenny Rojas','Cajamarca', 'none', 'none', 'none', 'Disponible', 0.25, '217');	
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Leonel Orrego','Santander', 'none', 'none', 'none', 'Disponible', 0.25, '216');	
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Marina Belen Mora Nuñes ','Cajamarca', 'none', 'none', 'none', 'Disponible', 0.25, '215');	
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Miller hernan orozco', 'Cauca', 'none', 'none', 'none', 'Disponible', 0.25, '214');	
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Olando Arias wilches', 'Barranquilla', 'none', 'none', 'none', 'Disponible', 0.25, '213');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Pedro José Burgos', 'Cordoba', 'none', 'none', 'none', 'Disponible', 0.25, '212');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Pedro Nel Goméz Peñaloza', 'Arauca', 'none', 'none', 'none', 'Disponible', 0.25, '211');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Pedro pablo barbosa', 'Bogotá', 'none', 'none', 'none', 'Disponible', 0.25, '210');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Rafael Arismendi', 'Santander', 'none', 'none', 'none', 'Disponible', 0.25, '229');
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Salomon Fabian Rincon', 'Cajamarca', 'none', 'none', 'none', 'Disponible', 0.25, '228');	
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Willian Lisandro Montoya', 'Cajamarca', 'none', 'none', 'none', 'Disponible', 0.25, '227');	
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Wilson Beltran Ramos', 'Cajamarca', 'none', 'none', 'none', 'Disponible', 0.25, '226');	
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Cayetano Rugeles Mantilla', 'Nacional', 'none', 'none', 'none', 'Disponible', 0.25, '225');
	    
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Jesus Octaviani Hernandez', 'Nacional', 'none', 'none', 'none', 'Disponible', 0.25, '224');	
	    
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('David Moncayo Gonzalez', 'Cundinamarca', 'none', 'none', 'none', 'Disponible', 0.25, '223');	
	    
insert into tblINSPECTORS (inspector_name, inspector_address, inspector_mail, inspector_cel, inspector_tel, inspector_available, inspector_percentage, inspector_nit) 
	    values ('Simon Peña Mendoza', 'Cordoba', 'none', 'none', 'none', 'Disponible', 0.25, '222');		    
	    
insert into tblTHIRDPARTIES (thrd_nit, thrd_name, thrd_representative, thrd_cc, thrd_address, thrd_mail, thrd_cel, thrd_tel, city_id) 
	    values('111111','Constructora Mejía S.A','Aurelio Cheverony', '1234578', 'Cra 7ª Nº 3-21', 'aurelito@gmail.com', '3209874532', '8765432', 1);
insert into tblTHIRDPARTIES (thrd_nit, thrd_name, thrd_representative, thrd_cc, thrd_address, thrd_mail, thrd_cel, thrd_tel, city_id)
            values('222222','Ingelectricos del Norte','Marino Gomez', '9123448', 'Av 34 Cll 24', 'marinillo@gmail.com', '3087654234', '2578987', 2);
insert into tblTHIRDPARTIES (thrd_nit, thrd_name, thrd_representative, thrd_cc, thrd_address, thrd_mail, thrd_cel, thrd_tel, city_id)
            values('333333','Ingeniería Robitech','Alfonso Medina', '12345678', 'Transv 80 Cra 25', 'gerencia@ingrobitech.com', '3004569887', '4563421', 3);

insert into tblUSES (use_name) values ('Residencial');
insert into tblUSES (use_name) values ('Comercial');
insert into tblUSES (use_name) values ('Industrial');
insert into tblUSES (use_name) values ('Oficial');
insert into tblUSES (use_name) values ('Especiales');
insert into tblUSES (use_name) values ('Rural');
insert into tblUSES (use_name) values ('Urbano');
insert into tblUSES (use_name) values ('Aislada del SIN');
insert into tblUSES (use_name) values ('Servicio Público');
insert into tblUSES (use_name) values ('Servicio Privado');
insert into tblUSES (use_name) values ('Uso General');
insert into tblUSES (use_name) values ('Uso Exclusivo');
insert into tblUSES (use_name) values ('Servicio General');
insert into tblUSES (use_name) values ('Alumbrado Público');

insert into tblPROCESSES (process_name) values ('Generación');
insert into tblPROCESSES (process_name) values ('Transmisión');
insert into tblPROCESSES (process_name) values ('Transformación');
insert into tblPROCESSES (process_name) values ('Distribución');
insert into tblPROCESSES (process_name) values ('Uso Final');
insert into tblPROCESSES (process_name) values ('Alumbrado Exterior');
insert into tblPROCESSES (process_name) values ('Alumbrado Interior');
insert into tblPROCESSES (process_name) values ('Especiales');
insert into tblPROCESSES (process_name) values ('Normas Voluntarias');


insert into tblSUBPROCESSES (subproc_name, subproc_path, process_id) values ('Subestación tipo poste','chelists/RIG-FO-001.html',2);
insert into tblSUBPROCESSES (subproc_name, subproc_path, process_id) values ('Redes Aéreas','chelists/RIG-FO-002.html',3);
insert into tblSUBPROCESSES (subproc_name, subproc_path, process_id) values ('Vivienda unifamiliar','chelists/RIG-FO-002.html',4);
insert into tblSUBPROCESSES (subproc_name, subproc_path, process_id) values ('Subestación encapsulada','chelists/RIG-FO-005.html',2);
insert into tblSUBPROCESSES (subproc_name, subproc_path, process_id) values ('Vivienda movil','chelists/RIG-FO-010.html',4);

--Se insertan los documentos (solo nombres) que son necesarios en las propuestas, dictamenes y chequeos
insert into tblDOCUMENTS (document_name, document_type) values ('a - Análisis de carga','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('b - Cálculo de transformadores','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('c - Análisis de nivel de tensión requerido', 'RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('d - Distancias de seguridad','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('e - Cálculos de regulación','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('f - Cálculos de pérdidas de energía','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('g - Análisis de cortocircuito y falla a tierra','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('h - Cálculo de coordinación de protecciones','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('i - Cálculo económico de conductores','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('j - Cálculo de ductos , (tuberías, canalizaciones, canaletas, blindobarras)','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('k - Cálculo del sistema de puestas a tierra','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('l - Análisis de protección contra rayos','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('m - Cálculo mecánico de estructuras','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('n - Análisis de coordinación de aislamiento','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('o - Análisis de riesgos eléctricos y medidas para mitigarlos','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('p - Cálculo de campos electromagnéticos en áreas o espacios cercanos a elementos con altas
tensiones o altas corrientes donde desarrollen actividades rutinarias las personas','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('q - Cálculo de iluminación','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('r - Especificaciones de construcción complementarias a los planos incluyendo las de tipo técnico de
equipos y materiales','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('s - Justificación técnica de desviación de la NTC 2050 cuando sea permitido, siempre y cuando no
comprometa la seguridad de las personas o de la instalación','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('t - Diagramas unifilares','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('u - Planos eléctricos de construcción','RETIE');
insert into tblDOCUMENTS (document_name, document_type) values ('v - Los demás estudios que el tipo de instalación requiera para su correcta y segura operación','RETIE');

-- Documentos que exige RIG
insert into tblDOCUMENTS (document_name, document_type) values ('Archivo Fotográfico','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Orden de Servicio','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Declaración de independencia, Imparcialidad y Confidencialidad', 'RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Matriz de Selección','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Acta de inspección','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Declaración de cumplimento del reglamento técnico de instalaciones eléctricas','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Fotocopia de la matricula profesional del constructor, diseñador e Interventor','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Listado de Productos con certificado Retie','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Certificados de Productos o constancia de la verificación ? Retie','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Listas de Verificación','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Predictamen de Instalaciones eléctricas','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Diagrama unifilar','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Planos y/o esquemas eléctricos','RIG');
insert into tblDOCUMENTS (document_name, document_type) values ('Análisis y memorias de calculo','RIG');

INSERT INTO tblrequirements VALUES (1, 'Independencia constructiva de las edificaciones', 1);
INSERT INTO tblrequirements VALUES (2, 'Matriales acordes con las condiciones ambientales', 1);
INSERT INTO tblrequirements VALUES (3, 'Soportabilida al fuego de materiales', 1);
INSERT INTO tblrequirements VALUES (4, 'Disposición de mimicos', 1);
INSERT INTO tblrequirements VALUES (5, 'Maniobrabilidad, señalización y sistema de alarma sonoro de puente gruas', 1);
INSERT INTO tblrequirements VALUES (6, 'Instalación de sistema de control automatico y manual para compuertas de captación de la central hidraulica', 1);
INSERT INTO tblrequirements VALUES (7, 'Señalización Aeronautica', 1);
INSERT INTO tblrequirements VALUES (8, 'Restricciones en cuarto de bateria', 1);
INSERT INTO tblrequirements VALUES (9, 'Sistemas de protección contra incendios', 1);
INSERT INTO tblrequirements VALUES (10, 'Conductores eléctricos', 1);
INSERT INTO tblrequirements VALUES (11, 'Niveles de iluminancia', 1);
INSERT INTO tblrequirements VALUES (12, 'Sistemas de alumbrado de emergencia', 1);
INSERT INTO tblrequirements VALUES (13, 'Memorias de calculo', 1);
INSERT INTO tblrequirements VALUES (14, 'Disositivos deseccionaiento y mando', 1);
INSERT INTO tblrequirements VALUES (15, 'Avisos y señales de seguridad', 1);
INSERT INTO tblrequirements VALUES (16, 'Distancias de seguridad', 1);
INSERT INTO tblrequirements VALUES (17, 'Ejecución de las conexiones', 1);
INSERT INTO tblrequirements VALUES (18, 'Barreras de Acceso', 1);
INSERT INTO tblrequirements VALUES (19, 'Campos electromagneticos en areas de trabajo permanente', 1);
INSERT INTO tblrequirements VALUES (20, 'Continuidad delos conductores de tierra y conexiones equipotenciales', 1);
INSERT INTO tblrequirements VALUES (21, 'Planos, esquemas y diagramas', 1);
INSERT INTO tblrequirements VALUES (22, 'Funconamieto del corte automatico de la alimentación', 1);
INSERT INTO tblrequirements VALUES (23, 'Encerramientos de equipos (mallas, cuartos y bóvedas)', 1);
INSERT INTO tblrequirements VALUES (24, 'Protección contra rayos', 1);
INSERT INTO tblrequirements VALUES (25, 'Protección contra arcos internos', 1);
INSERT INTO tblrequirements VALUES (26, 'Resistencia de puesta a tierra _RSPT', 1);
INSERT INTO tblrequirements VALUES (27, 'Revisones de certificaciones de prducto', 1);
INSERT INTO tblrequirements VALUES (28, 'Seleccón de dispositivos de protección contra sobrecorrientes', 1);
INSERT INTO tblrequirements VALUES (29, 'Seleccón de dispositivos de protección contra sobretensiones', 1);
INSERT INTO tblrequirements VALUES (30, 'Tiepo de respuesta de protecciones para despeje de fallas', 1);
INSERT INTO tblrequirements VALUES (31, 'Ventilación', 1);
INSERT INTO tblrequirements VALUES (32, 'Tensiones de paso, cntacto y transferidas', 1);
INSERT INTO tblrequirements VALUES (33, 'Verificación detensiones de paso, contacto y transferidas', 1);
INSERT INTO tblrequirements VALUES (34, 'Aisladores', 2);
INSERT INTO tblrequirements VALUES (35, 'Aislamiento', 2);
INSERT INTO tblrequirements VALUES (36, 'Avisos y Señales de seguridad', 2);
INSERT INTO tblrequirements VALUES (37, 'Campos electromagnéticos', 2);
INSERT INTO tblrequirements VALUES (38, 'Condiciones de diseño de estructuras y herrajes', 2);
INSERT INTO tblrequirements VALUES (39, 'Conductores', 2);
INSERT INTO tblrequirements VALUES (40, 'Dispositivos de seccionamiento y mando', 2);
INSERT INTO tblrequirements VALUES (41, 'Distancias de seguridad', 2);
INSERT INTO tblrequirements VALUES (42, 'Ejecución de las conexiones', 2);
INSERT INTO tblrequirements VALUES (43, 'Ensayos funcionales', 2);
INSERT INTO tblrequirements VALUES (44, 'Estructuras acorde con los requerimientos mecánicos', 2);
INSERT INTO tblrequirements VALUES (45, 'Franja de servidumbre', 2);
INSERT INTO tblrequirements VALUES (46, 'Funcionamiento del corte automático de la alimentación', 2);
INSERT INTO tblrequirements VALUES (47, 'Materiales acordes con las condiciones ambientales', 2);
INSERT INTO tblrequirements VALUES (48, 'Memorias de cálculo', 2);
INSERT INTO tblrequirements VALUES (49, 'Planos, esquemas y diagramas', 2);
INSERT INTO tblrequirements VALUES (50, 'Protección contra la corrosión', 2);
INSERT INTO tblrequirements VALUES (51, 'Resistencia de puesta a tierra _RSPT', 2);
INSERT INTO tblrequirements VALUES (52, 'Revisión de certificaciones de productos', 2);
INSERT INTO tblrequirements VALUES (53, 'Selección de conductores', 2);
INSERT INTO tblrequirements VALUES (54, 'Selección de dispositivos de protección contra sobrecorrientes', 2);
INSERT INTO tblrequirements VALUES (55, 'Selección de dispositivos de protección contra sobretensiones', 2);
INSERT INTO tblrequirements VALUES (56, 'Señales de aeronavegación', 2);
INSERT INTO tblrequirements VALUES (57, 'Tensiones de paso y de contacto', 2);
INSERT INTO tblrequirements VALUES (58, 'Verificación de Tensiones de paso, contacto y transferidas', 2);
INSERT INTO tblrequirements VALUES (59, 'Zona de servidumbre', 2);
INSERT INTO tblrequirements VALUES (60, 'Accesibilidad a todos los dispositivos de protección ', 3);
INSERT INTO tblrequirements VALUES (61, 'Avisos y señales de seguridad', 3);
INSERT INTO tblrequirements VALUES (62, 'Barreras de acceso ', 3);
INSERT INTO tblrequirements VALUES (63, 'Campos electromagnéticos en áreas de trabajo permanente ', 3);
INSERT INTO tblrequirements VALUES (64, 'Continuidad de los conductores de tierra y conexiones equipotenciales ', 3);
INSERT INTO tblrequirements VALUES (65, 'Corriente en el sistema puesta a tierra.', 3);
INSERT INTO tblrequirements VALUES (66, 'Dispositivo de seccionamiento y mando. ', 3);
INSERT INTO tblrequirements VALUES (67, 'Distancias de seguridad ', 3);
INSERT INTO tblrequirements VALUES (68, 'Ejecución de las conexiones.', 3);
INSERT INTO tblrequirements VALUES (69, 'Encerramientos de equipos (mallas, cuartos, bóvedas) ', 3);
INSERT INTO tblrequirements VALUES (70, 'Enclavamientos ', 3);
INSERT INTO tblrequirements VALUES (71, 'Ensayos dieléctricos ', 3);
INSERT INTO tblrequirements VALUES (72, 'Equipotencialidad ', 3);
INSERT INTO tblrequirements VALUES (73, 'Estructuras y herrajes', 3);
INSERT INTO tblrequirements VALUES (74, 'Identificación de circuitos, conductores de neutro y de tierras. ', 3);
INSERT INTO tblrequirements VALUES (75, 'Materiales acordes con las condiciones ambientales ', 3);
INSERT INTO tblrequirements VALUES (76, 'Memorias de cálculo ', 3);
INSERT INTO tblrequirements VALUES (77, 'Mímicos ', 3);
INSERT INTO tblrequirements VALUES (78, 'Montaje ', 3);
INSERT INTO tblrequirements VALUES (79, 'Planos, esquemas y diagramas ', 3);
INSERT INTO tblrequirements VALUES (80, 'Protección contra arcos internos ', 3);
INSERT INTO tblrequirements VALUES (81, 'Protección contra electrocución por contacto directo. ', 3);
INSERT INTO tblrequirements VALUES (82, 'Protección contra electrocución por contacto indirecto. ', 3);
INSERT INTO tblrequirements VALUES (83, 'Protección contra rayos ', 3);
INSERT INTO tblrequirements VALUES (84, 'Resistencia de puesta a tierra. _RSPT', 3);
INSERT INTO tblrequirements VALUES (85, 'Resistencia de aislamiento. ', 3);
INSERT INTO tblrequirements VALUES (86, 'Revisiones de certificaciones de producto.', 3);
INSERT INTO tblrequirements VALUES (87, 'Selección de conductores ', 3);
INSERT INTO tblrequirements VALUES (88, 'Selección de dispositivos de protección contra sobrecorrientes. ', 3);
INSERT INTO tblrequirements VALUES (89, 'Selección de dispositivos de protección contra sobretensiones. ', 3);
INSERT INTO tblrequirements VALUES (90, 'Sistema contra incendio ', 3);
INSERT INTO tblrequirements VALUES (91, 'Soportabilidad al fuego de materiales ', 3);
INSERT INTO tblrequirements VALUES (92, 'Tensión de contacto y transferida ', 3);
INSERT INTO tblrequirements VALUES (93, 'Tensión de paso. ', 3);
INSERT INTO tblrequirements VALUES (94, 'Tiempo de respuesta de protecciones para despeje de fallas. ', 3);
INSERT INTO tblrequirements VALUES (95, 'Ventilación ', 3);
INSERT INTO tblrequirements VALUES (96, 'Verificación de tensiones de paso, contacto y transferidas', 3);
INSERT INTO tblrequirements VALUES (97, 'Accesibilidad a todos los dispositivos de protección ', 4);
INSERT INTO tblrequirements VALUES (98, 'Apoyos o estructuras ', 4);
INSERT INTO tblrequirements VALUES (99, 'Avisos y señales de seguridad ', 4);
INSERT INTO tblrequirements VALUES (100, 'Cámaras y canalizaciones adecuadas ', 4);
INSERT INTO tblrequirements VALUES (101, 'Dispositivos de seccionamiento y mando ', 4);
INSERT INTO tblrequirements VALUES (102, 'Distancias de seguridad ', 4);
INSERT INTO tblrequirements VALUES (103, 'Ejecución de las conexiones.', 4);
INSERT INTO tblrequirements VALUES (104, 'Funcionamiento del corte automático de la alimentación ', 4);
INSERT INTO tblrequirements VALUES (105, 'Herrajes ', 4);
INSERT INTO tblrequirements VALUES (106, 'Identificación de circuitos', 4);
INSERT INTO tblrequirements VALUES (107, 'Materiales acordes con las condiciones ambientales ', 4);
INSERT INTO tblrequirements VALUES (108, 'Memorias de cálculo ', 4);
INSERT INTO tblrequirements VALUES (109, 'Planos, esquemas y diagramas ', 4);
INSERT INTO tblrequirements VALUES (110, 'Protección contra la corrosión ', 4);
INSERT INTO tblrequirements VALUES (111, 'Resistencia de puesta a tierra. RSPT', 4);
INSERT INTO tblrequirements VALUES (112, 'Resistencia de aislamiento. ', 4);
INSERT INTO tblrequirements VALUES (113, 'Revisión de certificaciones de productos ', 4);
INSERT INTO tblrequirements VALUES (114, 'Selección de conductores ', 4);
INSERT INTO tblrequirements VALUES (115, 'Selección de dispositivos de protección contra sobrecorrientes. ', 4);
INSERT INTO tblrequirements VALUES (116, 'Selección de dispositivos de protección contra sobretensiones. ', 4);
INSERT INTO tblrequirements VALUES (117, 'Tensiones de paso, contacto y transferidas ', 4);
INSERT INTO tblrequirements VALUES (118, 'Valores de Campo Electromagnéticos. ', 4);
INSERT INTO tblrequirements VALUES (119, 'Accesibilidad a todos los dispositivos de protección ', 5);
INSERT INTO tblrequirements VALUES (120, 'Bomba contra incendio ', 5);
INSERT INTO tblrequirements VALUES (121, 'Continuidad de los conductores de tierra y conexiones equipotenciales ', 5);
INSERT INTO tblrequirements VALUES (122, 'Corrientes en el sistema de puesta a tierra ', 5);
INSERT INTO tblrequirements VALUES (123, 'Distancias de seguridad ', 5);
INSERT INTO tblrequirements VALUES (124, 'Ejecución de las conexiones ', 5);
INSERT INTO tblrequirements VALUES (125, 'Ensayos funcionales ', 5);
INSERT INTO tblrequirements VALUES (126, 'Existencia de planos, esquema, aviso y señales ', 5);
INSERT INTO tblrequirements VALUES (127, 'Funcionamiento del corte automático de la alimentación ', 5);
INSERT INTO tblrequirements VALUES (128, 'Identificación de canalizaciones ', 5);
INSERT INTO tblrequirements VALUES (129, 'Identificación de circuitos ', 5);
INSERT INTO tblrequirements VALUES (130, 'Identificación de conductores de fase, neutro y tierras ', 5);
INSERT INTO tblrequirements VALUES (131, 'Materiales acordes con las condiciones ambientales ', 5);
INSERT INTO tblrequirements VALUES (132, 'Memorias de cálculo ', 5);
INSERT INTO tblrequirements VALUES (133, 'Niveles de iluminación  ', 5);
INSERT INTO tblrequirements VALUES (134, 'Protección contra arcos internos ', 5);
INSERT INTO tblrequirements VALUES (135, 'Protección contra electrocución por contacto directo ', 5);
INSERT INTO tblrequirements VALUES (136, 'Protección contra electrocución por contacto indirecto ', 5);
INSERT INTO tblrequirements VALUES (137, 'Resistencia de aislamiento ', 5);
INSERT INTO tblrequirements VALUES (138, 'Resistencia de puesta a tierra _RSPT', 5);
INSERT INTO tblrequirements VALUES (139, 'Revisiones de certificaciones de producto ', 5);
INSERT INTO tblrequirements VALUES (140, 'Selección de conductores ', 5);
INSERT INTO tblrequirements VALUES (141, 'Selección de dispositivos de protección contra sobrecorrientes ', 5);
INSERT INTO tblrequirements VALUES (142, 'Selección de dispositivos de protección contra sobretensiones ', 5);
INSERT INTO tblrequirements VALUES (143, 'Sistema de emergencia ', 5);
INSERT INTO tblrequirements VALUES (144, 'Sistema de protección contra rayos ', 5);
INSERT INTO tblrequirements VALUES (145, 'Valores de campos Electromagnéticos ', 5);
INSERT INTO tblrequirements VALUES (146, 'Memorias de cálculo', 6);
INSERT INTO tblrequirements VALUES (147, 'Determinación de clases de iluminación', 6);
INSERT INTO tblrequirements VALUES (148, 'Selección de las fuentes luminosas (IRC, vida útil) y compatibilidad con luminarias y ambiente de instalación (IP, IK, FHS)', 6);
INSERT INTO tblrequirements VALUES (149, 'Información fotométrica de las luminarias utilizadas certificada (Matriz de intensidades, Curvas o Coeficientes de Utilización).', 6);
INSERT INTO tblrequirements VALUES (150, 'Validación de software de diseño', 6);
INSERT INTO tblrequirements VALUES (151, 'Cálculo manual ( alcance, parámetros incluidos y supuestos realizados )', 6);
INSERT INTO tblrequirements VALUES (152, 'Cumplimiento de los parámetros de diseño establecidos en el RETILAP', 6);
INSERT INTO tblrequirements VALUES (153, 'Resultados del diseño - Factor de uniformidad longitudinal UL', 6);
INSERT INTO tblrequirements VALUES (154, 'Resultados del diseño - Relación de alrededores (SR)', 6);
INSERT INTO tblrequirements VALUES (155, 'Resultados del diseño - Iluminancia promedio mínima mantenida (luxes)', 6);
INSERT INTO tblrequirements VALUES (156, 'Resultados del diseño - Coeficiente de uniformidad de iluminancias', 6);
INSERT INTO tblrequirements VALUES (157, 'Resultados del diseño - Iluminancia horizontal promedio (luxes)', 6);
INSERT INTO tblrequirements VALUES (158, 'Resultados del diseño - Luminancia promedio (cd/m2)', 6);
INSERT INTO tblrequirements VALUES (159, 'Resultados del diseño - Factor de uniformidad general Uo', 6);
INSERT INTO tblrequirements VALUES (160, 'Resultados del diseño - Incremento de umbral TI (%)', 6);
INSERT INTO tblrequirements VALUES (161, 'Determinación del factor de mantenimiento de la instalación de alumbrado', 6);
INSERT INTO tblrequirements VALUES (162, 'Esquema de mantenimiento disponible al operador o propietario', 6);
INSERT INTO tblrequirements VALUES (163, 'Planos del proyecto de alumbrado aprobados por responsable de la prestación del servicio de alumbrado', 6);
INSERT INTO tblrequirements VALUES (164, 'Accesibilidad a todos los dispositivos de control de luminarias', 6);
INSERT INTO tblrequirements VALUES (165, 'Mediciones fotométricas sistema de Alumbrado (a las 100 horas de funcionamiento) - Coeficiente de uniformidad de iluminancias', 6);
INSERT INTO tblrequirements VALUES (166, 'Mediciones fotométricas sistema de Alumbrado (a las 100 horas de funcionamiento) - Iluminancia promedio (luxes)', 6);
INSERT INTO tblrequirements VALUES (167, 'Control de iluminación de exteriores (Incluye avisos)', 6);
INSERT INTO tblrequirements VALUES (168, 'Cumplimiento de los valores ofrecidos en el diseño', 6);
INSERT INTO tblrequirements VALUES (169, 'Cumplimiento de Valores de Densidad de Potencia de la instalación (DPEA)', 6);
INSERT INTO tblrequirements VALUES (170, 'Sistema de control automático (fotocontroles) de alumbrado Público (Ensayos funcionales)', 6);
INSERT INTO tblrequirements VALUES (171, 'Puesta a tierra de carcasas de luminarias', 6);
INSERT INTO tblrequirements VALUES (172, 'Revisión de certificados de conformidad de productos de iluminación', 6);
INSERT INTO tblrequirements VALUES (173, 'Certificación de instalaciones eléctricas con RETIE', 6);
INSERT INTO tblrequirements VALUES (174, 'Memorias de cálculo', 7);
INSERT INTO tblrequirements VALUES (175, 'Estudio y aplicación del Índice de Contribución de Luz Diurna (CLD)', 7);
INSERT INTO tblrequirements VALUES (176, 'Selección de las fuentes luminosas (IRC, vida útil) y compatibilidad con luminarias', 7);
INSERT INTO tblrequirements VALUES (177, 'Información fotométrica de las luminarias utilizadas certificada (Matriz de intensidades, Curvas o Coeficientes de Utilización)', 7);
INSERT INTO tblrequirements VALUES (178, 'Validación de software de diseño', 7);
INSERT INTO tblrequirements VALUES (179, 'Cálculo manual ( alcance, parámetros incluidos y supuestos realizados )', 7);
INSERT INTO tblrequirements VALUES (180, 'Cumplimiento de los parámetros de diseño establecidos en el RETILAP', 7);
INSERT INTO tblrequirements VALUES (181, 'Iluminancia horizontal promedio (luxes) resultado de diseño', 7);
INSERT INTO tblrequirements VALUES (182, 'Coeficiente de uniformidad de iluminancias resultado de diseño', 7);
INSERT INTO tblrequirements VALUES (183, 'Índice de deslumbramiento unificado (UGR) resultado de diseño', 7);
INSERT INTO tblrequirements VALUES (184, 'Factor de mantenimiento de la instalación de alumbrado', 7);
INSERT INTO tblrequirements VALUES (185, 'Esquema de mantenimiento disponible al operador o propietario', 7);
INSERT INTO tblrequirements VALUES (186, 'Accesibilidad a todos los dispositivos de control de luminarias', 7);
INSERT INTO tblrequirements VALUES (187, 'Mediciones fotométricas del sistema de iluminación general - Coeficiente de uniformidad de iluminancias', 7);
INSERT INTO tblrequirements VALUES (188, 'Mediciones fotométricas del sistema de iluminación general - Iluminancia horizontal promedio (Luxes)', 7);
INSERT INTO tblrequirements VALUES (189, 'Mediciones fotométricas en los puestos de trabajo - Coeficiente de uniformidad de iluminancias', 7);
INSERT INTO tblrequirements VALUES (190, 'Mediciones fotométricas en los puestos de trabajo - Iluminancia promedio (Luxes)', 7);
INSERT INTO tblrequirements VALUES (191, 'Cumplimiento de los valores ofrecidos en el diseño', 7);
INSERT INTO tblrequirements VALUES (192, 'Cumplimiento de Valores de eficiencia energética de la instalación (VEEI)', 7);
INSERT INTO tblrequirements VALUES (193, 'Sistema de alumbrado de emergencia', 7);
INSERT INTO tblrequirements VALUES (194, 'Puesta a tierra de carcasas de luminarias', 7);
INSERT INTO tblrequirements VALUES (195, 'Revisión de certificados de conformidad de productos de iluminación', 7);
INSERT INTO tblrequirements VALUES (196, 'Certificación de instalaciones eléctricas con RETIE', 7);

insert into tblQUOTATIONS (quot_date, quot_name, quot_scope, quot_contact, quot_address, quot_mail, quot_cel, quot_tel, quot_inspect_type, thrd_id, city_id, use_id) 
	    values ('2012-05-15', 'Edificio las Camelias', 'Acometida e instalaciones interiores', 'Jacinto Tocaima','Av 15, Transv 80','lilola@hotmail.com','3134324566','8632345','RETIE',1,1,1);
insert into tblQUOTATIONS (quot_date, quot_name, quot_scope, quot_contact, quot_address, quot_mail, quot_cel, quot_tel, quot_inspect_type, thrd_id, city_id, use_id) 
	    values ('2012-05-20', 'Centro Comercial La Aurora', 'Subestación tipo poste y Tablero general', 'Lazaro Buenavida','Cra 7ª Nº33-12','truchocarucho@gmail.com','','5602345','RETIE',2,50,2);
insert into tblQUOTATIONS (quot_date, quot_name, quot_scope, quot_contact, quot_address, quot_mail, quot_cel, quot_tel, quot_inspect_type, thrd_id, city_id, use_id) 
	    values ('2012-05-21', 'Acerías Ternium', 'Caldera con Cogeneración', 'Rogelio Pataquiva','Kilómetro 15 autopista del café','ingenieria@ternium.com','3004256060','2603456','RETIE',3,100,3);
insert into tblQUOTATIONS (quot_date, quot_name, quot_scope, quot_contact, quot_address, quot_mail, quot_cel, quot_tel, quot_inspect_type, thrd_id, city_id, use_id) 
	    values ('2012-08-22', 'Cicolsa', 'Transformador de Potencia', 'Rodrigo Lara Bonilla','Kilómetro 1 vía bogotá','comercial@cicolsa.com','3104256060','8743456','RETIE',3,2,2);
	    
insert into tblQUOTPROCESSES (quot_id, process_id) values (1,4);
insert into tblQUOTPROCESSES (quot_id, process_id) values (2,2);
insert into tblQUOTPROCESSES (quot_id, process_id) values (2,3);
insert into tblQUOTPROCESSES (quot_id, process_id) values (2,4);
insert into tblQUOTPROCESSES (quot_id, process_id) values (3,1);
insert into tblQUOTPROCESSES (quot_id, process_id) values (4,3);
	
insert into tblPROPOSALS (prop_date, prop_scope, prop_value, prop_iva, prop_viatical, prop_total_value, prop_payway, prop_state, prop_user_perc, quot_id, user_id) 
	    values ('2012-05-16', 'Acometida e instalaciones interiores', 300000, 48000, 60000, 408000, '50% - 50%', 'Aprobada', 0.15, 1, 2);
insert into tblPROPOSALS (prop_date, prop_scope, prop_value, prop_iva, prop_viatical, prop_total_value, prop_payway, prop_state, prop_user_perc, quot_id, user_id) 
	    values ('2012-05-21', 'Subestación tipo poste y Tablero general', 1200000, 192000, 50000, 1442000, '100%', 'Aprobada', 0.2, 2, 3);
insert into tblPROPOSALS (prop_date, prop_scope, prop_value, prop_iva, prop_viatical, prop_total_value, prop_payway, prop_state,  prop_user_perc, quot_id, user_id) 
	    values ('2012-05-23','Caldera con Cogeneración', 3000000, 480000, 600000, 4080000, 'A Convenir', 'Aprobada', 0.25, 3, 2);
	    
insert into tblPROPDOCUMENTS (prop_id, document_id) values (10000 + date_part('year', now()), 1);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (10000 + date_part('year', now()), 2);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (10000 + date_part('year', now()), 3);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (10000 + date_part('year', now()), 4);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (10000 + date_part('year', now()), 16);

insert into tblPROPDOCUMENTS (prop_id, document_id) values (20000 + date_part('year', now()), 5);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (20000 + date_part('year', now()), 7);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (20000 + date_part('year', now()), 8);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (20000 + date_part('year', now()), 9);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (20000 + date_part('year', now()), 10);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (20000 + date_part('year', now()), 11);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (20000 + date_part('year', now()), 12);

insert into tblPROPDOCUMENTS (prop_id, document_id) values (30000 + date_part('year', now()), 1);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (30000 + date_part('year', now()), 2);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (30000 + date_part('year', now()), 5);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (30000 + date_part('year', now()), 8);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (30000 + date_part('year', now()), 10);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (30000 + date_part('year', now()), 12);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (30000 + date_part('year', now()), 14);
insert into tblPROPDOCUMENTS (prop_id, document_id) values (30000 + date_part('year', now()), 15);
	    	    
insert into tblRECORDS (record_foil) values ('Sin Archivar');
insert into tblRECORDS (record_foil) values ('AZ100');
insert into tblRECORDS (record_foil) values ('AZ101');
insert into tblRECORDS (record_foil) values ('AZ202');

insert into tblSERVICEORDERS (so_date, so_scope, so_observations, so_acc_processed, so_doc_processed, so_eng_processed, so_inspector_perc, so_assign_date, inspector_id, prop_id) 
values ('2012-05-18', 'Acometida e instalaciones interiores', 'No se observan anomalías', 'Sin Procesar', 'Revisada', 'Sin Procesar', 0.25, '2012-11-18', 7, 10000 + date_part('year', now()));
insert into tblSERVICEORDERS (so_date, so_scope, so_observations, so_acc_processed, so_doc_processed, so_eng_processed, so_inspector_perc, so_assign_date, inspector_id, prop_id) 
values ('2012-06-22', 'Subestación tipo poste y Tablero general', 'No se observan anomalías', 'Sin Procesar', 'Sin Procesar', 'Sin Procesar', 0.23, '2012-11-20', 12,  20000 + date_part('year', now()));
insert into tblSERVICEORDERS (so_date, so_scope, so_observations, so_acc_processed, so_doc_processed, so_eng_processed, so_inspector_perc, so_assign_date, inspector_id, prop_id) 
values ('2012-07-26', 'Caldera con Cogeneración', 'No se observan anomalías', 'Sin Procesar', 'Sin Procesar', 'Sin Procesar', 0.20, '2012-12-19', 3, 30000 + date_part('year', now()));

insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 23);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 24);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 25);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 26);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 27);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 28);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 29);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 30);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 31);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 32);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 33);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 34);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 35);
insert into tblSODOCUMENTS (so_id, document_id) values (10000 + date_part('year', now()), 36);

insert into tblSODOCUMENTS (so_id, document_id) values (20000 + date_part('year', now()), 23);
insert into tblSODOCUMENTS (so_id, document_id) values (20000 + date_part('year', now()), 24);
insert into tblSODOCUMENTS (so_id, document_id) values (20000 + date_part('year', now()), 25);
insert into tblSODOCUMENTS (so_id, document_id) values (20000 + date_part('year', now()), 28);
insert into tblSODOCUMENTS (so_id, document_id) values (20000 + date_part('year', now()), 30);
insert into tblSODOCUMENTS (so_id, document_id) values (20000 + date_part('year', now()), 31);

insert into tblSODOCUMENTS (so_id, document_id) values (30000 + date_part('year', now()), 23);
insert into tblSODOCUMENTS (so_id, document_id) values (30000 + date_part('year', now()), 24);
insert into tblSODOCUMENTS (so_id, document_id) values (30000 + date_part('year', now()), 26);
insert into tblSODOCUMENTS (so_id, document_id) values (30000 + date_part('year', now()), 29);
insert into tblSODOCUMENTS (so_id, document_id) values (30000 + date_part('year', now()), 30);
insert into tblSODOCUMENTS (so_id, document_id) values (30000 + date_part('year', now()), 32);

insert into tblSORECORDS (so_id, record_id) values (10000 + date_part('year', now()), 2);
insert into tblSORECORDS (so_id, record_id) values (10000 + date_part('year', now()), 3);
insert into tblSORECORDS (so_id, record_id) values (20000 + date_part('year', now()), 2);
insert into tblSORECORDS (so_id, record_id) values (30000 + date_part('year', now()), 2);
insert into tblSORECORDS (so_id, record_id) values (30000 + date_part('year', now()), 3);
insert into tblSORECORDS (so_id, record_id) values (30000 + date_part('year', now()), 4);

insert into tblSOTRACKING (trck_receipt_date, trck_receiver_name, trck_shipping_date, trck_shipper_name, trck_shipping_name, 
			  trck_shipping_company, trck_guide_number, trck_observations, city_id, so_id)
values ('2012-07-26', 'Angelica Cristina Sierra', '2012-08-21', 'Leonardo Moreno', 'Envío Nacional', 'Envía', '111522525-3', 'Se envía Factura', 80, 10000 + date_part('year', now()));
  
insert into tblMOVEMENTS (mov_date, mov_type, so_id, mov_value, mov_name, mov_nit, mov_documment, mov_observations)
values ('2012-07-26T21:59:39', 'FACTURA', 10000 + date_part('year', now()), 50000, 'Constructora Mejía S.A', '111111', 'FC0000001', 'Pago de factura');
insert into tblMOVEMENTS (mov_date, mov_type, so_id, mov_value, mov_name, mov_nit, mov_documment, mov_observations)
values ('2012-07-26T20:29:31', 'PAGO INSPECTOR', 10000 + date_part('year', now()), 20000, 'Alex Dario Lasso Hidalgo', '91815338', 'RC0000001', 'Pago de inspector');
insert into tblMOVEMENTS (mov_date, mov_type, so_id, mov_value, mov_name, mov_nit, mov_documment, mov_observations)
values ('2012-07-26T18:09:22', 'PAGO COMERCIAL', 10000 + date_part('year', now()), 30000, 'Leonardo Moreno', '21815238', 'RC0000001', 'Pago de comercial');

insert into tblDESIGNERS(designer_name, designer_mp, designer_mail, designer_cel) 
	    values ('No Aplica', 'No Aplica', '', '');
insert into tblDESIGNERS(designer_name, designer_mp, designer_mail, designer_cel) 
	    values ('Carlos carriazo', 'CU-802525', 'cariarriozo@hotmail.com', '3012938475');
insert into tblDESIGNERS(designer_name, designer_mp, designer_mail, designer_cel) 
	    values ('Ermelindo buenavida', 'CL-802530', 'emispis@hotmail.com', '3212938678');
insert into tblDESIGNERS(designer_name, designer_mp, designer_mail, designer_cel) 
	    values ('Fulgencio Batista', 'AN-306530', 'fulgis@hotmail.com', '3003938970');

insert into tblCONSTRUCTORS(constructor_name, constructor_mp, constructor_mail, constructor_cel) 
	    values ('No Aplica', 'No Aplica', '', '');
insert into tblCONSTRUCTORS(constructor_name, constructor_mp, constructor_mail, constructor_cel) 
	    values ('José Joseles', 'CL-002523', 'suabelito@yahoo.com', '3312938476');
insert into tblCONSTRUCTORS(constructor_name, constructor_mp, constructor_mail, constructor_cel) 
	    values ('Fulgencio Suicida', 'AN-502520', 'lalolambda@hotmail.com', '3012978679');

insert into tblAUDITORS(auditor_name, auditor_mp, auditor_mail, auditor_cel) 
	    values ('No Aplica', 'No Aplica', '', '');
insert into tblAUDITORS(auditor_name, auditor_mp, auditor_mail, auditor_cel) 
	    values ('Ricardo Ordui', 'CU-202529', 'rigualisto@unal.edu.co', '3005938675');
insert into tblAUDITORS(auditor_name, auditor_mp, auditor_mail, auditor_cel) 
	    values ('Mariana Solano', 'CL-308765', 'marianilla@hotmail.com', '3117938478');

insert into tblEVENTTYPE (event_type) values ('Creacion de usuario');
insert into tblEVENTTYPE (event_type) values ('Edición de usuario');
insert into tblEVENTTYPE (event_type) values ('Eliminación de usuario');
insert into tblEVENTTYPE (event_type) values ('Creación de inspector');
insert into tblEVENTTYPE (event_type) values ('Edicion de inspector');
insert into tblEVENTTYPE (event_type) values ('Eliminación de inspector');
insert into tblEVENTTYPE (event_type) values ('Creación de diseñador');
insert into tblEVENTTYPE (event_type) values ('Edicion de diseñador');
insert into tblEVENTTYPE (event_type) values ('Eliminación de diseñador');
insert into tblEVENTTYPE (event_type) values ('Creación de constructor');
insert into tblEVENTTYPE (event_type) values ('Edicion de constructor');
insert into tblEVENTTYPE (event_type) values ('Eliminación de constructor');
insert into tblEVENTTYPE (event_type) values ('Creación de interventor');
insert into tblEVENTTYPE (event_type) values ('Edición de interventor');
insert into tblEVENTTYPE (event_type) values ('Eliminación de interventor');
insert into tblEVENTTYPE (event_type) values ('Login');
insert into tblEVENTTYPE (event_type) values ('Logout');
insert into tblEVENTTYPE (event_type) values ('Nueva cotización con cliente');
insert into tblEVENTTYPE (event_type) values ('Nueva cotización');
insert into tblEVENTTYPE (event_type) values ('Edición de cotización');
insert into tblEVENTTYPE (event_type) values ('Edición de cliente');
insert into tblEVENTTYPE (event_type) values ('Eliminación de cotización');
insert into tblEVENTTYPE (event_type) values ('Nueva propuesta');
insert into tblEVENTTYPE (event_type) values ('Edición de propuesta');
insert into tblEVENTTYPE (event_type) values ('Eliminación de propuesta');
insert into tblEVENTTYPE (event_type) values ('Nueva orden de servicio');
insert into tblEVENTTYPE (event_type) values ('Edición de orden de servicio');
insert into tblEVENTTYPE (event_type) values ('Eliminación de orden de servicio');
insert into tblEVENTTYPE (event_type) values ('Impresión de propuesta');
insert into tblEVENTTYPE (event_type) values ('Impresión de orden de servicio');
insert into tblEVENTTYPE (event_type) values ('Facturación de orden de servicio');
insert into tblEVENTTYPE (event_type) values ('Abono a factura');
insert into tblEVENTTYPE (event_type) values ('Abono a inspector');
insert into tblEVENTTYPE (event_type) values ('Abono a comercial');
insert into tblEVENTTYPE (event_type) values ('Saldo cero factura');
insert into tblEVENTTYPE (event_type) values ('Saldo cero inspector');
insert into tblEVENTTYPE (event_type) values ('Saldo cero comercial');
insert into tblEVENTTYPE (event_type) values ('Expediente completo archivado');
insert into tblEVENTTYPE (event_type) values ('Expediente incompleto archivado');
insert into tblEVENTTYPE (event_type) values ('Creación de AZ');
insert into tblEVENTTYPE (event_type) values ('Expediente radicado');
insert into tblEVENTTYPE (event_type) values ('Expediente enviado');
insert into tblEVENTTYPE (event_type) values ('Expediente con observaciones');
insert into tblEVENTTYPE (event_type) values ('Inspección procesada');
insert into tblEVENTTYPE (event_type) values ('Inspección editada');
insert into tblEVENTTYPE (event_type) values ('Inspección finalizada');
insert into tblEVENTTYPE (event_type) values ('Dictamen procesado');
insert into tblEVENTTYPE (event_type) values ('Dictamen editado');
insert into tblEVENTTYPE (event_type) values ('Consectuvos añadidos');
insert into tblEVENTTYPE (event_type) values ('Consecutivo editado');
insert into tblEVENTTYPE (event_type) values ('Impresión de dictamen');
insert into tblEVENTTYPE (event_type) values ('Impresión de consecutivo');

-- insert into tblINSPECTIONS (inspection_state_docs, inspection_observ_docs, inspection_state_tech, inspection_observ_tech, so_id, designer_id, constructor_id, auditor_id, record_id) 
-- 	    values ('Correcto', 'Completo', 'Correcto', 'Correcto', 1, 1, 1, 1, 1);
-- insert into tblINSPECTIONS (inspection_state_docs, inspection_observ_docs, inspection_state_tech, inspection_observ_tech, so_id, designer_id, constructor_id, auditor_id, record_id) 
-- 	    values ('Incorrecto', 'Falta Declaración de Tatata', 'Correcto', 'Correcto', 2, 2, 2, 2, 2);
-- insert into tblINSPECTIONS (inspection_state_docs, inspection_observ_docs, inspection_state_tech, inspection_observ_tech, so_id, designer_id, constructor_id, auditor_id, record_id) 
-- 	    values ('Correcto', 'Completo', 'Incorrecto', 'Regulación del alimentador por debajo', 3, 3, 1, 2, 2);
