
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


## 4. Array & Linked list  
* [참고](https://techdifferences.com/difference-between-array-and-linked-list.html)  

#### 1. Array(배열)  

* 배열은 index 기반의 자료구조로서, 각 요소는 하나의 index와 관련된다.  
* **index 기반이기에 데이터 접근에 용이**하다.  
* **동일한 자료형**의 데이터를 일렬로 나열.  
* 데이터의 삽입과 삭제가 어렵다. (메모리 카피가 발생)  

#### 2. Linked list  
* 각 노드가 **데이터**와 **포인터**를 가지고 일렬로 연결되어 있는 방식.  
* 데이터의 접근이 느리다.  
* 데이터의 삽입과 삭제가 용이하다.  

#### 3. 차이점  

1) 배열은 run time에 **고정된 크기**로, 배열의 요소들은 메모리 상에 일련적으로 배치된다.  
2) linked list의 각 노드는 Data field와 link field를 가지며, run time에 **크기가 가변적**이며, **메모리 상에 일련적으로 배치되지 않을 수** 있다.  

| Basic | Array | Linked list |
|:--------:|:--------:|:--------:|
| Size| 선언 시 확정됨 | 실행 중 grow, shrink 가능|
| 할당 | 컴파일 시 메모리에 일련적으로 할당 | 런타임 시 메모리에 일련적이지 않게 할당 |
| 접근 | index 기반의 direct, random access 가능 | head node로부터 traverse를 통한 접근 |
| 삽입/삭제 | 요소의 이동(shifting)요구 시 상대적으로 느림 | 쉽고 빠르다. |
| 탐색 | 순차탐색, 이분탐색 | 순차탐색 |
| 요구되는 메모리 | 적음 | 많음 |
| 메모리 활용도 | 비효율적 | 효율적 |


3) 자료구조 그 자체만으로는 의미가 없다. 그것을 어떻게 쓰는가가 자료구조에 의미를 부여하는데  
Access, Search, Insert/Delete의 관점에서  
빠른 Access와 Search가 요구되고, 데이터의 변동(Insert/Delete)이 자주 발생하지 않는 경우에는 Array를,  
데이터의 변동(Insert/Delete)이 자주 발생하고, 데이터의 전체 갯수가 고정적이지 않는 경우에는 Linked list를 사용  


