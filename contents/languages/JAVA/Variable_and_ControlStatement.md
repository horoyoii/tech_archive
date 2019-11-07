
## 2. 변수



### 1. 기본형 ( Primitive Type )

   #### 1)  8개의 타입(자료형)이 있다.
   * boolean(1byte), char(2byte), byte(1byte), short(2byte), int(4byte), long(8byte), float(4byte), double(8byte)  
   * char : 자바에서는 **유니코드(2byte 문자체계)** 를 사용한다.
      - 특히 자바에서는 UTF-16을 사용하기에 모든 문자는 2byte의 고정크기로 인코딩되며 처음 128자는 아스키와 동일하다.
       
  
   #### 2) 변수, 상수, 리터럴
   

       int age = 19; 
       final int MAX_VALUE = 123;    
       age : 변수
       MAX_VALUE : 상수
       19, 123 : 리터럴

     
   
   
  #### 3) 형변환
  
  * (타입)피연산자
  
  
 ### 2. 제어문 ( Control Statement )
 
   * 제어문이란 프로그램의 흐름(Flow)을 바꾸는 역할을 하는 문장이다.  
   
   #### 1) 조건문 ( Conditional Statement )  
   
   * if, switch  
   * **블럭** : 괄호{}를 이용하여 여러 문장을 하나의 단위로 만들 수 있는데, 이를 블럭이라고 한다.
     - 주로 같은 블럭 내의 문장들은 탭(tab)으로 들여쓰기(Indentation)를 하여 보기 좋게 한다.  
   * if 문의 경우 블럭에 속한 문장이 하나인 경우 괄호{}를 생략할 수 있다.    
    <pre><code>if(age > 19) System.out.println("Hello"); </code></pre>
   
   #### 2) 반복문 ( Iteratoin Statement )
   
   * for, while  
   * for loop의 세 가지 요소 (초기화, 조건식, 증감식)은 생략가능.
   
   <pre><code> 
   for(; ; ){
      System.out.println("Loop");
   }
   </code></pre>
  
  
         
 
