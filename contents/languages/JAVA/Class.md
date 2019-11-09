## 5.1. Class  


### 1. What is OOP?  

 * 객체지향이론의 기본개념은 **실제 세계와 유사한 가상 세계를 컴퓨터 속에 구현하는 것**이다.  
 * 이 기본개념의 토대는 **실제 세계는 사물(객체)로 이루어져 있으며, 발생하는 모든 사건들은 사물간의 상호작용이다**라는 것.  
 * 객체지향의 가장 큰 장점은  
   1) 코드의 재사용성이 높다.  
   2) 코드의 유지보수가 용이하다.  
   3) 중복 코드의 제거  
   
   
### 2. 클래스와 객체

#### 1) 클래스 : 객체를 정의해놓은 것 / 객체의 설계도 혹은 틀 / 주물  
#### 2) 객체  
  * 사전적 의미 - 실제로 존재하는 것.  
  * 프로그래밍적 의미 - **클래스에 정의된 내용대로 메모리에 생성된 것**.  
              
  * 클래스는 단지 객체를 생성하는데 사용될 뿐, 그 자체로 객체는 아닌 것이다.  
  
#### 3) 객체와 인스턴스  

   * 어떤 클래스로부터 객체를 만드는 과정을 **인스턴스화(Instantiate)**이라고 한다.  
   * 어떤 클래스로부터 만들어진 객체를 **인스턴스(Instance)**라고 한다.  
   
   * 객체와 인스턴스의 문맥에 따른 구분.  
     - 학생은 인스턴스다 ->  학생은 객체다. 
     - 학생은 학생 클래스의 객체다 -> 학생은 학생 클래스의 인스턴스다.  
     
   * 객체와 인스턴스는 같은 의미이지만, 객체는 모든 인스턴스를 대표하는 포괄적인 의미를 가지며, 인스턴스는 어떤 클래스로부터 만들어진... 그러한 것을 강조한느 보다 구체적인 의미 
   

### 3. 객체의 구성요소 - 속성과 기능  

#### 1) 객체는 속성과 기능, 두 **종류**의 구성요소로 이뤄진다.  
#### 2) 속성 - Property, Attribute, Field, State, Member Variable 등으로 표현된다.  
#### 3) 기능 - Function, Method, Behavior 등으로 표현된다.  



### 4. 인스턴스의 생성과 사용  

#### 1 클래스로부터 인스턴스를 생성하는 방법은 여러가지가 있지만 다음과 같이 할 수 있다.  
<pre><code>
클래스명 변수명;
변수명 = new 클래스명();

Student student;
student = new Student();
</code></pre>

<pre><code>
public class Hello{
  
    public static void main(String[] args){
         
        Student std;
        std = new Student("Hame", 123);

  }

}


class Student{
    String  name;
    int     age;
    boolean isAbsence;


    Student(String _name, int _age){
        this.name = _name;
        this.age = _age;
    }
    
    String getName(){
        return name;
    }
    
    void setName(String _name){
        this.name = _name;
    }



}

</code></pre>

#### 1) Student std;  
 * Student클래스 타입의 참조변수 std를 선언한다. 선언을 한 해당 함수의 스택 프레임에는 참조변수 std를 위한 공간이 마련된다. 
 
#### 2) new Student();  
 * 연산자 new에 의해 Heap의 빈 공간에 Student클래스의 인스턴스가 생성된다. 
 * 이 때, 멤버변수는 생성자에서 초기화를 하지 않는다면 각 자료형에 맞는 기본값으로 초기화된다.  
 * 참조형이라면 null, int타입이라면 0, boolean타입이라면 false로 ...
 
#### 3) std = new Student();  
  * 그 후 대입연산자(=)에 의해서 Heap에 생성된 객체의 주소값을 참조변수 std에 저장한다.
  

### 5. 객체의 회수 by GC  

<pre><code>
Student std1 = new Student("Kane", 12);
Student std2 = new Student("Jane", 14);

std1 = std2;

</code></pre>
  
  
#### 1. 참조변수 st1은 Jane 객체를 가르키게 되고, Kane객체는 더 이상 자신을 가르키는 참조변수가 없게 된다.  
 - 객체의 인스턴스는 오직 참
 - **자신을 참조하고 있는 참조변수가 하나도 없는 인스턴스는 더 이상 사용되어질 수 없으므로, GC에 의해서 자동적으로 메모리에서 해제**된다.
  
  




