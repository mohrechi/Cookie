/*
ID: cyberzh1
LANG: C++
TASK: runround
*/
#include<stdio.h>
#include<string.h>
FILE* fin=fopen("runround.in","r");
FILE* fout=fopen("runround.out","w");
char s[20];
bool f[20],v[10];
bool round(int num)
{
    sprintf(s,"%d",num);
    int len=strlen(s);
    for(int i=1;i<10;i++)
    {
        v[i]=false;
    }
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0') return true;
        s[i]-='0', f[i]=false;
        if(v[s[i]]) return true;
        v[s[i]]=true;
    }
    int pos=0;
    while(true)
    {
        if(f[pos]) break;
        f[pos]=true;
        pos=(pos+s[pos])%len;
    }
    if(pos!=0) return true;
    for(int i=0;i<len;i++)
    {
        if(not f[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    fscanf(fin,"%d",&n);
    while(round(++n));
    fprintf(fout,"%d\n",n);
    return 0;
}
