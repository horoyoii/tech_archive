
# List Interface  

[설명](https://www.javatpoint.com/collections-in-java)  

![스크린샷, 2020-01-30 11-56-49](https://user-images.githubusercontent.com/34915108/73416246-a785c900-4357-11ea-9170-6a948cdc98c8.png)

```
public interface List<E> extends Collection<E>{
  void add(int index, E o);
  boolean add(E o);
  void clear();
  boolean contains(Object o);
  boolean equals(Object o);
  E get(int index);
  boolean isEmpty();
  Iterator<E> iterator();
  ...
}
```

  * Iterable interface를 상속한 Collection interface를 상속한 List interface  
  * 이를 통해 **ArrayList**, **LinkedList**, **Stack**, **Vector** 가 구현됨.  
  

## 1. 특징  

  1. duplicate value 저장 가능  
  2. 삽입 순으로 정렬되어 저장  
  3. **동기화는 제공되지 않음**   
  
```
List<Integer> list1 = new ArrayList<>();
List<Integer> list2 = new LinkedList<>();
List<Integer> list3 = new Vector<>();
List<Integer> list4 = new Stack<>();
```

## 2. LinkedList  
  * 내부적으로 Doubly Linked list를 구현   
  * remove("B") : linked list내의 특정 노드를 삭제한다.  
  -> 내부적으로는 head부터 순차 탐색  
```
       LinkedList<String> object = new LinkedList<String>(); 
  
        // Adding elements to the linked list 
        object.add("A"); 
        object.add("B"); 
        object.addLast("C"); 
        object.addFirst("D"); 
        object.add(2, "E"); 
        object.add("F"); 
        object.add("G"); 
        System.out.println("Linked list : " + object); 
  
        // Removing elements from the linked list 
        object.remove("B"); 
        object.remove(3); 
        object.removeFirst(); 
        object.removeLast(); 
```
  
[소스코드](http://developer.classpath.org/doc/java/util/LinkedList-source.html)  

```
// LinkedList 소스코드
 406:   public boolean remove(Object o)
 407:   {
 408:     Entry<T> e = first;
 409:     while (e != null)
 410:       {
 411:         if (equals(o, e.data))
 412:           {
 413:             removeEntry(e);
 414:             return true;
 415:           }
 416:         e = e.next;
 417:       }
 418:     return false;
 419:   }
```

