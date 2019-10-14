
# Sorting

![캡처](https://user-images.githubusercontent.com/34915108/66751411-ecc9dc00-eec9-11e9-91fe-dd34cde4e297.PNG)
* Selection sort는 not stable
* [출처] https://ratsgo.github.io/data%20structure&algorithm/2017/10/19/sort/


## Prefix
 * In-Place : input list의 크기 외의 추가적인 메모리 할당을 요구하지 않는 속성.
 
 * Stable : 주어진 input list에 대하여 요구되는 조건 외에서는 정렬 상태가 유지되는 속성.
   * 예를들어, 특정 input을 오름차순으로 정렬하되, 값이 동일하다면 처음 input으로 들어온 순서 그대로가 유지되는 것.
   * Merge Sort가 Quick Sort에 비해 가지는 이점이다. 
   * A sorting algorithm is said to be stable if two objects with equal or same keys appear in the same order in sorted output as they appear in the input array to be sorted.
 
### 1. Bubble Sort

 * 서로 인접한 두 원소를 비교하면서 정렬하는 알고리즘

   * 1회전 후 가장 큰 원소는 가장 마지막에 위치하게 된다.
   * 2회전 후 그 다음으로 큰 원소가 그 다음의 마지막에 위치하게 된다.
   
* 즉, 매 회전마다 정렬해야 하는 원소의 수가 하나씩 줄어든다.
   
     
* Time Complexity
 
  * 비교횟수 : 총 n-1 번의 회전을 하게 되고, 각 회전마다 비교횟수가 1씩 감소한다.
    (n-1) + (n-2) + (n-3) ... + 1 = n(n-1)/2
     * BEST, AVG, WORST : O(n^2)

### 2. Selection Sort

  1) (오름차순 기준) 1회전 시 첫번째 원소를 선택한 후 마지막 원소까지 순회하면서 가장 작은 값을 찾는다.
  2) 이렇게 찾아진 가장 작은 원소와 처음에 선택했던 첫번째 원소를 스왑.
  3) 이를 통해 1 회전 시 가장 작은 값은 제자리로 정렬된다.
  4) 2회전 시 두번째 원소를 선택한 후 그 다음 원소부터 마지막 원소까지 순회하면서 가장 작은 값을 찾은 후 위와 같이 스왑
  
  * 즉, 각 회전마다 정렬될 위치를 선택한 후 그에 맞는 원소를 선택하여 위치시킨다.
  * 버블 정렬과 달리, 매 회전 시 스왑 횟수가 1회 or 0회가 보장된다.
  
  * Not Stable 
     * 5(1) 4 5(2) 2 를 정렬하면 2 4 5(2) 5(1) 로 나올 수 있기에 Not Stable 하다.
     
  * Time Complexity 
    * BEST, AVG, WORST : O(N^2)
