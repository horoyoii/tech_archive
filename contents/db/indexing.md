 # Indexing  
 
 
 **1. avoid full scan**  
 **2. RDBMS에서 검색 속도를 높이는 기술** / insert, delete, update는 느려짐.   
 **3. index table에 따로 유지되며, B+Tree를 사용**  


##### Clustered index  
1. Clustered index는 아래의 PK와 같이, 디스크에 저절로 PK 순으로 배치되어 있는 형태  
2. Clustered index를 기반으로 한 search query는 [1-10] 에 대한 Binary Search로 접근가능 .  
3. 인덱스를 위한 추가의 공간은 없어도 됨.  
![스크린샷, 2020-01-17 20-54-06](https://user-images.githubusercontent.com/34915108/72610742-88f0fc80-396b-11ea-8700-7de0fd7b8d0a.png)

##### Non Clustered index  
![스크린샷, 2020-01-17 20-43-52](https://user-images.githubusercontent.com/34915108/72610215-28ad8b00-396a-11ea-8ffc-d6cc9738b757.png)
1. 기존 테이블에 대하여 First name column을 index로 지정하면  
2. 이 colum을 key로 하고, 실제 해당 레코드가 저장된 secondary storage의 location을 value로 하는  
3. 인덱스 자료구조가 생성되고, 이는 아래와 같이 B+tree 형태이다. 
4. 다음과 같이 인덱스로 지정된 column이 select query에 포함되면  
```
SELECT * FROM people WHERE FirstName = "Lovelace";
```
5. "Lovelace" 를 테이블에서 full scan하는 것이 아닌, 인덱스라는 B+tree에서 search하여 O(LogN)  
6. 인덱스 트리에서 FirstName = "Lovelace" 인 record의 물리적 위치를 찾은 후 직접 테이블에 접근.  


![스크린샷, 2020-01-17 20-43-59](https://user-images.githubusercontent.com/34915108/72610218-2a774e80-396a-11ea-8a6f-89acf35d8837.png)



 ##  2. Clustered vs Non clustered index  
 
 #### 0. Basic concepts  
 1. Heap : a Table is stored without a **clustered indedx**.  
 -> clustered index가 없다는 것은 레코드가 특정 순서에 맞춰 저장되지 않음.  
 
  
 #### 1. Clustered index  
 
   ##### only one clustered index is in a table.  
   -> 디스크에 배치된 record는 하나의 column으로만 정렬되기 때문.  
   
   ##### 레코드들은 실제 디스크에 clustered index 순으로 정렬되어 배치되어 있다.  
   ![스크린샷, 2020-01-17 20-54-06](https://user-images.githubusercontent.com/34915108/72610742-88f0fc80-396b-11ea-8700-7de0fd7b8d0a.png)

   ##### Clustered index is normally a Primary key.  
   ##### Clustered index does not need extra storage.  
   
 
 
 ## Drawbacks  
 
 ##### 1. It takes up space to store indexes itself  
 
 ##### 2. Slower INSERT, DELETE, UPDATE operations  
 
   * Search는 빠르지만, row의 insert, delete, update 연산 시  
   index table도 갱신되어야 하기에...  
   
