#include<iostream>
using namespace std;

int a[105][105],b[105][105],m,n;

int ds(int x,int y)
{
    if(b[x][y]) return b[x][y];
    int num(0);
    if(a[x][y]>a[x-1][y])
    {
        int temp=ds(x-1,y);
        num=num>temp?num:temp;
    }
    if(a[x][y]>a[x+1][y])
    {
        int temp=ds(x+1,y);
        num=num>temp?num:temp;
    }
    if(a[x][y]>a[x][y-1])
    {
        int temp=ds(x,y-1);
        num=num>temp?num:temp;
    }
    if(a[x][y]>a[x][y+1])
    {
        int temp=ds(x,y+1);
        num=num>temp?num:temp;
    }
    return b[x][y]=num+1;
}

int main(int argc, char* argv[])
{
	cin>>m>>n;
	m++, n++;
	for(int i=0;i<=m;i++)
	{
	    for(int j=0;j<=n;j++)
	    {
	        a[i][j]=2100000000;
	        b[i][j]=0;
	    }
	}
	m--, n--;
	for(int i=1;i<=m;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	        cin>>a[i][j];
	    }
	}
	for(int i=1;i<=m;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	        ds(i,j);
	    }
	}
	int max=0;
	for(int i=1;i<=m;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	        if(b[i][j]>max)
	        {
	            max=b[i][j];
	        }
	    }
	}
	cout<<max<<endl;
	return 0;
}
