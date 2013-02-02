/*
ID: cyberzh1
LANG: C++
TASK: calfflac
*/
#include<stdio.h>
#include<string.h>

struct copy
{
    char ch;
    int x;
}c[20005];

int main()
{
    FILE* fin=fopen("calfflac.in","r");
    FILE* fout=fopen("calfflac.out","w");
    int n=0,k=0;
    char s[20005];
    while(fscanf(fin,"%c",&s[n++])!=EOF);
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' and s[i]<='z')
        {
            c[k].x=i;
            c[k++].ch=s[i];
        }
        if(s[i]>='A' and s[i]<='Z')
        {
            c[k].x=i;
            c[k++].ch=s[i]-'A'+'a';
        }
    }
    int max=0,start,end;
    for(int i=0;i<k;i++)
    {
        int count=1;
        while(i-count>=0 and i+count<k and c[i-count].ch==c[i+count].ch)
        {
            count++;
        }
        if(count*2-1>max)
        {
            max=count--*2-1;
            start=i-count,end=i+count;
        }
        if(c[i].ch==c[i+1].ch)
        {
            count=1;
            while(i-count>=0 and i+count+1<k and c[i-count].ch==c[i+count+1].ch)
            {
                count++;
            }
            if(count*2>max)
            {
                max=count--*2;
                start=i-count, end=i+count+1;
            }
        }
    }
    s[c[end].x+1]=0;
    fprintf(fout,"%d\n%s\n",max,s+c[start].x);
    return 0;
}
