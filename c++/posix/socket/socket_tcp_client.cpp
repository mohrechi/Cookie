#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(19627);

    int client_sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == client_sockfd)
    {
        return -1;
    }

    if (-1 == connect(client_sockfd, (sockaddr*)&server_addr, sizeof(sockaddr_in)))
    {
        perror("Connect");
        return -1;
    }

    char buf[BUFSIZ];
    int len = recv(client_sockfd, buf, BUFSIZ, 0);
    buf[len] = 0;
    printf("Receive: %s\n", buf);

    shutdown(client_sockfd, SHUT_RDWR);
    return 0;
}
