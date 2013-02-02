#include<iostream>
using namespace std;
long long A , B , C , K;
long long extended_cuclid(long long a , long long b , long long &x , long long &y)
{
    if(b==0)
    {
        x=1 , y=0;
        return a;
    }
    else
    {
        long long res =  extended_cuclid(b , a%b , x ,y);
        long long t = x; x=y; y = t-(a/b)*y;
        return res;
    }
}

long long equation(long long a , long long b ,long long n)
{
    long long d , x , y , e;
    d = extended_cuclid(a , n , x , y);
    if(b%d!=0) return -1;
    e=x*(b/d)%n+n;
    return e%(n/d);
}

int main()
{
    while(cin>>A>>B>>C>>K && (A!=0 || B!=0 || C!=0 || K!=0))
    {
        long long p = equation(C , B-A , 1LL<<K);
        if(p==-1)cout<<"FOREVER"<<endl;
        else cout<<p<<endl;
    }
    return 0;
}
