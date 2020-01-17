  
  
 # 컴파일 과정  
 
**main.c** (high level language의 source code)  
  
  
  [전처리기] : #으로 시작되는 include, macro, 조건부 컴파일 지시자(#ifdef) 을 처리(치환) / 주석 제거  
   
  **main.i** 
  
  [컴파일러] : 전처리 된 소스코드를 어셈블리어로 변환.  
  
  **main.s**
  
  [어셈블러] : 어셈블리어 코드를 object file로 변환.  
  
  **main.o**
  
  [ 링커 ] : object file을 조합하여 executable object file로 반환.  
  
  **a.out**  
  
  
  ## Object file의 종류  
  
  1. executable object file : 링크과정까지 끝나서 바로 실행가능한 object file.  
  2. relocatble object file : 어셈블러를 통해 생성된, 아직은 링크되지 않은 object file.  
  3. shared object file : 동적 링킹이 가능한 object file(run time 중 링킹 가능)  
  
  
  
# GCC 옵션  
[gcc 기본 이해](http://doc.kldp.org/KoreanDoc/html/gcc_and_make/gcc_and_make-2.html)  

#### -o option  : 
  output 파일 명을 지정
```
$ gcc main.c -o main
$ ls
main.c main
```

#### -E option  : 
  소스코드의 전처리 결과 코드 .i 를 생성.  

```
$ gcc -E main.c > main.i
$ ls
main.c main.i
```
```
#define MAX 10
int main(void){
  int arr[MAX];
  // hello world 
  return 0;
}
```
전처리 후의 .i 파일  
- 주석제거 / macro 대체  

```
int main(void){
  int arr[10];
  return 0;
}
```

#### - S option  
상위의 소스코드나 전처리된 코드를 바탕으로 어셈블리 코드 생성.  
```
$ gcc -S main.c (or main.i) 
$ ls
main.c main.s
```
컴파일러의 결과로 다음의 어셈블리 코드가 생성.  

```
	.file	"main.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
```

#### -c option  
상위의 코드를 바탕으로 object file (.o)를 생성  
```
$ gcc -c main.c(or main.i / main.s) 
$ ls 
main.o
```
#### -L options  
relocatable object file을 링킹한다.  

```
#include<stdio.h> 가 있다면  

$ gcc main.o -L/usr/include 
or
$ gcc main.o
// /usr/include 밑에 stdio.h 파일 있음. 
```

#### 여러 파일 링킹  

main.c가 mathLib.h에 의존한다면...   
```
#include<stdio.h>
#include "mathLib.h"

#define MAX 10

int main(void){
    
    printf("Hello world\n");


    int arr[MAX];

    int sum =0; 
    sum = myAdd(10, 20);
    printf("sum is %d\n", sum);

    return 0;
}
```

main.c의 단일한 main.o (relocatable object file은 생성됨.  
```
$ gcc -c main.c
$ ls
main.o
```

그러나 링킹을 하면 myMath.c의 object file도 필요함.  
```
$ gcc main.o
// undefined reference to 'myAdd'
```

두 개의 object file을 gcc에 같이 알
```
$ gcc -c mathLib.c

$ gcc main.o mathLib.o -o main

```
