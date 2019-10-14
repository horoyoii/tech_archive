
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
    
    
### 3. Insertion Sort

  * 만약 input이 이미 정렬되어 있다면 O(N)으로 효율적인 정렬을 보장한다.
  * 모든 원소에 대하여 앞에서부터 차례대로 이미 정렬된 배열과 비교하여 자신의 위치를 찾아 삽입한다.
  
  
  
### 6. Counting Sort (계수 정렬)

 * 비교연산 없이 정렬이 가능하다.
 * 시간복잡도는 O(N + K)
 * 각 원소가 몇 개 등장하는지를 **카운트**하여 정렬한다. (즉, 각 원소의 등장 빈도를 센다.) 
 * 구현 방식에 따라 Stable Sort 유도 가능
 * In-place sort가 아니다. 정렬을 위한 추가 메모리 할당이 필요하다.
 * 원소의 값이 곧 추가 할당될 배열의 index가 되므로 input에 음수가 있으면 적용할 수 없다(?) < minimum value를 구해서 0으로 shifting해서 구할 수 있다.
 
 1) 주어진 input list의 원소 중 최솟값과 최댓값을 안다면(혹은 구하여)  
 인덱스가 최솟값부터 시작하여 최댓값으로 끝나는 배열을 할당하고 0으로 초기화한다.
 
 2) 그리고 input list를 처음부터 순회하면서 각 원소의 값을 인덱스로 하여 추가 할당된 배열의 해당 값에 +1을 한다.
 
 3) 이렇게 만들어진 추가 할당 배열에 누적합을 계산한다.  
  누적합은 향후 input list를 정렬할 때 인덱스로 사용된다. O(K)
  
 4) Stable Sort를 위하여 input list의 마지막 원소부터 정렬한다.  
  이때 어디에 위치시킬지는 추가 할당된 배열의 누적합을 기반으로 계산할 수 있다.
 
 

  
