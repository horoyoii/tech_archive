
# Introduction to Index  

**mysql 서버에서 임의의 100만개의 데이터로 실헝해본 결과  index 사용 시 select query수행시간은 350배 상승**  

[good site](https://www.vertabelo.com/blog/what-is-a-database-index/)  

  When database performance is no longer satisfactory,  
one of the very first thing is database indexing.  

  In general, a database index is a **data structure** used to **improve queries execution time**  

## Understanding heap tables  

  **Heap** table is where data is stored in no particular order. new data is inserted  
without sorting or reorganizing previosly inserted data in any way.  

  -> 테이블이 힙이라면, 물리적 디스크 상에서 데이터들은 특정 순서 없이, 삽입되는 순으로 저장.  
  -> 이는 **INSERT**는 빠르지만, **RETRIEVE**는 느림.  
  
|ssn|first_name|last_name|
|:----:|:----:|:----:|
|'111-22-333'|'horoyoii'|'anysoon'|  

* 100만개의 row가 특정 순서없이 저장되어 있을 때,   
![스크린샷, 2020-01-18 14-10-37](https://user-images.githubusercontent.com/34915108/72659020-94403880-39fc-11ea-89b3-a801fece23d9.png)
* Heap table에서는 insert는 빠르지만...
![스크린샷, 2020-01-18 14-10-41](https://user-images.githubusercontent.com/34915108/72659021-95716580-39fc-11ea-84fb-4efcf986543a.png)
* select는 느림.  
-> This is because the data is not structured in any specific way.   
-> In order to fetch the required rows, the DB needs to scan the whole table.  


## Creating an index  

  We can speed up the query execution time by creating an index on column.  
![스크린샷, 2020-01-18 14-17-00](https://user-images.githubusercontent.com/34915108/72659065-3cee9800-39fd-11ea-8942-db2c6dd9308b.png)

  * 인덱스 생성에는 시간이 소요 
![스크린샷, 2020-01-18 14-17-05](https://user-images.githubusercontent.com/34915108/72659066-3d872e80-39fd-11ea-9420-b277d59ebcbc.png)

  * select의 where절에서 index로 선택된 column이 사용되어 쿼리 수행 시간이 단축됨. 350배 정도.  
  
 1) This time the DB used the index, not the table for query execution.  
 2) The index holds ssn column values as a **key** and pointer to the corresponding  
 table rows as a **value** in a well-organized data structure like B+tree.  
 3) when executing the query, the index structure is **traversed** to collect all  
 pointers to rows that match the **filter predicate**.  
 4) This huge performance gain is due to the fact that not entire index structure  
 but only part of it is visited.  
 
```
test=> select * from people where ssn = '111-22-3334' or last_name = 'Johnson';
 
Time: 238,426 ms
```
This execution time got significantly worse.  
This is because the DB needs to scan the whole table to find the matching rows to last_name.  

To make such a query run faster, we'd need to create a second index on 'last_name' column.  

```
test=> create index ln_idx on people (last_name); 
CREATE INDEX
 
Time: 13234,828 ms
```

```
test=> select * from people where ssn = '111-22-3334' or last_name = 'Johnson'; 
 
Time: 7,207 ms
```
