/*
ID: cyberzh1
LANG: C++
TASK: milk4
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
FILE* fin=fopen("milk4.in","r");
FILE* fout=fopen("milk4.out","w");
int quart, pailNum, pail[100];
bool could[20005],use[100];
int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}
bool search(int depth, int total, int index)
{
    if(depth==total)
    {
        return could[quart];
    }
    int memory[10005],memoryNum=0;
    for(int i=index;i<pailNum;i++)
    {
        use[i]=true;
        for(int j=0;j<quart;j++)
        {
            if(could[j] and j+pail[i]<=quart and not could[j+pail[i]])
            {
                could[j+pail[i]]=true;
                memory[memoryNum++]=j+pail[i];
            }
        }
        if(search(depth+1,total,i+1))
        {
            return true;
        }
        for(int j=0;j<memoryNum;j++)
        {
            could[memory[j]]=false;
        }
        use[i]=false;
    }
    return false;
}
int main()
{
    fscanf(fin,"%d%d",&quart,&pailNum);
    for(int i=0;i<pailNum;i++)
    {
        fscanf(fin,"%d",&pail[i]);
    }
    qsort(pail,pailNum,sizeof(int),cmp);
    int i;
    for(i=1;i<=pailNum;i++)
    {
        memset(could,0,sizeof(could));
        could[0]=true;
        if(search(0,i,0))
        {
            break;
        }
    }
    fprintf(fout,"%d",i);
    for(int i=0;i<pailNum;i++)
    {
        if(use[i])
        {
            fprintf(fout," %d",pail[i]);
        }
    }
    fprintf(fout,"\n");
	return 0;
}
