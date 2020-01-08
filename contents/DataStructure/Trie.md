## 트라이  

#### 개념  

  * 문자열에 특화된 트리 자료구조로서, 문자열의 집합이 있을 때 이를 저장하고  
  특정 문자열을 찾는데 O(N)이 걸린다.  
  * 접두사 트리라고도 불린다.  
  * 단점 : 각 노드가 (알파벳이라면) 26개의 포인터를 가져야 하기에 공간복잡도가 취약하다.  
  

![스크린샷, 2020-01-08 15-20-19](https://user-images.githubusercontent.com/34915108/71955004-6dc71400-322a-11ea-950c-445eadd344c2.png)

```

class Node{
public:
    bool finish;
    Node* children[26];

    Node()
        :finish(false){
        for(int i =0 ; i < 26;i++)
            children[i] = nullptr;
    }

    
    void insert(char* str){
        if(*str == '\0') 
            finish = true;

        int idx = *str - 'a';

        if(children[idx] == nullptr)
            children[idx] = new Node;

        children[idx]->insert(str+1);
        
    }

    
    bool find(const char* str){
        if(*str == '\0')
            return finish;

        if(children[*str - 'a'] == nullptr)
            return false;
        return children[*str - 'a']->find(str+1);


    }
};

```


