## SCC  

#### Strongly Connected Components  

  * Directed graph 에서 임의의 정점으로 구성된 그룹에서, 그룹 안의 모든 정점 쌍이 서로를 향해 갈 수 있을 때,  
  그 그룹을 **강한 결합 연결 요소** 라고 함.  
  
#### 아래의 그래프는 4개의 SCC로 구성됨.  
  ![스크린샷, 2020-01-15 19-05-01](https://user-images.githubusercontent.com/34915108/72424833-f36a3700-37c9-11ea-96e8-3a64e6957639.png)
     

#### 코라사주 알고리즘  
**DFS**  
**스택**  
**역방향 그래**   

1) 그래프를 대상으로 DFS 수행  
2) 탐색이 종료되는 Vertex부터 스택에 삽입.  
3) 역방향 그래프 생성.  
4) 스택에서 원소를 꺼내어 이를 start로하여 DFS 수행.  
5) DFS 과정에서 만들어지는 하나의 Tree가 SCC가 됨.  


![스크린샷, 2020-01-15 19-11-37](https://user-images.githubusercontent.com/34915108/72425307-e3068c00-37ca-11ea-9140-f3508418579c.png)

```
7번 노드부터 DFS 시작.  
스택 : [ 2 3 7 - 6 - 5 4 1 : 


```

![스크린샷, 2020-01-15 19-11-42](https://user-images.githubusercontent.com/34915108/72425310-e437b900-37ca-11ea-8259-86035d47a73b.png)

```
스택 : [ 2 3 7 - 6 - 5 4 1 : 

1을 pop한 후 DFS 결과 : ( 1 4 5 )
4, 5 pop 무시 
6 pop - ( 6 )
7 pop - ( 7 2 3) 
3, 2 무시

총 세 개의 SCC 

```
