#include <iostream>
#include <cmath>
using namespace std;

int n,maxValue,value[105],num[105],cnt,dp[100005];

void completePack(int value, int weight)
{
    for(int i=value;i<=maxValue;i++)
    {
        dp[i]=max(dp[i],dp[i-value]+weight);
    }
}

void zeroOnePack(int value, int weight)
{
    for(int i=maxValue;i>=value;i--)
    {
        dp[i]=max(dp[i],dp[i-value]+weight);
    }
}

void multiplePack(int value, int weight, int number)
{
    if(value*number>maxValue)
    {
        completePack(value,weight);
    }
    else
    {
        int i=1;
        while(number>i)
        {
            zeroOnePack(value*i, weight*i);
            number-=i;
            i<<=1;
        }
        zeroOnePack(value*number, weight*number);
    }
}

int main(int argc, char *argv[])
{
	while(cin>>n>>maxValue,n||maxValue)
	{
	    for(int i=0;i<n;i++)
	    {
	        cin>>value[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>num[i];
	    }
	    for(int i=0;i<=maxValue;i++)
	    {
	        dp[i]=0;
	    }
	    for(int i=0;i<n;i++)
	    {
	        multiplePack(value[i],value[i],num[i]);
	    }
	    cnt=0;
	    for(int i=1;i<=maxValue;i++)
	    {
	        if(dp[i]==i)
	        {
	            ++cnt;
	        }
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}
