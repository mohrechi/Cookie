/*
ID: cyberzh1
LANG: C++
TASK: beads
*/

#include<stdio.h>

int n;
char s[400];

int check(char neck[])
{
    int max=0;
    char memo;
    int i;
    for(i=0;i<n;i++)
    {
        if(neck[i]=='w')
        {
            max++;
        }
        else
        {
            memo=neck[i];
            break;
        }
    }
    if(max==n) return max;
    for(;i<n;i++)
    {
        if(neck[i]==memo or neck[i]=='w')
        {
            max++;
        }
        else
        {
            break;
        }
    }
    if(max==n) return max;
    for(i=n-1;i>=0;i--)
    {
        if(neck[i]=='w')
        {
            max++;
        }
        else
        {
            memo=neck[i];
            break;
        }
    }
    for(;i>=0;i--)
    {
        if(neck[i]==memo or neck[i]=='w')
        {
            max++;
        }
        else
        {
            break;
        }
    }
    return max>n?n:max;
}

int calc(int breakpoint)
{
    char temp[400],*t;
    t=temp;
    for(int i=breakpoint;i<n;i++)
    {
        *t++=s[i];
    }
    for(int i=0;i<breakpoint;i++)
    {
        *t++=s[i];
    }
    return check(temp);
}

int main()
{
    FILE* fin  = fopen("beads.in", "r");
    FILE* fout = fopen("beads.out","w");
    fscanf(fin,"%d%s",&n,s);
    int max=0;
    for(int i=0;i<n;i++)
    {
        int temp=calc(i);
        if(temp>max)
        {
            max=temp;
        }
    }
    fprintf(fout,"%d\n",max);
    return 0;
}
