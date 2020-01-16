  
# Hashing  
  [GeeksForGeeks](https://www.geeksforgeeks.org/hashing-set-1-introduction/)  
## 1. What is hashing  

  ##### Key, value 의 데이터를 저장하는데 Key를 바탕으로 hash function을 통한 Hash value를 생성하여  
  ##### 이 값을 hash table의 index에 매핑시켜 데이터를 저장하는 것.  
  ##### hash table 그 자체도 일종의 **Dynamic array**이다. (load factor에 따른 Rehashing 고려 시)  
  ##### 그렇기에 hashing은 **Search**, **Access**, **Insert**, **Delete**가 평균!! O(1)  
  ##### 이는 **Array**의 특성인 index만 안다면 direct random access가 가능하다는 것을 바탕으로  
  ##### 그렇다면 데이터가 저장된 index의 정보를 Key에서 구한다는 것이다.  
  ##### Hashing은 배열 뿐만 아니라, collision을 해소하기 위한 방안으로 Chaining을 적용한다면  
  ##### Linked list에도 의존할 수 있다.  
  
## 2. Example  

 
  
## 3. hash function 의 조건  
  ##### 1. 주어지는 Key에 대하여 Uniformly distributed 해야 함.  -> collision 최소화.  


## 4. Collision Handling  
  1. 우선 예방 : 데이터 셋에서 Key를 잘 선택한다. 전화번호에서 앞의 세자리면 안될 것.  
  2. 우선 예방2 : 좋은 hash function을 선택. Uniformly distributed한 것.  
  
  그럼에도 발생할 수 밖에 없고 이 때는 대처.  

  * Hash function은 큰 범위의 키를 바탕으로 상대적으로 작은 범위의 hash value(code)를  
  생성하기에 언젠가 반드시 해쉬 충돌이 발생할 수 밖에 없다.  
    
  * Hash collision : hash function이 서로 다른 두 키에 대하여 동일한 hash value를 생성하는 것.  
  
### 1. Chaining  
  1. hash table의 각 cell(slot, bucket)을 Linked list로 만들어서 collision이 발생한 데이터들을 linked list에 sequential하게 저장.  
  2. hash table의 각 slot은 linked list의 head pointer를 저장.  
  
### 2. Open Addressing  
  collision 발생 시 hash table 내에서 비어있는 slot을 **probing**하여 그곳에 삽입.  
  
 #### 1. Linear probing  
 * 특정 slot이 채워져있다면 그 다음 slot을 확인하는 방식.  
 ```
 hash(x) was filled 
 hash(x) + 1 index check
 ```

 #### 2. Quadratic probing  
  * Linear probing의 문제점은 clustering이다. 특정 range에 집중 분포가능. -> 이는 곧 접근 시간을 선형적으로 증가시킴.  
  * i^2만큼 slot 이동하면서 탐색  
  
 #### 3. Double hashing  
   * hash(x) 가 이미 채워져있다면 다른 hash function을 적용하여 다음 index 계산.  


## Chaining vs Open addressing  
  [비교](https://www.geeksforgeeks.org/hashing-set-3-open-addressing/)  

```
Cache performance 측면

Open addressing 기법이 휠씬 cache friendly 하다. 
캐쉬는 작은 block단위인 cache line을 기반으로 동작한다.
이 cache line은 대게 64byte 정도. 
동일한 key를 생성한 두 데이터는 open addressing에서 clustered(뭉쳐있을) 확률이 높다.
메모리 상 인접하게 배치되었기에 동일한 캐시라인에 매핑될 수 있다.
반면, chaining은 내부적으로 linked list에 기반하기에 메모리 상 인접하게 할당x
캐싱안되어있다면 상대적으로 높은 cost의 memory access 
```
[cache performance](https://stackoverflow.com/questions/49709873/cache-performance-in-hash-tables-with-chaining-vs-open-addressing/49742905)  

## Load factor / Rehashing  
