

## Polymorphism (다형성)  


* 객체지향의 중요한 개념 중 상속과 더불어 **다형성**  
* 다형성은 말 그대로 **여러 가지 형태를 가질 수 있는 능력**이다.  
##### 자바에서는 한 타입의 참조변수가 여러 타입의 객체를 참조할 수 있도록 함으로써 다형성을 프로그래밍적으로 구현했다.  


#### 1. 지금까지는 생성된 인스턴스를 다루기 위하여, 그 인스턴스 타입과 일치하는 타입의 참조변수만을 사용했다.  

* 조상클래스 타입의 참조변수로 자손클래스 타입의 인스턴스를 참조할 수 있게 된다.  

```
class Tv{
    boolean power;
    int channel;

    void power(){
        power != power;
    }

}

class CaptionTv extends Tv{
    String text;
    void caption(){
        System.out.println("Caption ");
    }
}

Tv t = new CaptionTv();
CaptionTv c = new CaptionTv();

```

* 위의 t와 c는 동일한 타입의 인스턴스를 가르키지만, **참조변수의 타입**에 따라 호출할 수 있는 멤버변수가 제한된다.  
```
Tv t = new CaptionTv().
t.caption(); // error
```


* 자손클래스 타입의 참조변수로는 조상 클래스 타입의 인스턴스를 가르킬 수 없다.  


#### 2. 형변환  

* 기본형 변수처럼 참조변수 역시 형변환이 가능하지만 **상속관계**에 있는 경우에만 형변환이 가능한다.  

* 자손타입 -> 조상타입 : 업 캐스팅  
 - 자손타입의 참조변수를 조상타입의 참조변수로 형변환 시 형변환 생략가능하다.  
  
* 조상타입 -> 자손타입 : 다운 캐스팅  

```

class Car{
    String color;
    void drive(){
        System.out.println("brrrr~");
    }

}

class FireEngine extends Car{
    void water(){
        System.out.println("water!!");
    }

}
class Ambulance extends Car{
    void siren(){
        System.out.println("siren~~~~");
    }

}
```

* 위의 예를 활용한 형변환 예제  

```
      Car car = null;
      FireEngine fe = new FireEngine();
      
      car = fe; // 업 캐스팅 

      FireEngine fe2 = null;
      
      fe2 = (FireEngine)car; // 다운 캐스팅   
```


#### 3. instanceof 연산자  

* 형변환에 앞서 어떤 참조변수가 실제로 어떤 인스턴스 타입을 가르키고 있는지 확인하는 것이 중요하다.  

```
if(c instanceof FireEngine){
    // c가 FireEngine의 인스턴스를 가르키고 있다면 true를 반환한다.  
}

```
* 부모클래스에 대한 instanceof 연산 역시 true가 된다.


```
Car c = new FireEngine();

if(c instanceof Car) // true

if(c instanceof Object) // true
```


* 조상클래스 타입의 참조변수는 자손클래스의 인스턴스를 가르킬 수 있으며,   
동시에 조상타입의 참조변수로는 실제 인스턴스의 멤버를 모두 사용할 수 없기에  
실제 인스턴스를 확인 후 형변환하여 사용해야 한다.  
```
void doWork(Car c){
  
  if(c instanceof FireEngine){
      FireEngine fe = (FireEngine)c;
      fe.water();
  }else if( c instanceof Ambulance){
      Ambulance a = (Ambulance)c;
      a.siren();
  }

}

```


#### 4. 변수와 메서드의 이름 중복  


* 메서드가 오버라이딩된 경우 참조변수의 타입과 상관없이 실제 인스턴스의 메서드를 호출한다.  

```
class Parent{
    int x = 100;

    void method(){
        System.out.println("parent method");
    }

}

class Child extends Parent{
    int x = 200;

    void method(){
        System.out.println("Child method");

    }
}
```

```
Parent p = new Child();
Child  c = new Child();

p.method(); // Child mehtod 
c.method();  // Child method
```

* 반면, 멤버변수의 이름이 중복되는 경우 참조변수의 

```

p.x; // 100
c.x; // 200
```


#### 5. 다형성의 장점  

* 왜 다형성이 필요한가?  

##### 1. 코드의 길이를 줄일 수 있다. 확장성이 좋다.  

```
class Product{
  int price;
}

class Tv extends Product{}
class Audio extends Product{}
class Computer extends Product{}

```

위의 경우 제품이 늘어날수록 아래의 buy 메서드를 추가해야 한다.   

```
void buy(Tv t){
  money -= t.price;
}

void buy(Audio a){
  money -= a.price;
}
```

* 하지만 매개변수에 다형성을 적용한다면 하나의 메서드로 구현이 가능하다.  
이때, 매개변수 p는 자손클래스의 참조변수가 업캐스팅되어 들어온 것이다.  

```
buyer.buy(new Tv());
buyer.buy(new Audio());


void buy(Product p){
  money -= p.price;
}
```


##### 2. 여러 종류의 객체를 하나의 배열로 다루기  

```
Product[] products = new Product[10]; // 

products[0] = new Audio();
products[1] = new Computer();
```
