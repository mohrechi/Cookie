#include <cstdio>
#include <cstring>

int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        if(n<=2) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
