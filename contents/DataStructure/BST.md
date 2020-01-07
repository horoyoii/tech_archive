

## Binary Search Tree  

#### 1. Definition  

  * 노드 기반의 이진 트리로서 다음의 속성을 만족해야 한다.  
  * 1) 특정 노드의 left subtree의 모든 keys는 특정 노드의 key보다 작아야 함.  
  * 2) 특정 노드의 right subtree의 모든 keys는 특정 노드의 key보다 커야 함.  
  * 3) 특정 노드의 left, right subtree 역시 BST여야 함.  
  
  * 각 노드이 key 값들은 중복되지 않아야 한다.  
  
  

#### 2. Search  

  * 특정 key를 찾고자할 때  
  root 노드부터 시작하여 방문한 노드의 key가 target key보다 크다면 (target key)는 left subtree에 있을 수 있기에 left subtree를 방문.  
  만일 방문한 노드의 key가 target key보다 작다면 right subtree를 방문.  
  
  * 이를 재귀적으로 구현가능.  
  ```
  node_ptr search(node_ptr root, int target){
    if(root == nullptr)
        return nullptr; // 없음.
        
    if(root->val == target){
        return root;
    }else if(root->val < target){
        return search(root->right, target);
    }else{ 
        return search(root->left, target);
    }
    
    
  }
  ```
  
  #### 3. Insert  
    * 먼저 Search 후 삽입  
    
  #### 4. Delete  
    * 세 가지 상태 고려  
    
    * 1) 삭제될 노드가 leaf 노드면 그냥 삭제  
    * 2) 삭제될 노드가 자식이 하나 있다면 parent에 붙여주고 삭제  
    * 3) 삭제될 노드가 자식이 두개 있다면 left subtree에서 가장 큰 key를 가지는 노드 / right subtree에서 가장 작은 key를 가지는 노드와  
    교체한 후 삭제  
    
  #### Performance comparison  
  
|Worst Case              |   Access    |    Search          |     Insert     |         Delete |
|:----------|:----------|:----------|:----------|:----------|
|Sorted Array |                1       |      LogN          |      N         |         N      |
|Unsorted Linked List |        N       |      N             |       1        |         N       |
|Binary Search Tree |         N        |        N           |       N        |         N       | 


  * BST의 최악의 경우는 skewed(편향된 트리)로 형성되는 경우이다.  
  * BST의 Search time은 N이 되고, **Insert 와 Delete 연산은 Search에 의존적이기 역시 N이된다. **  
  
  * 정렬된 배열에서 Search time은 이분탐색 적용시 LogN이 되지만,  
  Insert와 Delete가 배열 첫번째 원소에서 발생 시 N번의 메모리 카피가 발생하기에 N이된다.  
  
|Avg Case              |   Access    |    Search          |     Insert     |         Delete |
|:----------|:----------|:----------|:----------|:----------|
|Sorted Array |                1       |      LogN          |      N/2         |         N/2     |
|Unsorted Linked List |        N       |      N             |       1        |         N/2       |
|Binary Search Tree |         logN        |        logN           |      logN        |         logN       | 

  

   
