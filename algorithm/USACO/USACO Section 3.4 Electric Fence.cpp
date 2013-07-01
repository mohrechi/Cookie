/*
ID: cyberzh1
LANG: C++
TASK: fence9
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("fence9.in","r");
FILE* fout=fopen("fence9.out","w");
int swap(int &x, int &y)
{
    x^=y,y^=x,x^=y;
}
int gcd(int x, int y)
{
    if(x>y) swap(x,y);
    if(x==0) return y;
    return gcd(y%x,x);
}
int main()
{
    int n,m,p,s,i;
    fscanf(fin,"%d%d%d",&n,&m,&p);
    s=m*p*0.5;
    i=(gcd(n,m)+gcd(abs(n-p),m)+p)*0.5;
    fprintf(fout,"%d\n",s-i+1);
	return 0;
}
