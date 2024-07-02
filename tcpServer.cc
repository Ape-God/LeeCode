#include "tcpServer.h"
#include <memory>

using namespace std;
using namespace ns_server;

static void usage(string proc)
{
    std::cout << "Usage:\n\t" << proc << " port\n"
        << std::endl;
}

std::string echo(const std::string& message)
{
    return message;
}

// ./tcp_server port
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        usage(argv[0]);
        exit(USAGE_ERR);
    }
    uint16_t port = atoi(argv[1]);
    unique_ptr<TcpServer> tsvr(new TcpServer(echo, port));

    tsvr->initServer();//服务器先初始化
    tsvr->start();//然后让服务器start起来
    return 0;
}