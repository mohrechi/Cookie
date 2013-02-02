#include<stdio.h>
#include<stdlib.h>
struct Manufacturer
{
    int bandwidth, price;
}manufacturer[105][105];
int n,t,m[105];
double bp;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m[i]);
            for(int j=0;j<m[i];j++)
            {
                scanf("%d%d",&manufacturer[i][j].bandwidth,&manufacturer[i][j].price);
            }
        }
        bp=0;
        int minPrice;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m[i];j++)
            {
                int minBandwidth=manufacturer[i][j].bandwidth;
                int sumPrice=manufacturer[i][j].price;
                for(int k=0;k<n;k++)
                {
                    if(k==i)
                    {
                        continue;
                    }
                    minPrice=0x7FFFFFFF;
                    for(int l=0;l<m[k];l++)
                    {
                        if(minBandwidth<=manufacturer[k][l].bandwidth && minPrice>manufacturer[k][l].price)
                        {
                            minPrice=manufacturer[k][l].price;
                        }
                    }
                    if(minPrice==0x7FFFFFFF)
                    {
                        break;
                    }
                    sumPrice+=minPrice;
                }
                if(minPrice==0x7FFFFFFF)
                {
                    break;
                }
                if(bp<(double)minBandwidth/sumPrice)
                {
                    bp=(double)minBandwidth/sumPrice;
                }
            }
        }
        printf("%.3lf\n",bp);
    }
    return 0;
}
