#include "sniffer.h"
#include "string.h"
sniffer::sniffer(int protocol):rawsocket(protocol),max_packet_len(2048)
{
    packet=(char*)malloc(sizeof(char)*max_packet_len);
    memset(&myfiter,0,sizeof(myfiter));

}

sniffer::~sniffer()
{

}

bool sniffer::sniffer_init()
{
   return  set_dopromisc((char*)"enp0s3");
}

void sniffer::analyze()
{
    
    ether_header_t *etherpacket=(ether_header_t*)packet;
    printf("MAC:");
    for(int i=0;i<6;i++)
    {
        printf("%.2X:",etherpacket->src_hw_addr[i]&ethernetmask);
    }
    printf("-------->");
       for(int i=0;i<6;i++)
    {
        printf("%.2X:",etherpacket->des_hw_addr[i]&ethernetmask);
    }
    printf("\n");
    printf("frametype:");
    for(int i=0;i<2;i++)
    {
         printf("%.2X",etherpacket->frametype[i]&ethernetmask);
    }
       printf("\n");
    ParseIPPacket();
   
}

void sniffer::ParseIPPacket()
{
        ip_packet_t *ip_header=(ip_packet_t*)packet;
        printf("IP:");
        for(int i=0;i<=3;i++)
        {
            printf("%d",ip_header->ipheader.ip_src[i]&ethernetmask);
            if(i!=3)
            printf(".");
        }
        printf("-------->");
        for(int i=0;i<=3;i++)
        {
              printf("%d",ip_header->ipheader.ip_dst[i]&ethernetmask);
            if(i!=3)
            printf(".");
        }
        printf("\n");

        int  prototype=ip_header->ipheader.ip_p;
        printf("Protocol: ");
        switch(prototype)
        {
            case IPPROTO_ICMP:
                printf("ICMP\n");
                break;
            case IPPROTO_IGMP:
                printf("IGMP\n");
                break;
            case IPPROTO_IPIP:
                printf("IP\n");
                break;
            case IPPROTO_TCP :
                printf("TCP\n");
              
                break;
            case IPPROTO_UDP :
                printf("UDP \n");
              
                break;
            case IPPROTO_RAW :
                printf("RAW\n");
                break;
            default:
                printf("Unkown\n");
        }
      
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

