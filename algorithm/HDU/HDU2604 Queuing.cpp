#include <iostream>
using namespace std;

char a[5]={0,2,4,6,9},b[31][1000001];

int main(int argc, char *argv[])
{
    b[1][0]=0;
	for(int i=2;i<=30;i++)
	{
	    for(int j=1;j<=4;j++)
	    {
	        b[i][j]=a[j]%i;
	    }
	}
	for(int i=2;i<=30;i++)
	{
	    for(int j=5;j<=1000000;j++)
	    {
	        b[i][j]=(b[i][j-1]+b[i][j-3]+b[i][j-4])%i;
	    }
	}
	int n,m;
	while(cin>>n>>m)
	{
	    cout<<(int)b[m][n]<<endl;
	}
	return 0;
}
