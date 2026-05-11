CREATE DATABASE db_firestation_muktasid;
USE db_firestation_muktasid;

CREATE TABLE tbl_firefighter (
    firefighter_id CHAR(8) NOT NULL,
    ff_name VARCHAR(100) NOT NULL,
    ff_contact VARCHAR(15) NOT NULL,
    ff_expertise VARCHAR(50) NOT NULL
);

CREATE TABLE tbl_incident (
    incident_id INT,
    in_threat VARCHAR(100) NOT NULL,
    in_street VARCHAR(100) NOT NULL,
    in_city VARCHAR(100) NOT NULL
);

CREATE TABLE tbl_dispatch (
    dispatch_id INT,
    firefighter_id CHAR(8) NOT NULL,
    incident_id INT NOT NULL
);


ALTER TABLE tbl_firefighter
ADD CONSTRAINT pk_tbl_firefighter PRIMARY KEY (firefighter_id);

ALTER TABLE tbl_incident
ADD CONSTRAINT pk_tbl_incident PRIMARY KEY (incident_id);

ALTER TABLE tbl_dispatch
ADD CONSTRAINT pk_tbl_dispatch PRIMARY KEY (dispatch_id);

ALTER TABLE tbl_incident
MODIFY incident_id INT AUTO_INCREMENT;

ALTER TABLE tbl_dispatch
MODIFY dispatch_id INT AUTO_INCREMENT;

ALTER TABLE tbl_dispatch
ADD CONSTRAINT fk_dispatch_firefighter
FOREIGN KEY (firefighter_id)
REFERENCES tbl_firefighter(firefighter_id)
ON DELETE NO ACTION
ON UPDATE CASCADE;

ALTER TABLE tbl_dispatch
ADD CONSTRAINT fk_dispatch_incident
FOREIGN KEY (incident_id)
REFERENCES tbl_incident(incident_id)
ON DELETE NO ACTION
ON UPDATE CASCADE;

ALTER TABLE tbl_firefighter
MODIFY ff_expertise ENUM(
    'Rescuer',
    'Medic',
    'Electric Technician',
    'Chemical Technician'
) NOT NULL;
