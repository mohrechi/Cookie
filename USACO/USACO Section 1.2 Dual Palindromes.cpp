/*
ID: cyberzh1
LANG: C++
TASK: dualpal
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

int main()
{
    FILE* fin=fopen("dualpal.in","r");
    FILE* fout=fopen("dualpal.out","w");
    int n,s;
    char res[100];
    fscanf(fin,"%d%d",&n,&s);
    for(int i=s+1;n;i++)
    {
        int num=0;
        for(int j=2;j<=10;j++)
        {
            Base(i,j,res);
            if(judge(res))
            {
                if(++num==2)
                {
                    n--;
                    fprintf(fout,"%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
