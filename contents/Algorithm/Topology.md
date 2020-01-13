

# Topological Sort  
  
  * DAG 에서 변의 방향을 거스르지 않도록 나열하는 것을 의미.  
  * Cycle이 없어야 함.  
  * 과목의 수강 순서 결정 문제 등  
  
##### 구현    
  * **DFS** 
  * **In-degree 소거** 
  

## In-degree 소거 방법  

  *  BFS 방식의 일환.  
  *  Queue 사용 

```
int in_degree[N];
```

1. 그래프의 입력을 받을 때 각 vertex의 진입 차수를 카운트  

2. 진입 차수가 0인 vertex들을 Queue에 삽입  

3. Queue에서 제거한 노드(v) 가 향하는 vertex(u) 의 진입차수를 1 감소 / in_degree[u]--;   
  이 때 그 노드의 진입차수가 0이되면 Queue에 삽입.  
  
4. Queue가 빌 때까지 반복.  

5. Queue가 비었을 때 모든 정점이 처리되지 않았다면 (그래프에 남아있다면)  **사이클 존재**  
