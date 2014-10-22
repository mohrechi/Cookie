/*
ID: cyberzh1
LANG: C++
TASK: clocks
*/
#include<stdio.h>
int rotate[10][10]={{0,0,0,0,0,0,0,0,0,0},
{0,1,1,0,1,1,0,0,0,0},
{0,1,1,1,0,0,0,0,0,0},
{0,0,1,1,0,1,1,0,0,0},
{0,1,0,0,1,0,0,1,0,0},
{0,0,1,0,1,1,1,0,1,0},
{0,0,0,1,0,0,1,0,0,1},
{0,0,0,0,1,1,0,1,1,0},
{0,0,0,0,0,0,0,1,1,1},
{0,0,0,0,0,1,1,0,1,1}};
int clock[10],use[11]={0},temp[10],min=40,ans[40];

bool check()
{
    for(int i=1;i<=9;i++)
    {
        temp[i]=clock[i];
        for(int j=1;j<=9;j++)
        {
            temp[i]+=rotate[j][i]*use[j];
        }
        if(temp[i]%4)
        {
            return false;
        }
    }
    return true;
}
void copy()
{
    int p=0;
    for(int i=1;i<=9;i++)
    {
        int k=0;
        while(k<use[i])
        {
            ans[p++]=i;
            k++;
        }
    }
}
int num()
{
    int t=0;
    for(int i=1;i<=9;i++)
    {
        t+=use[i];
    }
    return t;
}
void search()
{
    while(true)
    {
        use[1]++;
        for(int i=1;i<=9;i++)
        {
            if(use[i]==4)
            {
                use[i]=0, use[i+1]++;
            }
        }
        if(use[10])break;
        if(check())
        {
            int t=num();
            if(min!=40 and t<=min)
            {
                int p=0,i;
                for(i=1;i<=9;i++)
                {
                    int k=0;
                    while(k<use[i])
                    {
                        if(i>ans[p++])
                        {
                            break;
                        }
                        k++;
                    }
                    if(k<use[i])break;
                }
                if(i>9)
                {
                    min=t;
                    copy();
                }
            }
            if(min==40)
            {
                min=num();
                copy();
            }
        }
    }
}

int main()
{
    FILE* fin=fopen("clocks.in","r");
    FILE* fout=fopen("clocks.out","w");
    for(int i=1;i<=9;i++)
    {
        fscanf(fin,"%d",&clock[i]);
        clock[i]=clock[i]/3;
    }
    int layer=0;
    search();
    for(int i=0;i<min;i++)
    {
        if(i==0)fprintf(fout,"%d",ans[i]);
        else fprintf(fout," %d",ans[i]);
    }
    fprintf(fout,"\n");
    return 0;
}
