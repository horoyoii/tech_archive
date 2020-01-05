
1) Binary tree  
2) Binary Search tree  
3) Heap (based on complete binary tree)  
4) Balanced Binary tree  
  - AVL tree 
  - Red-Black tree  
  - B or B+ tree  
  

## 1. Tree  
  * 자료들 간의 **계층**적인 관계를 나타내는 자료구조로서, 부모-자식 관계로 표현된다.  
  
  #### 1. 트리와 그래프  
  * 그래프는 노드 간의 **관계**를 표현하는 자료구조라면  
  트리는 노드 간의 **계층**을 표현하는 자료구조이다.  
  
  * 트리는 그래프의 일종으로서, 
  1. cycle이 없다.  
  2. 두 노드 사이에는 반드시 1개의 edge가 존재한다.  
  3. 간선의 수는 노드의 수 -1 이다.  
  4. Undirected Acycle graph(무향 그래프)이다.  
  5. 트리의 순회는 In-order, Pre-order, Post-order traverse로 이뤄진다.  
  #### 2. 용어  
  * Depth(깊이) : 루트 노드에서 해당 노드까지 도달하는데 사용되는 **간선**의 수  
  * Level(레벨) : 깊이 + 1  
  * Heigth : 가장 큰 깊이 + 1  
  * Degree(차수) : 해당 노드의 자식 수  
  * Leaf : 자식 노드가 없는 노드 / 차수가 0인 노드  
  #### 3. 순회  
  * **Depth First Traverse**  
  전위, 후위, 중위 순회는 모두 DFS의 일종이다.  
  * **Breadth First Traverse**  
  Level order traverse 가 BFS에 해당한다.  
## 2. Binary tree  

#### 1. 특징  
  * 트리 내의 모든 노드의 차수가 2 이하인 트리  
  * 높이가 N인 트리의 최대 노드의 수는 2^N - 1  
#### 2. 이진 트리의 종류  
  * Perfect Binary Tree : 마지막 레벨까지 모든 노드가 차있는 트리   
  * Complemet Binary Tree : 마지막 레벨의 노드는 왼쪽에 몰려있고 마지막 레벨을 제외하면 포화 이진 트리가 되는 트리   
  * Skewed Binary Tree : 연결리스트처럼 한 줄로 연결 되어있는 트리  
  
#### 3. 구현  
  * **배열 기반** 구현  
  배열의 [1] 위치부터 저장을 시작하고 다음과 같이 index에 대한 연산으로 부모, 자식 노드의 위치를 구할 수 있다.  
  ```
  int parent(int idx) { return idx / 2; }
  int left_child(int idx) { return idx*2; }
  int right_child(int idx) { return idx*2 + 1; }
  ```
  height H에 대하여 2^H 만큼의 공간이 필요하다.  
  [문제] 루트부터 리프까지의 모든 노드를 메모리 상 cnosequetive하게 배치하지만 skewed 형과 같은 경우 메모리 낭비를 유발한다.  
  * **링크드 리스트 기반** 구현  
  ```
  struct Node{
    int val;
    Node* left_child;
    Node* right_child;
  }
  ```
  
#### 4. 순회  

##### 1. Pre-odred  
  * 반문하자마다 그 노드에 대한 **처리** 후 자식 노드를 순회  
```
void pre_order(Node* node){
  if(node != nullptr){
      processing something(node);
      pre_order(node->left);
      pre_order(node->right);
  }
}
```
##### 2. In-odred  
  * 하나 방문 후 그 노드에 대한 **처리** 후 나머지 노드 순회  
```
void in_order(Node* node){
  if(node != nullptr){
      in_order(node->left);
      processing something(node);
      in_order(node->right);
  }
}
```
##### 3. Post-odred  
  * 모든 자식 노드 방문 후 그 노드에 대한 **처리**  
```
void post_order(Node* node){
  if(node != nullptr){
      post_order(node->left);
      post_order(node->right);
      processing something(node);
  }
}
```

##### 4. Level order traverse  
  * BFS 방식  
  ```
  void level_order(Node* root_node){
      queue<Node*> queue;
      queue.push(root_node);
      
      while(!queue.empty()){
        Node* curNode = queue.front(); queue.pop();
        
        processing(curNode); // do something with this node e.g.) printf
        
        if(curNode->left != nullptr)
            queue.push(curNode->left);
        if(curNode->right != nullptr)
            queue.push(curNode->right);
            
            
      
      }
      
      
  }
  ```
  
