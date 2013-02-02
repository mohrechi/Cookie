#include<math.h>
#include<iostream>
using namespace std;

long long n,m,num[20],factor[120000],factorNum,shared,share[120000];

void getShared(long long start, long long current, long long max)
{
   long long get=m;
   if(current==max)
   {
       for(long long i=0;i<max;i++)
       {
           get/=share[i];
       }
       long long ans=1, tn=n;
        while(tn--)
        {
            ans*=get;
        }
       shared+=ans;
   }
   else
   {
       for(long long i=start;i<factorNum;i++)
       {
           share[current]=factor[i];
           getShared(i+1,current+1,max);
       }
   }
}

int main()
{
    cin>>n>>m;
    long long tm=m;
    factorNum=0;
    while(0==(tm&1))
    {
        tm/=2;
    }
    if(tm!=m)
    {
        factor[factorNum++]=2;
    }
    for(int i=3;i*i<=tm;i+=2)
    {
        if(0==tm%i)
        {
            while(0==tm%i)
            {
                tm/=i;
            }
            factor[factorNum++]=i;
        }
    }
    if(1!=tm)
    {
        factor[factorNum++]=tm;
    }
    long long ans=1;
    long long tn=n;
    while(tn--)
    {
        ans*=m;
    }
    for(int i=0;i<factorNum;i++)
    {
        shared=0;
        getShared(0,0,i+1);
        if(i&1)
        {
            ans+=shared;
        }
        else
        {
            ans-=shared;
        }
    }
    cout<<ans<<endl;
    return 0;
}
