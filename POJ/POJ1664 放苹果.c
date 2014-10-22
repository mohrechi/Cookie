#include<stdio.h>

int dg(int m,int n)
{
    if(m<0) return 0;
    if(m==1||n==1) return 1;
    return dg(m-n,n)+dg(m,n-1);
}

int main(int argc, char* argv[])
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        printf("%d\n",dg(m,n));
    }
    return 0;
}
