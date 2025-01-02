CREATE DATABASE Assignment4;
USE Assignment4;
-- Create Table Department
CREATE TABLE department(
did INT,
dname VARCHAR(20),
building VARCHAR(20),
budget NUMERIC(8,2)
);

-- Create faculty table

CREATE TABLE faculty(
fid INT,
fname VARCHAR(20),
did INT,
salary NUMERIC(8,2)
);
-- Create student table
CREATE TABLE student(
sid INT,
sname VARCHAR(20),
age INT,
did int
);
CREATE TABLE course (
    cid INT,
    cname VARCHAR(20),
    credit INT,
    did INT
);
-- Create teaches table
CREATE TABLE teaches (
    fid INT,
    cid INT
);
-- Create takes table
CREATE TABLE takes (
    sid INT,
    cid INT
);
-- Create advisor table
CREATE TABLE advisor (
    sid INT,
    fid INT,
    title VARCHAR(100)
);
-- Insert sample data into department table
INSERT INTO department VALUES(101, 'CSE', 'CSE_DEPT_BUILDING', 500000.50),
                             (102, 'ECE', 'ECE_DEPT_BUILDING', 450000.00),
                             (103, 'EEE', 'EEE_DEPT_BUILDING', 300000.00),
                             (104,'MECH','MECH_DEPT_BUILDING',600000.00);
INSERT INTO faculty VALUES (11,'SUMIT MISHRA','101',999999.99),
							(12,'AKSHIT','101',111111.11),
                            (13,'SUMIT MISHRA','102',100000.00),
                            (14,'ANURADHA','104',150000.00),
                            (15,'SUMIT MISHRA','104',110000.50),
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
-- 1. Find the total number of courses.

SELECT COUNT(*) AS total_course FROM course;

-- Find the total number of courses which are taken by more than two students.

SELECT COUNT(*) AS Course_taken_more_than_two
FROM(
    SELECT cid, COUNT(*) AS num_students
    FROM takes 
    GROUP BY cid 
    HAVING COUNT(*)>2
    )AS Course;
    -- Find the courses with the maximum number of students
    -- (if there is more than one such course then show all such courses).
    
    SELECT cid , COUNT(*) AS num_students
    FROM takes
    GROUP BY cid
    HAVING COUNT(*)=(
       SELECT MAX(num_Students)
       FROM(
         SELECT COUNT(*) AS num_students
         FROM takes
         GROUP BY cid
         )AS course_counts
         );
    -- Find the name of the faculty which is teaching more than two courses.
-- sql
SELECT f.fname
FROM faculty f
JOIN teaches t ON f.fid = t.fid
GROUP BY f.fid, f.fname
HAVING COUNT(*) > 2;
-- Find the name of the faculty which is an advisor to more than four courses.

SELECT f.fname
FROM faculty f
JOIN advisor a ON f.fid = a.fid
GROUP BY f.fid, f.fname
HAVING COUNT(*) > 4;

-- Find the name of the faculty who is teaching the courses with maximum credit (individual course).
-- sql
 SELECT f.fname
FROM faculty f
JOIN teaches t ON f.fid = t.fid
JOIN course c ON t.cid = c.cid
WHERE c.credit = (
    SELECT MAX(credit) FROM course
);

-- Find the name faculty who is teaching the courses with maximum credit (all courses of the faculty combined).
SELECT f.fname
FROM faculty f
JOIN teaches t ON f.fid = t.fid
JOIN course c ON t.cid = c.cid
GROUP BY f.fname
HAVING SUM(c.credit) = (
    SELECT MAX(total_credit)
    FROM (
        SELECT SUM(credit) AS total_credit
        FROM course
        GROUP BY did
    ) AS max_credit
);





