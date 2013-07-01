/*
ID: cyberzh1
LANG: C++
TASK: rectbarn
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("rectbarn.in","r");
FILE* fout=fopen("rectbarn.out","w");
int r,c,p,height[3005],left[3005],right[3005],answer;
bool damage[3005][3005];
int min(int x, int y)
{
    return x<y?x:y;
}
int max(int x, int y)
{
    return x>y?x:y;
}
int main()
{
    fscanf(fin,"%d%d%d",&r,&c,&p);
    int x,y;
    while(p--)
    {
        fscanf(fin,"%d%d",&x,&y);
        damage[x][y]=true;
    }
    for(int i=1;i<=r;i++)
    {
        int k=0;
        for(int j=1;j<=c;j++)
        {
            if(not damage[i][j])
            {
                height[j]=height[j]+1;
                if(left[j])
                {
                    left[j]=min(left[j],++k);
                }
                else
                {
                    left[j]=++k;
                }
            }
            else
            {
                height[j]=left[j]=k=0;
            }
        }
        k=0;
        for(int j=c;j>0;j--)
        {
            if(not damage[i][j])
            {
                if(right[j])
                {
                    right[j]=min(right[j],++k);
                }
                else
                {
                    right[j]=++k;
                }
                answer=max(answer, height[j]*(left[j]+right[j]-1));
            }
            else
            {
                right[j]=k=0;
            }
        }
    }
    fprintf(fout,"%d\n",answer);
    return 0;
}
