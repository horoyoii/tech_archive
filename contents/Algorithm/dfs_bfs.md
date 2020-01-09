
* 그래프의 탐색을 위한 두 가지 방법 : 깊이 우선 탐색 vs 너비 우선 탐색  
* 두 탐색 모두 그래프의 모든 정점을 탐색하지만 방법에 차이가 있다.  
* DFS는 현재 정점에서 갈 수 있는 정점들 중, 한 곳을 우선적으로 끝까지 탐색  | 마치 귓속말  
* BFS는 현재 정점에서 갈 수 있는 정점들을 모두 먼저 탐색.  | 마치 소문  


# 1. DFS  
  
#### 특징  

  * 스택 혹은 재귀함수로 구현  
  * 깊이 우선 탐색 : DFS의 장점(시작 정점으로부터 깊은 곳에 있을수록 더 빨리 찾을 수 있다.)  
  * 트리에서의 순회 방법들(전위, 중위, 후위) 역시 DFS의 일환이다.  
  

#### 구현  
```
void DFS(int v){
  visited[v] = true;
  
  // processing(v)
  
  for(auto u : adjList[v]){
      if(visited[u] == false){
          DFS(u);
      }
  }

}

```

```
stack<int> stack;
vector<int> visited;

stack.push(start);

while(!stack.empty()){
    int v = stack.top(); stack.pop();
    
    if(visited[v] == true)
      continue;
    
    visited[v] = true;
   
    processing(v);
    
    for(auto u : adjList[v]){
        if(visited[u] == false){
            stack.push(u);
        }
    }

}
```



# 2. BFS  

* 트리의 level-order 순회 방식이다.  

```
queue<int> queue;
vector<bool> visited;

queue.push(start);

while(!queue.empty()){
  int v = queue.front(); queue.pop();
  visited[v] = true;
  
  for(auto u : adjList[v]){
      if(visited[u] == false){
          queue.push(u);     
      }
  }


}
```
