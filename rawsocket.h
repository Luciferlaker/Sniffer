#include "sys/socket.h"
#include "sys/types.h"
#include "string.h"
#include "linux/if.h"
#include "sys/ioctl.h"
#include "linux/if_ether.h"
#include "stdio.h"
#include "stdlib.h"
class rawsocket
{
    private:
      int socket_fd;
    public:
        rawsocket(int protocol);
        ~rawsocket();

        bool set_dopromisc(char*nif);
        int receive_msg(char*recvbuf,int buflen,struct sockaddr_in *from,int*addrlen);

};