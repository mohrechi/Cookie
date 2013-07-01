#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int n,candy[1000],temp[1000],min,max;
	while(cin>>n,n)
	{
	    min=2100000000,max=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>candy[i];
	        if(candy[i]<min) min=candy[i];
	        if(candy[i]>max) max=candy[i];
	    }
	    int count=0;
	    while(min<max)
	    {
	        for(int i=0;i<n;i++)
	        {
	            temp[i]=candy[i]/2;
	        }
	        candy[0]+=temp[n-1]-temp[0];
	        if(candy[0]%2==1)
            {
                candy[0]++;
            }
            max=candy[0],min=candy[0];
	        for(int i=1;i<n;i++)
	        {
	            candy[i]+=temp[i-1]-temp[i];
	            if(candy[i]%2==1)
	            {
	                candy[i]++;
	            }
	            if(candy[i]<min) min=candy[i];
	            if(candy[i]>max) max=candy[i];
	        }
	        count++;
	    }
	    cout<<count<<" "<<max<<endl;
	}
	return 0;
}
