
# MST  
  * Connected, undirected Graph에서 모든 정점을 연결하되, 거기에 사용되는 Edge들의 가중치 합이 최소가 되는 **트리**  
  * MST에서의 Edge의 수는 V - 1.  
  * Kruskal 혹은 Prim 사용.  
  * **Kruskal** :  Edge-based / Union-Find / Sorting / Greedy  
  
  
## Kruskal  

  **Edge 기반 알고리즘**  
  **Union-Find 사용**  
  **Sorting 필요**  
  **Greedy적**  
 
#### What  
  
  1. 모든 Edge를 가중치 기준으로 오름차순 정렬  
  2. 가장 작은 가중치의 Edge 선택.  
  ```
  struct Edge{
      int u;
      int v;
      int weight;
  };
  ```
  선택된 Edge가 **MST의 subset**에 포함될 때 Cycle이 발생하지 않는다면 MST subset에 포함.  
  Cycle을 발생시키면 다음 Edge 선택.  
  **Union-Find 사용됨 **  
  3. 모든 Edge를 확인할 때까지 반복.  
  
## Prim  

  **Vertex 기반** - 시작정점 선택.  
  **D[] 배열 유지**  
  **우선순위 큐 사용** 
  
  MST를 만들어나가는 vertex의 집합을 Subset이라고 할 때,  
  MST에 추가된 vertex의 집합 무리에서 나아갈 수 있는 vertex까지의 거리.  
  
  1) 시작정점 선택.   
  2) 그 정점과 연결된 **정점들**까지의 거리를 비교 후 저장.  
  3) 갱신된 D 중 가장 작은 값을 선택 후 동일하게 실행.  

#### D 배열은 (시작정저부터의 최소거리가 아닌) MST Subset과 non subset 간의 거리   
즉, 두 정점 간의 최소 거리.  
  ![스크린샷, 2020-01-15 18-43-23](https://user-images.githubusercontent.com/34915108/72423074-f44d9980-37c6-11ea-9985-6f18d71100f0.png)


  
  
