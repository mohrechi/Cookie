#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(0==b) return a;
    return gcd(b,a%b);
}

int main()
{
    int t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        if(1==gcd(n,m)) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
