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

    int server_sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == server_sockfd)
    {
        return -1;
    }

    if (-1 == bind(server_sockfd, (sockaddr*)&server_addr, sizeof(sockaddr_in)))
    {
        return -1;
    }

    listen(server_sockfd, 5);

    char buf[BUFSIZ];
    socklen_t sin_size = sizeof(sockaddr_in);
    int client_sockfd;
    sockaddr_in client_addr;
    client_sockfd = accept(server_sockfd, (sockaddr*)&client_addr, &sin_size);
    if (-1 == client_sockfd)
    {
        return -1;
    }

    printf("Client: %s\n", inet_ntoa(client_addr.sin_addr));
    int len = send(client_sockfd, "SOCK_STREAM", 11, 0);

    while ((len = recv(client_sockfd, buf, BUFSIZ, 0)) != 0)
    {
        buf[len] = 0;
        if (-1 == send(client_sockfd, buf, len, 0))
        {
            return -1;
        }
    }
    shutdown(client_sockfd, SHUT_RDWR);
    shutdown(server_sockfd, SHUT_RDWR);
    return 0;
}
