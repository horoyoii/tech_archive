

## Interface  


* 인터페이스는 추상 메서드를 갖지만 추상클래스보다 추상화 정도가 높다.  
일반메서드나 멤버변수를 가질 수 없다.  

* 오로지 추상메서드와 상수만을 가질 수 있다.  이들의 접근 제어자는 public이다.  
 모든 멤버변수는 public static final이다.  
 모든 메서드는 public abstract 이다.  
 
 #### 1. 인터페이스의 상속  
 
 * 인터페이스는 인터페이스로부터만 상속받을 수 있으며, 다중상속이 가능하다.  
 
 ```
 interface Movable{
    int move(int a, int b);
 }
 
 interface Fightable extends Movable, Attackable{ }
 ```
 
 
 #### 2. implenets를 통한 구현  
 
 ```
 class Fighter implements Fightable{ }
 ```
 
 #### 3. 인터페이스의 다중상속  
 
 * 두 조상으로부터 상속받은 멤버 중 멤버변수의 이름이 같거나, 메서드의 선언부가 같으면 어느 것으로부터 상속되었는지 모호하다. : 다중상속의 단점.  
 이러한 연유로 자바에서는 다중상속을 허용하지 않는다.  
 
 * 또한 인터페이스는 다중상속을 위한 것이 아니다.  
 
 
 
 #### 4. 인터페이스를 통한 다형성  
 
 * 다형성은 조상클래스 타입의 참조변수가 자손클래스 타입의 인스턴스를 가르킬 수 있음을 의미하다.  
 
 * 인터페이스 역시 이를 구현한 클래스의 조상이기에 인터페이스 타입의 참조변수는 이를 구현한 클래스 인스턴스를 가르킬 수 있다.  
 
 ```
 interface Flyable{
    int move();
 }
 
 class Duck implements Flyable{
    int move() {  }
 }
 
 Flyable duck = new Duck();
 duck.move(); // 다형성에서, 오버라이딩된 메서드 호출은 참조변수와 무관하게, 실제 인스턴스의 메서드를 정확하게 호출한다.  
 ```
 
 * 매개변수 타입으로서 인터페이스가 올 수 있다.   
 ```
 
 {
      Duck duck  = new Duck();
      goUp(duck); // Duck타입은 Flyable로 업-캐스팅되어 매개변수로 넘어간다.
 }
 
void  goUp(Flyable f){
    f.move();
}
```


#### 5. 인터페이스의 장점  

* 1. 서로 관계없는 클래스들에게 새로운 관계를 맺어줄 수 있다.  
* 2. 개발시간을 단축시킬 수 있다.  
* 3. 표준화가 가능하다.  


#### 6. 인터페이스의 장점  

```
class Unit{
    int HP;
    Unit(int hp){
        HP = hp;
    }
}

class GroundUnit extends Unit{
    GroundUnit(int hp){
        super(hp);
    }
}

class AirUnit extends Unit{
    AirUnit(int hp){
        super(hp);
    }
}

class Tank extends GroundUnit{
    Tank(){
        super(150);
    }
}

class Marine extends GroundUnit{
    Marine(){
        super(110);
    }
}

class DropShip extends AirUnit{
    DropShip(){
        super(22);
    }
    
}

class SCV extends GrounUnit{
    SCV(){
        super(123);
    }

    void repair(){  } // HOW to
}
```
 
![Untitled Diagram (1)](https://user-images.githubusercontent.com/34915108/71664768-a5067280-2d9d-11ea-9602-fb9f2fad07a3.png)


##### 1. 문제 1

* SCV의 repair함수는 기계화 Unit을 고친다. 

```
void repair(Tank t){  
   t.hp += 100;
   t.
}

void repair(DropShip s){  
   s.hp += 100;
}
```

* 하지만 위의 경우 새로운 타입이 추가되면 오버로딩해야 할 메서드가 늘어난다.  


##### 2. 문제 2  

* 공통조상 타입의 매개변수를 사용한다면 기계가 아닌 Marine 클래스도 포함될 수 있어 좋지 않다.  
```
void repair(Unit u){
  u.hp += 100;
}
```


##### 3. 인터페이스 사용  

![Untitled Diagram (2)](https://user-images.githubusercontent.com/34915108/71664988-8359bb00-2d9e-11ea-8b7a-de6ffd3d6875.png)


```
interface Repairable{} 

class Tank extends GroundUnit implements Repairable {
    Tank(){
        super(150);
    }
}

void repair(Repairable r){
    
    if( r instanceof Unit){
        Unit u = (Unit)r;
        u.hp += 100;
    }

}
```


* 기계화 유닛에 Repairable이라는 인터페이스로 새로운 관계를 맺어주고, 매개변수의 타입으로 이를 사용한다.  
* 이때, 인터페이스 참조변수 타입은 정의된 메서드가 없기에 할 수 있는 일이 없다. 


#### 7. A 클래스가 인터페이스를 구현(implements)하고, 그 인터페이스를 구현한 또 다른 a클래스를 A 클래스의 멤버로 포함시켜 내부적으로 
a클래스의 내용을 호출하도록 설계한다.  


```

interface Liftable {
    void LiftOff();
    void move(int x, int y);
    void stop();
    void land();

}

class LiftableImpl implements Liftable{
    void LiftOff() {}
    void move(int x, int y) {}
    void stop() {}
    void land(){} 
}

class Academy extends Building{

}

class Factor extends Building implements Liftable{
    LiftableImpl l = new LiftableImpl();

    void LiftOff(){
        l.LiftOff();
    }
    void move(int x, int y){
        l.move(x, y);
    }
    void stop(){
        l.stop();
    }
    void land(){
        l.land();
    }


}
```
