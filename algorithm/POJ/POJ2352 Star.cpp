#include<cstdio>
using namespace std;

int c[33000],level[16000],n;

int lowBit(int x)
{
    return x&(x^(x-1));
}

void modify(int i, int x)
{
    while(i<=32001)
    {
        c[i]+=x;
        i+=lowBit(i);
    }
}

int sum(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=c[i];
        i-=lowBit(i);
    }
    return sum;
}

int main()
{
    int x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        x++;
        modify(x,1);
        level[sum(x)]++;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",level[i]);
    }
    return 0;
}
