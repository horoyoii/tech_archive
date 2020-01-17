
# Transaction Isolation levels  

## Prerequisted  

#### 1. Consistency  

  * Data cannot be written that would violate **the database's own rules for valid data**  
  1. **Data consistency**는 database의 defined rules에 위배되지 않는 상태를 유지하는 것.   
  2. a tranaction will be allowed to modify data only if the transaction complies with the predined db rules.  
  
  ```
  database's predefined rules :
  A simple rule of consistency may state that the 'Gender' attribute should have the valuues 
  'Male', 'Female', 'Unkwon'.
  
  Constraints, Cascades, triggers 등등
  ```

#### 2. Transaction  

##### a logical unit of works | 작업의 논리적인 단위  

```
Trx는 단일 연산이 아닐 수가 있다. A의 돈을 빼고, B의 돈을 더하는 두 개의 연산.
이 두가지의 연산이 합쳐져야 "계좌이체"라는 논리적인 하나의 작업 단위가 나옴.
불행히도, 이 두가지 연산은 원자적으로 동시에 실행될 수 없다. 
그렇기에 트랜젝션의 속성으로 All of Nothing을 구현하여 원자성을 보장한다.  
```

#### ACID  
  In order to maintain **consistency** in a database, transaction has four properties.  
  
  1. **Atomicity** : The tasks composing a transaction should take place at once  
  or doesn't happend at all.  (All or nothing)  
  
  2. **Consistency** : Before and **After** the transaction, integrity constraints  
  must be maintained so that the database is consistent.  
  >> 트랜젝션 발생 전후에도 데이터베이스는 일관적인 상태가 유지되어야 한다.  
  >> 트랜잭션 발생 후에도 데이터베이스의 defined rule이 깨지면 안됨.  
  
  3. **Isolation** : 트랜젝션은 다른 트렌젝션의 간섭 없이 수행되어야 한다.  
  ```
  DBMS는 기본적으로 다중 사용자를 지원.  
  즉, 여러 트랜젝션이 동시에 발생할 수 있다. 
  서로 간섭없이 동시에 진행됨을 보장하여, sequential하게 진행했을 때와의 동일한 결과가 나오게 함.  
  ```
  
  4. **Durability** : Once the transaction has been completed, the result should be
  guaranteed to persist **even if a system fails**.  


## Isolation Levels  

**Isolation은 locking mechanism에 의존적이기에 **
**고립도가 증가할수록 Concurrency는 낮춰진다!!**  


### Isolation이 보장되지 않는 상황에서 다음 세 가지의 현상이 발생.  
  1. Dirty read  
  2. Non repeatble read  
  3. Phantom Read  

##### 1. Dirty Read  
  It is the situation that a transaction **reads a data that has not been commited**.  
  For example, T1 updates a row and leaves it uncommitted.  
  Meanwhile, T2 reads the updated row. 
  Then, if T1 **rolls back the changes**, T2 will have read data that never exists.  
  
##### 2. Non repeatable read  
  It occurs when a transaction reads same row twice.  
  For example, T1 reads a data. Due to concurrency, T2 updates the data and commit.  
  Now if T1 reads the data, it will retrieve a different value.  

##### 3. Phantom Read  
  In a range query, T1 retrieves a set of rows that satisfy the criteria.  
  Meanwhile, T2 insert a new row that also satisfy the criteria.  
  Then, T1 runs the same range query but the number of retrieved rows are different.  
  

### 고립도에 따라 위의 현상을 방지할 수 있다.  

  1. Read uncommitted  
  2. Read committed  
  3. Repeatbale Read  
  4. Serializable  
  
##### 1. Read uncommitted  

  In this level, one Trx may read not yet committed data made by ohter Trx,  
  thereby allowing dirty read.  
  
##### 2. Read committed  

  This level guarantees that only data that is committed at the moment can be read.  
  
  1. **Shared Lock** 은 statement 시작 시 획득, statement 종료 후 unlock  
  2. **Exclusive lock**은 statement 시작 시 획득, TRx 종료 후 unlock.  
  
##### 3. Repeatable Read  
  TRx의 연속된 read가 동일한 값을 가져오는 것이 보장.  
  -> T1이 특정 row 읽으면, 다른 모든 T는 그것에 대한 쓰기 불가.  
  
  1. **Shared Lock** 은 statement 시작 시 획득, TRx 종료 후 unlock.  
  2. **Exclusive lock**은 state,ent 시작 시 획득, TRx 종료 후 unlock.  
  
##### 4. Serializable  
  TRx 들이 시리얼하게 처리되기에, Concurrency는 최악.  
  

 **Repeatble read level에서는 Shared Lock이 statement 종료가 아닌, 트랜젝션 종료 시에  
 반환되기에 Non repeatable read 방지 가능** 
 
 
| |Dirty Read|Non repeatable read|Phantom Read|
|:----:|:----:|:----:|:----:|
|read uncommitted| ㅇ | ㅇ | ㅇ |
|read committed| x | ㅇ|ㅇ |
|repeatble read| x| x| o|
|serializable| x|x | x|

  
  
  

