#include "rawsocket.h"


rawsocket::rawsocket(int proctocol)
{
     printf("%d\n",proctocol);
    socket_fd=socket(PF_PACKET,SOCK_RAW,proctocol);
    if(socket_fd<0)
    {
        printf("wrong\n");
    }
}


rawsocket::~rawsocket()
{

}

bool rawsocket::set_dopromisc(char*nif)
{
    struct ifreq ifr;              
    strncpy(ifr.ifr_name, nif,strlen(nif)+1);  
    if((ioctl(socket_fd, SIOCGIFFLAGS, &ifr) == -1))  
    {         
        perror("ioctlread: ");  
    return false;
    }   
    ifr.ifr_flags |= IFF_PROMISC; 
    if(ioctl(socket_fd, SIOCSIFFLAGS, &ifr) == -1 )
    { 
        perror("ioctlset: ");
    return false;
    }
    return true;
} 

int rawsocket::receive_msg(char*recvbuf,int buflen,struct sockaddr_in *from,int*addrlen)
{
    int recvlen;
     recvlen=recvfrom(socket_fd,recvbuf,buflen,0,(struct sockaddr *)from,(socklen_t *)addrlen);
    recvbuf[recvlen]='\0';
    return recvlen;
}