/*
ID: cyberzh1
LANG: C++
TASK: concom
*/
#include<stdio.h>
FILE* fin=fopen("concom.in","r");
FILE* fout=fopen("concom.out","w");
int n,a[105][105]={0};
bool control[105][105];
int max(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    int t;
    fscanf(fin,"%d",&t);
    while(t--)
    {
        int x,y,per;
        fscanf(fin,"%d%d%d",&x,&y,&per);
        a[x][y]=per;
        n=max(max(x,y),n);
        if(per>=50)
        {
            control[x][y]=true;
        }
    }
    for(int i=1;i<=n;i++)
    {
        control[i][i]=true;
    }
    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(not control[i][j])
                {
                    int sum=0;
                    for(int k=1;k<=n;k++)
                    {
                        if(j!=k and control[i][k])
                        {
                            sum+=a[k][j];
                        }
                    }
                    if(sum>=50)
                    {
                        control[i][j]=true;
                        flag=true;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(control[i][j] and i!=j)
            {
                fprintf(fout,"%d %d\n",i,j);
            }
        }
    }
}
