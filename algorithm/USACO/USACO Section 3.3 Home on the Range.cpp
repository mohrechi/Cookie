/*
ID: cyberzh1
LANG: C++
TASK: range
*/
#include<stdio.h>
FILE* fin=fopen("range.in","r");
FILE* fout=fopen("range.out","w");
int n,map[251][251],square[251][251];
int main()
{
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;)
        {
            char ch;
            fscanf(fin,"%c",&ch);
            if(ch=='1')
            {
                map[i][j++]=0;
            }
            else if(ch=='0')
            {
                map[i][j++]=1;
            }
            square[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            square[i][j]=square[i-1][j]+square[i][j-1]-square[i-1][j-1]+map[i][j];
        }
    }
    for(int i=2;i<=n;i++)
    {
        int count=0;
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<=n;k++)
            {
                if(square[j][k]-square[j-i][k]-square[j][k-i]+square[j-i][k-i]==0)
                {
                    count++;
                }
            }
        }
        if(count)
        {
            fprintf(fout,"%d %d\n",i,count);
        }
    }
    return 0;
}
