# 1. shared_ptr  
* C++ 11이전에도, 더 이상 사용하지 않는 스마트 포인터인 std::auto_ptr 이 있었다. 
* 하나의 특정 객체를 참조하는 여러 개의 스마트 포인터가 있을 수 있다.
* 참조 횟수는 특정 객체에 대한 새로운 shared_ptr이 추가될 때마다 +1 되며, 수명이 다할 때마다 -1이 되며 마지막 shared_ptr이 수명이 다하여,  
  참조 횟수가 0이 되면 delete 연산자가 적용되어 메모리를 자동으로 해제한다.  
  
  

### 1. What : Reference count(참조 횟수) model  

* shared_ptr 은 raw pointer의 container이다.  
* reference counting ownership model(참조 횟수 카운터 모델)을 따른다.  
 - shared_ptr 변수 자체는 참조자이다. 하나의 객체는 여러 참조자에게 참조 당할 수 있지만 객체 자체는 복사되지 않는다.
   
    ```
    shared_ptr<int> sh_ptr(new int(10)); // reference count +1
    
    shared_ptr<int> sh_ptr2 = sh_ptr; // refCount +1
    
    shared_ptr<int> sh_ptr3 = sh_ptr2; // refCount +1

    cout<<sh_ptr.use_count()<<endl; // 3

    *sh_ptr = 100;

    cout<<*sh_ptr2<<endl; // 100
    ```
    ![Untitled Diagram](https://user-images.githubusercontent.com/34915108/71593533-db62a880-2b77-11ea-87c9-46270734d0c7.png)


### 2. 참조 카운터가 0이 되면 자동으로 해제한다.  
* shared_ptr 참조자가 해제될 때 refCount는 하나씩 감소하며 0이 되면 shared_ptr 참조자가 가르키는 객체에 대한 delete 연산을 적용한다.  


* 아래의 경우 boo라는 함수 스코프 내에서 Person을 동적할당하였지만 실수로 delete를 하지 못하였다면 프로그램 종료 전까지 살아있게 된다. 
- memory leak 발생  

```
void boo(){
    Person* ptr = new Person(10, 12);
    ptr->show();

    //delete ptr;
}
```


* 반면, shared_ptr을 사용하여 동적할당을 한다면 foo 함수 스코프에서 반환될 때(caller로 돌아갈 때) 지역변수인 sh_ptr과 sh_ptr2는 자동으로 해제된다. 

* 1) 스택 영역에 할당된 객체는 그 스택 프레임이 소멸 시 자동으로 해제된다는 것을 이용하여
  2) sh_ptr과 sh_ptr2라는 참조자가 해제되면,
  3) 동적할당된 Person 객체의 참조 카운터가 0이 되어,
  4) Person 

```
void foo(){
    shared_ptr<Person> sh_ptr(new Person(10, 11));
    sh_ptr->show();
    
    shared_ptr<Person> sh_ptr2 = sh_ptr;
    
    // 함수 빠져나갈 때 Person 객체는 자동으로 해제됨...!
}
```


### 3. 결국 share_ptr은 RAII 패턴을 구현한 것이다.  
 * arr eh eye eye 라고 발음.  
 * GC가 없는 C++의 경우 동적으로 메모리 할당을 하면, 이에 대한 관리(해제)는 온전히 프로그래머의 몫이다.  
 * 스택영역에 할당된 메모리는 자동으로 해제되다는 것을 활용한 것이 RAII 패턴이다.  
 
 
 ### 4. make_shared 

* new를 대신하여 make_shared를 통한 스마트 포인터 생성  
``` 
typedef shared_ptr<User> UserPtr;

int main(void){
   
    shared_ptr<User> user(new User(10, 1234));
           
    UserPtr user_ptr2(new User(11, 444));

    shared_ptr<User> user_ptr3 = make_shared<User>(10, 3333);

    UserPtr user_ptr4 = make_shared<User>(12, 344);
```
    
    
 ### 5. 문제점  
 
 
 ##### 1. delete[]가 아닌 delete를 적용한다.  
 
 ##### 2. 순환 참조 문제  
 
 * 그룹 객체와 소속 객체 간의 서로에 대한 참조 시 메모리 해제가 제대로 되지 않을 수 있다.  
 
 
 
 
 
