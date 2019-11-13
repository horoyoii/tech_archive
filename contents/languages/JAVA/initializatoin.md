
## 5.7. 변수의 초기화  

#### 1. 초기화  

 * 변수를 선언하고 처음으로 값을 저장하는 것을 '변수의 초기화'라고 한다.  
 
#### 2. 멤버 변수와 지역 변수  
* 멤버 변수 : (인스턴스 변수 + 클래스 변수) 따로 초기화를 하지 않아도 자료형에 맞는 기본값으로 초기화된다.  
* 지역 변수 : 사용하기 전에 반드시 초기화해야 한다.  


#### 3. 멤버 변수의 초기화 방법  

### 1. 명시적 초기화  
* 변수의 선언과 동시에 초기화를 진행.  
<pre><code>
Card{
  int num = 0;
  Shape s = new Shape();

  Card(){
  
  }
}
</code></pre>

### 2. 초기화 블럭  
* 클래스 내에 블럭{}을 만들고 그 안에 코드를 작성하면 된다.  

<pre><code>
Card{

  Card(){
    count++;
    serialNo = count;
    
    this.color = "white";
  }
  
  Card(String color){
    count++;
    serialNo = count;
    
    this.color = color;
  }
}
</code></pre>

* 인스턴스 초기화 블럭은 생성자보다 먼저 호출되며, 인스턴스 생성 시마다 호출된다.  
* 여러 생성자들에서 중복되는 코드를 제거하는 용도로 사용될 수 있다.  

<pre><code>
Card{
  
  {
      count++;
      serialNo = count;
  }
  
  Card(){
    this.color = "white";
  }
  
  Card(String color){
    this.color = color;
  }
}
</code></pre>

* 클래스 초기화 블럭  
- 클래스 자체가 메모리에 로딩될 때, 클래스 초기화 블럭이 한번 실행된다.  
- 클래스 인스턴스를 초기화하기 위하여 사용된다.  

<pre><code>
Card{
  static int count;
  
  static {
     count=0;
  }
  
  Card(){
    this.color = "white";
  }
  
  Card(String color){
    this.color = color;
  }
}
</code></pre>
3. 생성자  
