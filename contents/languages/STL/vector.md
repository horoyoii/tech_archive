

# vector  


### 개념  

  ##### 동적 배열(Dynamic Array)  
  원소들이 메모리 상에 **연속적으로** 할당된다.  
  이는 곧 Iterator를 통해 순차적으로 접근(Access) 가능할 뿐만 아니라  
  메모리 상의 offset을 계산하여 상수 시간 O(1) Direct Access가 가능함을 의미한다.  
    
  ##### 동적 재할당  
  vector는 내부적으로 정적 배열을 가지며,  
  원소가 추가될 때 배열의 크기가 부족하다면 더 큰 사이즈로, **자동으로 배열을 재할당**한다.  
  배열 재할당 시 **모든 원소의 복사**가 발생한다. O(N)    
  
  ##### 배열의 재할당 시 현재 크기 x 2 만큼 추가해나간다.  
  실제 메모리 상에 할당된 크기는 capacity()로 확인.  
  ```
  vector<int> vc;
  
  // vector에 원소 7개 추가 시
  vc.capacity();  // 8
  
  // vector에 원소 400개 추가 시
  vc.capacity();  // 512
  
  ```
  
  ##### 재할당(Reallocation)  
  
  * **vector에서 end에 원소를 추가**하는 것은 O(1)로 빠르다.  (max capacity가 아니라면)  
  * **vector에서 middle에 원소를 추가**하는 것은 O(n)이다.  
   내부적으로 static array이기에 삽입된 위치 이후부터 한칸 씩 밀어줘야 한다.  
  
  ##### reserve() 사용  
  삽입될 원소의 수를 미리 알고 있다면 reserve함수를 통해 capacity 만큼 미리 메모리에 크기를 할당할 수 있다.  
  이를 통해 실행 중 불필요한 memory reallocation을 막는다.  
  
  
### Member Function  

##### size()  
  * 실제 할당된 원소의 수 반환  
##### capacity()  
  * 메모리 상에 할당된 배열의 크기를 반환  
```
vector<int> vc;
vc.push_back(1);
vc.push_back(2);
vc.push_back(3);

vc.size();     // 3
vc.capacity(); // 4
```

##### reserve(int new_cap)  
  * capacity를 new_cap으로 늘인다. 
  * resize와 달리, 원소 자체를 할당-초기화하진 않는다.
```
vector<int> vc;
vc.reserve(10);

vc[2]; // 0

vector<Person> vc;
vc.reserve(4);     // 생성자는 호출 안됨.
```

##### resize(int, value) or resize(int)    
  * vector의 size를 int로 조정한다.  
  * 동시에 초기화를 수행한다.  
  * 이미 들어있는 원소들은 영향이 없고 기존 size보다 작은 크기로 조정 시 원래 값은 버려진다.  
```
vector<Person> vc;
vc.resize(10);      // 생성자 10번 호출

vc.resize(5);        // 소멸자 5번 호출 

vc.resize(7);       // 생성자 2번 호출
```
  
##### assign(int, value)  
  * resize(int, value) 는 기존의 값은 건들이지 않는다.  
  * assign은 처음부터 int개까지 전부 value로 초기화한다.  기존의 값은 사라진다.  
  * **empty**상태에서는 resize와 assign은 동일한다.  
  
  
```
vector<int> vc;
vc.push_back(1);
vc.push_back(2);

vc.assign(5, 555);
// 555 555 555 555 555
```
```
vector<int> vc;
vc.push_back(1);
vc.push_back(2);

vc.resize(5, 555);
// 1 2 555 555 555
```
##### clear()  
  * 모든 원소 삭제  
  * size = 0 
##### push_back()  
  * 마지막에 원소 추가  
##### pop_back()  
  * 마지막의 원소 삭제  
##### erase(Iterator)  
  * iterator 위치의 원소 삭제  
  * 삭제된 원소 다음 원소의 iterator 반환  
#####

  
  
  
  
  
  
  
  
