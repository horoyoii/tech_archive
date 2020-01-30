
# ArrayList  

  * Collection 인터페이스를 **상속**한 List 인터페이스를 **구현**한 ArrayList  
  * 내부적으로 **Dynamic array** : run time에 유동적으로 크기가 변한다.  
  * insertion order로 저장된다.  
  * random access 가능  
  * **primitive type** 사용 불가 : wrapper class 사용  
  * C++의 vector와 유사  

```
ArrayList<Integer> list = new ArrayList<Integer>();

list.add(11);
list.add(22);
list.add(33);

Iterator iter = list.iterator();

while(iter.hasNext()){
    System.out.println(iter.next());
}

```


## Method  

#### get(int idx)  
```
list.get(2);
```

#### set(int idx, E elemet)  
 * 대체  
```
list.set(2, "Hello");
```

#### remove(int idx)  
```
list.remove(3);
```

#### forEach(Consumer<? super E> action)  
```
list.forEach( (n) -> { System.out.println(n); n+1; } );
```

#### contains(Ojbect O)  
```
arr.contains(3); // true or false
```

#### isEmpty()  
```
arr.isEmpty()
```
#### clear()  

#### add(Object O)  
  * tail에 O 추가  
  
#### indexOf(Ojbect O)  
  * O가 처음 등장하는 index 반환 없다면 -1  
  
#### iterator()  
  * iterator 반복자 반환  
  
```
Iterator iter = list.iterator();

while(iter.hasNext()){
  System.out.println(iter.next());
}
```
