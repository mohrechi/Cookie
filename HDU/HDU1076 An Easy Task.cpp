#include<stdio.h>
#include<stdlib.h>

bool isLeap(int year)
{
    return (year%4==0 && year%100!=0) || year%400==0;
}

int main()
{
    int t,y,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&y,&c);
        while(c)
        {
            if(isLeap(y))
            {
                --c;
            }
            ++y;
        }
        printf("%d\n",y-1);
    }
    return 0;
}
