 
 # unordered_map  
 
 ### What  
   * associative container  
   * key-value pair 저장 구조  
   * **unique key** 보장  
   * Search / Insert / Delete 는 **constant time** 이 보장  
     key를 바탕으로 한번의 hash가 계산되면 이를 바탕으로 버킷에 바로 접근.  
   * 내부적으로 **not sorted**  
   hash table을 기반으로 구현됨.  
   각 원소는 버킷에 저장되며, 어떤 버킷에 담기게 될지는 키로 결정된다.  
   
   
 #### Member Function  
 
##### clear()  
clears the contents   
  
##### empty()  
check whether the container is empty. 
  
##### insert();  

```
unordered_map<int, string> hs;

hs.insert(make_pair(10, "hello"));
hs.insert({11, "bye"});
```
**insert보다는 []연산자를 써라...!**
  
##### operator[]   
  * access or insert specified element
  * 원소에 접근할 뿐만 아니라 생성가능.  
  * insert와 달리, 기존값을 **overwrite**가능.  
```
hs[10] = "aaa";
hs[20] = "bbb";

hs[10] = "ccc";

cout<<hs[10]<<endl;  // ccc
```  

##### find(T key);  
   key를 통해 **Iterator**를 반환  
 ```
 unordered_map<int, string>::iterator iter = hs.find(10);
 if(iter != hs.end()) ~
```

##### erase(Iterator)  
```
iter = hs.find(10);
hs.erase(iter);
```

