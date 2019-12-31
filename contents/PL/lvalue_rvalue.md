## 1. L-value   

#### 1. Definition  : Location-Value  

* L-value 는 assignment operation(할당 연산자)의 좌측에 올 수 있는 값을 의미한다.  
* 더 정확히는, **메모리 상의 식별가능한 주소를 가지는 개체**이다.  
  
   
   
* 아래의 var 변수는 스택영역의 어딘가에 주소를 가지고 있기에 L-value가 된다.  
```
int var; 
var = 10; // var is a l-value  

10 = var; // error
```


## 2. R-value  

#### 1. Definition   

* R-value는 exclusion으로 정의될 수 있는데, L-value가 아닌 **모든 expression**이 R-value가 된다.  
* 즉, 메모리 상의 특정 주소를 나타내지 않는 변수이다.  

```
int glov = 10;

int& foo(){
  return glov;
}

int main(void){

  foo() = 10; // foo()는 glov의 참조자를 반환하기에, L-value로서 할당 연산자의 좌측에 올 수 있다.  
}

```


## 3. Conversion(변환)  

* L-value는 R-value로 변환이 가능하지만, 그 역은 안된다.  

```
int a = 20;
int b = 30;
int c = a + b;
```

* 더하기 연산자(+)는 두 개의 R-value를 받아 하나의 R-value를 반환한다.  
이 때, 위의 a와 b는 L-value이지만 line 3에서 implicitly L-value to R-value로 변환된 것이다.  




## 4. Footer  

* 원래의 L-value는 할당 연산자의 좌측에 올 수 있는 개체이지만, const 의 등장 이후 메모리의 식별가능한 주소를 가지는 개체로 바뀌었다.  

```
const int var = 20;
var = 30 // Error
```

* 






