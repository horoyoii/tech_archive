




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
 
   * 1. 변수의 선언 후 초기화 없이 컴파일 시 에러가 나온다. ( C++과 차이점 )
   <pre><code>
       int num;
       System.out.println(num); //error: variable num might not have been initialized
   </code></pre>
   
   * 2. [자바에서의 명명 규칙](https://m.blog.naver.com/reona7140/221306141987)
     
      - **클래스 이름**의 첫 글자는 항상 대문자.
      - **변수 이름**은 소문자로 시작하되, 대소문자 혼용가능. ex) account, eventHandler
      - **메서드 이름**은 소문자로 시작하고, 대소문자를 혼용하되, 동사를 사용한다. ex) modifyAccount
      - 상수의 이름은 모두 대문자이며, 여러 단어로 이뤄진다면 '_'로 구분한다.  ex) MAX_INT
      - 속성에 접근하는 메서드는 get, set 접두사를 사용 ex) getStudentId, setStudentId
      - 반환값이 boolean인 경우 is 접두사 사용 ex) isStudent
      - 해당 객체를 다른 형태의 객체로 변환하여 반환하는 경우 to 접두사 사용 ex) toString
      - 
   
   
   *
   
 
 
