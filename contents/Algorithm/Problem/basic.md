

#### 1. Linked-List cycle detection.  

[문제](https://leetcode.com/problems/linked-list-cycle) 

1) with Hash Table, node의 메모리 주소를 hasing하여 노드 방문을 기록한다.  
2) with Floid's 토끼와 거북이, 한번에 한 칸씩 뛰는 거북이, 두 칸씩 뛰는 토끼라는 two pointer를 사용한다.  
   - if cyclic, 토끼와 거북이는 언젠가 만난다. 
   - if non-cyclic, 토끼는 next = nullptr에 도착한다.  
   
   
#### 2. minStack 
[문제](https://leetcode.com/problems/min-stack/)

1) minStack.getMin() 호출 시 스택 원소 중 가장 작은 값을 반환한다. -> constant time에 구현.  
2) stack<pair<int,int>> : pair< 요소 값, 이 요소를 포함한 아래의 모든 원소 중 가장 작은 값 > 
3) 혹은 double stack 으로 구현해서 pair를 각

#### 3. reverse bits
[문제](https://leetcode.com/problems/reverse-bits/)  

1) 비트연산자를 활용한 divide 방식  
n = n>>16 | n <<16  
   n = (n & 0xff00)<<8 | (n & 0x00ff)>>8   
   ...
   
   
#### 4. count one bit (Hamming Weight)  
[문제](https://leetcode.com/problems/number-of-1-bits/)  

1) >> 연산자 활용  
2) n 과 n-1에 대하여 and 연산 적용 시 내림수 아래는 모두 0이 된다.  



#### 4. reverse Linked-List 
[문제](https://leetcode.com/problems/reverse-linked-list/)  

1) Iterative version  : prev node를 통해서 간결하게 만들기  
2) Recursive version  

#### 5. count primes  
[문제](https://leetcode.com/problems/count-primes/)  

1) 소수 세기 : 에라스토테네스의 체  

#### 6. Stack using Queues  
[문제](https://leetcode.com/problems/implement-stack-using-queues/)  

1) by two queue 
2) by one queue 



   
