/*
ID: cyberzh1
LANG: C++
TASK: pprime
*/
#include<stdio.h>
#include<string.h>
int a,b;
bool isPrime(int number)
{
    if(number==2)
    {
        return true;
    }
    if(number&1)
    {
        for(int i=3;i*i<=number;i+=2)
        {
            if(number%i==0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
int getPalindrome(int number)
{
    char s[100];
    sprintf(s,"%d",number);
    int len=strlen(s);
    for(int i=0;i<len-1;i++)
    {
        s[(len-1)*2-i]=s[i];
    }
    len=len*2-1;
    s[len]=0;
    int res=0;
    for(int i=0;i<len;i++)
    {
        res=res*10+s[i]-'0';
    }
    return res;
}
int initPalindrome(int number)
{
    char s[100];
    sprintf(s,"%d",number);
    int len=(strlen(s)+1)/2;
    int res=0;
    for(int i=0;i<len;i++)
    {
        res=res*10+s[i]-'0';
    }
    while(true)
    {
        int temp=getPalindrome(res);
        if(temp>=a and temp<=b)
        {
            return res;
        }
        res++;
    }
}
int main()
{
    FILE *fin=fopen("pprime.in","r");
    FILE *fout=fopen("pprime.out","w");
    fscanf(fin,"%d%d",&a,&b);
    if(a<100)
    {
        if(a<=5)fprintf(fout,"5\n");
        if(a<=7)fprintf(fout,"7\n");
        if(a<=11)fprintf(fout,"11\n");
        a=101;
        if(b<100)
        {
            b=101;
        }
    }
    int num=initPalindrome(a);
    while(true)
    {
        int temp=getPalindrome(num);
        if(temp<a or temp>b)
        {
            break;
        }
        if(isPrime(temp))
        {
            fprintf(fout,"%d\n",temp);
        }
        num++;
    }
    return 0;
}
