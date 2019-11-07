

## 3. Array in Java


  #### 1. 배열이란
  
  * 같은 타입의 여러 변수를 하나의 묶음으로 다루는 것이 배열.
  * **배열은 한번 생성되면 그 길이를 변경할 수 없다.**
  * **In java, an object is a class instance or an array**.
    - java에서 array는 object이다. 
    - arr.length 를 통해 배열의 길이를 반환받는데 이는 JVM이 모든 배열의 길이를 별도로 관리하기 때문이다.
    - array는 길이가 고정적이기에 arr.length 는 상수다. 
    
   
  <pre><code>  
     int[] arr = new int[3];
     혹은
     int arr[] = new int[3];
  </code></pre>
  
  *  **변수 arr 은 배열을 다루기 위한 참조변수**일 뿐이다. a.k.a Pointer
  * int형 변수들은 Heap에 연속적으로 저장된다.
  * 참조변수인 arr은 Stack에 저장된다.
  
  ![스크린샷, 2019-11-07 15-12-31](https://user-images.githubusercontent.com/34915108/68364378-1eecf780-0171-11ea-8fcf-137391ee1d34.png)

 #### 2. 배열의 선언과 생성 및 초기화
 
  <pre><code>
  int[] score;  // array 선언
  score = new int[5]; // array 생성 및 초기화
  </code></pre>
 
 ##### 1) int[] score;  
  int형 array의 참조 변수 score를 선언한다.  
  * 해당 Stack frame에는 참조변수 score의 공간만 할당된 상태.
  ![스크린샷, 2019-11-07 15-22-33](https://user-images.githubusercontent.com/34915108/68364859-88b9d100-0172-11ea-8cf3-ae0f9636c0d7.png)

##### 2) new int[5];  
  * new 연산자에 의해서 Heap의 빈 공간에 5개의 int형 데이터를 저장할 수 있는 공간을 연속적으로 할당한 후 0으로 초기화한다.
![스크린샷, 2019-11-07 15-23-03](https://user-images.githubusercontent.com/34915108/68364860-89526780-0172-11ea-880f-821b30f476dd.png)

##### 3) score = new int[5]  
 * =대입연산자를 통해서 Heap에 할당된 array의 시작주소를 참조변수 score에 대입한다.
 
![스크린샷, 2019-11-07 15-23-08](https://user-images.githubusercontent.com/34915108/68364863-8a839480-0172-11ea-9881-59ff5cd02941.png)



