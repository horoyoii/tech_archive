

## 5.4. 변수와 메서드  


### 1. 변수

 * 변수는 클래스 변수, 인스턴스 변수, 지역변수 모두 세 종류가 있다.  
 * 멤버변수를 제외한 모든 변수는 지역변수이다. 멤버변수 중 static keyword가 붙은 변수는 클래스 변수이다.  
 
 #### 1) 클래스 변수 : 클래스가 메모리에 올라갈 때 생성.  
  - 인스턴스마다 독립적인 저장공간을 가지는 인스턴스 변수와 달리, 클래스 변수는 모든 인스턴스가 공통된 저장공간을 공유한다.  
  - 한 클래스의 모든 인스턴스가 공통적인 값을 유지해야하는 속성이 있다는 클래스 변수로 선언.  
  - 인스턴스를 생성하지 않고도 바로 사용할 수 있다.
  - **클래스가 메모리에 로딩될 때 생성되어 프로그램이 종료될 때까지 유지되기에 public을 붙이면 전역변수의 성격을 가진다.**  
  - 클래스명.변수명 으로 사용될 수 있다.  
  
  
 #### 2) 인스턴스 변수 : 인스턴스가 생성될 때 생성.  
  - 그렇기에 인스턴스변수를 읽거나 쓰기 위해서는 인스턴스를 먼저 생성해야 한다.  
    
####  3) 지역변수 : 변수 선언문이 실행될 때 생성.  
  - 메서드 내에 생성되어 메서드 내에서만 사용 가능하다.  
  - 메서드가 종료되면 소멸되어 사용할 수 없게 된다.  
  
  <pre><code>
  class Student{
    int age; // 인스턴스 변수
    static int school_code = 123; // 클래스 변수
    void foo(){
      int local_var; // 지역변수
    }
  }
  
  public static void main(){
    Student.school_code; 바로 사용 가능.  
  }
  </code></pre>
 
 
 
 ### 2. 메서드  
 
  * 메서드란 특정작업을 수행하는 '일련의 문장들'을 하나로 묶은 것.  
  
 
