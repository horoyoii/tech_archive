## Key Types  
[참고](https://www.studytonight.com/dbms/database-key.php)  

### Introduction to Database Keys  

  * Keys in DB are used to establish and identify relationships between tables  
  and also to uniquely identify any record or row inside a table.  
  
  * Key는 단일 attribute(column)으로 구성될 수 있을 뿐만 아니라 여러 attribute의 조합으로도 만들 수 있다.  
  * 무슨 무슨 키라함은 전부 테이블 내의 레코드에 대한 유일한 식별성을 내포.  
  
### Super Key  
  * a set of attributes within a table that can uniquely identify each record.  

### Cadidate Key  
  * a **minimal** set of attributes within a table which can uniquely identify each record.  
  * super 키 중 <<최소한의 속성>>으로 구성되어야 한다는 조건이 추가.  
  
### Primary Key  
  * Primary key is a one of the candidate keys that is most appropriate.  
  * PK : 테이블 안에서 각 레코드를 유일하게 식별가능한 attribute의 최소 집합을 후보 키라고 하고,  
  그중 가장 적절한 하나의 키가 PK  

### Composite Key  
  * Key that consists of two or more attributes that uniquely identify any record in a table.  
  * 조합 키 역시 유일한 식별성을 가져야 함.  
  ![스크린샷, 2020-01-14 18-17-22](https://user-images.githubusercontent.com/34915108/72330615-2644fa00-36fa-11ea-98f1-795b5acab2bc.png)
  
  - (student_id, subject_id) is a composite key as well as a primary key.  
  
### Secondary or Alternative Key  
  * keys within a set of candidate keys but not selected as primary key.  
  

### Foreign Key  

#### Customer Table  
|customer_id|name |phone|address | 
|:----:|:----:|:----:|:----:|
| 1 | horoyoii |010 |aaaa |
| 2 | yeong |0101 |bbbb |
 
 #### Order Table  
|o_id| order_data | c_id | food | 
|:----:|:----:|:----:|:----:|
| 1 | 0901 |1 | chicken |
| 2 | 0402 |2 |pizza | 
| 3 | 0402 |1 | cola |
| 4 | 0402 |1 | pta |


```
CREATE TABLE Customer(
    customer_id int,
    name VARCHAR(255) NOT NULL,
    phone VARCHAR(255),
    address VARCHAR(255),
    PRIMARY KEY(c_id)
);

CREATE TABLE Order(
    o_id int NOT NULL,
    order_date int,
    c_id int,
    food varchar(255),
    PRIMARY KEY(o_id),
    FOREIGN KEY(c_id) REFERENCES Customer(customer_id)
);

SELECT c.customer_id, o.food 
FROM Customer c, Order o 
WHERE c.name = 'horoyoii';
```

  * 한 테이블(Order)의 필드 중 (c_id) **다른 테이블의 행을 식별할 수 있는 키**  
  
   



  ![스크린샷, 2020-01-14 18-21-00](https://user-images.githubusercontent.com/34915108/72330909-aa977d00-36fa-11ea-9c93-0a39ab34c53c.png)
  
