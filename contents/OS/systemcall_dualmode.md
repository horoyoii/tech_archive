
[바로 여기봐도 됨.](https://duksoo.tistory.com/entry/System-call-%EB%93%B1%EB%A1%9D-%EC%88%9C%EC%84%9C)  

# System call  
  * **user application이 privileged instruction을 실행하기 위하여  
  OS의 Kernel에 서비스를 요청하는 것.**  
  system call is a way for programs to interact with the OS.  
  sytem call is the only entry point into the kernel system.  
  system call is 소프트웨어 인터럽트(트랩).  
  
  
  ![스크린샷, 2020-01-19 10-06-06](https://user-images.githubusercontent.com/34915108/72672796-5b0ed380-3aa3-11ea-9582-17e7e97a1dea.png)

  * 시스템 콜이 호출되면 user mode에서 kernel mode로 변경되고(mod bit 1 -> 0)  
  시스템을 보호하기 위하여 특권명령은 kernel mode에서만 동작한다.  
  -> 유저 프로그램이 공유 자원에 임의 접근을 막아야 함.  
  -> 유저모드에서 특권명령 시도 시 trap to os 발생.  
  

## Dual mode  
  **시스템 실행 시의 모드를 두 가지로 나눈 이유는 공유자원의 보호!!**  
  -> user program을 신뢰하지 않아서다...  
  
#### 1. User mode  
  * General instructions in a user application runs in this mode.  
#### 2. Kernel mode  
  * In **mode bit** set to 0, if **system is in kernel mode**, it can run any privileged instruction.  
  

## HOW IT WORKS  

#### 1. trap : 소프트웨어적, 프로그램 내부에서 발생시키는 인터럽트 to OS  
  * 두 가지로 인해 발생됨.  
1) **Exception** : divide_error(0x0), segment_not_present(), page_fault(), timer_interrupt(0x20)
2) **System call** : system_call(0x80)  

#### 2. IDT(Interrupt Descriptor Table)  
  * 프로세스에서 발생되는 인터럽트(트랩)은 IDT에서 관리됨.  
  * IDT는 소프트웨어 인터럽트 식별 번호와 그것의 핸들러(서비스 루틴)의 매핑 정보 저장.  
  
![스크린샷, 2020-01-19 10-20-22](https://user-images.githubusercontent.com/34915108/72672907-521f0180-3aa5-11ea-9ab2-981012733b84.png)

#### 3. When a system call is called in LINUX,  

![스크린샷, 2020-01-19 10-26-00](https://user-images.githubusercontent.com/34915108/72672950-1df81080-3aa6-11ea-8e3d-91298cd5125e.png)

 1) 유저 프로세스에서 fork() 함수(시스템 콜)를 호출 시  
 2) fork 식별번호인 2를 eax레지스터에 저장 후 0x80 인터럽트 발생  
 3) 커널은 IDT에서 0x80 인터럽트에 해당하는 trap handler를 호출.  
 4) system_call()이라는 트랩 핸들러는 시스템콜 번호(2)에 해당하는 함수(루틴)을 호출.  
 5) 그 루틴에서 커널이 '프로세스 생성'이라는 작업 수행  
 6) 종료 시 유저 프로세스로 return.  
 
 


###  참고  

