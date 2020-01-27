# 1. MySQL storage engine  
  * mysql의 내부 engine은 두 가지가 있다.  
#### 1. MyISAM  
  * 많은 기능이 없음으로 구조가 단순하여 전체적인 속도가 빠르다  
  * 이로인해 **select 작업 속도가 빠르기에 읽기 작업에 적합**  
  * 트랜젝션 동시성 제어 시 **Table-level locking**이기에 쓰기작업(insert, update)가 느리다.  
  * 변경을 많이 요하는 작업이라면 MyISAM은 적합하지 않음.  
  
#### 2. InnoDB  
  * **Row-level locking**으로 변경작업(insert, update)가 빠르다.  
  * 외래키, 제약조건 등 복잡한 기능을 제공  
  * 복구 능력이 더 좋음  
  * **foreign key**에 대하여 자동으로 index를 생성해줌  

-> engine이 innodb임을 확인하는 예  
![스크린샷, 2020-01-27 20-38-53](https://user-images.githubusercontent.com/34915108/73172063-82217100-4145-11ea-8f1f-7e0e90e660d3.png)

->자동으로 fk에 대한 인덱스를 설정한 예  
![스크린샷, 2020-01-27 20-39-07](https://user-images.githubusercontent.com/34915108/73172069-83eb3480-4145-11ea-8940-4a0c5bd529a3.png)

#### 3. alter 명령어를 통하여 내부 엔진을 설정할 수 있음  
```
alter table comment engine=innodb;
```
