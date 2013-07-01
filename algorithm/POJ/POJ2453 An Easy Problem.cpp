#include<iostream>
using namespace std;

int main()
{
    int n,s,e;
    while(cin>>n,n)
    {
        for(s=1;!(s&n);s<<=1);
        for(e=s,s=1;e&n;e<<=1,s<<=1);
        n|=e;
        n=n-(n&(e-1));
        n|=((s>>1)-1);
        cout<<n<<endl;
    }
    return 0;
}
