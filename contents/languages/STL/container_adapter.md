
# Stack  

### 1. 개념  

  * stack은 **container adapter** 이다.  
  ```
  template<class T, class Container = deque<T> >
  class stack;
  ```
  [container 종류](https://stackoverflow.com/questions/3873802/what-are-containers-adapters-c)  
  ### container adapter  
  기존의 container를 감싸는 **일종의 wrapper 컨터이너**이다.  
  기존의 container에는 **sequence container** 와 **associative container**가 있다.  
  이러한 기존의 container를 감쌈과 동시에, 기존 컨테이너가 가지는 기능들 중 제한된 일부만 인터페이스로 노출함으로써  
  새로운 타입의 자료구조(컨테이너)를 제공한다.  
    
  container adapter에는 **stack**, **queue**, **priority_queue**가 있다.  
  **container adapter들은 sequence container위에 구현된다.**  
    
  * stack은 기본적으로 **deque** 위에 구현된다.  
  ```
  stack<int> stack1; // deque 기반의 stack  
  
  stack<int, vector<int>> stack2; // vector 기반의 stack
  
  stack<int, list<int>> stack3;   // list 기반의 stack 
  ```
  

### 2. Member functions  


##### push()  
  * top에 원소를 삽입  
##### pop()  
  * top의 원소를 제거 
  * @retuns NONE   
##### top()  
  * top에 위치한 원소를 반환  
##### empty()  
  * stack의 비었는지를 확인
  * returns true if it is empty  
##### size()  
  * 원소의 개수를 반환  

```
#include<stack>  // <stack> 에 정의됨.

stack<int> st;

st.push(1);
st.push(2);
st.push(3);

cout<<st.size()<<endl;

while(!st.empty()){
  cout<< st.top() <<endl;
  st.pop(); 
}
```


# queue  

### 개념  
  ```
  template<class T, class Container = std::deque<T>>
  class queue;
  ```

### Member function  

##### push  
  
##### pop  
  front에 위치한 원소 삭제  

##### front  
  front에 위치한 원소 접근  
  
##### back  
  rear에 위치한 원소 접근  

##### size  
  큐의 원소의 갯수 확인  
  
##### empty
  큐가 비었는지 확인  
  
