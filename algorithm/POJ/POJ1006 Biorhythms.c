#include<stdio.h>

int main(int argc, char *argv[])
{
    int p,e,i,d,count,time=1;
    while(1)
    {
        scanf("%d%d%d%d",&p,&e,&i,&d);
        if(-1==p)break;
        count=(5544*p+14421*e+1288*i-d+21252)%21252;
        if(count==0) count=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",time++,count);
    }
}
