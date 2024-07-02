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
    class ThreadData//Ϊ�˷������˵Ķ��̰߳汾�������˸���
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
        TcpServer(func_t func, uint16_t port = defaultport) : func_(func), port_(port), quit_(true)//quit�Ƿ�������״̬��һ��ʼ��û�����еġ�func_t func�ڴ���������ʱ�򣬽����ݴ������Ľӿڱ�©���������ϲ����ṩ�����������ݴ����γ�һ�ֽ���ϵ�������
        {
        }
        void initServer()
        {
            // 1. ����socket�׽��֣� �ļ�
            listensock_ = socket(AF_INET, SOCK_STREAM, 0);//AF_INET��ʶipv4������Э�飬SOCK_STREAM�ṩ����ɿ�����ʽ���񣬴����ɹ������ļ�������
            if (listensock_ < 0)
            {
                std::cerr << "create socket error" << std::endl;
                exit(SOCKET_ERR);
            }
            // 2. bind�󶨱�������ip�Ͷ˿ں�
            struct sockaddr_in local;
            memset(&local, 0, sizeof(local));//�Ƚ��ṹ���ʼ��Ϊȫ�� 
            local.sin_family = AF_INET;
            local.sin_port = htons(port_);//����������Ϣ������Ҫ��������һ�ε�ip�Ͷ˿ںŵģ���Ϊ�Է�����Ҫ������Щ���ҷ����ݡ�ֻ���ڰ󶨵Ľ׶β���Ҫ�û����д�С��ת��Ҳ�����������к��������е�ת������sendto����recvfrom���Զ����д�С��ת����
            local.sin_addr.s_addr = htonl(INADDR_ANY);//ȫ�㣬�����Ƿ����ת��������Ҫ.
            if (bind(listensock_, (struct sockaddr*)&local, sizeof(local)) < 0)//��һ���������׽��ֽӿڣ��ڶ� ��������sockaddr_in�������������Ǵ�С�������߽��а�
            {
                std::cerr << "bind socket error" << std::endl;
                exit(BIND_ERR);
            }
            // 3. �ⲽ��ʼ��udp��һ���ˣ�����
            if (listen(listensock_, backlog) < 0)//���׽���listensock���ó�Ϊ����״̬
            {
                std::cerr << "listen socket error" << std::endl;
                exit(LISTEN_ERR);
            }
        }
        void start()
        {
            // signal(SIGCHLD, SIG_IGN); //ok, ������Ƽ��ģ�
            // signal(SIGCHLD, handler); // ��handler������׽����̫�Ƽ�

            quit_ = false;//��������ʼ��������״̬
            while (!quit_)//������һ�����ܶ���ʼһֱ�����е�״̬
            {
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                // 4. tcp��Ȼ�������ӣ���һ���������ң������Ȱ����ӻ�ȡ������accept
                int sock = accept(listensock_, (struct sockaddr*)&client, &len);//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);������������������Ͳ�����������֪�����ĸ��ͻ����������ǡ�����ֵ��һ���ļ���������listensock_�Ǽ����׽��֣����������׽��ֵģ��Ǵ������ȡ���������������ͳɹ�accept�᷵��һ���ļ����������������ṩio�����
                if (sock < 0)//����ʧ�ܣ�������Ҫ�ý�����ֹ�����Ǽ���continue������һ������
                {
                    std::cerr << "accept error" << std::endl;
                    continue;
                }
                // ��ȡclient��Ϣ -- debug
                std::string clientip = inet_ntoa(client.sin_addr);
                uint16_t clientport = ntohs(client.sin_port);

                // 5. ��ȡ�����ӳɹ�, ��ʼ����ҵ����
                std::cout << "��ȡ�����ӳɹ�: " << sock << " from " << listensock_ << ", "
                    << clientip << "-" << clientport << std::endl;
                // v1 ��ǰ�������޷��������ͻ��˵����⣬ֻ��ÿ��һ���ͻ������ӷ�������udp֮���Ե����̿����������ͻ��˵�ԭ������Ϊ����ȡ���ݵ�ʱ����Ҫ���Ӳ���Ҫaccept�ȴ����������ͺͳԷ�����ͬһ���ˣ������ǽ���service�ṩͨ�ŷ����ʱ����û�а취ȥ����accept����ġ�
                // service(sock, clientip, clientport);//���з���Ҫ���׽��֡�����ͻ��˹ر��ˣ���ô������server�������ú�����Ȼ�����ٴν���while(!quit_)ѭ������������һ���ͻ������ӷ�������

                // v2: ����̰汾
                // pid_t id = fork();
                // if (id < 0)
                // {
                //     close(sock);//�����������ʧ��˵���������Ѿ�û������ȥ�������Ŀͻ����ˣ����ʱ�����ǽ��ÿͻ���sock�ص���
                //     continue;
                // }
                // else if (id == 0) // child����, �����̵�fd���ᱻchild�̳��𣿻ᡣ ���ӻ���ͬһ���ļ����������𣿲��ᣬ�ӽ��̿����̳и����̵�fd table;�����ӽ���һ�����Կ���listensock��sock���ӽ��̽���service���񼴿ɡ�
                // {
                //     // ����رյ�����Ҫ��fd����Ϊ�ӽ�����ִ��service֮��������˳�����
                //     close(listensock_);
                //     if(fork() > 0) exit(0); // ����һ�д��룬���ӽ��̵����ڴ������Σ��������0�����ӽ����˳�������0�����ӽ��̡�
                //     // child�Ѿ����ˣ����ӽ��������У������游���̵�waitpid��Զ�Ǹ����̶��ӽ��̵ĵȴ�����������ӽ��̽����㸺�������ӽ��̴���֮�������˳���������Ҳ��������գ������ӽ�����Ϊû���˸����̾ͱ��˹¶����̣��ͻᱻϵͳ�������������ӽ����ṩ�����֮���˳��Ļ��չ����ͻ���ϵͳ�����е��ˡ�
                //     service(sock, clientip, clientport);
                //     exit(0);
                // }

                // // ��, һ���رյ�����Ҫ��fd, ���رգ��ᵼ��fdй©
                // close(sock);
                // pid_t ret = waitpid(id, nullptr, 0); //���ֱ�Ӳ��������ȴ�����һЩС������ʼ��v1�汾��һ���ģ���������������һЩС����ʹ��waitpid��������С�����signal(SIGCHLD, SIG_IGN)���ַ�������ֵ���Ƽ��ģ� waitpid(id, nullptr, WNOHANG)���Ƽ�����Ϊ��������������Ӹ����̾ͻ���accept����������û�л�����ȥ����waitpid�ˡ�
                //waitpid�ɹ�֮�󣬸����̾Ϳ����ٴν���ѭ��ȥaccept��ȡ���ӣ������ȡ���ӳɹ�������Ҫ����һ���ӽ��̽���ͨ�ŷ��񣬴Ӷ�ʵ��һ������˿���Ϊ����ͻ����ṩ����
                // if(ret == id) std::cout << "wait child " << id << " success" << std::endl; 

                // v3: ����̵ĵ��óɱ�̫���ˣ��������ǲ��ö��߳� -- ԭ�����߳�
                // 1. Ҫ��Ҫ�رղ�Ҫ��socket�������ܣ���Ϊ���߳����ļ����������ǹ���ģ����߳�ֻ�ܹ��ر��Լ���socket�׽��֣���Ҫ�ر��˼ҵġ�
                // 2. Ҫ��Ҫ�����̣߳���λ��գ��᲻���������߳�һ��Ҫ���գ�������߳���phread_join�ֻ������������������ֱ�������߳��ڲ�detach�Ϳ����ˡ�
                // pthread_t tid;
                // ThreadData *td = new ThreadData(sock, clientip, clientport, this);
                // pthread_create(&tid, nullptr, threadRoutine, td);

                // v4: һ���û����ˣ���Ŵ����̣߳� �̳߳��𣿣�
            }
        }
        static void* threadRoutine(void* args)
        {
            pthread_detach(pthread_self());

            ThreadData* td = static_cast<ThreadData*>(args);
            td->current->service(td->sock, td->clientip, td->clientport);
            delete td;//�������֮��delete td����
            return nullptr;
        }
        void service(int sock, const std::string& clientip, const uint16_t& clientport)
        {
            std::string who = clientip + "-" + std::to_string(clientport);
            char buffer[1024];
            while (true)
            {
                ssize_t s = read(sock, buffer, sizeof(buffer) - 1); //�������е���ʽ����Ϳ���ֱ��ͨ��read���ض����ļ��������ж�ȡ���ݣ�����udp���������ݱ���������ʽ�ģ����Բ����Բ���read��write����io�ӿڡ�read���Զ��ļ�Ҳ���Զ����磬��Ҳ��linux��һ�н��ļ������֡�����֮���Ե���������Ҫ��1����Ϊ�������ǽ����ݵ����ַ���������
                if (s > 0)
                {
                    buffer[s] = 0;
                    std::string res = func(buffer); // ���лص�,�����յ������ݵĴ��������ع�����
                    std::cout << who << ">>> " << res << std::endl;
                    write(sock, res.c_str(), res.size());//�����Ǵ�sock������Ϣ��Ȼ����Ϣ�������֮���ٽ���Ϣwrite��sock����
                }
                else if (s == 0)//����ֵΪ������׽��ֶ������㣬��ζ�ŶԶ˽����ӹر��ˣ��Է��رգ��ҷ�Ҳ�رա����ͻ���ctrl+c�ͻᵼ�·�������ȡʱ����ֵsΪ��
                {
                    // �Է������ӹر��ˣ����Ǿ�ֱ��break�ˡ�
                    close(sock);
                    std::cout << who << " quit, me too" << std::endl;
                    break;
                }
                else//����ֵС����
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
        uint16_t port_;//�˿ںţ����ǲ���Ҫָ��ip��ַ����Ϊ�����Ʒ�������Ե�ʡ�
        int listensock_; // ��Ϊ���õ����׽���ͨ�ţ�����һ��Ҫ��sock��������׽����Ǽ����׽��֣����������õġ������׽��ֵĺ��Ĺ����Ǵӵײ�����ǻ�ȡ����������������ȡ�������׽��ֲ��������������ṩ����ġ�
        bool quit_;//��ʶ��������״̬���Ǵ������л���δ����״̬
        func_t func_;//�������������ݴ���ĺ���
    };
}