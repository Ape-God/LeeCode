#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <sys/types.h> /* See NOTES */
#include<winsock.h>
#include <winsock2.h>
#include <windows.h>
#include <io.h>
#include <process.h>
#include "error.h"

namespace ns_server
{
    static const uint16_t defaultport = 8081;
    static const int backlog = 32; //? TODO

    using func_t = std::function<std::string(const std::string&)>;

    class TcpServer;
    class ThreadData//为了服务服务端的多线程版本而创建了该类
    {
    public:
        ThreadData(int fd, const std::string& ip, const uint16_t& port, TcpServer* ts)
            : sock(fd), clientip(ip), clientport(port), current(ts)
        {}
    public:
        int sock;
        std::string clientip;
        uint16_t clientport;
        TcpServer* current;
    };

    class TcpServer
    {
    public:
        TcpServer(func_t func, uint16_t port = defaultport) : func_(func), port_(port), quit_(true)//quit是服务器的状态，一开始是没有运行的。func_t func在创建类对象的时候，将数据处理函数的接口暴漏出来，让上层来提供函数进行数据处理，形成一种解耦合的做法。
        {
        }
        void initServer()
        {
            // 1. 创建socket套接字， 文件
            listensock_ = socket(AF_INET, SOCK_STREAM, 0);//AF_INET标识ipv4的网络协议，SOCK_STREAM提供有序可靠的流式服务，创建成功返回文件描述符
            if (listensock_ < 0)
            {
                std::cerr << "create socket error" << std::endl;
                exit(SOCKET_ERR);
            }
            // 2. bind绑定本地网络ip和端口号
            struct sockaddr_in local;
            memset(&local, 0, sizeof(local));//先将结构体初始化为全零 
            local.sin_family = AF_INET;
            local.sin_port = htons(port_);//发送网络信息是是需要发送我这一段的ip和端口号的，因为对方可能要根据这些向我发数据。只有在绑定的阶段才需要用户进行大小端转换也就是主机序列和网络序列的转换，在sendto或者recvfrom是自动进行大小端转换。
            local.sin_addr.s_addr = htonl(INADDR_ANY);//全零，所以是否进行转换都不重要.
            if (bind(listensock_, (struct sockaddr*)&local, sizeof(local)) < 0)//第一个参数是套接字接口，第二 个参数是sockaddr_in，第三个参数是大小，将二者进行绑定
            {
                std::cerr << "bind socket error" << std::endl;
                exit(BIND_ERR);
            }
            // 3. 这步开始和udp不一样了，监听
            if (listen(listensock_, backlog) < 0)//将套接字listensock设置成为监听状态
            {
                std::cerr << "listen socket error" << std::endl;
                exit(LISTEN_ERR);
            }
        }
        void start()
        {
            // signal(SIGCHLD, SIG_IGN); //ok, 我最后推荐的！
            // signal(SIGCHLD, handler); // 以handler方法捕捉，不太推荐

            quit_ = false;//服务器开始处于运行状态
            while (!quit_)//服务器一定是周而复始一直在运行的状态
            {
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                // 4. tcp既然面向连接，就一定有人连我，现在先把连接获取上来。accept
                int sock = accept(listensock_, (struct sockaddr*)&client, &len);//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);后面连个参数是输出型参数，让我们知道是哪个客户但连的我们。返回值是一个文件描述符，listensock_是监听套接字，属于揽客套接字的，是从下面获取新连接上来，揽客成功accept会返回一个文件描述符就是真正提供io服务的
                if (sock < 0)//揽客失败，并不需要让进程终止，而是继续continue揽获下一个链接
                {
                    std::cerr << "accept error" << std::endl;
                    continue;
                }
                // 提取client信息 -- debug
                std::string clientip = inet_ntoa(client.sin_addr);
                uint16_t clientport = ntohs(client.sin_port);

                // 5. 获取新连接成功, 开始进行业务处理
                std::cout << "获取新连接成功: " << sock << " from " << listensock_ << ", "
                    << clientip << "-" << clientport << std::endl;
                // v1 当前服务器无法处理多个客户端的问题，只能每次一个客户端连接服务器。udp之所以单进程可以受理多个客户端的原因是因为它收取数据的时候不需要链接不需要accept等待，现在揽客和吃饭的是同一个人，当我们进行service提供通信服务的时候，是没有办法去进行accept服务的。
                // service(sock, clientip, clientport);//进行服务，要传套接字。如果客户端关闭了，那么服务器server会跳出该函数，然后又再次进入while(!quit_)循环。等在另外一个客户端连接服务器。

                // v2: 多进程版本
                // pid_t id = fork();
                // if (id < 0)
                // {
                //     close(sock);//如果进程生成失败说明服务器已经没有能力去处理更多的客户端了，这个时候我们将该客户端sock关掉。
                //     continue;
                // }
                // else if (id == 0) // child进程, 父进程的fd，会被child继承吗？会。 父子会用同一张文件描述符表吗？不会，子进程拷贝继承父进程的fd table;所以子进程一定可以看到listensock和sock，子进程进行service服务即可。
                // {
                //     // 建议关闭掉不需要的fd，因为子进程退执行service之后会立马退出进程
                //     close(listensock_);
                //     if(fork() > 0) exit(0); // 就这一行代码，在子进程当中在创建依次，如果大于0就是子进程退出，等于0是孙子进程。
                //     // child已经退了，孙子进程在运行，而下面父进程的waitpid永远是父进程对子进程的等待，不会对孙子进程进行你负责，所以子进程创建之后立马退出，父进程也会立马回收，而孙子进程因为没有了父进程就变了孤儿进程，就会被系统进程领养，孙子进程提供完服务之后退出的回收工作就会由系统主动承担了。
                //     service(sock, clientip, clientport);
                //     exit(0);
                // }

                // // 父, 一定关闭掉不需要的fd, 不关闭，会导致fd泄漏
                // close(sock);
                // pid_t ret = waitpid(id, nullptr, 0); //如果直接采用阻塞等待不做一些小处理起始和v1版本是一样的，我们再上面做了一些小处理使得waitpid在这里可行。其中signal(SIGCHLD, SIG_IGN)这种方法是最值得推荐的！ waitpid(id, nullptr, WNOHANG)不推荐，因为如果不产生新连接父进程就会再accept处阻塞，就没有机会再去调用waitpid了。
                //waitpid成功之后，父进程就可以再次进入循环去accept获取连接，如果获取连接成功就有需要创建一个子进程进行通信服务，从而实现一个服务端可以为多个客户端提供服务。
                // if(ret == id) std::cout << "wait child " << id << " success" << std::endl; 

                // v3: 多进程的调用成本太大了，所以我们采用多线程 -- 原生多线程
                // 1. 要不要关闭不要的socket？？不能，因为多线程中文件描述符表是共享的，新线程只能够关闭自己的socket套接字，不要关闭人家的。
                // 2. 要不要回收线程？如何回收？会不会阻塞？线程一定要回收，如果主线程主phread_join又会造成阻塞，所以我们直接再新线程内部detach就可以了。
                // pthread_t tid;
                // ThreadData *td = new ThreadData(sock, clientip, clientport, this);
                // pthread_create(&tid, nullptr, threadRoutine, td);

                // v4: 一旦用户来了，你才创建线程， 线程池吗？？
            }
        }
        static void* threadRoutine(void* args)
        {
            pthread_detach(pthread_self());

            ThreadData* td = static_cast<ThreadData*>(args);
            td->current->service(td->sock, td->clientip, td->clientport);
            delete td;//服务完成之后delete td对象
            return nullptr;
        }
        void service(int sock, const std::string& clientip, const uint16_t& clientport)
        {
            std::string who = clientip + "-" + std::to_string(clientport);
            char buffer[1024];
            while (true)
            {
                ssize_t s = read(sock, buffer, sizeof(buffer) - 1); //凡是所有的流式服务就可以直接通过read从特定的文件描述符中读取内容，但是udp是面向数据报，不是流式的，所以不可以采用read、write这类io接口。read可以读文件也可以读网络，这也是linux下一切皆文件的体现。这里之所以第三个参数要减1是因为这里我们将数据当作字符串来看。
                if (s > 0)
                {
                    buffer[s] = 0;
                    std::string res = func(buffer); // 进行回调,将接收到的数据的处理结果返回过来。
                    std::cout << who << ">>> " << res << std::endl;
                    write(sock, res.c_str(), res.size());//上面是从sock读到信息，然后将信息处理完成之后再将信息write到sock里面
                }
                else if (s == 0)//返回值为零代表套接字读到了零，意味着对端将链接关闭了，对方关闭，我方也关闭。当客户端ctrl+c就会导致服务器读取时返回值s为零
                {
                    // 对方将连接关闭了，我们就直接break了。
                    close(sock);
                    std::cout << who << " quit, me too" << std::endl;
                    break;
                }
                else//返回值小于零
                {
                    close(sock);
                    std::cerr << "read error: " << strerror(errno) << std::endl;
                    break;
                }
            }
        }
        ~TcpServer()
        {
        }

    private:
        uint16_t port_;//端口号，但是不需要指明ip地址，因为这是云服务器的缘故。
        int listensock_; // 因为采用的是套接字通信，所以一定要有sock。这里的套接字是监听套接字，用来揽客用的。监听套接字的核心工作是从底层帮我们获取新链接上来，而获取上来的套接字才是真正给我们提供服务的。
        bool quit_;//标识服务器的状态，是处于运行还是未运行状态
        func_t func_;//服务器关于数据处理的函数
    };
}