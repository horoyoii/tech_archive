## 3. Function Pointer   

#### 1. Definition  

* Pointer는 단지, another variable의 주소를 가지는 변수이다.  
a pointer is a variable that holds the address of another variable.  

* Function pointer는 단지 변수가 아닌, 함수의 주소를 가르키는 변수이다...!  

```

int boo(int a, int b){

    return a+b;
}

void goo(double a){

    cout<<"hello : "<<a<<endl;
}

int main(void){
    

    int (*booPtr)(int, int) = boo;
    
    cout<<booPtr(1, 2)<<endl;


    void (*gooPtr)(double); // 반환형이 void이고 매개변수가 double인 함수 포인터라는 변수 gooPtr을 선언.

    gooPtr = goo; // 그리고 정의.

    gooPtr(10.2);

```


#### 2. Pointer to function  

```
int (*fcnPtr)(); 
```

* 위의 fcnPtr은 반환형이 int이고 매개변수가 없는 함수들을 가르킬 수 있는 함수 포인터이다.  


```
int (*fcnPtr)(double, double); // 함수 포인터형 변수 선언

fcnPtr = foo;  // 정의 

fcnPtr(10.2, 13.2); // 호출
```


#### 3. Passing a function as arguments to other function  

* 함수 포인터가 유용하게 사용될 때는 **callback function**으로서, 다른 함수에게 넘겨줄 때이다.  

```
void goo(int a){

    cout<<"hello : "<<a<<endl;
}

void foo(int a, int b, void (*fcnPtr)(int)){

    int sum = a+b;
    
    fcnPtr(sum);
}

int main(void){
    
    foo(10, 20, goo); // goo 함수를 callback 함수로 넘겨준다. 

    return 0;
}
```
  
  
* <algorithm>이 sort 함수 역시 comparison을 수행하는 특정 함수를 받을 수 있다.

```

bool myComp(int a, int b){
  return a > b;
}

sort(arr.begin(), arr.end(), myComp);
```


#### 4. make it pretty  

###### 1. typedef 사용.  

* typedef를 사용하여 함수 포인터를 예쁘게 만들 수 있다.  
```
typedef bool (*compareFcn)(int, int); 

void mySort(RandomAccessIterator first, RandomAccessIterator last, compareFcn comp){
   ...
   comp(a, b);
   ...
}

```


##### 2. std::function 사용 in C++11 <functional>  

* <> 안에 반환형과 그 안의 ()
```
std::function<void(int, int)> compPtr = myCompare;
```

```
void foo(int a, int b, function<void(int)> callback){

    int sum = a+b;
    
    callback(sum);
}

int main(void){
    
    foo(10, 20, goo);

    function<void(int)> fcnPtr = goo;

    fcnPtr(10);

    return 0;
}
```












#### 5. Reference  

[here](https://www.learncpp.com/cpp-tutorial/78-function-pointers/)


