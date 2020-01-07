
## 1. lower_bound & upper_bound  
* [구현](https://m.blog.naver.com/PostView.nhn?blogId=bestmaker0290&logNo=220820005454&proxyReferer=https%3A%2F%2Fwww.google.co.uk%2F)  

#### 1. lower_bound  
  * ForwardIterator( 증가연산(++)이 적용되는 iterator)를 가진 컨테이너에서 동작  
  * **정렬되어 있음**을 가정한다. 
  * 주어진 key 이상의 값을 찾아 iterator를 반환한다.  
```
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val);
```

#### 2. upper_bound 
  * 주어진 key 초과의 값 중 최소의 값을 찾아 그 iterator를 반환한다.  
  
```
#include<algorithm>

int arr[] = {10, 20, 20, 20, 30, 40, 50, 60};
vector<int> vc(arr, arr+8);

vector<int>::iterator iter;

iter = lower_bound(vc.begin(), vc.end(), 20);
iter = upper_bound(vc.begin(), vc.end(), 20);

*iter // 20
*iter // 30

iter = lower_bound(vc.begin(), vc.end(), 23);
iter = upper_bound(vc.begin(), vc.end(), 23);

*iter // 30
*iter // 30

```
## 2. sort  

## 3. find  
