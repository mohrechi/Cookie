/*
ID: cyberzh1
LANG: C++
TASK: frac1
*/
#include<stdio.h>
#include<stdlib.h>
FILE *fin = fopen("frac1.in","r");
FILE *fout = fopen("frac1.out","w");
struct Fraction
{
    int x,y;
    bool min;
}f[40000];
int cmp(const void* a, const void* b)
{
    return (*(Fraction*)a).x*(*(Fraction*)b).y-(*(Fraction*)a).y*(*(Fraction*)b).x;
}
int min(int x, int y)
{
    return x<y?x:y;
}
void judge(int fra)
{
    if(f[fra].x>f[fra].y)
    {
        f[fra].min=false;
        return;
    }
    int m=min(f[fra].x,f[fra].y);
    for(int i=2;i<=m;i++)
    {
        if(f[fra].x%i==0 and f[fra].y%i==0)
        {
            f[fra].min=false;
            return;
        }
    }
    f[fra].min=true;
}
int main()
{
    int n;
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp=i*n+j;
            f[temp].x=i+1;
            f[temp].y=j+1;
            judge(temp);
        }
    }
    n*=n;
    qsort(f,n,sizeof(*f),cmp);
    fprintf(fout,"0/1\n");
    for(int i=0;i<n;i++)
    {
        if(f[i].min)
        {
            fprintf(fout,"%d/%d\n",f[i].x, f[i].y);
        }
    }
    return 0;
}
