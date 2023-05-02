#include "lab4.h"

int Socket(int domain, int type, int protocol) // создание сокета
{
    int res;
    
    res = socket(domain, type, protocol);
    if (res == -1) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) 
{
    int res;
    
    res = connect(sockfd, addr, addrlen);
    if (res == -1) 
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
}

void Inet_pton(int af, const char *src, void *dst) 
{
    int res = inet_pton(af, src, dst);
    if (res == 0) 
    {
        printf("inet_pton failed: src does not contain a character"
            " string representing a valid network address in the specified"
            " address family\n");
        exit(EXIT_FAILURE);
    }
    if (res == -1) 
    {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    int                 nbytes;
    int                 fd;
    struct sockaddr_in  adr = {0};
    char                buf[256];

    fd = Socket(AF_INET, SOCK_STREAM, 0); // создает fd сокета
    adr.sin_family = AF_INET;
    adr.sin_port = htons(8080);
    Inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
    Connect(fd, (struct sockaddr *) &adr, sizeof adr);
    write(fd, "watsup\n", 7);
    nbytes = read(fd, buf, 256);
    if (nbytes == -1) 
    {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    if (nbytes == 0)
        printf("EOF!\n");
    write(1, buf, nbytes);
    sleep(5);
    close(fd);
}
