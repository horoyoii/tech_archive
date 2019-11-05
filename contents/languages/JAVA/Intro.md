




### 1. 특징


### 2. 개요

 * 1. 자바에서 모든 코드는 반드시 클래스 안에 존재해야 한다.
 
 
 * 2. public static void main(String[] args) 선언부는 java.exe(자바 인터프리터)에 의해 호출된 지점이 된다. 
      - java 어플리케이션은 main메서드의 호출로 시작하여 main 메서드가 끝나면 종료된다.
      - java.exe [main method가 포함된 클래스 이름] 형태로 실행시킨다.
      
      
 * 3. 보통의 경우 하나의 소스코드(.java)에 하나의 클래스를 정의한다.
      - public class가 있는 경우, 소스파일의 이름은 public class의 명과 일치해야 한다.
      - 두 개의 class가 정의된 소스코드를 컴파일할 경우 두 개의 class 파일이 생성된다.
 
 
 ### 3. 변수
 
   * 1 . 변수의 선언 후 초기화 없이 컴파일 시 에러가 나온다. ( C++과 차이점 )
   <pre><code>
       int num;
       System.out.println(num); //error: variable num might not have been initialized
   </code></pre>
   
   * 2 . [자바에서의 명명 규칙](https://m.blog.naver.com/reona7140/221306141987)
     
      - **클래스 이름**의 첫 글자는 항상 대문자.
      - **변수 이름**은 소문자로 시작하되, 대소문자 혼용가능. ex) account, eventHandler
      - **메서드 이름**은 소문자로 시작하고, 대소문자를 혼용하되, 동사를 사용한다. ex) modifyAccount
      - 상수의 이름은 모두 대문자이며, 여러 단어로 이뤄진다면 '_'로 구분한다.  ex) MAX_INT
      - 속성에 접근하는 메서드는 get, set 접두사를 사용 ex) getStudentId, setStudentId
      - 반환값이 boolean인 경우 is 접두사 사용 ex) isStudent
      - 해당 객체를 다른 형태의 객체로 변환하여 반환하는 경우 to 접두사 사용 ex) toString
        
     
   
   * 3 . **기본형**과 **참조형** 변수 (Primitive type & Reference type)
   
       1 ) **Primitive type** : 실제 데이터를 저장. 8개( boolean, char, byte, short, int, long, float, double  
       2 ) **Reference type** : **객체의 주소를 저장**. 8개의 기본형을 제외한 나머지 타입.
           - 참조형 변수를 선언할 때 변수의 타입으로 클래스의 이름을 사용하기에 클래스의 이름이 참조변수의 타입이 된다. ex) Student std;  
           
       3 ) Memory Allocation in JAVA 
          * code section : bytecode  
          * stack section : local variables, reference variables  
          * heap section : objects ( may also reference variables)  
          * static section : static varible/method  
          
### 4. Java is **Call by Value**  
       
   <pre><code>
   public void m3(){
	        Account ref = new Account();
       	// more code 
        // This example is in here, https://www.guru99.com/java-stack-heap.html
   }
   </code></pre>
   
   1. new Account() 를 통해 account의 object가 Heap에 생성.
   ![image](https://user-images.githubusercontent.com/34915108/68208402-6a3dc380-0014-11ea-867c-8e1d14ae40cf.png)
   
   
   2. reference variable 인 "ref" 는 stack에 생성.
   ![image](https://user-images.githubusercontent.com/34915108/68208488-95c0ae00-0014-11ea-8068-d39aa9118f1b.png)
       
 
   3. "=" 할당 연산자를 통해 reference variable인 ref가 heap의 object를 pointing 하도록 한다.
   ![image](https://user-images.githubusercontent.com/34915108/68208504-a07b4300-0014-11ea-8b80-e27b9484b782.png)

   4. m3 function이 종료 시 flow of control이 caller인 m2로 돌아간다.
     - 이 때, m3의 stack frame은 해제된다.(flushed out)
![image](https://user-images.githubusercontent.com/34915108/68208729-2bf4d400-0015-11ea-996c-e381236b6c64.png)

   5. 더 이상 reference variable이 heap의 object를 pointing하지 않기에(reference variable이 해제되었음으로) 
     heap의 account object는 **eligible for garbage collertion** 이라고 표현된다.
![image](https://user-images.githubusercontent.com/34915108/68208736-2eefc480-0015-11ea-8a15-5643b45eb6aa.png)


### 5. Another example

   1 . 매개변수로 넘기는 것은 obj의 주소값이다. 
   2. caller에서 object에 대한 reference variable을 인자로 넘겨주고  
      callee에서는 매개변수로 reference variable를 받을 때 주소값에 대한 복사가 이뤄지기에 call by value인 것...  
      
   3. 기본적으로 primitive type을 넘겨줄 때는 call by value로 
   <pre><code>
   
    // some code...
       Student student = new Student(12, "JIM");
        
        System.out.println(student.getAge());
        
        modifyAge(student); // changed 
        
        System.out.println(student.getAge());
        
        modifyObj(student); // not changed 
        
        System.out.println(student.getAge());
   }

    public static void modifyAge(Student _student){
        _student.setAge(13);

    }

    public static void modifyObj(Student _student){
        _student = new Student(14, "JANE");
    }

   </code></pre>








