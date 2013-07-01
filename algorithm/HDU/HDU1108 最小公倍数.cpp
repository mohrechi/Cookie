#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,c,d;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        c=a,d=b;
        while(a!=b)
        {
            if(a>b) a-=b;
            else b-=a;
        }
        printf("%d\n",c*d/a);
    }
    return 0;
}
