#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	long long a[40][40];
	memset(a,0,sizeof(a));
	for(int i=0;i<36;i++)
	{
	    a[i][0]=a[0][i]=1;
	}
	for(int i=1;i<36;i++)
	{
	    for(int j=1;j<36;j++)
	    {
	        if(i==j)
	        {
	            a[i][j]=a[i-1][j];
            }
            else
            {
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
	    }
	}
	int n,count=0;
	while(cin>>n,n+1)
	{
	    cout<<++count<<" "<<n<<" "<<2*a[n][n]<<endl;
	}
	return 0;
}
