#include<iostream>
using namespace std;

int main()
{
    int l,m,a,b,ans;
    while(cin>>l>>m, l||m)
    {
        ans=l+1;
        while(m--)
        {
            cin>>a>>b;
            ans-=b-a+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
