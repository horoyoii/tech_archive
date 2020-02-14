

# 1. REST


### 1. What
 * HTTP 위에서, 서버와 클라이언트 간 통신을 위한 규약. 
 * 자원(Resource)의 표현(Representation)에 의한 자원의 상태(State) 전달. 
 
    * 자원 : 서버에서 관리되는 모든 것. 문서, 그림, 데이터 등등
    * 표현 : 위의 자원들을 말그대로 표현하는 것.
    * 상태 전달 : 요청된 자원의 상태 혹은 정보를 전달하는 것. JSON 혹은 XML 형식으로 반환.
    
    * 예) GET : www.hello.com/api/v1/students/111/score  
      서버에는 학생들의 데이터가 DB에 저장되어있다. (자원)  
      위의 URI를 통해 클라이언트는 학번이 111인 학생의 점수를 서버에 요청한다. (표현 : 학생을 students로, 학번을 111로, 점수를 score로 표현함)
      이에 대한 응답으로 서버에서는 JSON 형식으로 그 학생의 점수를 응답할 수 있다. (상태 전달)
      
  * HTTP URI를 통해 자원을 명시하고, HTTP Method를 통해 해당 자원에 대한 CRUD를 적용시킨다.
 
 
### 2. Features

   1. 클라이언트 - 서버 구조
  
   2. Stateless 
  
   3. Cacheable
  
   4. Self-descriptive
  
   5. Uniform Interface
  
   6. 계층형 구조
   


### 3. 요약  

[사이트 1](https://hackernoon.com/restful-api-design-step-by-step-guide-2f2c9f9fcdbf)  
 
 
 
[조대협님 사이트](https://bcho.tistory.com/954)  





