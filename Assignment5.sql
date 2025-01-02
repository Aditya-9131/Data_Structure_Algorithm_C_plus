CREATE DATABASE Assignment5;
USE Assignment5;

CREATE TABLE department (
    did INT,
    dname VARCHAR(20),
    building VARCHAR(20),
    budget NUMERIC(8,2),
    PRIMARY KEY (did)
);

CREATE TABLE faculty (
    fid INT,
    fname VARCHAR(20),
    did INT,
    salary NUMERIC(8,2),
    PRIMARY KEY (fid),
    FOREIGN KEY (did) REFERENCES department(did)
);

CREATE TABLE student (
    sid INT,
    sname VARCHAR(20),
    age INT,
    did INT,
    PRIMARY KEY (sid),
    FOREIGN KEY (did) REFERENCES department(did)
);

CREATE TABLE course (
    cid INT,
    cname VARCHAR(20),
    credit INT,
    did INT,
    PRIMARY KEY (cid),
    FOREIGN KEY (did) REFERENCES department(did)
);

CREATE TABLE teaches (
    fid INT,
    cid INT,
    PRIMARY KEY (fid, cid),
    FOREIGN KEY (fid) REFERENCES faculty(fid),
    FOREIGN KEY (cid) REFERENCES course(cid)
);

CREATE TABLE takes (
    sid INT,
    cid INT,
    PRIMARY KEY (sid, cid),
    FOREIGN KEY (sid) REFERENCES student(sid),
    FOREIGN KEY (cid) REFERENCES course(cid)
);

CREATE TABLE advisor (
    sid INT,
    fid INT,
    title VARCHAR(100),
    PRIMARY KEY (sid),
    FOREIGN KEY (sid) REFERENCES student(sid),
    FOREIGN KEY (fid) REFERENCES faculty(fid)
);

-- Department table
INSERT INTO department (did, dname, building, budget)
VALUES (1, 'Computer Science', 'Smith Building', 100000.00),
       (2, 'Mathematics', 'Jones Hall', 80000.00),
       (3, 'Physics', 'Newton Tower', 120000.00);

-- Faculty table
INSERT INTO faculty (fid, fname, did, salary)
VALUES (101, 'John Smith', 1, 80000.00),
       (102, 'Emily Johnson', 1, 75000.00),
       (103, 'Michael Brown', 2, 70000.00),
       (104, 'Emma Davis', 3, 85000.00);

-- Student table
INSERT INTO student (sid, sname, age, did)
VALUES (1001, 'Alice Johnson', 20, 1),
       (1002, 'Bob Smith', 22, 1),
       (1003, 'Charlie Brown', 21, 2),
       (1004, 'Diana Davis', 23, 3);

-- Course table
INSERT INTO course (cid, cname, credit, did)
VALUES (201, 'Introduction to Programming', 3, 1),
       (202, 'Linear Algebra', 4, 2),
       (203, 'Mechanics', 3, 3);

-- Teaches table
INSERT INTO teaches (fid, cid)
VALUES (101, 201),
       (103, 202),
       (104, 203);

-- Takes table
INSERT INTO takes (sid, cid)
VALUES (1001, 201),
       (1002, 202),
       (1003, 202),
       (1004, 203);

-- Advisor table
INSERT INTO advisor (sid, fid, title)
VALUES (1001, 101, 'Software Engineering Project'),
       (1002, 102, 'Database Management Project');


SELECT d.dname
FROM department d
INNER JOIN course c ON d.did = c.did
GROUP BY d.dname
HAVING COUNT(*) >= 2;

SELECT d.dname
FROM department d
INNER JOIN course c ON d.did = c.did
GROUP BY d.dname
HAVING COUNT(*) <= 2;

SELECT d.dname
FROM department d
INNER JOIN course c ON d.did = c.did
GROUP BY d.dname
ORDER BY COUNT(*) DESC
LIMIT 1;

SELECT d.dname
FROM department d
INNER JOIN course c ON d.did = c.did
GROUP BY d.dname
ORDER BY COUNT(*) ASC
LIMIT 1;


SELECT cname
FROM course
ORDER BY credit DESC
LIMIT 1 OFFSET 1;

SELECT DISTINCT f.fname
FROM faculty f
INNER JOIN advisor a ON f.fid = a.fid
WHERE a.title LIKE '%AI%';

