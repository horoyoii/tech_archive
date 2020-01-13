
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
  
