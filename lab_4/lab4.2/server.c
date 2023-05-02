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

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) // привязка сокета к адресу
{
    int res;
    
    res = bind(sockfd, addr, addrlen);
    if (res == -1) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void Listen(int sockfd, int backlog) // прослушивание входящих соединений
{
    int res;
    
    res = listen(sockfd, backlog);
    if (res == -1)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) // принятие клиента на сокете
{
    int res;
    
    res = accept(sockfd, addr, addrlen);
    if (res == -1) 
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

int main()
{
    struct sockaddr_in  adr = {0}; // структура для создания протокола IPv4
    socklen_t           adrlen;
    int                 server;
    int                 client;
    int                 nbytes;
    char                buf[256];

    server = Socket(AF_INET, SOCK_STREAM, 0); // создает fd сокета
    adr.sin_family = AF_INET; // семейство адресов (IPv4)
    adr.sin_port = htons(8080); // порт для прослушивания + значение порта на хосте и в сети может иметь разный порядок байт от хоста к сети
    adrlen = sizeof(adr);
    Bind(server, (struct sockaddr *) &adr, adrlen);
    Listen(server, 1);
    client = Accept(server, (struct sockaddr *) &adr, &adrlen); // создает fd для общения с клиентом
    nbytes = read(client, buf, 256);
    if (nbytes == -1)
    {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    if (nbytes == 0)
        printf("EOF!\n");
    write(1, buf, nbytes);
    write(client, buf, nbytes);
    sleep(5);
    close(server);
    close(client);
}
