#include <cstdio>
#include <cstring>

int main()
{
    int n, a;
    while(scanf("%d", &n) != EOF)
    {
        int s = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            if(a == 1)
            {
                ++ s;
            }
        }
        if(n == 1)
        {
            printf("Alice\n");
        }
        else if(n == 2)
        {
            if(s == 1)
            {
                printf("Alice\n");
            }
            else
            {
                printf("Bob\n");
            }
        }
        else
        {
            if(n % 2 == 1)
            {
                printf("Alice\n");
            }
            else
            {
                printf("Bob\n");
            }
        }
    }
}
