[Tutorials](https://www.tutorialspoint.com/jenkins/jenkins_overview.htm)  

# Jenkins  

 This is **CI/CD server**.
 

## What is this  
  * a software that allows **continuous integration**.  
  * cause this is also software so it runs on **a remote server where the central build occurs**.  
  * CI : is the merging all developers' codes to a shared main project at regular intervals.  
  
  * It has two release lines.  
 
 
## How to use  

  [설치 링크](https://jybaek.tistory.com/764)  
  * based on Docker  
  1. Download the image from docker hub and run    
  ```
  docker pull jenkins/jenkins
  docker run -p 8080:8080 jenkins/jenkins:lts
  ```
  
  2. now, access jenkins ui via browser  
  ```
  http://localhost:8080
  ```
   
   
  
  
