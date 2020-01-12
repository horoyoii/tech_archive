

## 1. container  
  * 컨테이너를 데이터를 저장하는 방식이며,  
  데이터를 삽입 순서에 맞게 선형적으로 저장하는 **sequence container**와  
  key-value pair의 형태로, 삽입 순서와 무관하게 내부적인 re-ordering을 통한 비선형적으로 저장하는 **associative container**   
  * **sequence** : **vector**, **array**, **deque**, **list**, **forward_list**  
  * **associative** : **map**, **set**, **unordered_map**, **unordered_set**   
  
[container](/contents/languages/STL/container.md)  
  
## 2. container adapter  
  * 이는 기존의 container(특히, sequence container) 위에서 구현되는 컨터이너로서,  
  기존 컨테이너의 기능을 제한함으로써 새로운 타입의 인터페이스를 제공한다.  
  * **stack**, **queue**, **priority_queue**  
  
[container adapters](/contents/languages/STL/container_adapter.md)  


## unodered_map  
[unordered_map](/contents/languages/STL/unordered_map.md)  

## map  
  * 균형이진트리(RB 트리) 기반 구현  
  **정렬상태** 유지  
  **O(LogN)** 복잡도  
  ```
  map<int, string> hs; // 기본적으로 less<T> - 오름차순
  map<int, string, greater<int>>; // 키 대상 내림차순
  ```
  
