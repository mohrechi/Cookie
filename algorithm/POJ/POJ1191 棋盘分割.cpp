#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string.h>
using namespace std;

int sum[9][9];
int d[15][9][9][9][9];

int SUM(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}

int fun(int k,int x1,int y1,int x2,int y2)
{
    int t,a,b,c,e,MIN=10000000;
    if(d[k][x1][y1][x2][y2]!=-1)
        return d[k][x1][y1][x2][y2];
    if(k==0)
    {
        t=SUM(x1,y1,x2,y2);
        d[k][x1][y1][x2][y2]=t*t;
        return t*t;
    }
    for(a=x1;a<x2;a++)
    {
        c=SUM(a+1,y1,x2,y2);
        e=SUM(x1,y1,a,y2);
        t=min(fun(k-1,x1,y1,a,y2)+c*c,fun(k-1,a+1,y1,x2,y2)+e*e);
        if(MIN>t) MIN=t;
    }
    for(b=y1;b<y2;b++)
    {
        c=SUM(x1,b+1,x2,y2);
        e=SUM(x1,y1,x2,b);
        t=min(fun(k-1,x1,y1,x2,b)+c*c,fun(k-1,x1,b+1,x2,y2)+e*e);
        if(MIN>t) MIN=t;
    }
    d[k][x1][y1][x2][y2]=MIN;
    return MIN;
}
int main()
{
    int n,i,j,s,value;
    double b;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=8;i++)
        {
            sum[0][i]=0;sum[i][0]=0;
        }
        for(i=1;i<=8;i++)
        {
            for(j=1,s=0;j<=8;j++)
            {
                scanf("%d",&value); s+=value;
                sum[i][j]=sum[i-1][j]+s;
            }
        }
        memset(d,-1,sizeof(d));
        s=sum[8][8]*sum[8][8];
        value=fun(n-1,1,1,8,8);
        value*=n;value-=s;
        b=double(value)/double(n*n);
        printf("%.3lf\n",sqrt(b));
    }
    return 0;
}
