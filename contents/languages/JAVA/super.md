
## 6.2. super & super()  


### 1. super  

* 자손 클래스에서 조상클래스로부터 상속받은 멤버를 참조하는데 사용되는 **참조변수**이다.  

* 조상 클래스의 멤버와 자손 클래스의 멤버가 중복으로 정의되어 있다면 super를 통하여 서로 구분한다.  

* 조상과 자손의 멤버를 구별한다는 점을 제외하곤, this와 super는 동일한다.  
* **모든 인스턴스메서드에는 자신이 속한 인스턴스의 주소가 지역변수로 저장되는데, 이것이 참조변수의 this와 super의 값이 된다.**  

* 메서드 역시 super를 써서 호출할 수 있으며, 이 경우 조상클래스의 메서드가 오버라이딩된 경우에 사용한다.  
<pre><code>
void childPlay(){
  super.play();
}
</code></pre>

<pre><code>
class Parent{
    int x=10;
    int z= 40;
    void play(){
        System.out.println("play in parent");
    }
}


class Child extends Parent{

    int x = 20;
    int y = 30;


    void play(){
        System.out.println("play in child");
    }

    void method(){
        
        System.out.println(this.x); // 20
        System.out.println(super.x); // 10

        //System.out.println(super.y); // error : cannot find symbol
        
        System.out.println(this.z);

        play();
        this.play();

        super.play();
    }
}
</code></pre>


### 2. super()  

* this()와 마찬가지로 super() 역시 생성자이다.  

* this()는 같은 클래스의 다른 생성자를 호출하는데 사용되었지만,  
super()는 조상 클래스의 생성자를 호출하는데 사용된다.  


* 자손 클래스의 인스턴스를 생성하면, 자손의 멤버 + 조상의 멤버가 모두 합쳐진 하나의 인스턴스가 생성되기에,  
조상 클래스의 멤버 초기화가 이뤄져야하고 이는 **자손 클래스의 생성자에서 조상 클래스의 생성자를 호출**함으로써 진행된다.  


* 자손 클래스의 생성자 첫 줄에 조상 클래스의 생성자가 호출되어야 한다.  

<pre><code>
class Child extends Parent{
  int x;
  int y;
  Child(){
    super();
    x = 10;
    y = 20;
  }

}
</code></pre>


#### 1. Object 클래스를 제외한 모든 클래스의 생성자의 첫 줄에는 this() 혹은 super()가 있어야 한다.  

- 없을 경우 컴파일러가 자동으로 super(); 를 추가한다.  

#### 2. 컴파일 에러가 나는 예  

* Child의 생성자에 자동으로 super()가 추가되는데 Parent의 생성자는 두 개의 인자를 받아야 한다.  
<pre><code>
class Parent{
  int a;
  int b;
  Parent(int _a, int _b){
    a = _a;
    b = _b;
  }
}

class Child extends Parent{
  int x;
  int y;
  Child(){
  
    x = 10;
    y = 20;
  }
}
</code></pre>

- 그렇기에 아래와 같이 명시적으로 super(10, 20); 을 적어줘야 한다.  


<pre><code>
class Parent{
  int a;
  int b;
  Parent(int _a, int _b){
    a = _a;
    b = _b;
  }
}

class Child extends Parent{
  int x;
  int y;
  Child(){
    super(10, 20);
    x = 10;
    y = 20;
  }
}
</code></pre>
