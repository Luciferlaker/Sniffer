#include <sys/types.h>
#include <asm/byteorder.h>
typedef  struct ether_header_t      //以太网帧格式
{
    char  des_hw_addr[6];                  //目的地址
    char src_hw_addr[6];                    //源地址
    char frametype[2];                          //帧格式
}ether_header_t;

typedef struct  arp_header_t  //arp分组字段
{
 char hw_type[2];                       
 char prot_type[2];
 char hw_addr_len;
 char prot_addr_len;
 char   flag[2];
 char send_hw_addr[6];
 char send_ip_addr[2];
 char des_hw_addr[6];
 char des_port_addr[2];
}arp_header_t;

typedef struct arp_packet_t   //arp数据包
{
    ether_header_t etherheader;
    arp_header_t  arpheader;
}arp_packet_t;


typedef struct ip_header_t
{

    char ip_v[4];                           //版本
    char ip_hl[4];                         //头部长度
    char  ip_tos[8];                     //服务类型
    char  ip_len[16];                   //总长度
    char ip_id[19];                     //标识值
    char ip_off[13];                    //片偏移
    char ip_ttl[8];                        //生存时间
    char  ip_p[8];                         //协议类型
    char ip_sum[16];                  //校验和
    char ip_src[32];                   //源地址                                 
    char ip_dst[32];                   //目的地址 

}ip_header_t;

typedef  struct ip_packet_t     //ip数据包头
{
   ether_header_t  etherheader;
   ip_header_t  ipheader;
}ip_packet_t;


typedef struct udp_header_t
{
    char source[16];                        //源地址
    char dest[16];                         //目的地址
    char len[16];                           //udp长度
    char cheack[16];                   //udp校验和
}udp_header_t;


typedef struct udp_packet_t
{
    ip_packet_t ippack_header;
    udp_header_t udpheader;
}udp_packet_t;

typedef  struct tcp_header_t
{
    char source[16];                //源地址
    char dest[16];                      //目的地址
    char seq[32];                       //序列号
    char ack_seq[32];               //确认序列号
    char doff[4];                           
    char res[4];
    char cwr;
    char ece;
    char urg;
    char ack;
    char psh;
    char rst;
    char syn;
    char fin;
    char windows[16];                   //滑动窗口大小
    char cheack[16];                        //校验和
    char urg_ptr[16];                       //紧急字段指针

}tcp_header_t;


typedef struct tcp_packet_t
{
    ip_packet_t ippack_header;
    tcp_header_t tcp_header;
}tcp_packet_t;


