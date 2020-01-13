[참고](https://www.digitalocean.com/community/tutorials/understanding-database-sharding)  
[참고](https://www.acodersjourney.com/database-sharding/)  
  
  
## Sharding  

  * 샤딩은 기본적으로 **분산 데이터베이스 환경**에서 테이블을 쪼개어 여러 노드에 저장하는 방식.  
  * **Horizontally partitioning**을 통해 하나의 테이블을 여러 record로 나누어 저장.  
  * 각 노드에 분산적으로 저장된 테이블의 각 일부들을 **shard**라고 함.  
  * 이점 : horizontal scaling 시에 용이하게 작용 / query response time을 축소시킴.  
   즉, make scaling up easier and improve performance.  
   
  * 단점 : 설계의 어려움  / shard 간의 unbalance.  
  * 방식 : key based sharding(hash based) / range based sharding / directory based sharding  
  
### What is Sharding?  

  * This is related to **horizontal partitioning** - the practice of separating one table's rows  
  into multiple different tables, known as **partition**.  
  Each partition has the **same schema and column**, but entirely different rows.  
  
  * Vertical patitioning vs Horizontal partitioning  
  ![스크린샷, 2020-01-13 14-09-23](https://user-images.githubusercontent.com/34915108/72234045-54e5a680-360e-11ea-97a4-dddec703325f.png)  
  
  
  * Sharding involves breaking up one's data into two or more smaller chuncks, called **logical shard**.  
  The logical shards are then distributed across separate database nodes, referred to as **physical shard**.  
  
  
### Benefits  
  * It can help to **faciliate horizontal scaling**, also known as **scale out**.  
  * Another reason why some might choose a shared database is **to speed up query response time**.  
  It may have to search every row in the table in ap application with a large, monolithic database.  
  But with shared database, queries have to go over **fewer** rows.  


### Drawbacks  
  * We'll discuss some of these and why they might be reasons to avoid sharding.  
    
  * Difficulity of implementing a shared database architecture properly.  
  * another problem that users sometimes encounter after having shared a database is that the shards eventually  
  become unbalanced.  
  Let's say you have a database shared with two separate shard, one for customers whose last names begin with A through M and  
  another for whose last name begin with N through Z.  
  
## How to Shard  

  ### Key Based Sharding   
  *  This involves using a value taken from table - such as customer ID - and plugging it into a **hash function** 
  to determine which shard it should go to.  
  So the hash value from the hash function is called **Shard ID** and this value is used to determine which shard  
  the data should be stored on.  
  
  * The value enterted into the hash function should all **come from the same column**.  
  This column is knonw as **shard key**. It shoud be static.  
  ![스크린샷, 2020-01-13 14-39-52](https://user-images.githubusercontent.com/34915108/72235422-7a29e300-3615-11ea-82c8-a15f930cb87a.png)
  #### pros 
  It can be used to **evenly distribute data** so as to prevent hotspot.  
  #### cons 
  **It can make things tricky when trying to add or remove a node from the server.**  
  This job needs to modify the hash function  and remap all data in shards.  - consistent hashing needed...!  
  
  
  
  ### Range Based Sharding   
  * This involves sharding data based on range of a given value.  
  ![스크린샷, 2020-01-13 14-52-03](https://user-images.githubusercontent.com/34915108/72235425-7c8c3d00-3615-11ea-91e5-09c314552e57.png)
  #### pros  
  It is relatively **easy to implement**.  
  #### cons  
  This can not protect data from **being unevenly distributed**, leading to unbalancing.  
  
  ### Directory Based Sharding  
  * one must maintain a **lookup table** that uses shard keys to keep track of which shard holds which data.  
  * Each record has a additional shard key field.  
![스크린샷, 2020-01-13 14-57-35](https://user-images.githubusercontent.com/34915108/72235429-7e560080-3615-11ea-829a-78f0d6707ef1.png)  
  