SELECT fname
FROM faculty
WHERE fid NOT IN (SELECT DISTINCT fid FROM teaches);

SELECT DISTINCT f.fname
FROM faculty f
INNER JOIN teaches t ON f.fid = t.fid
INNER JOIN course c ON t.cid = c.cid
WHERE c.did <> f.did;

SELECT DISTINCT f.fname
FROM faculty f
LEFT JOIN teaches t ON f.fid = t.fid
LEFT JOIN course c ON t.cid = c.cid
WHERE f.did = c.did AND c.did IS NOT NULL;

SELECT DISTINCT f.fname
FROM faculty f
LEFT JOIN teaches t ON f.fid = t.fid
LEFT JOIN course c ON t.cid = c.cid
WHERE f.did <> c.did AND c.did IS NOT NULL;

SELECT c.cname
FROM course c
INNER JOIN takes t ON c.cid = t.cid
INNER JOIN student s ON t.sid = s.sid
GROUP BY c.cname
ORDER BY AVG(s.age) ASC
LIMIT 1;

CREATE TABLE Marks (
    sid INT,
    cid INT,
    marks INT,
    PRIMARY KEY (sid, cid),
    FOREIGN KEY (sid) REFERENCES student(sid),
    FOREIGN KEY (cid) REFERENCES course(cid)
);

-- 12. Find the student who is overall topper.
SELECT s.sid, s.sname, SUM(m.marks) AS total_marks
FROM student s
JOIN marks m ON s.sid = m.sid
GROUP BY s.sid, s.sname
ORDER BY total_marks DESC
LIMIT 1;

-- 13. Find the course where maximum students got more than 50 marks.
SELECT cid, cname
FROM (
    SELECT cid, COUNT(*) AS num_students
    FROM marks
    WHERE marks > 50
    GROUP BY cid
    ORDER BY num_students DESC
    LIMIT 1
) AS max_students
JOIN course ON max_students.cid = course.cid;

-- 14. Find the course where all students got 70 marks.
SELECT cid, cname
FROM (
    SELECT cid, COUNT(*) AS num_students
    FROM marks
    WHERE marks = 70
    GROUP BY cid
    HAVING COUNT(*) = (SELECT COUNT(*) FROM student)
) AS all_students
JOIN course ON all_students.cid = course.cid;

-- 15. Assign grades based on average marks of students.
SELECT sid, AVG(marks) AS avg_marks,
    CASE
        WHEN AVG(marks) >= 80 THEN 'AA'
        WHEN AVG(marks) >= 60 THEN 'AB'
        WHEN AVG(marks) >= 40 THEN 'BB'
        WHEN AVG(marks) >= 20 THEN 'BC'
        ELSE 'F'
    END AS grade
FROM marks
GROUP BY sid;

-- 16. Function: Given the name of a department, return the count of the number of instructors in that department.
CREATE FUNCTION CountInstructorsInDepartment(department_name VARCHAR(20))
RETURNS INT
BEGIN
    DECLARE instructor_count INT;
    SELECT COUNT(*)
    INTO instructor_count
    FROM faculty f
    JOIN department d ON f.did = d.did
    WHERE d.dname = department_name;
    RETURN instructor_count;
END;

-- 17. Using the above function, find the information about the department where there are two or more instructors.
SELECT dname
FROM department
WHERE CountInstructorsInDepartment(dname) >= 2;

-- 18. Function: Given a salary, return the number of instructors who are receiving that salary.
CREATE FUNCTION CountInstructorsWithSalary(target_salary NUMERIC(8,2))
RETURNS INT
BEGIN
    DECLARE instructor_count INT;
    SELECT COUNT(*)
    INTO instructor_count
    FROM faculty
    WHERE salary = target_salary;
    RETURN instructor_count;
END;

-- 19. Using the above function, find the number of instructors whose salary is 100.
SELECT CountInstructorsWithSalary(100);

-- 20. Find the information about the instructor where there is at least two instructors who are receiving the same salary as him/her.
SELECT f1.fname, f1.salary
FROM faculty f1
JOIN faculty f2 ON f1.salary = f2.salary AND f1.fid != f2.fid
GROUP BY f1.fname, f1.salary;



