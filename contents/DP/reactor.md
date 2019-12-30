## 2. Reactor Pattern  


#### 1. Abstract  

* Event-driven 방식의 디자인 패턴  
* 하나의 reactor가 특정 이벤트 발생을 감지한 후 그 이벤트를 특정 이벤트 핸들러에게 이를 알려 이벤트 핸들러에서 그 이벤트를 처리하는 방식.  

* 아래의 예에서는 epoll을 사용하여 구현.
* epoll은 리눅스의 동기적 I/O Notification model이다.  
 1) 동기적 : wait()을 사용하여 이벤트 발생 시까지 대기한다.  
 2) I/O 통지 : 어플리케이션에서 관심있어하는 fd등록 후, 커널이 그 fd에서 이벤트 발생 

[Jump into the Code](/contents/DP/reactor.cpp)
