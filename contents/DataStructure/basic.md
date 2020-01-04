
## 1. Stack  

* Insert와 Delete가 한 방향에서 이뤄지는 선형 자료구조  
* 한 방향에서 삽입과 삭제가 이뤄지기에 나중에 삽입된 데이터가 먼저 삭제된다. LIFO(Last In First Out)  

* 스택에서 데이터가 삽입될, 혹은 삭제될 위치를 Top 이라고 한다.  

[stack using fixed-size array](https://gist.github.com/horoyoii/b42cfc0c4ccaf659c53151c4e4d833b4)  

## 2. Queue  

 * 한 방향에서는 삽입연산이, 다른 방향에서는 삭제 연산이 일어나는 선형 자료구조  
 * 먼저 삽입된 데이터가 먼저 삭제되는 FIFO( First In First Out) 구조를 가진다.  
 * 데이터가 삭제되는 위치를 Front / Head 라고하며, 삽입되는 위치를 Rear / Tail 이라고 한다.  
 
#### How to implement  

1) Queue using array  
* 배열 기반으로 구현 시 **선형 큐**의 문제점은 dequeu 발생 후 앞 공간을 활용할 수 없다는 것이다.  
* 이를 보완하기 위하여 배열 기반의 **환형 큐**를 구현할 수 있다.  
```
Front = 0 
Rear = 0 초기화

Enqueue 시 Rear++ 가 가르키는 곳에 삽입.  
Dequeue 시 Front++ 가 가르키는 곳의 데이터를 반환  

Empty 와 Full의 조건을 구분하기 위하여 MAX_SIZE - 1 을 MAX_SIZE로 정의.

isFull = (Rear + 1) % MAX_SIZE == Front.  
isEmpyty = Rear == Front

```
[Queue.cpp](https://gist.github.com/horoyoii/a23c7ffcf4c2881fc22d50d79c34836e)

2) Queue using linked list  
3) Queue using double stacks  



## 3. Deque  

