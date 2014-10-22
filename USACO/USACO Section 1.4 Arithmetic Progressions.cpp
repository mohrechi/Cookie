/*
ID: cyberzh1
LANG: C++
TASK: ariprog
*/
#include<stdio.h>
int n,m,bisquares[125010]={0},atop,max;
int main()
{
    FILE* fin=fopen("ariprog.in","r");
    FILE* fout=fopen("ariprog.out","w");
    fscanf(fin,"%d%d",&n,&m);
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            bisquares[i*i+j*j]=1;
        }
    }
    atop=0,max=m*m*2;
    int imax=max/(n-1);
    for(int i=1;i<=imax;i++)
    {
        for(int j=0;j<=max;j++)
        {
            int temp=j+i*(n-1),k=0;
            if(temp>max) break;
            for(;k<n;k++,temp-=i)
            {
                if(not bisquares[temp])
                {
                    break;
                }
            }
            if(k==n)
            {
                fprintf(fout,"%d %d\n",j,i);
                atop++;
            }
        }
    }
    if(not atop)
    {
        fprintf(fout,"NONE\n");
    }
    return 0;
}
