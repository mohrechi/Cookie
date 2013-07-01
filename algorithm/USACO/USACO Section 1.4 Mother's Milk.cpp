/*
ID: cyberzh1
LANG: C++
TASK: milk3
*/
#include<stdio.h>
#include<memory.h>
bool ans[25];
int bucket[3],milk[3],top,record[8000][3];

void check()
{
    for(int i=0;i<top;i++)
    {
        int j;
        for(j=0;j<3;j++)
        {
            if(milk[j]!=record[i][j])
            {
                break;
            }
        }
        if(j==3) return;
    }
    for(int i=0;i<3;i++)
    {
        record[top][i]=milk[i];
    }
    top++;
}

void copy(int k)
{
    for(int i=0;i<3;i++)
    {
        milk[i]=record[k][i];
    }
}

void pour(int i,int j,int k)
{
    copy(k);
    if(milk[i]>bucket[j]-milk[j])
    {
        milk[i]-=bucket[j]-milk[j];
        milk[j]=bucket[j];
    }
    else
    {
        milk[j]+=milk[i];
        milk[i]=0;
    }
    if(not milk[0])ans[milk[2]]=true;
    check();
}

int main()
{
    FILE* fin=fopen("milk3.in","r");
    FILE* fout=fopen("milk3.out","w");
    memset(ans,false,sizeof(ans));
    fscanf(fin,"%d%d%d",&bucket[0],&bucket[1],&bucket[2]);
    milk[0]=0,milk[1]=0,milk[2]=bucket[2];
    ans[bucket[2]]=true,top=1,record[0][0]=0,record[0][1]=0,record[0][2]=bucket[2];
    int i=0;
    while(i<top)
    {
        pour(0,1,i),pour(0,2,i),pour(1,0,i),pour(1,2,i),pour(2,0,i),pour(2,1,i);
        i++;
    }
    for(i=0;i<=20;i++)
    {
        if(ans[i])
        {
            fprintf(fout,"%d",i++);
            break;
        }
    }
    for(;i<=20;i++)
    {
        if(ans[i])
        {
            fprintf(fout," %d",i);
        }
    }
    fprintf(fout,"\n");
    return 0;
}
