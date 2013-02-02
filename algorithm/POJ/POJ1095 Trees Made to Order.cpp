#include<stdio.h>
long long catalan[]={1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700};  
void output(long long n, long long k)
{
    long long i,sum=0;
    if(n==1)
    {
        printf("X");
        return;
    }
    for(i=0;k>sum;i++)
    {
        sum+=catalan[i]*catalan[n-i-1];
    }
    --i;
    sum-=catalan[i]*catalan[n-i-1];
    k-=sum;
    if(i)
    {
        printf("(");
        output(i,(k-1)/catalan[n-i-1]+1);
        printf(")");
    }
    printf("X");
    if(n-i-1)
    {
        printf("(");
        output(n-i-1,(k-1)%catalan[n-i-1]+1);
        printf(")");
    }
}


int main()
{
    long long n,i,sum;
    while(scanf("%lld",&n),n)
    {
        sum=0; 
        for(i=1;n>sum;i++)
        {
            sum+=catalan[i];
        }
        i--;
        output(i,n-sum+catalan[i]);
        printf("\n");
    }
    return 0;
} 
