/*
ID: cyberzh1
LANG: C++
TASK: lamps
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE* fin=fopen("lamps.in","r");
FILE* fout=fopen("lamps.out","w");
int n,c,final[105],temp[105],ansNum;
char ans[16][110];
bool solve[16];
int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}
void flip(int &num)
{
    if(num) num=0;
    else num=1;
}
bool reliable()
{
    for(int i=1;i<=n;i++)
    {
        if(final[i]!=-1)
        {
            if(final[i]!=temp[i])
            {
                return false;
            }
        }
    }
    return true;
}
void saveAnswer()
{
    for(int i=0;i<n;i++)
    {
        ans[ansNum][i]=temp[i+1]+'0';
    }
    ans[ansNum][n]=0;
    int i=0;
    while(i<ansNum)
    {
        if(not strcmp(ans[ansNum],ans[i]))
        {
            return;
        }
        i++;
    }
    ansNum++;
}
void getMethod()
{
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<=n;j++)
        {
            temp[j]=1;
        }
        int count=0;
        if(i&1)
        {
            count++;
            for(int j=1;j<=n;j++)
            {
                flip(temp[j]);
            }
        }
        if(i&2)
        {
            count++;
            for(int j=1;j<=n;j+=2)
            {
                flip(temp[j]);
            }
        }
        if(i&4)
        {
            count++;
            for(int j=2;j<=n;j+=2)
            {
                flip(temp[j]);
            }
        }
        if(i&8)
        {
            count++;
            for(int j=1;j<=n;j+=3)
            {
                flip(temp[j]);
            }
        }
        if(count>c) continue;
        if(reliable())
        {
            saveAnswer();
            solve[i]=true;
        }
    }
}
int main()
{
    fscanf(fin,"%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        final[i]=-1;
    }
    while(true)
    {
        fscanf(fin,"%d",&final[104]);
        if(final[104]==-1)
        {
            break;
        }
        final[final[104]]=1;
    }
    while(true)
    {
        fscanf(fin,"%d",&final[104]);
        if(final[104]==-1)
        {
            break;
        }
        final[final[104]]=0;
    }
    ansNum=0;
    getMethod();
    if(not ansNum)
    {
        fprintf(fout,"IMPOSSIBLE\n");
    }
    else
    {
        qsort(ans,ansNum,sizeof(*ans),cmp);
        for(int i=0;i<ansNum;i++)
        {
            fprintf(fout,"%s\n",ans[i]);
        }
    }
    return 0;
}
