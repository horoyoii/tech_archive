#include<sys/epoll.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<functional>
#include<unistd.h>

using namespace std;

/**
    epoll은 리눅스에서 select의 단점을 보완하기 위하여 만든
    I/O notification(통지) 모델이다.

    - select의 단점은 특정 file descripter에서 이벤트 발생 시 
    이를 찾기 위해 모든 fd를 순회해야 한다는 것.
    - FD_ISSET loop를 돈다.

    epoll is a synchronous event demultiplexer 

    Reactors need to manage what is known as a synchronous event demultiplexer like epoll or select. Epoll, which is what we’ll use in this example, is described in the Linux man pages as an “I/O event notification facility”. It is synchronous in that when we call wait it blocks: our application stops processing when wait is called until the operating system lets us know an event has occurred. In this example we tell epoll to let us know when input has been entered by registering interest in the stdin file descriptor. Once we are notified by epoll that a subscribed-to event has arrived we fire off the corresponding handler. In essence this is what a Reactor does: it utilizes a system call like epoll or select to listen to events and fires off a handler when it receives them.
*/
class Epoll{ // simple epoll wrapper
public:
    Epoll(){
        
        /**
            epoll_craete1 :  epoll_fd를 만든다. 
            enum Events
            {
               EPOLLIN,   //수신할 데이터가 있다.
               EPOLLOUT,  //송신 가능하다.
               EPOLLPRI,  //중요한 데이터(OOB)가 발생.
               EPOLLRDHUD,//연결 종료 or Half-close 발생
               EPOLLERR,  //에러 발생
               EPOLLET,   //엣지 트리거 방식으로 설정
               EPOLLONESHOT, //한번만 이벤트 받음
            }
             
        */
        fd = epoll_create1(0);
        
        event.data.fd = STDIN_FILENO; // POSIX 표준의 stdin 
        event.events = EPOLLIN | EPOLLPRI;
    
        result_events = new struct epoll_event[10];
    }

    int control(){
        
        /**
            epoll_ctl : 관찰 대상이 되는 파일 디스크립터를 등록, 삭제하는데 사용.
            params 
            1) int epoll_fd
            2) int operate_enum 
               - EPOLL_CTL_ADD : 새로운 fd 등록
               - EPOLL_CTL_DEL : fd 제거
               - EPOLL_CTL_MOD : 등록된 fd의 이벤트 발생상황 변경
            3) int epoll_fd : 등록할 fd
            4) struct epoll_event* event : 등록할 fd의 관찰 이벤트 유형

            return 
            실패 : -1, 성공 : 0

        */
        int res = epoll_ctl(fd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
        return res;
    }

    int wait(){

        /**
            epoll_wait : 
         params 
         1) int epoll_fd 
         2) struct epoll_event* event
         3) int maxevents
         4) timeout : timeout 시 자동 반환, -1 : 무제한

         return 
         실패 : -1, 성공 : 이벤트 발생한 fd 갯수 반환

        */
        int res = epoll_wait(fd, result_events, 10, -1);
        return res;
    }

private:
    int fd;
    struct epoll_event event;
    struct epoll_event* result_events;
};


class Reactor{
public:
    Reactor(){
        epoll.control();   
    }
    
    //                            function<반환형(매개변수)> 함수 포인터 
    void addHandler(string event, function<void()> callback){
        handlers.emplace(event, callback);
    }

    void run(){
        while(true){
            int numOfEvents = wait();

            for(int i =0; i < numOfEvents; i++){
                string input;
                getline(cin, input);

                try{
                    handlers.at(input)();
                }catch(const out_of_range& e){
                    cout<<"no handler fo "<<input<<endl;
                }
            }

        
            sleep(5);
        }
    }

private:
    Epoll epoll;
    unordered_map<string, std::function<void()>> handlers{};
    
    int wait(){
        int numOfEvents = epoll.wait();
        return numOfEvents;
    }

};


int main(void){
    Reactor reactor;

    reactor.addHandler("one", [](){
        cout<<"one handler called!"<<endl;   
    });
    
    reactor.addHandler("two", [](){
        cout<<"two handler called"<<endl;   
    });

    reactor.run();

    return 0;
}
