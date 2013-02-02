#include<iostream>
using namespace std;

int n,a[30];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]&1)
            {
                if(i&1) x++;
                else y++;
            }
        }
        if(n&1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            x-=y;
            if(x<0)x=-x;
            if(x<=1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
