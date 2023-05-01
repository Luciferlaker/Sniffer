#include "rawsocket.h"
#include "netinet/in.h"
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
public:
    sniffer(int protocol);
    ~sniffer();
    bool sniffer_init();
    bool set_filter(filter myfiter);
    void sniffer_start();
    void analyze();
};


