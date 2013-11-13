#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <setjmp.h>
#include <errno.h>
#include <sys/time.h>
#include <resolv.h>
#include <fcntl.h>

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum=0;
    unsigned short result;
    for (sum = 0; len > 1; len -= 2)
    {
        sum += *buf++;
    }
    if (len == 1)
    {
        sum += *(unsigned char*)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int ping(char *adress)
{
    struct packet
    {
        struct icmphdr hdr;
        char msg[64 - sizeof(struct icmphdr)];
    };
    int pid = -1, cnt = 1, len;
    struct protoent *proto=NULL;
    const int val=255;
    int i, sd, loop;
    struct packet pckt;
    struct sockaddr_in r_addr;
    struct hostent *hname;
    struct sockaddr_in addr_ping,*addr;

    pid = getpid();
    proto = getprotobyname("ICMP");
    hname = gethostbyname(adress);
    bzero(&addr_ping, sizeof(addr_ping));
    addr_ping.sin_family = hname->h_addrtype;
    addr_ping.sin_port = 0;
    addr_ping.sin_addr.s_addr = *(long*)hname->h_addr;

    addr = &addr_ping;

    sd = socket(PF_INET, SOCK_RAW, proto->p_proto);
    if (sd < 0)
    {
        return -1;
    }
    if (setsockopt(sd, SOL_IP, IP_TTL, &val, sizeof(val)) != 0)
    {
        return -1;
    }
    if (fcntl(sd, F_SETFL, O_NONBLOCK) != 0)
    {
        return -1;
    }
    for (loop = 0; loop < 10; ++loop)
    {
        len = sizeof(r_addr);
        if (recvfrom(sd, &pckt, sizeof(pckt), 0, (struct sockaddr*)&r_addr, &len) > 0)
        {
            return 0;
        }
        bzero(&pckt, sizeof(pckt));
        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = pid;
        for (i = 0; i < sizeof(pckt.msg)-1; ++i)
        {
            pckt.msg[i] = i + '0';
        }
        pckt.msg[i] = 0;
        pckt.hdr.un.echo.sequence = cnt++;
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));
        if (sendto(sd, &pckt, sizeof(pckt), 0, (struct sockaddr*)addr, sizeof(*addr)) <= 0)
        {
            return -1;
        }
        usleep(300000);
    }
    return -1;
}

int main(int argc, char *argv[])
{
    if (ping("www.baidu.com") == -1)
    {
        printf("Ping is not OK. \n");
    }
    else
    {
        printf("Ping is OK. \n");
    }
    return 0;
}
