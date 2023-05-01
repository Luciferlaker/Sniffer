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