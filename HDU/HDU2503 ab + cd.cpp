#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

int main(int argc, char *argv[])
{
	int t,a,b,c,d,x;
	cin>>t;
	while(t--)
	{
	    cin>>a>>b>>c>>d;
	    a=a*d+c*b;
	    b=b*d;
	    x=gcd(a,b);
	    a/=x, b/=x;
	    cout<<a<<" "<<b<<endl;
	}
	return 0;
}
