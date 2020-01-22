[참고](https://gmlwjd9405.github.io/2018/10/27/webserver-vs-was.html)  


# 1. static page 와 dynamic page  

#### 1. static page  
  * image, html, css, js 파일 등 고정되어 있는 파일.  

#### 2. dynamic page  
  * request 인자 등에 따라 내부의 컨텐츠가 변화하는 페이지.  
  
# 2. Web Server  

  * 클라이언트로부터 HTTP 요청을 받아 **정적인 컨텐츠**(.html, .jpeg, .css)를 제공하는 프로그램.  
#### 1. 기능  
1) 정적인 컨텐츠 제공  
2) WAS를 거치지 않고 바로 자원 제공  
3) 동적 컨텐츠 제공을 위한 요청을 WAS **전달**  
4) 클라이언트의 요청을 WAS에 보내고, WAS의 처리결과(응답)을 받아 클라이언트로 전달  

#### 2. Web server의 예  
1) Apache Server  
2) NginX  


# 3. WAS (Web Application Server)    

#### 2. Web Application Server의 예  
1) Tomcat  



# 4. Why we need both of them  

![스크린샷, 2020-01-22 17-45-25](https://user-images.githubusercontent.com/34915108/72878836-09827500-3d3f-11ea-86a0-7b12f4b0f512.png)

#### 1. Web server  
 1. 하나의 웹 페이지를 서빙할 때 보내지는 html 파일 내의 image, css, js 등의 파일은 한번에 같이 보내지지 않음.  
 2. html문서를 먼저 클라이언트가 받고 이후 필요한 정적 파일들을 순차적으로 요청보냄.  
 3. 하나의 페이지를 제공하기 위하여 서버에는 하나 이상의 요청을 처리해야 함.  
 4. **Web Server**를 통해 정적 파일들은 WAS까지 가지 않고 앞단에서 빠르게 처리 가능  
 
#### 2. Web Application server  
 1. 사용자의 요청에 맞게 적절한 동적 컨텐츠를 제공해야 함.  
 2. WAS는 데이터를 DB에서 가져와서 비지니스 로직에 맞게 가공하여 동적 컨텐츠를 제공할 수 있음.  
 

#### 3. Web serve + WAS  
  1. WAS는 DB조회, 다양한 로직처리 등으로 바쁘기에 단순한 정적 컨텐츠는 Web server가 빠르게 제공.  
  
