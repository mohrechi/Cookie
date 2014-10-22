/*
ID: cyberzh1
LANG: C++
TASK: theme
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("theme.in","r");
FILE* fout=fopen("theme.out","w");
int n,theme[5005],ans;
int main()
{
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d",&theme[i]);
    }
    for(int i=4;i<n-1;i++)
    {
        int len=0, dis=100;
        for(int j=0;i+j<n;j++)
        {
            if(theme[j]-theme[i+j]==dis)
            {
                if(len==i)
                {
                    break;
                }
                len++;
                if(len>=5 and len>ans)
                {
                    ans=len;
                }
            }
            else
            {
                len=1;
                dis=theme[j]-theme[i+j];
            }
        }
    }
    fprintf(fout,"%d\n",ans);
    return 0;
}
