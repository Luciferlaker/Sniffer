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

#if __BYTE_ORDER==__LITTLE_ENDIAN
        char ip_hl:4,           //版本
        ip_v:4;            //头部长度
#endif

#if __BYTE_ORDER==__BIG_ENDIAN
         unsigned int ip_v:4;            //头部长度
         unsigned int ip_hl:4;           //版本
#endif
    char  ip_tos;                     //服务类型
    char  ip_len[2];                   //总长度
    char ip_id[2];                     //标识值
    char ip_off[2];                    //片偏移
    char ip_ttl;                        //生存时间
    char  ip_p;                         //协议类型
    char ip_sum[2];                  //校验和
    char ip_src[4];                   //源地址                                 
    char ip_dst[4];                   //目的地址 
    char ip_type[4];              //选项
}ip_header_t;

typedef  struct ip_packet_t     //ip数据包头
{
   ether_header_t  etherheader;
   ip_header_t  ipheader;
}ip_packet_t;


typedef struct udp_header_t
{
    char source[2];                        //源地址
    char dest[2];                         //目的地址
    char len[2];                           //udp长度
    char cheack[2];                   //udp校验和
}udp_header_t;


typedef struct udp_packet_t
{
    ip_packet_t ippack_header;
    udp_header_t udpheader;
}udp_packet_t;

typedef  struct tcp_header_t
{
    char source[2];                //源地址
    char dest[2];                      //目的地址
    char seq[4];                       //序列号
    char ack_seq[4];               //确认序列号

#if __BYTE_ORDER==__LITTLE_ENDIAN
        __u16 resl:4,
        doff:4,
        fin:1,
        syn:1,
        rst:1,
        psh:1,
        ack:1,
        urg:1,
        ece:1,
        cwr:1;
#endif

#if __BYTE_ORDER==__BIG_ENDIAN
     __u16 doff:4,
     resl:4,
     cwr:1,
     ece:1,
     urg:1,
     ack:1,
     psh:1,
     rst:1,
     syn:1,
     fin:1;
#endif
    char windows[2];                   //滑动窗口大小
    char cheack[2];                        //校验和
    char urg_ptr[2];                       //紧急字段指针

}tcp_header_t;


typedef struct tcp_packet_t
{
    ip_packet_t ippack_header;
    tcp_header_t tcp_header;
}tcp_packet_t;


