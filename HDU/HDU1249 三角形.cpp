#include<iostream>
using namespace std;

int a[10005]={0,2,8};
int main()
{
    for(int i=3;i<=10000;++i)
    {
        a[i]=a[i-1]+6*(i-1);
    }
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}
