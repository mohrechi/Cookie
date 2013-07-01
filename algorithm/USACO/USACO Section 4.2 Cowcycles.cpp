/*
ID: cyberzh1
LANG: C++
TASK: cowcycle
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
FILE* fin=fopen("cowcycle.in","r");
FILE* fout=fopen("cowcycle.out","w");
int F,F1,F2,R,R1,R2,ansF[15],ansR[15],methodF[15],methodR[15];
double ratio[105][55],ratios[105],minVariance;
void input()
{
    fscanf(fin,"%d%d",&F,&R);
    fscanf(fin,"%d%d",&F1,&F2);
    fscanf(fin,"%d%d",&R1,&R2);
}
void initRatio()
{
    for(int i=F1;i<=F2;i++)
    {
        for(int j=R1;j<=R2;j++)
        {
            ratio[i][j]=1.0*i/j;
        }
    }
}
void initMethodF()
{
    for(int i=0;i<F;i++)
    {
        methodF[i]=F1+i;
    }
}
void initMethodR()
{
    for(int i=0;i<R;i++)
    {
        methodR[i]=R1+i;
    }
}
bool addF()
{
    methodF[F-1]++;
    for(int i=F-1;i>0;i--)
    {
        if(methodF[i]>F2-F+i+1)
        {
            methodF[i-1]++;
        }
    }
    for(int i=1;i<F;i++)
    {
        if(methodF[i]>F2-F+i+1)
        {
            methodF[i]=methodF[i-1]+1;
        }
    }
    return methodF[0]<=F2-F+1;
}
bool addR()
{
    methodR[R-1]++;
    for(int i=R-1;i>0;i--)
    {
        if(methodR[i]>R2-R+i+1)
        {
            methodR[i-1]++;
        }
    }
    for(int i=1;i<R;i++)
    {
        if(methodR[i]>R2-R+i+1)
        {
            methodR[i]=methodR[i-1]+1;
        }
    }
    return methodR[0]<=R2-R+1;
}

void sort()
{
    int k=0,t;
    double sum=0,sum2=0,average,variance,temp;
    ratios[0]=0;
    for(int i=0;i<F;i++)
    {
        for(int j=0;j<R;j++)
        {
            t=++k;
            while(ratios[t-1]>=ratio[methodF[i]][methodR[j]])
            {
                ratios[t]=ratios[t-1];
                t--;
            }
            ratios[t]=ratio[methodF[i]][methodR[j]];
        }
    }
    for(int i=1;i<k;i++)
    {
        temp=ratios[i+1]-ratios[i];
        sum+=temp;
        sum2+=temp*temp;
    }
    average=sum/(k-1);
    variance=sum2-sum*average;
    if(variance<minVariance)
    {
        minVariance=variance;
        memcpy(ansF,methodF,sizeof(int)*F);
        memcpy(ansR,methodR,sizeof(int)*R);
    }
}
void search()
{
    initMethodF();
    initMethodR();
    minVariance=1e10;
    while(true)
    {
        if(methodF[F-1]*methodR[R-1]>=3*methodF[0]*methodR[0])
        {
            sort();
        }
        if(not addF())
        {
            initMethodF();
            if(not addR())
            {
                break;
            }
        }
    }
}
void output()
{
    for(int i=0;i<F-1;i++)
    {
        fprintf(fout,"%d ",ansF[i]);
    }
    fprintf(fout,"%d\n",ansF[F-1]);
    for(int i=0;i<R-1;i++)
    {
        fprintf(fout,"%d ",ansR[i]);
    }
    fprintf(fout,"%d\n",ansR[R-1]);
}
int main()
{
    input();
    initRatio();
    search();
    output();
    return 0;
}
