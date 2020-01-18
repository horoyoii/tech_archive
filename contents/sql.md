 
# SQL (Structured Query Language)  

DDL : CREATE / DROP / ALTER / RENAME / COMMENT / TRUNCATE  
DML : SELECT / INSERT / DELETE / UPDATE / MERGE / CALL  
DCL : GRANT / REVOKE  
 ㄴ TCL : COMMIT / ROLLBACK / SAVEPOINT / SET TRANSACTION
 
 
## DDL (Data Definition Language)  

used to define the database structure or scheme.  
  * Domain constraints, Referentail Integrity 등을 정의한다.  
  * 테이블의 구조, 제약조건을 정의  

#### CREATE
  * used to create a table or database  
  
```
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    CHECK (Age>=18)
);

CREATE DATABASE testDB;
```

 * **Constraints** can be set in create statements.  
 [제약조건] 은 데이터베이스에서 '데이터 무결성'을 지키기 위한 조건.  
 -> create 이나 alter로 추가 가능.  
 
 1. NOT NULL :  
 2. UNIQUE :  
 3. PRIMARY KEY
 4. FOREIGN KEY 
 ```
 CREATE TABLE mytable(
    ID int,
    parentId int,
    PRIMARY KEY(ID),
    FOREIGN KEY(parentId) REFERENCES TestDB(tid) ON 
 );
 ```
 5. AUTO_INCREMENT  
 
 
 #### ALTER  
   * 기존 테이블 구조 변경 및 제약조건 수정   
```
ALTER TABLE Persons
MODIFY COLUMN FirstName varchar(255) NOT NULL;  // 기존 컬럼에 제약조건 추가

ADD phone varchar(12) NOT NULL; // 새로운 컬럼 추가
```

#### DROP  
```
DROP TABLE `sample_table`;  
```

#### RENAME  
```
RENAME TABLE `current_table_name` TO `new_table_name`;
```

## DML (Data Manipulation Language)  

#### INSERT  
```
INSERT INTO Reservation(ID, Name, ReserveDate, RoomNum)
VALUES(5, '이순신', '2016-02-16', 1108);
```

#### DELETE  
 * 명시적인 레코드 제거  
```
DELETE FROM Reservation
WHERE Name = '홍길동';
```

#### UPDATE  
```
UPDATE Reservation
SET RoomNum = 20002
WHERE Name = '홍길동';
```

#### SELECT  
```
SELECT *
FROM Reservation
WHERE Name = '홍길동';
```
```
SELECT *
FROM Reservation
WHERE ID <= 3 AND ReserveDate > '2016-02-01';
```

```
SELECT DISTINCT Name
FROM Reservation;
```
```
SELECT * 
FROM Reservation
ORDER BY ReserveDate; // 기준으로 정렬 (DESC) 추가시 내림차순
```

## DCL (Data Control Language)  
  * used to **control access to data**.  
  * about authorization  
  
#### GRANT  
  * 특정 유저에게 특정 기능 부여  
```
GRANT DELET, INSERT, SELECT, UPDATE ON testdb.* TO 'horoyoi@localhost';
```
#### REVOKE  
  * 특정 유저에게 특정 기능 박탈  
```
REVOKE INSERT on class.* FROM horoyoii;
```

-> TCL(Transaction Control language)로 세부분류되기도 함.  
#### COMMIT  
  * permanently save any transaction into the database.  
#### ROLLBACK  
  * restores the database to last committed state.  
#### SAVEPOINT  
 * rollback to the save point  
