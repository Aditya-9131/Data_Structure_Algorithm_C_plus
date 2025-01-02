create database Assignment3;
USE Assignment3;
CREATE TABLE department(
	did INT PRIMARY KEY,
    dname VARCHAR(20),
    Building VARCHAR(20),
    Budget NUMERIC(8,2)
);

CREATE TABLE faculty (
	fid INT PRIMARY KEY,
    fname VARCHAR(20),
    did INT,
    salary NUMERIC(8,2),
    FOREIGN KEY(did)
    REFERENCES
    department(did)
);

CREATE TABLE student (
	sid INT PRIMARY KEY,
    sname VARCHAR(20),
    age INT,
    did INT,
    FOREIGN KEY(did)
    REFERENCES
    department(did)
);

CREATE TABLE course(
	cid INT PRIMARY KEY,
    cname VARCHAR(20),
    credit INT,
    did INT,
    FOREIGN KEY(did)
    REFERENCES
    department(did)
);

CREATE TABLE teaches(
	fid INT, 
    cid INT,
    PRIMARY KEY(fid,cid),
    FOREIGN KEY(fid)
    REFERENCES
    faculty(fid),
    FOREIGN KEY(cid)
    REFERENCES
    course(cid)
);

CREATE TABLE takes(
	sid INT, 
    cid INT,
    PRIMARY KEY(sid,cid),
    FOREIGN KEY(sid)
    REFERENCES
    student(sid),
    FOREIGN KEY(cid)
    REFERENCES
    course(cid)
);

CREATE TABLE advisor(
	sid INT PRIMARY KEY,
    fid INT,
    title VARCHAR(100),
    FOREIGN KEY(fid)
    REFERENCES
    faculty(fid),
    FOREIGN KEY(sid)
    REFERENCES
    student(sid)
);
	

INSERT INTO department VALUES (101, 'CSE', 'CSE_DEPT_BUILDING', 500000.50),
                             (102, 'ECE', 'ECE_DEPT_BUILDING', 450000.00),
                             (103, 'EEE', 'EEE_DEPT_BUILDING', 300000.00),
                             (104,'MECH','MECH_DEPT_BUILDING',600000.00);

INSERT INTO faculty VALUES (11,'SUMIT MISHRA','101',999999.99),
							(12,'AKSHIT','101',111111.11),
                            (13,'RIPUDAMAN','102',100000.00),
                            (14,'ANURADHA','104',150000.00),
                            (15,'DEPENDU','104',110000.50),
                            (16,'SIKHA DEKA','101',150000.60);

INSERT INTO student VALUES (1001,'HARINARAYAN',21,101),
							(1002,'KESHAV',19,102),
                            (1003,'KAUSHAL',23,101),
                            (1004,'CHANDAN',19,101),
                            (1005,'DIVENDU VATS',20,102),
                            (1006,'HEMANT PORWAL',22,102),
                            (1007,'NITISH',25,104),
                            (1008,'TAJ',35,104),
                            (1009,'KAHANI',23,101),
                            (1010,'AADITYA',25,103);
                            
INSERT INTO course VALUES (1,'ALGO',6,101),
							(2,'OS',8,101),
                            (3,'AI',6,101),
                            (4,'DD',6,102),
                            (5,'MA',8,104),
                            (6,'DBMS',6,101),
                            (7,'JAVA',7,103);
                            
INSERT INTO teaches VALUES (11,1),
							(11,6),
                            (12,3),
                            (16,6),
                            (14,5),
                            (15,5),
                            (13,4);
						
INSERT INTO takes VALUES (1001,1),
						(1001,3),
                        (1002,4),
                        (1003,2),
                        (1004,3),
                        (1008,5),
                        (1010,7);
                        
INSERT INTO advisor VALUES (1001,11,'PROJECT_1'),
							(1002,13,'PROJECT_2'),
                            (1003,11,'PROJECT_1'),
                            (1004,16,'PROJECT_3');
                            
-- These inserts are for signifying changes in question 1 and 2 

INSERT INTO faculty VALUES(17,'AKSHIT',101,100000.90);    

INSERT INTO department VALUES(105,'ECE','ECE2_DEPT_BUILDING',120000.12);  

-- Question 1 

SELECT *
FROM faculty;                      

SELECT DISTINCT fname
FROM faculty;

-- Question 2

SELECT *
FROM department;

SELECT DISTINCT dname
FROM department;

-- Question 3

SELECT fname
FROM faculty NATURAL JOIN teaches
WHERE teaches.cid='5';

-- Question 4

SELECT DISTINCT sname
FROM student NATURAL JOIN takes;

-- Question 5