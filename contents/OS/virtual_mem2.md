
# Virtual Memory  

  * 가상 메모리는 프로세스마다 가상의 메모리를 할당한 후 실제로는 물리 메모리와 디스크에 페이지 단위로 할당하는 메모리 관리 기법.   
  * 가상 메모리라는 것은 프로세스마다 할당됨 / 유저 프로그램의 관점에서의 메모리   
  * secondary memory(디스크)를 메인 메모리의 연장선 상으로 볼 수 있게 됨.  
  
![스크린샷, 2020-01-20 09-38-22](https://user-images.githubusercontent.com/34915108/72691427-a3dc9000-3b68-11ea-9f23-4ec1c5bc2018.png)

[이점]  
1. **External fragmentation**을 제거(Contiguous allocation에서의 문제)  
2. 디스크를 통한 스왑 in-out을 통한 **실제 물리 메모리 이상의 메모리 사용 가능**.  

[단점]
1. 연속할당에 비하여, virtual address를 physical address로 변환하는 작업을 거치기에 오버헤드 발생.  

## 1. Paging  
  **페이징은 프로세스마다 가지는 가상 메모리 공간을 일정한 크기(페이지, 4KB)로 나누어,    
  물리 메모리 공간의 프레임에 할당하거나 디스크에 스왑인&아웃을 하는 기법으로  
  가상 메모리 구현 기법.  
  
##### Logical address space is splitted into fix-side blocks, called **pages**.  
##### Phygical address space is divide into corresponding blocks, called **frame**.  


## 2. Page Table  

###### PC(Program counter) : a **register** in a computer processor that contains the address of the instruction being executed at the current time.  
-> 다음 실행될 instruction의 가상 메모리 주소를 가르키고 있는 레지스터.  

#### 2.1. Page table   
  * virtual address와 physical address 간의 mapping 정보를 담고 있는 자료구조.  
  * page table 역시 사용되기 위하여 메모리에 떠있어야 함.  
  * PTE(Page Table Entry) : 물리 메모리의 프레임 넘버와 optional bits 저장.  
  * Present bit가 false면 현재 요청된 페이지는 메모리에 없고, 디스크에 있기에 swap in 필요.  
  * 페이지가 메모리에서 evict되어 swap-out될 때, **Dirty bit**가 1일 때만 disk write 수행.  
  
![스크린샷, 2020-01-20 09-59-25](https://user-images.githubusercontent.com/34915108/72691816-92e14e00-3b6b-11ea-8bbf-23c34f7edb30.png)


