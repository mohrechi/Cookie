/*
ID: cyberzh1
LANG: C++
TASK: milk
*/
#include<stdio.h>
#include<stdlib.h>

struct farmer
{
    int price, amount;
}f[5005];

int cmp(const void* a, const void* b)
{
    return (*(farmer*)a).price-(*(farmer*)b).price;
}

int main()
{
    FILE* fin=fopen("milk.in","r");
    FILE* fout=fopen("milk.out","w");
    int n,m;
    fscanf(fin,"%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        fscanf(fin,"%d%d",&f[i].price,&f[i].amount);
    }
    qsort(f,m,sizeof(*f),cmp);
    int res=0;
    for(int i=0;i<m;i++)
    {
        if(f[i].amount<n)
        {
            res+=f[i].price*f[i].amount;
            n-=f[i].amount;
        }
        else
        {
            res+=f[i].price*n;
            break;
        }
    }
    fprintf(fout,"%d\n",res);
    return 0;
}
