#include<stdio.h>

int cal(int n,int k)
{
    if(n==1)return ++k;
    else if(n%2==1) return cal(3*n+1,++k);
    else return cal(n/2,++k);
 }

int main(int argc, char* argv[])
{
    int i,j,temp,max;
    while(scanf("%d%d",&i,&j)!=EOF)
    {
        printf("%d %d ",i,j);
        if(i>j)
        {
            temp=i,i=j,j=temp;
        }
        max=0;
        for(;i<=j;i++)
        {
            temp=cal(i,0);
            if(max<temp)max=temp;
        }
        printf("%d\n",max);
    }
    return 0;
}
