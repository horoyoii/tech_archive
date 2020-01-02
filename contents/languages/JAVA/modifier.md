
## Modifier(제어자)  

* 클래스, 변수, 메서드의 선언부에 함께 사용되어 부가적인 의미를 나타낸다.  

#### 1. Static  

* '클래스의', '공통적인' 이라는 의미를 가짐.  
* **인스턴스변수**는 하나의 클래스로부터 생성되더라도 각기 다른 값(상태)을 유지하지만, **클래스변수**(static멤버변수)는   
모든 인스턴스가 공유하게 된다.  
* static이 붙은 멤버변수, 메서드 등은 인스턴스의 생성없이도 호출될 수 있다.  


```

    System.out.println(Math.max(10, 20));    
    System.out.println(Math.PI);
   }

}

class Math{
    public static double PI = 3.14;  // static 변수

    static int max(int a, int b){    // static 메서드
        return a > b? a : b;
    }

}
```

#### 2. final  

* final이 붙게 되면 이는 상수가 된다.  
* 클래스 앞에 final이 온다면 확장될 수 없는 클래스가 됨.  
* 메서드 앞에 final이 온다면 오버라이딩을 할 수 없는 클래스가 됨.  

* final이 붙는 변수는 상수이기에 선언과 동시에 초기화를 해야하지만,  
인스턴스변수의 경우 생성자에서 초기화가 가능하다.  

```
class Card{
  final int NUMBER;
  
  Card(int num){
      NUMBER = num;
  }
}
```

