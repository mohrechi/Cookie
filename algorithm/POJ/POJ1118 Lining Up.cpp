#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

bool cmp(const double &a, const double &b)
{
    return a<b;
}

int main(int argc, char* argv[])
{
    int n,x[800],y[800],max;
    double k[800];
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        max=0;
        for(int i=0;i<n;i++)
        {
            int m=0,inf=0;
            for(int j=0;j<=n;j++)
            {
                if(x[i]==x[j])
                {
                    inf++;
                }
                else
                {
                    k[m++]=(double)(y[i]-y[j])/(x[i]-x[j]);
                }
            }
            sort(k,k+m,cmp);
            int count=2,p=0;
            for(int j=1;j<m;j++)
            {
                if(k[p]==k[j])
                {
                    count++;
                }
                else
                {
                    p=j;
                    if(count>max)
                    {
                        max=count;
                    }
                    count=2;
                }
            }
            if(count>max)
            {
                max=count;
            }
            if(inf>max)
            {
                max=inf;
            }
        }
        printf("%d\n",max);
    }
	return 0;
}
