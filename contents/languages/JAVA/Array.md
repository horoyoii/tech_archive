

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

 #### 2. 배열의 선언과 생성
 
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


#### 3. 배열의 초기화 

   * 배열은 생성됨과 동시에 기본적으로 자료형 타입에 맞는 기본값으로 초기화된다. ex) int형 array라면 0으로 채워짐.
   * 중괄호{} 를 통해 배열의 값들을 초기화할 수 있다. 이 때, 대괄호[] 안에는 요소의 수를 적지 않는다.  
   * 중괄호{}를 사용하여 초기화할 경우 **new int[]** 생략할 수 있다.  

 <pre><code>   
        int[] arr = new int[5];

        int[] arr2 = new int[]{1,2,3,4,5};
    
        int[] arr3 = {1,2,3,4,5};

        for(int v : arr2)
            System.out.println(v);
        
        for(int i=0; i < arr3.length ; i++)
            System.out.println(arr3[i]);
        
 </code></pre>



#### 4 배열의 복사

  * 배열은 한번 생성하면 그 길이를 변경할 수 없다. 그렇기에 더 많은 저장공간이 필요하게 되면 더 큰 배열을 생성하여 기존 값들을 복사해야 한다.
  
  
  ##### 1) 첫번째 방법 : for문 사용
  
  * 확장된 배열 tmp 를 새로 만든 후 for loop을 통하여 요소들을 복사하고  
    기존의 배열을 가르키던 참조형 변수 arr에 (새로 만든)참조변수 tmp 값을 저장한다.
    
  
  <pre><code>
      public static void main(String[] args){
      
        int arr[] = new int[]{1,2,3,4,5};
        
        expandArraySize(arr);

        for(int v : arr)
            System.out.println(v);

  }
  
    static void expandArraySize(int[] _arr){
    
        int[] tmp = new int[_arr.length * 2];

        for(int i =0; i < _arr.length; i++){
            tmp[i] = _arr[i];
        }

        _arr = tmp;
    }  
  </code></pre>
  
  * java는 call by value이기에 위의 코드는 원하는 결과를 가져오지 못한다. 
  * **아래와 같이 return 값으로 caller에서 값을 대입해줘야 한다. <= call by value의 단점**.
  
  
  <pre><code>
      public static void main(String[] args){

         int arr[] = new int[]{1,2,3,4,5};
         
         arr = expandArraySize(arr);

        for(int v : arr)
            System.out.println(v);

  }
  
    static int[] expandArraySize(int[] _arr){

        int[] tmp = new int[_arr.length * 2];

        for(int i =0; i < _arr.length; i++){
            tmp[i] = _arr[i];
        }

        return tmp;
    }  
  </code></pre>
  
  * 위의 경우 기존의 arr이 가르키던 크기 5인 배열은 **더 이상 자신을 가르키는 참조변수가 없기에 GC에 의해 자동적으로 메모리에서 제거**된다.
  
  
  ##### 2) 두번째 방법 : System클래스의 arraycopy() 메서드 사용.
  
  
  <pre><code>
  
  System.arraycopy(기존배열, 기존배열의 복사 시작 index, 확장된 배열, 확장된 배열에서 복사를 시작할 index, 기존배열에서 복사할 요소의 갯수)
  
  int[] arr = new int[5];
  
  int[] new_arr = new int[arr.length * 2];
  
  System.arraycopy(arr, 0, new_arr, 0, arr.length);
  
  
  </code></pre>
  
  
  


#### 5. 다차원 배열




