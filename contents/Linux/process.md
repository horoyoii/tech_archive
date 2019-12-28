
## Process  

### 1. 가상화 위의 프로세스  
 * 현대 운영체제에서 프로세스는 **가상 프로세서**와 **가상 메모리**라는 두 가지 가상환경을 제공한다.  
  가상 프로세서란 수백 개의 프로세스가 하나의 프로세서를 공유하더라도 프로세스가 혼자 시스템을 사용하는 듯한 가상환경을 제공해주는 것이며, 이는 운영체제의 프로세스
  스케쥴링에 의해 지원된다.   
  * 쓰레드는 각자 고유한 가상 프로세서를 할당받지만 가상 메모리는 공유한다.  
  
### 2. 프로세스  

* 프로세스란 실행 중인 프로그램이자 1) 사용 중인 파일, 2) 대기 중인 시그널 3) 프로세서 상태 4) 할당받은 메모리 주소 공간 등의 정보의 집합이다.  
* 리눅스에서는 프로세스와 스레드(고유한 PC, 프로세스 스택, 프로세스 레지터를 가짐)의 구분이 없다. 

### 3.Process Descripter  

 * 커널은 프로세스 목록을 **Task List**라고 부르는 양방향 연결 리스트 형태로 저장한다.  
 * struct task_struct 는 32bit 시스템에서 약 1.7KB에 달하는 크기를 가지지만 프로세스의 모든 정보를 저장한다.  
 
 
### 4. 프로세스 상태  
 
    struct task_struct {
      #ifdef CONFIG_THREAD_INFO_IN_TASK
      /*
       * For reasons of header soup (see current_thread_info()), this
       * must be the first element of task_struct.
       */
      struct thread_info		thread_info;
    #endif
      /* -1 unrunnable, 0 runnable, >0 stopped: */
      volatile long			state;
      ...
  }
  
  ![스크린샷, 2019-12-28 16-44-45](https://user-images.githubusercontent.com/34915108/71540706-69306f00-2991-11ea-8d94-13748b300a5d.png)
  
  
 ### 5.  
  
