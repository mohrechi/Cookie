#include<stdio.h>

int main(int argc, char* argv[])
{
    int n,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&x,&y);
        if(x==y)
        {
            if(x%2==0)
                printf("%d\n",x*2);
            else
                printf("%d\n",x*2-1);
        }
        else if(x-2==y)
        {
            if(x%2==0)
                printf("%d\n",x*2-2);
            else
                printf("%d\n",x*2-3);
        }
        else
        {
            printf("No Number\n");
        }
    }
    return 0;
}
