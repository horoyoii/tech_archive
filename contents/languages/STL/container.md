## Container  
  * 모든 컨테이너의 목적은 하나다; 데이터의 저장  
  [참고!!](https://subscription.packtpub.com/book/application_development/9781788831390/1/ch01lvl1sec9/associative-containers)  
#### 1. Sequence containser vs Associative container  
  [참고2!!](https://www.hackerearth.com/practice/notes/c-stls-when-to-use-which-stl/)  

##### 시퀀스 컨테이너  
  * 동일한 타입의 데이터를 **선형적으로 저장**한다. 
  * 이를 통해 데이터들은 순차적인 접근이 가능하다.  
  * 삽입된 순서대로 선형적으로 데이터는 저장된다.  
  

| Sequence container | 특징 |
|:--------|:----------|
| array | 고정크기의 배열. 사이즈 수정 불가 |
| vector | 실행 시 크기의 변경이 가능한 **동적** 배열 / 빠른 random access |
| deque | double-ended queue / random access 가능 |
|forward_list | singly linked list | 
|list| doubly linked list |
 
 ##### 연관 컨테이너  
   * key - value pair를 기반으로 데이터가 저장된다.  
   * 삽입 순서에 무관하게 내부적인 ordering 방식에 따라 비선형적으로 저장된다.  
   * unordered_ 가 아니라면 **정렬된** 형태로 저장.  
   
 |Associative container | 특징 | 
 |:----------|:------------|
 |map| key value pair형태로 저장 / key는 unique / 내부적으로 **Balanced BST(레드 블랙)** 형태로 저장. |
 |set| 데이터 자체가 key가 됨 / 오름차순으로 정렬된 상태 유지 |
 |multimap| key-value pair로 저장하되, key는 중복가능.| 
 |multiset | key의 중복을 허용하는 set | 
 
 
 |unordered_ 연관 컨테이너 | 특징 |
 |:----------|:-------------|
 |unordered_set | 내부적으로 정렬된 상태를 유지하지 않는 형태의 set / 내부적으로 **hash table** 사용|
 |unordered_map | 내부적으로 정렬된 상태를 유지하지 않는 형태의 map / 내부적으로 hash table 사용 |
 |unordered_multiset ||
 |unordered_multimap ||
 
 
 ##### When to use  
 
   * 연관 컨테이너의 경우 Balanced BST로 구현되었기에 **Search** 가 빠르다. (logN)  
   * 연관 컨테이너의 경우 insert / delete 가 logN이 보장  
   * 시퀀스 컨테이너의 경우 중간에서 insert / delete가 자주 발생한다면 avoid  
   * 시퀀스 컨테이너의 경우 Access time이 constant
   * set : 데이터가 정렬된 상태로 유지되며, **데이터의 중복**을 피하고 싶은 경우  
   
   
* By default, you should use a vector. It has the simplest internal data structure and provides random access. Thus, data access is convenient and flexible, and data processing is often fast enough.

* If you insert and/or remove elements often at the beginning and the end of a sequence, you should use a deque. You should also use a deque if it is important that the amount of internal memory used by the container shrinks when elements are removed. Also, because a vector usually uses one block of memory for its elements, a deque might be able to contain more elements because it uses several blocks.

* If you insert, remove, and move elements often in the middle of a container, consider using a list. Lists provide special member functions to move elements from one container to another in constant time. Note, however, that because a list provides no random access, you might suffer significant performance penalties on access to elements inside the list if you have only the beginning of the list. Like all node-based containers, a list doesn’t invalidate iterators that refer to elements, as long as those elements are part of the container. Vectors invalidate all their iterators, pointers, and references whenever they exceed their capacity and part of their iterators, pointers, and references on insertions and deletions. Deques invalidate iterators, pointers, and references when they change their size, respectively.

* If you need a container that handles exceptions so that each operation either succeeds or has no effect, you should use either a list (without calling assignment operations and sort() and, if comparing the elements may throw, without calling merge(), remove(), remove_if(), and unique();or an associative/unordered container (without calling the multiple-element insert operations and, if copying/assigning the comparison criterion may throw, without calling swap() or erase()).

* If you often need to search for elements according to a certain criterion, use an unordered set or multiset that hashes according to this criterion. However, hash containers have no ordering, so if you need to rely on element order, you should use a set or a multiset that sorts elements according to the search criterion.

* To process key/value pairs, use an unordered (multi)map or, if the element order matters, a (multi) map.

* If you need an associative array, use an unordered map or, if the element order matters, a map.

* If you need a dictionary, use an unordered multimap or, if the element order matters, a multimap.
 
