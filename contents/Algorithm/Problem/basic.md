

#### 1. Linked-List cycle detection.  

[문제](https://leetcode.com/problems/linked-list-cycle) 

1) with Hash Table, node의 메모리 주소를 hasing하여 노드 방문을 기록한다.  
2) with Floid's 토끼와 거북이, 한번에 한 칸씩 뛰는 거북이, 두 칸씩 뛰는 토끼라는 two pointer를 사용한다.  
   - if cyclic, 토끼와 거북이는 언젠가 만난다. 
   - if non-cyclic, 토끼는 next = nullptr에 도착한다.  
   
