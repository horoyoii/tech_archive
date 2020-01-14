# Redis   
[Reference](https://codeburst.io/redis-what-and-why-d52b6829813)  
## Introduction  

  * Redis is a in-memory database.  
  * Advanced **key-value store**  
  * Default PORT : 6379  
  * Redis also acts aa s Pub/Sub server.  
  
## This is not a simple KEY-VALUE storage  

  * Redis는 단지 데이터를 key-value pair로 저장할 뿐만 아니라, **여러 종류의 데이터 타입**을 지원.  

#### List data type  
  * the List data type in Redis is implemented via **Linked List**, not **Array** which python uses to implement the List.  
  This means that **insert or delete** operations are faster, but **access** is slower.  
  In a database system, it is cruical to add a new element to a very long list in a very fast way.  
  * If **fast access** to the middle of a large collection of elements is important, use another data structure.  
  ```
  > lpush mylist 1 2 3 4 // lpush adds elements to a list at the head 
  > rpush mylist A B     // rpush adds elements to a list at the tail
  > lrange mylist 0 -1   // extracts ranges of elements from lists. 
  ```
  

  
  
## Redis COMMAND  
![스크린샷, 2020-01-14 19-32-25](https://user-images.githubusercontent.com/34915108/72336724-ad976b00-3704-11ea-98b9-2729ec93f5be.png)
![스크린샷, 2020-01-14 19-32-33](https://user-images.githubusercontent.com/34915108/72336723-ad976b00-3704-11ea-8375-747f94d427f8.png)
![스크린샷, 2020-01-14 19-32-49](https://user-images.githubusercontent.com/34915108/72336720-acfed480-3704-11ea-9188-153abdf6eee9.png)
