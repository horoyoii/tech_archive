
# Join  

  * join 혹은 sql join statement 란 **두 개 이상의 테이블을 공통 필드를 바탕으로 결합하는 것**  
  
## 1. Types of Join SQL    

  * 조인에는 **inner join**, **left join**, **right join**, **full join**이 있다.  
  * 더불어 **self join**, **equi join**  
  
  ![스크린샷, 2020-02-18 17-00-10](https://user-images.githubusercontent.com/34915108/74715641-2d6aa500-5270-11ea-88c3-2407745a9804.png)  

#### 1.0 OUTER 는 동일하다.  
  * OUTER 란 공통필드 외에 나머지 부분도 포함을 의미  
  * LEFT JOIN이 곧 LEFT OUTER JOIN  

```sql
A LEFT JOIN B       =     A LEFT OUTER JOIN B
A RIGHT JOIN B      =     A RIGHT OUTER JOIN B
A FULL JOIN B       =     A FULL OUTER JOIN B
A INNER JOIN B      =     A JOIN B
```

![스크린샷, 2020-02-18 17-05-37](https://user-images.githubusercontent.com/34915108/74716433-e67daf00-5271-11ea-9493-09cf4122b351.png)  


#### 1.1 Inner join  
  
  * 교집합 : join의 조건 (ON 절 뒤에 오는)을 충족하는 모든 rows를 결합하여 **result set**을 만듦    
  
```sql
//ANSI/ISO SQL 표준 방식

SELECT * FROM Customer
INNER JOIN City
ON Customer.CityId = City.CityId
```
 ![스크린샷, 2020-02-18 17-08-50](https://user-images.githubusercontent.com/34915108/74716394-ce0d9480-5271-11ea-884c-c27479e744b9.png)  
 
 
#### 1.2. Left join  

  * 조인 대상이 되는 left size의 테이블을 모두 포함하되, join의 조건이 일치하는 경우 right size테이블의 row를  
  결합하고, 일치하지 않는 left size의 row는 나머지 필드가 null로 채워짐.   
  
```sql
//ANSI/ISO SQL 표준 방식

SELECT * FROM Customer
LEFT JOIN City
ON Customer.CityId = City.CityId
```

![스크린샷, 2020-02-18 17-12-00](https://user-images.githubusercontent.com/34915108/74716400-cfd75800-5271-11ea-9786-27e508d2ccff.png)  


#### 1.3. Right join  
 
  * right size 테이블의 모둔 row를 result set에 포함하고, join 조건이 일치하는 left size의 row를 결합시키되,  
  join 조건이 일치하지 않는 필드는 null로 채운다.  
  

```sql
//ANSI/ISO SQL 표준 방식

SELECT * FROM Customer
RIGHT JOIN City
ON Customer.CityId = City.CityId
```  

![스크린샷, 2020-02-18 17-14-56](https://user-images.githubusercontent.com/34915108/74716595-352b4900-5272-11ea-8b2d-924d02873a6f.png)  


#### 1.4. Full join  

  * left join의 결과셋과, right join의 결과셋을 합친 것  
  
```sql
SELECT * FROM Customer
FULL JOIN City
ON Customer.CityId = City.CityId
```

![스크린샷, 2020-02-18 17-18-45](https://user-images.githubusercontent.com/34915108/74716889-bd115300-5272-11ea-80be-d0a53be89f22.png)  


#### 1.5. EQUI JOIN  

  * 두 테이블을 조인하되, = 연산자만을 사용하여 조인하는 것  
```sql 
SELECT * 
FROM T1, T2
WHERE T1.city_name = T2.city_name;
```
  * equi join 과 inner join의 차이  
  **equi join의 조인 조건절에는 = 연산자만 올 수 있고, inner join의 조건절에는 다른 연산자들도 올 수 있음.**  
  
  
 
 ## 2. MySQL 은 full join을 지원하지 않기에 left join과 right join을 **union**하여 사용한다  
 
   * UNION 이란 집합 연산자 중 하나로서, **중복된 행을 제외한다.** 
   
```sql
SELECT * FROM Customer 
LEFT JOIN City
ON Customer.CityId = Customer.CityId
UNION
SELECT * FROM Customer 
RIGHT JOIN City
ON Customer.CityId = Customer.CityId
```

## 3. ANSI SQL 과 Oracle SQL  

#### 3.1 ANSI SQL  
```sql
select * from t1
join t2
on t1.col = t2.col
```

#### 3.2 Oracle SQL  
```sql
select * 
from t1, t2
where t1.col = t2.col
```

#### 3.3. 장단점  

  * **ANSI sql은 표준이기에 대부분의 dbms와 호환된다.**  
  * 하지만 기본적인 sql 외에, 특정 dbms 밴더가 제공하는 sql을 사용할 수 없다. 

