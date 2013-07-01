#include <iostream>
using namespace std;

long humble[5843];

int min(int a, int b)
{
    return a<b?a:b;
}

int min(int a, int b, int c, int d)
{
    return min(min(a,b),min(c,d));
}

int main(int argc, char *argv[])
{
	int fact[4]={1,1,1,1};
	int mul[4]={2,3,5,7};
	long hum[4];
	humble[1]=1;
	for(int i=2;i<5843;i++)
	{
	    for(int j=0;j<4;j++)
	    {
	        hum[j]=mul[j]*humble[fact[j]];
	    }
	    humble[i]=min(hum[0],hum[1],hum[2],hum[3]);
	    for(int j=0;j<4;j++)
	    {
	        if(humble[i]==hum[j])
	        {
	            fact[j]++;
	        }
	    }
	}
	int n;
	while(cin>>n,n)
	{
	    cout<<"The "<<n;
	    if(n%100!=11 && n%10==1) cout<<"st";
	    else if(n%100!=12 && n%10==2) cout<<"nd";
	    else if(n%100!=13 && n%10==3) cout<<"rd";
	    else cout<<"th";
	    cout<<" humble number is "<<humble[n]<<"."<<endl;
	}
	return 0;
}
