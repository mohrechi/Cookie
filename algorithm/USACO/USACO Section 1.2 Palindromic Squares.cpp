/*
ID: cyberzh1
LANG: C++
TASK: palsquare
*/
#include<stdio.h>
#include<string.h>

bool judge(char s[])
{
    int i=0,j=strlen(s)-1;
    while(i<j)
    {
        if(s[i++]!=s[j--])
        {
            return false;
        }
    }
    return true;
}

void Base(int x, int base, char res[])
{
    int len=0;
    while(x>0)
    {
        res[len++]=x%base;
        x/=base;
    }
    for(int i=0;i<len;i++)
    {
        if(res[i]>=0 and res[i]<=9)
        {
            res[i]=res[i]+'0';
        }
        else
        {
            res[i]=res[i]-10+'A';
        }
    }
    for(int i=0;i<len/2;i++)
    {
        char temp;
        temp=res[i],res[i]=res[len-i-1],res[len-i-1]=temp;
    }
    res[len]=0;
}

void change(int x, int xx, int base, FILE *fout)
{
    char res1[500],res2[500];
    Base(xx,base,res2);
    if(judge(res2))
    {
        Base(x,base,res1);
        fprintf(fout,"%s %s\n",res1,res2);
    }
}

int main()
{
    FILE* fin=fopen("palsquare.in","r");
    FILE* fout=fopen("palsquare.out","w");
    int a[301];
    for(int i=0;i<=300;i++)
    {
        a[i]=i*i;
    }
    int base;
    fscanf(fin,"%d",&base);
    for(int i=1;i<=300;i++)
    {
        change(i,a[i],base,fout);
    }
    return 0;
}
