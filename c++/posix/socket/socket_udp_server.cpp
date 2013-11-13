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
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(19627);

    int server_sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if (-1 == server_sockfd)
    {
        return -1;
    }

    if (-1 == bind(server_sockfd, (sockaddr*)&server_addr, sizeof(sockaddr_in)))
    {
        return -1;
    }

    char buf[BUFSIZ];
    socklen_t sin_size = sizeof(sockaddr_in);
    sockaddr_in client_addr;

    int len = recvfrom(server_sockfd, buf, BUFSIZ, 0, (sockaddr*)&client_addr, &sin_size);
    if (-1 == len)
    {
        return -1;
    }

    printf("Client: %s\n", inet_ntoa(client_addr.sin_addr));
    buf[len] = 0;
    printf("Recevied: %s\n", buf);

    shutdown(server_sockfd, SHUT_RDWR);
    return 0;
}
