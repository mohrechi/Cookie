#include <iostream>
using namespace std;

const int INF=1000000000;
int a[100005],b[100005],c[100005];

int main(int argc, char *argv[])
{
	int t,n,max,s,e,temp;
	bool flag=true;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
	    cin>>n;
	    max=-INF;
	    b[0]=0,c[0]=1;
	    for(int i=1;i<=n;i++)
	    {
	        cin>>a[i];
            if(b[i-1]>=0)
            {
                b[i]=a[i]+b[i-1];
                c[i]=c[i-1];
            }
            else
            {
                b[i]=a[i];
                c[i]=i;
            }
            if(b[i]>max)
            {
                max=b[i];
                s=c[i],e=i;
            }
	    }
	    if(flag)
	    {
	        flag=false;
	    }
	    else
	    {
	        cout<<endl;
	    }
	    cout<<"Case "<<k<<":"<<endl;
	    cout<<max<<" "<<s<<" "<<e<<endl;
	}
	return 0;
}
