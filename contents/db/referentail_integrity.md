
# Referential Integrity  
  * 참조 무결성  
  
## 1. What is this?  

  1) RDBMS에서는 여러 테이블들은 서로 관계를 맺을 수 있다.  
  2) 이 관계는 부모 테이블의 primary key를 참조하는 foreign key를 자식 테이블이 가져서 구현됨.  
  3) 그렇기에 **테이블 간의 관계를 intact하게 유지하는 것**이 참조 무결성이다.  
  
## 2. Example  

 * 참조 무결성이 위배된 경우  
 1) 부모 테이블에서 pk가 15인 record를 삭제 시  
 2) 자식 테이블에서는 여전히 foreign key가 15인 record를 가지고 있다면  
 3) 이 record는 **Orphan record**가 된다.  
 
![스크린샷, 2020-01-27 19-33-28](https://user-images.githubusercontent.com/34915108/73167832-f1926300-413b-11ea-9ef8-7bd84556e55f.png)

## 3. Foreign key Constraint  

  * 외래 키 제약 조건 : Referential integrity를 지키기 위한 조건  
  * 부모 테이블의 pk에 대한 삭제, 업데이트 시 **자식 테이블에 대한 연계 동작을 정의**하여 참조 무결성을 지킬 수 있음.  

#### 3.1. NO ACTION (MySql - RESTRICT)  
  **부모 테이블의 레코드에 대한 삭제, (pk 자체에 대한)업데이트 시  
  자식 테이블의 레코드 중 그 레코드를 참조하는 것이 있다면 NO action(취소시킴)  
  
```
> alter table child 
add constraint foreign key(pid) 
references parent(pid) 
on delete restrict on update restrict;
```

* 자식 테이블 중 pid가 2가 있다면  
```
> delete from parent where pid = 2;
>> error
```
```
> update parent set pid= 4 where pid=2;
>> error 
```

#### 3.2. SET NULL  
  * 부모 테이블에 참조하고 있는 pk가 바뀌거나, 삭제되면 자식 테이블의 fk 필드를 NULL로...  
  
```
> alter table child 
add constraint foreign key(pid) references parent(pid) 
on delete set null on update set null;
```


#### 3.3. CASCADE  
  * 부모 테이블의 pk의 변경 혹은 삭제 시 이를 참조하고 있는 자식 테이블에서도 동일하게 동작  
  
```
> alter table child 
add constraint foreign key(pid) references parent(pid) 
on delete cascade on update cascade;
```
```
> update parent set pid=11 where pid=3;
-> 자식 테이블의 fk가 3인 모든 레코드가 fk필드값이 11됨

> delete from parent where pid=11;
-> 자식 테이블의 fk가 11인 모든 레코드가 삭제됨  
```
 

#### 3.4. SET DEFAULT  
  * 부모 테이블이 변경 시, 사용자에게 지정된 디폴트 값으로 바뀜  
  
