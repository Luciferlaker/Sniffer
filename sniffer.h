#include "rawsocket.h"
#include "netinet/in.h"
#include "inetheader.h"

typedef struct filter
{
    unsigned long  sip;
    unsigned long dip;
   unsigned  int protocol;
}filter;


class sniffer:public rawsocket
{
private:
    char*packet;
    filter myfiter;
    const int  max_packet_len;
    int ethernetmask=0xFF;
public:
    sniffer(int protocol);
    ~sniffer();
    bool sniffer_init();
    bool set_filter(filter myfiter);
    void sniffer_start();
    void analyze();
    void ParseIPPacket();
    void ParseARPPacket();
};


