#include<stdio.h>

int mgy(int a,int b)
{
    if(a%b==0) return b;
    if(b%a==0) return a;
    while(a!=b)
    {
        if(a>b) a%=b;
        else b%=a;
    }
    return a;
}

int gcd(int a,int b)
{
    if(a==b) return a;
    if((a&1)==0)
    {
        if((b&1)==0) return gcd(a>>1,b>>1)<<1;
        else return gcd(a>>1,b);
    }
    else
    {
        if((b&1)==0) return gcd(a,b>>1);
        else return gcd(((a>b)?(a-b):(b-a))>>1,(a+b)>>1);
    }
}

int main(int argc, char* argv[])
{
    char s[500];
    int a,b,c,d,o,e,f,i;
    while(scanf("%s",s)!=EOF)
    {
        a=s[0]-'0', b=s[2]-'0';
        c=s[4]-'0', d=s[6]-'0';
        o=-1;
        if(s[3]=='+')
        {
            o=1;
        }
        e=b*d/gcd(b,d);
        f=a*e/b+o*c*e/d;
        if(f==0)
        {
            printf("0\n");
        }
        else
        {
            if(f>0) i=gcd(e,f);
            else i=gcd(e,-f);
            e/=i,f/=i;
            if(e!=1) printf("%d/%d\n",f,e);
            else printf("%d\n",f);
        }
    }
    return 0;
}
