#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAXN 10001

struct Product
{
    int profit, deadline;
}product[MAXN];
int profit[MAXN];
int father[MAXN];
int productNumber;
int lastDeadline;
int totalProfit;

bool compare(const Product a, const Product b)
{
    return a.profit > b.profit;
}

void initial()
{
    for(int i=0;i<=lastDeadline;++i)
    {
        father[i] = i;
        profit[i] = 0;
    }
}

int find(int x)
{
    if(father[x] == x)
    {
        return x;
    }
    return father[x] = find(father[x]);
}

void insert(Product &pro)
{
    int time = find(pro.deadline);
    if(time > 0)
    {
        profit[time] = pro.profit;
        father[time] = time - 1;
    }
}

int main(int argc, char* argv[])
{
    while(~scanf("%d",&productNumber))
    {
        lastDeadline = 0;
        for(int i=0;i<productNumber;++i)
        {
            scanf("%d%d",&product[i].profit,&product[i].deadline);
            if(product[i].deadline > lastDeadline)
            {
                lastDeadline = product[i].deadline;
            }
        }
        sort(product, product + productNumber, compare);
        initial();
        for(int i=0;i<productNumber;++i)
        {
            insert(product[i]);
        }
        totalProfit = 0;
        for(int i=1;i<=lastDeadline;++i)
        {
            totalProfit += profit[i];
        }
        printf("%d\n",totalProfit);
    }
    return 0;
}
