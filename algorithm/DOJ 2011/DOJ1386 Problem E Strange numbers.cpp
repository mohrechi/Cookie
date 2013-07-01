#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d 2 1",n-4);
        n-=7;
        while(n--)
        {
            printf(" 0");
        }
        printf(" 1 0 0 0\n");
    }
    return 0;
}
