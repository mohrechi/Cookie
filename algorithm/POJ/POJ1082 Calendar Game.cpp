#include<iostream>
using namespace std;

int main()
{
    int t,y,m,d,a;
    cin>>t;
    while(t--)
    {
        cin>>y>>m>>d;
        a=0;
        if((m+d)&1) a=1;
        if(d==30 && (m==9 || m==11)) a=0;
        if(a)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
