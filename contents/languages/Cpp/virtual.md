
```
class Base{
public:
    void method(){
        cout<<"Base"<<endl;
    }

};

class Derived : public Base{
public:
    void method(){
        cout<<"Derived"<<endl;
    }

};

int main(void){

    Base* b = new Derived();
    
    /**
        Without "virtual" keyword, 
        function 'method()' is set by the complier at compile time.
        this function is fixed before execution.

        Also called 'early binding'
    */ 
    b->method();    // "Base"


```

# Virtual keyword  

 * Polymrophism 이란 having many forms.  
 * C++에서는 **compile time polymorphism**과 **run time polymorphism**이 있다.  
 1) compile time 다형성 : **method overloading** / **operator overloading**  
 2) run time 다형성 : **method overriding**  
 
 
 
 * b->meㅁthod()는 실제 인스턴스를 인지하지 못한체, 컴파일 시점에 래퍼런스 타입으로  
 해당 함수를 binding 시킴.  -> early binding.  
 
 
### Virtual 사용을 통한 late binding 유도.  

  * Base 클래스의 method function 앞에 virtual 키워드를 추가한다.  
  * 이를 통해 컴파일러는 method function에 대한 late binding을 유도.  
  * C++에서 다형성은 조상 클래스 타입이 자손 클래스 타입의 인스턴스를 가르킬 수 있고 virtual 키워드의 도움으로 구현.  
  * 거기에 method overloading 역시 다형성의 일부.  
  
```
class Base{
public:
    virtual void method(){
        cout<<"Base"<<endl;
    }

};
```

### virtual function    
  * virtual은 클래스 멤버 함수를 동적바인딩 시켜주기 위함.  
  * **virtual keyword**는 컴파일러에게 late binding할테니 건들지마라는 것을 알려주는 키워드  
  * 건들지말고 vtable과 vptr만 추가해라.  
  
#### Pure virtual function (순수 가상 함수)  

  * C++ 추상클래스 : 그냥 가상함수가 아닌 **순수 가상함수*를 하나라도 가지는 클래스  
  * 특정 클래스에서 어떤 기능의 동작을 선명하게 구현할 수 없지만, 그것을 상속받는 클래스들은  
  그 동작을 구현할 수 있다면 기능의 이름 + 매개변수 타입 + 반환형 만 선언하고  
  남은 구현(정의)는 자식에게 맡김.  
  * Animal의 move는 Animal class 자체에서 구현할 수 없다. 걷는 방식은 동물마다 다름.  
  
  * 자손 클래스에서 pure virtual function을 구현하지(overriding) 않는다면  
  이 역시 추상 클래스가 됨.  
  
```
class Base{
public:
    virtual void method() = 0;

};
```

### Interface VS abstract class  

  * 인터페이스가 추상화 강도가 더 높음.  
  * 인터페이스는 단지 메서드 선언의 집합체다. ( + constant 멤버 변수 포함 )  
  -> 자바에서 interface 내에 member variable 정의 시 암묵적으로 public static final 됨.  
  * C++에서는, 특정 클래스의 모든 메서드를 pure virtual method로 만들어 인터페이스 구현됨.  \
  


