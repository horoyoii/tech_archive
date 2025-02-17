
# 1. Proxy server  
![image](https://user-images.githubusercontent.com/34915108/73276285-c8e99680-422b-11ea-990f-5bb385ed9ca5.png)  

  1. 서버의 부하를 분산시킬 수 있다.  
  2. 클라이언트의 요청은 서버로 바로 가는 것이 아닌, 프록시 서버로 가게 된다.  
  3. 프록시 서버에서는 그 요청에 대한 응답이 캐싱되어 있다면 그것을 클라이언트에게 반환한다.  
  4. 응답이 캐싱되어 있지 않다면 **프록시 서버가 대신 요청**을 수행한다.  


# 2. Reverse Proxy server  
![image](https://user-images.githubusercontent.com/34915108/73276310-d30b9500-422b-11ea-8317-8b507246ace0.png)  

  1. 프록시 서버가 클라이언트들에게 사용되는 것이었다면  
  2.리버스 프록시는 서버가 사용한다.  
  3. 클라이언트의 모든 요청은 리버스 프록시 서버로 들어온다.  
  4. 프록시 서버는 그 요청을 웹 어플리케이션 서버 **클러스터**에 골고루 분배한다.  
  5. **load balancing** 기능이 있다.  
  6. static contents라면 웹 어플리케이션까지 갈 필요 없기에 리버스 프록시에 **Caching**하여 바로 반환가능.  
  
  
  
  
