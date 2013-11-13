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

    int client_sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if (-1 == client_sockfd)
    {
        return -1;
    }

    char buf[BUFSIZ];
    int len = sendto(client_sockfd, "SOCK_DGRAM", 10, 0, (sockaddr*)&server_addr, sizeof(sockaddr_in));
    if (len < 0)
    {
        return -1;
    }
    shutdown(client_sockfd, SHUT_RDWR);
    return 0;
}
