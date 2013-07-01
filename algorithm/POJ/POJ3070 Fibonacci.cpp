#include <iostream>
#include <memory.h>
using namespace std;
#define MOD 10000

int fibonacci(int n)
{
    int a[2][2]={{1,1},{1,0}};
    int b[2][2]={{1,1},{1,0}};
    int c[2][2];
    for(int i=1;i<=n;i<<=1)
    {
        if(n&i)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    c[j][k] = 0;
                }
            }
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    for(int l=0;l<2;l++)
                    {
                        c[j][k] += a[j][l] * b[l][k];
                    }
                }
            }
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    b[j][k] = c[j][k] % MOD;
                }
            }
        }
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                c[j][k] = 0;
            }
        }
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                for(int l=0;l<2;l++)
                {
                    c[j][k] += a[j][l] * a[l][k];
                }
            }
        }
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                a[j][k] = c[j][k] % MOD;
            }
        }
    }
    return b[0][0];
}

int main(int argc, char *argv[])
{
	int n;
	while(cin>>n,n+1)
	{
	    if(n==0) cout<<0<<endl;
	    else if(n==1) cout<<1<<endl;
	    else cout<<fibonacci(n-2)<<endl;
	}
	return 0;
}
