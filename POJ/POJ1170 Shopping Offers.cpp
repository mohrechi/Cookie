#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
struct Offer
{
    int n,code[5],num[5],price;
}offer[100];
struct Needs
{
    int code,num,price;
}needs[5];
int offerNum,needsNum,minCost[6][6][6][6][6];
void input()
{
    scanf("%d",&needsNum);
    for(int i=0;i<needsNum;i++)
    {
        scanf("%d%d%d",&needs[i].code,&needs[i].num,&needs[i].price);
    }
    scanf("%d",&offerNum);
    for(int i=0;i<offerNum;i++)
    {
        scanf("%d",&offer[i].n);
        for(int j=0;j<offer[i].n;j++)
        {
            scanf("%d%d",&offer[i].code[j],&offer[i].num[j]);
        }
        scanf("%d",&offer[i].price);
    }
}
void code()
{
    for(int i=0;i<offerNum;i++)
    {
        int tempNum[5];
        for(int j=0;j<5;j++)
        {
            tempNum[j]=0;
        }
        for(int j=0;j<offer[i].n;j++)
        {
            for(int k=0;k<needsNum;k++)
            {
                if(offer[i].code[j]==needs[k].code)
                {
                    tempNum[k]=offer[i].num[j];
                    break;
                }
            }
        }
        for(int j=0;j<5;j++)
        {
            offer[i].num[j]=tempNum[j];
        }
    }
    memset(minCost,-1,sizeof(minCost));
    minCost[0][0][0][0][0]=0;
}
int calc(int n1,int n2,int n3,int n4,int n5)
{
    if(minCost[n1][n2][n3][n4][n5]!=-1)
    {
        return minCost[n1][n2][n3][n4][n5];
    }
    int min=n1*needs[0].price+n2*needs[1].price+n3*needs[2].price+n4*needs[3].price+n5*needs[4].price;
    for(int i=0;i<offerNum;i++)
    {
        if(offer[i].num[0]<=n1 and offer[i].num[1]<=n2 and offer[i].num[2]<=n3 and offer[i].num[3]<=n4 and offer[i].num[4]<=n5)
        {
            int temp=offer[i].price+calc(n1-offer[i].num[0],n2-offer[i].num[1],n3-offer[i].num[2],n4-offer[i].num[3],n5-offer[i].num[4]);
            if(temp<min)
            {
                min=temp;
            }
        }
    }
    return minCost[n1][n2][n3][n4][n5]=min;
}
void output(int n1,int n2,int n3,int n4,int n5)
{
    printf("%d\n",minCost[n1][n2][n3][n4][n5]);
}
int main()
{
    input();
    code();
    calc(needs[0].num,needs[1].num,needs[2].num,needs[3].num,needs[4].num);
    output(needs[0].num,needs[1].num,needs[2].num,needs[3].num,needs[4].num);
    return 0;
}
