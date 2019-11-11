## 5.5. 매개변수와 반환타입  
  
  
### 1. 기본형 매개변수와 참조형 매개변수  

* **자바에서는 메서드를 호출할 때 넘겨준 인자값이 메서드의 매개변수에 복사된 형태로 넘겨준다.**  

 1) 즉, 매개변수 타입이 기본형인 경우 기본형의 값 자체가 복사된다.  
 2) 매개변수 타입이 참조형이라면 값이 저장된 주소를 복사한다.  
 
 >> 기본형 매개변수 - Read only  
 >> 참조형 매개변수 - Read & Write  
 
 
 ** 기본형으로 매개변수를 받을 경우  
 ** d.x값이 변경되는 것이 아닌 매개변수 x의 값이 변경된다.  
 <pre><code>
 public class Hello{
    public static void main(String[] args){
        Data d = new Data();

        d.x = 10;
        
        tryChange(d.x);

        System.out.println(d.x); // 10
            
    }

    static void tryChange(int x){
        x = 1000;
    }
}

class Data{
    int x;
}
 </pre></code>
 

** 참조형 매개변수의 경우 값의 변화가 가능해진다.  

<pre><code>
public class Hello{
    public static void main(String[] args){
        Data d = new Data();

        d.x = 10;
        
        tryChange(d);

        System.out.println(d.x); // 1000
            
    }

    static void tryChange(Data d){ // 인스턴스 d의 주소가 복사되었고...
        d.x = 1000;                 // 그 주소를 이용해 실제 Heap에 할당된 x 공간에 접근가능
    }
}

class Data{
    int x;
}
 </code></pre>

** 배열도 객체와 같이 참조변수를 통하여 데이터가 저장된 공간에 접근한다. 
<pre><code>
public class Hello{
    public static void main(String[] args){
        int[] arr = new int[3]{1,2,3};
        
               
        tryChange(arr);

        System.out.println(arr[2]); // 1000
            
    }

    static void tryChange(int[] d){ 
        d[2] = 1000;                
    }
}

class Data{
    int x;
}
</code></pre>

** 반환형 역시 참조자 타입이 될 수 있다.  
** 
<pre><code>
public class Hello{
    public static void main(String[] args){
        
        Data d = new Data();
        d.x = 10;

        Data d2 = tryChange(d);

        System.out.println(d2.x);             
    }

    static Data tryChange(Data d){ 
        Data rtn_d = new Data();
        
        rtn_d.x = d.x;
        
        return rtn_d;               
    }
}

class Data{
    int x;
}
</code></pre>
