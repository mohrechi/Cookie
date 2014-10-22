#include <cstdio>
#include <cstring>

bool space;
int div[10000];

void printNumber(int x)
{
    if(space)
    {
        printf(" ");
    }
    else
    {
        space = true;
    }
    printf("%d", x);
}

int main()
{
    int n, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        space = false;
        if(n == 2)
        {
            printNumber(1);
            printNumber(2);
            printf("\n");
            continue;
        }
        int s;
        for(s=1;;++s)
        {
            if(s * s >= n)
            {
                break;
            }
        }
        for(int i=0;i<s;++i)
        {
            div[i] = 1;
        }
        div[s-1] = s;
        int rest = n - s - (s - 1);
        for(int i=s-2;i>=0 && rest;--i)
        {
            if(rest >= s - 1)
            {
                div[i] = s;
                rest -= s - 1;
            }
            else
            {
                div[i] += rest;
                rest = 0;
            }
        }
        int start = 1;
        for(int i=0;i<s;++i)
        {
            for(int j=start+div[i]-1;j>=start;--j)
            {
                printNumber(j);
            }
            start += div[i];
        }
        printf("\n");
    }
    return 0;
}
