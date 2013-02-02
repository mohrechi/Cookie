/*
ID: cyberzh1
LANG: C++
TASK: fence8
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("fence8.in","r");
FILE* fout=fopen("fence8.out","w");
int ans,boardNum,railNum,board[50],rail[1023],sum=0,remain[50],lensum[1023],currentMin[1023],re,rem;
int cmp1(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}
int cmp2(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}
bool DFS(int depth, int current)
{
    if(not depth)
    {
        for(int i=current;i<boardNum;i++)
        {
            if(remain[i]>=rail[0])
            {
                fprintf(fout,"%d\n",ans+1);
                exit(0);
            }
        }
    }
    for(int i=current;i<boardNum;i++)
    {
        if(remain[i]>=rail[depth])
        {
            int r=re;
            remain[i]-=rail[depth];
            if(remain[i]<rail[0] and re+remain[i]>rem)
            {
                remain[i]+=rail[depth];
                continue;
            }
            if(remain[i]<rail[0])
            {
                re+=remain[i];
            }
            if(rail[depth-1]==rail[depth])
            {
                DFS(depth-1,i);
            }
            else
            {
                DFS(depth-1,0);
            }
            remain[i]+=rail[depth];
            re=r;
        }
    }
}
int main()
{
    fscanf(fin,"%d",&boardNum);
    for(int i=0;i<boardNum;i++)
    {
        fscanf(fin,"%d",&board[i]);
        sum+=board[i];
        remain[i]=board[i];
    }
    qsort(board,boardNum,sizeof(int),cmp2);
    fscanf(fin,"%d",&railNum);
    for(int i=0;i<railNum;i++)
    {
        fscanf(fin,"%d",&rail[i]);
    }
    qsort(rail,railNum,sizeof(int),cmp1);
    int i=0;
    lensum[0]=rail[0];
    while(i<railNum and lensum[i]<=sum)
    {
        i++;
        lensum[i]=lensum[i-1]+rail[i];
    }
    railNum=i;
    for(i=railNum-1;i>=0;i--)
    {
        re=0;
        rem=sum-lensum[i];
        ans=i;
        DFS(i,0);
    }
    fprintf(fout,"0\n");
    return 0;
}
