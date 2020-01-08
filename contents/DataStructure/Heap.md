## Heap  

### 1. 우선순위 큐 (Priority Queue)  
  
  * 우선순위 큐란 (기본 큐와 같이) 삽입된 순서대로 삭제되는 것이 아닌, 우선순위가 높은 데이터부터 삭제되는 자료구조이다.  
  * 우선순위 큐는 대게 힙 자료구조를 통하여 구현된다.  
  
##### 1. 우선순위 큐 구현 방법  

  * 1) unsorted array  
  Insert :  O(1) - 정렬상태를 유지하지 않는 배열이기에, 마지막에 원소를 삽입.   
  Delete :  O(N) - 우선순위가 가장 높은 원소를 탐색( O(N) ) 후 필요하다면 **데이터의 이동** 발생,  
  * 2) sorted array  
  Insert :  O(N) - 정렬되어있기에 이분탐색으로 삽입될 위치 탐색가능( O(logN) ) 하지만 데이터의 이동( O(N) ) 발생.  
  Delete :  O(1) - 정렬되어 있기에 가장 마지막의 원소를 선택하면 됨.  
  
  * 3) unordered linked list  
  Insert : O(1)  - tail에 원소 추가.  
  Delete : O(N)  - 순차탐색으로 가장 우선순위 높은 원소 탐색 후 삭제.  
  * 4) ordered linked list  
  Insert : O(N) - 이분탐색이 적용 불가하기에 순차 탐색 후 삽입  
  Delete : O(1) - tail의 원소 선택 후 삭제  
  
  * 5) **Binary Search Tree**  
  **트리의 모양에 따라 복잡도가 달라짐**  
  Delete : max 우선순위 큐라면 루트에서부터 마지막 오른쪽 자식까지 내려간 후 선택.  AVG : O(logN) / Worst : O(N)   
  Insert : 해당 leaf에 추가  AVG : O(logN) / Worst : O(N)  
  

### 2. 힙  

#### 1. 개념  
  * Heap 은 **완전이진트리** 이다.  
  * max heap이라면 부모의 key는 left, right 모든 자식의 key보다 크다.  
  * min heap이라면 부모의 key는 left, right 모든 자식의 key보다 작다.  
  
  ![스크린샷, 2020-01-08 14-41-13](https://user-images.githubusercontent.com/34915108/71953250-f8a51000-3224-11ea-8a46-d4f988a0e80d.png)  
  
#### 2. 구현  

 * 힙은 대게 우선순위 큐를 구현하기 위해 사용되며, (max heap이라면) 부모의 키 값이 자식들의 키값보다 큰 속성을 재귀적으로 유지하는 완전이진트리  
 이고, 내부적으로는 **배열**을 통해 구현된다.  
 
 * 배열을 통한 구현이 가능한 이유는 완전이진트리이기 때문이다.  
 완전이진트리라면 배열에서 낭비되는 공간이 없이 꽉 차있게 된다.  
 또한 특정 index를 바탕으로 다음의 값들이 쉽게 구해져 배열의 direct, random access가 가능하다.  
 index / 2 = 부모 index  
 index*2 = left child index  
 index*2+1 = right child index  
  
  
 #### 3. Operations  
 
 ##### 1. Insert  
 * 완전이진트리이기에 Last Leaf Node 다음의 위치에 새 데이터를 위치시킨 후 heap의 속성에 맞추기 위하여 부모의 값과 비교하여  
 re-ordering을 수행한다.  
 여기서 힙의 속성이란 max heap이라면 부모의 key는 자식의 key보다 커야한다와 같은 것.  
 ![스크린샷, 2020-01-08 14-54-10](https://user-images.githubusercontent.com/34915108/71953838-c1376300-3226-11ea-92d7-a09ab67bd0df.png)
 ##### 2. Delete  
 * root에 위치한 노드가 원하는 값이기에 삭제를 한다.  
 * 이후 루트를 채우기 위하여 last leaf node의 데이터를 root로 이동 후 heap의 속성에 맞추기 위하여 자식의 값과 비교하여 내려간다.  
 
 ![스크린샷, 2020-01-08 14-53-40](https://user-images.githubusercontent.com/34915108/71953813-b7adfb00-3226-11ea-9288-0242112d7606.png)
