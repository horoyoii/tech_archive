

# 


Volume ( -v )   

docker-compose   



## Every container has OS?  
Yes, they do. Every container is based on an OS image, e.g. Alpine, CentOS or Ubuntu.




## Volume  

  * docker의 이미지는 읽기 전용이라 쓰기 불가 / 컨테이너 계층에서 적립되는 데이터를 영속시키는 방법     
  * -v : 호스트 파일 시스템을 컨테이너에 마운트 하는 것  
  * 세 가지 방법  
   - 호스트 볼륨 공유  
   - 볼륨 컨테이너 사용  
   - docker가 제공하는 볼륨 사용  
  
#### 1. 호스트 볼륨 공유  

 1. 호스트 볼륨을 공유하지 않고 mysql 실행  
```
docker run --name mysql-test-204 -p 3308:3306 -e MYSQL_ROOT_PASSWORD='12345' -d mysql 
```

 2.1. 접속 시도 (1) 호스트의 mysql client 사용   
```
mysql -u root -p -h 127.0.0.1 -P 3308
```

 2.2. 접속 시도 (2) container에 직접 접속 후 mysql 실행   
```
docker exec -it mysql-test-204 bash
mysql -u root -p
```

3. DB 생성 후 table생성 후 데이터를 넣고 이 컨테이너 자체를 삭제한다.  
```
docker stop mysql-test-204
docker rm mysql-test-204
```

4. 그리고 다시 고정된 이미지로 컨테이너 생성하면 이미 영속되어야 할 데이터는 사라짐  
```
docker run --name mysql-test-204 -p 3308:3306 -e MYSQL_ROOT_PASSWORD='12345' -d mysql 
```

==================================================================  

1. -v 호스트 디렉토리:컨테이너 디렉토리  
  * 호스트 디렉토리가 없다면 자동 생성  
```
 docker run --name mysql-test-204 \
 -p 3308:3306 \
 -e MYSQL_ROOT_PASSWORD='12345' \
 -d \
 -v /mysql/data:/var/lib/mysql mysql
```

2. 호스트 머신의 /mysql/data 밑에 여러 데이터 생성  

3. 현재의 mysql 컨테이너에 데이터 삽입 후 컨테이너 자체를 삭제  

4. 그리고 -v 를 통해 기존에 있던 디렉토리 지정 시  
  * 기존의 디렉토리가 컨테이너의 디렉토리를 덮어써서 영속적인 데이터 확보가능  
```
 docker run --name mysql-test-204 \
 -p 3308:3306 \
 -e MYSQL_ROOT_PASSWORD='12345' \
 -d \
 -v /mysql/data:/var/lib/mysql mysql
```

5. 데이터가 살아있음.  




## docker-compsoe 사용  
[usages](https://www.44bits.io/ko/post/almost-perfect-development-environment-with-docker-and-docker-compose#docker-compose.yml-%ED%8C%8C%EC%9D%BC)  
 
  * define and run multiple containers in a single file. 
  
 
```
// docker-compose.yml
version: '3'

services:
  mysql-test-204:
    image: mysql:latest
    volumes:
      - ./my_data:/var/lib/mysql
    environment:
      MYSQL_ROOT_PASSWORD: '12345'
    ports:
      - "3308:3306"
```

```
docker-compose up -d
```

