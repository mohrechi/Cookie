#include<stdio.h>

int get2(int n)
{
    if(n==0) return 0;
    return n/2+get2(n/2);
}

int get5(int n)
{
    if(n==0) return 0;
    return n/5+get5(n/5);
}

int get(int n, int x)
{
    if(n==0) return 0;
    return n/10+(n%10>=x)+get(n/5,x);
}

int getx(int n, int x)
{
    if(n==0) return 0;
    return getx(n/2,x)+get(n,x);
}

int main()
{
    int n,m,num2,num3,num5,num7,num9;
    int table[4][4]={6,2,4,8,1,3,9,7,1,7,9,3,1,9,1,9};
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        num2=get2(n)-get2(n-m);
        num5=get5(n)-get5(n-m);
        num3=getx(n,3)-getx(n-m,3);
        num7=getx(n,7)-getx(n-m,7);
        num9=getx(n,9)-getx(n-m,9);
        if(num2<num5)
        {
            printf("5\n");
            continue;
        }
        int result=1;
        if(num2!=num5)
        {
            result*=table[0][(num2-num5)%4];
        }
        result*=table[1][num3%4];
        result*=table[2][num7%4];
        result*=table[3][num9&1];
        printf("%d\n",result%10);
    }
    return 0;
}
