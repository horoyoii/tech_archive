
##  추상 클래스  

* 클래스가 설계도라면, 추상클래스는 미완성 설계도이다.  

* 단지, 미완성 메서드(abstract method)를 가지는 클래스이다.  
  추상클래스는 상속을 통해 자손클래스에 의해 완성되며, 그 자체만으로는 인스턴스를 생성할 수 없다.  
  
* 추상 메서드를 포함한다는 것 외에는 일반 클래스와 동일하다.  


#### 1. 상속을 통한 완성  

 * 메서드의 이름과 매개변수, 리턴타입을 정의하는 것만으로도 메서드의 절반 이상이 완성된 것이다.  
  메서드를 사용하는 쪽에서는 위의 셋만 안다면 실제로 어떻게 구현되었는지 몰라도 잘 사용할 수 있다.  
  
  * 메서드는 선언부와 구현부로 구성되어있고, **추상 메서드**란 선언부만 작성하고 구현부는 작성하지 않은 채 남겨둔 것이다.  
  주석을 덧붙여 어떤 기능을 수행할 목적인지를 알려주고, 실제 내용은 이를 상속받는 자손클래스에서 구현한다.  
  
  * 추상클래스를 상속받는 자손클래스는 오버라이딩을 통해 모든 추상메서드를 구현해야 하며, 전부 구현하지 않는다면 자손클래스 역시 추상클래스가 된다.  
  
  
  
#### 2. 왜 사용하는가?  

* 여러 객체들의 공통된 부분을 찾아 추상클래스에 정의한 후 다른 부분만을 추상메서드로 정의하여 그 다른 부분만 자손클래스에서 알맞게 구현하도록  
위임하는 것이다.  




```
class Marine{
  int x, y;
  void move(int x, int y){  ~  }
  void shot() { }  
}

class DropShip{
  int x, y;
  void move(int x, int y){ ~ }
  void load() {  }
}

class Tank{
  int x, y;
  void move(int x, int y) {   ~  }
  void run() {   }
}

```
위의 세 가지 클래스에서 공통된 부분을 찾아 공통의 조상을 만드는 작업을 **추상화**라고 한다.  

```
abstract class Unit{
  int x, y;
  abstract void move(int x, int y);
}

class Marine extends Unit{
  void move(int x, int y){  ~  }
  void shot() { }  
}

class DropShip extends Unit{
  void move(int x, int y){ ~ }
  void load() {  }
}

class Tank extends Unit{
  void move(int x, int y) {   ~  }
  void run() {   }
}

```



* 다형성에서, 오버라이딩 된 메서드는 참조변수의 타입과 상관없이 실제 인스턴스의 메서드를 호출한다.  
```
Unit[] group = new Unit[3];
group[0] = new Marine();
group[1] = new Tank();
group[2] = new DropShip();

for(int i =0; i < group.length; i++)
  group[i].move();

```
