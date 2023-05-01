#include "sniffer.h"
#include "string.h"
sniffer::sniffer(int protocol):rawsocket(protocol),max_packet_len(2048)
{
    packet=new char[max_packet_len];
    memset(&myfiter,0,sizeof(myfiter));

}

bool sniffer::sniffer_init()
{
    set_dopromisc("eth0");
}


void  sniffer::sniffer_start()
{
    struct sockaddr_in from;
    int sockaddr_len=sizeof(struct sockaddr_in);
    int recvlen=0;
    while(1)
    {
        recvlen=receive_msg(packet,max_packet_len,&from,&sockaddr_len);
        if(recvlen>0)
        {
            analyze();
        }
        else
        {
            continue;
        }
    }

}
