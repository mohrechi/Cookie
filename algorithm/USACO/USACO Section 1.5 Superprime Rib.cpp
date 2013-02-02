/*
ID: cyberzh1
LANG: C++
TASK: sprime
*/
#include<stdio.h>
#include<math.h>

int p1[4]={2,3,5,7},p2[4]={1,3,7,9};
FILE *fin, *fout;
bool judge(int number)
{
    if(number==2)
    {
        return true;
    }
    if(number&1)
    {
        for(int i=3;i*i<=number;i+=2)
        {
            if(number%i==0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

void dfs(int layer, int number)
{
    if(judge(number))
    {
        if(not layer)
        {
            fprintf(fout,"%d\n",number);
        }
        else
        {
            number*=10;
            for(int i=0;i<4;i++)
            {
                dfs(layer-1,number+p2[i]);
            }
        }
    }
}

int main()
{
    fin=fopen("sprime.in","r");
    fout=fopen("sprime.out","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=0;i<4;i++)
    {
        dfs(n-1,p1[i]);
    }
    return 0;
}
