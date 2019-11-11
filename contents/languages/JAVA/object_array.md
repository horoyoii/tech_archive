## 5.2 객체 배열

### 1. 객체 배열이란?
 
 * 많은 수의 객체를 다뤄야할 경우 배열로 관리하면 편할 것이며, 객체 역시 배열로 관리할 수 있다.  
 <pre><code>
 
        Student std1, std2, std3;
        std = new Student("Hame", 123);
        std2 = new Student("Kane", 31);
        std3 = new Student("Jane", 31);

        //** 객체 배열

        Student[] stdArr = new Student[3];
        // 1) 각 요소는 Reference type의 기본값인 null로 초기화된다.
        // 2) 객체 배열 안에는 객체 그 자체가 저장되는 것이 아닌,
        //    객체의 주소가 저장된다.

       
        // 객체 배열 생성 후 다음과 같이 객체를 생성하여 그 주소를 배열에 저장한다.
        stdArr[0] = new Student();
        stdArr[1] = new Student();
        stdArr[2] = new Student();    
       
       
        for(int i =0; i < stdArr.length; i++){
            stdArr[i] = new Student();   
        }  
 
 </code></pre>
 
  * 모든 배열이 그러하듯, 객체 배열도 같은 타입의 객체만 저장할 수 있지만... 다형성을 통하여 여러 종류의 객체를 하나의 배열에 저장할 수 있다.  
  
### 2. C++과의 차이


* Java
<pre><code>
Student[] stdArr = new Student[3];
</code></pre>

* C++
<pre><code>
Student stdArr[3];
</code></pre>


* 위의 시행 결과 java에서는 해당 객체 배열이 정의된 함수 프레임에 reference type 의 변수를 3개의 공간만 할당한다. 
* c++에서는 실제로 배열 내에 객체를 생성을 완료한다. 즉, 생성자가 호출된다. 


* C++에서 위의 java코드와 같이 동작하기 위해서는 student의 pointer type
<pre><code>

Student* stdArr[3];

</code></pre>



