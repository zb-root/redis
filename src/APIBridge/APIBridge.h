#ifdef APIBRIDGE_EXPORTS
    #define APIBRIDGE_API __declspec(dllexport)
#else
    #define APIBRIDGE_API __declspec(dllimport)
#endif


// in order to avoid linker name collisions, all socket/fd calls need to be routed through this DLL 
class APIBRIDGE_API APIBridge {
public:
	static int WSAStartup(WORD wVersionRequired, LPWSADATA lpWSAData);
    static int WSACleanup(void);
    static int WSAGetLastError(void);
    static void WSASetLastError(int iError);
    static BOOL WSAGetOverlappedResult(SOCKET s, LPWSAOVERLAPPED lpOverlapped, LPDWORD lpcbTransfer,BOOL fWait,LPDWORD lpdwFlags);
    static int WSAIoctl(SOCKET s,DWORD dwIoControlCode,LPVOID lpvInBuffer,DWORD cbInBuffer,LPVOID lpvOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbBytesReturned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
    static int WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesSent,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
    static int WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesRecvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
    static int WSAPoll(WSAPOLLFD fdarray[],ULONG nfds,INT timeout);

	static BOOL AcceptEx(SOCKET sListen,SOCKET sAccept,PVOID lpOutputBuffer,DWORD dwReceiveDataLength,DWORD dwLocalAddressLength,DWORD dwRemoteAddressLength,LPDWORD lpdwBytesReceived,LPOVERLAPPED lpOverlapped);
	static BOOL ConnectEx(SOCKET s,const struct sockaddr *name,int namelen,PVOID lpSendBuffer,DWORD dwSendDataLength,LPDWORD lpdwBytesSent,LPOVERLAPPED lpOverlapped);
	static void GetAcceptExSockaddrs(SOCKET s,PVOID lpOutputBuffer,DWORD dwReceiveDataLength,DWORD dwLocalAddressLength,DWORD dwRemoteAddressLength,LPSOCKADDR *LocalSockaddr,LPINT LocalSockaddrLength,LPSOCKADDR *RemoteSockaddr,LPINT RemoteSockaddrLength);

    static SOCKET socket(int af,int type,int protocol);
    static int closesocket(SOCKET s);
    static int close(int fd);
    static int open(const char *filename, int oflag, int pmode); 
    static SOCKET accept(SOCKET s,struct sockaddr *addr,int *addrlen);
    static int setsockopt(SOCKET s,int level,int optname,const char *optval,int optlen);
    static int getsockopt(SOCKET s,int level,int optname,char *optval,int *optlen);
    static int connect(SOCKET s,const struct sockaddr *name,int namelen);
    static int recv(SOCKET s,char *buf,int len,int flags);
    static int read(int fd,void *buffer,unsigned int count);
    static int send(SOCKET s,const char *buf,int len,int flags);
    static int write(int fd,const void *buffer,unsigned int count);
    static intptr_t _get_osfhandle(int fd);
    static int listen(SOCKET s,int backlog);
    static int bind(SOCKET s,const struct sockaddr *name,int namelen);
    static int shutdown(SOCKET s,int how);
    static int ioctlsocket(SOCKET s,long cmd,u_long *argp);
    static unsigned long inet_addr(const char *cp);
    static struct hostent* gethostbyname(const char *name);
    static char* inet_ntoa(struct in_addr in);
    static u_short htons(u_short hostshort);
    static u_long htonl(u_long hostlong);
    static int getpeername(SOCKET s,struct sockaddr *name,int *namelen);
    static int getsockname(SOCKET s,struct sockaddr *name,int *namelen);
    static u_short ntohs(u_short netshort);
    static int _setmode(int fd,int mode);
    static int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
    static void freeaddrinfo(struct addrinfo *ai);
    static int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res);
    static const char *inet_ntop(int af, const void *src, char *dst, size_t size);

    static u_int ntohl(u_int netlong);
    static int isatty(int fd);
    static int access(const char *pathname, int mode);
    static u_int64 lseek64(int fd, u_int64 offset, int whence); 
    static intptr_t get_osfhandle(int fd);
};

