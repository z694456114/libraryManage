#include "func_socket.h"
#include "func_log.h"

ST_SERVER_TCPTLS_SOCKET g_server_tcptls;

int init_socket_struct()
{
    
}

int create_server_tcptls_socket()
{
    struct sockaddr_in seraddr;
    int serfd;

    serfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serfd < 0)
    {
        logPrint(LOG_ERROR, "create server tcptls socket fail\n");
        return -1;
    }
}