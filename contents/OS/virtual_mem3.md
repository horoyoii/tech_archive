
# Virtual Memory  

##### 1) It uses **secondary memory** which can be addressed as though it were part of main memory.  
##### 2) Virtual memory addresses which is generated by CPU and used by program are automatically translated to the corresponding physical addresses **at run time**.  
##### 3) main memory의 크기 제한이 더 커지게 됨.  
##### 4) A program may be broken into number of pieces called as **page**.  
   -> these pages need not be  continuously  located in the main memory during execution.  
   -> 단편화 예방 가능  
   -> It is also not necessary that all pages are present in the main memory during execution.  
   -> **It means that the required pages are loaded into main meomory whenever needed**  
   

# Demanding Paging  
  * 프로세스 실행 중 특정 페이지가 필요할 때마다 디스크의 스왑 공간에서 메인 메모리로 load하는 것.  
  
##### The process of loading the page into main memory on demand (when **page fault** occurs)  

1. If CPU try to refer a page that is currently not available in the main memory, it generates an interrupt indicating memory access fault.
2. The OS puts the interrupted process in a blocking state. For the execution to proceed the OS must bring the required page into the memory.
3. The OS will search for the required page in the logical address space.
4. The required page will be brought from logical address space to physical address space. The page replacement algorithms are used for the decision making of replacing the page in physical address space.
5. The page table will updated accordingly.
6. The signal will be sent to the CPU to continue the program execution and it will place the process back into ready state.  

# Swap space  

  * swap space is a portion of virtual memory that is on the hard disk, used when RAM is full.  
  
 # page fault handling    
 [GeeksForGeeeks](https://www.geeksforgeeks.org/page-fault-handling-in-operating-system/)    
 ![image](https://user-images.githubusercontent.com/34915108/73272402-a6ed1580-4225-11ea-82b4-4102a99da634.png)  

  1) when a virtual address generated by CPU has no corresponding frame on the main memory,  
  it is called as page fault.  
  2) Page fault occurs when a MMU fails to translate it.  
  3) Then MMU calls OS to help, which is **trap**.  
  4) When the OS know the page fault occurs by the trap,  
  OS set the process in the state of **blocking** and handle the fault.  
  5) OS finds the frame in the swap space and put it into the main memory.  
  6) Then, update the Page Table and restart the process.  
  
 # Page Replacement Algorithm  
   * cache size가 full되어 evict될 victim을 어떻게 고를 것인가?  
   
#### 1. FIFO  
 
#### 2. Optimal Replacement  
   * 가장 늦게 사용되리라고 예상되는 것을 뺌. - 구현 불가  
#### 3. LRU  
   * linked-list 와 hash table로 구현 가능  
   * 가장 덜 최근에 사용된 것을 뺌.  
#### 4. LFU  
   * min heap 사용 / 각 노드를 가르키는 hash table / 트리중간요소 빈도+1 시 자식과 비교해서 reorder  
   
   * 가장 사용빈도가 낮은 것을 뺌.  
   
#### 4. MFU  
  * 가장 사용빈도가 높은 것을 뺌  
  * 낮은 것이 다시 사용될 것이라는 판단 때문 / 높은 것은 이미 충분히 사용되었다.  
  
  
  
   
 
 
