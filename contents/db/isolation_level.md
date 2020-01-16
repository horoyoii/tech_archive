
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


##
