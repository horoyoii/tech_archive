## Template  

#### 0. generic programming(일반화 프로그래밍)을 위한 template  

* 일반화 프로그래밍(generic programming)이란 **데이터 타입에 의존함없이** 알고리즘을 설계하는 것이다.  
  이는 메서드, 클래스, 인터페이스 등에 데이터 타입을 매개변수로서 넘겨줌으로써 구현된다.  
  
* C++에서는 template을 통하여 generic programming이 구현된다.  



#### 1. 템플릿 이란?  

* data type을 **매개변수**로 넘겨줌으로써, 여러 데이터 타입에 대한 동일한 코드를 작성하지 않아도 된다.   

```
template<typename T>
T myMax(T a, T b){
  return a > b ? a : b;
}
```

* 이처럼 **template**과 **typename** 키워드를 통해 작성되며, typename 키워드는 언제나 **class** 키워드로 대체 가능하다.  


#### 2. 동작방식  

* 템플릿이 사용된 코드는 complie time에  컴파일러에 의해 확장된다.  

![스크린샷, 2020-01-04 17-12-06](https://user-images.githubusercontent.com/34915108/71762657-61cf0f80-2f15-11ea-9892-7aa0a62e2faf.png)



#### 3. 함수 템플릿 (Function Template)  

* 
```
template<typename T>
T myMax(T a, T b){
  return a > b ? a : b;
}


cout<< myMax<int>(10, 20) <<endl;
cout<< myMax<double>(10.2, 30.4) <<endl;
cout<< myMax<char>('a', 'b') <<endl;
```


#### 4. 클래스 템플릿( Class template)  

```
template<typename T>
class Array{
private:
  T *ptr;
  int size;
public:
  Array(T arr[], int s);
  void print();
}

template<typename T>
Array<T>:: Array(T arr[], int s){
  ptr = new T[s];
  size = s;
  for(int i=0;i<s;i++)
    ptr[i] = arr[i];
}

template<typename T>
void Array<T>::print(){
  // some code..
}

Array<int> a(arr, 5);
```
