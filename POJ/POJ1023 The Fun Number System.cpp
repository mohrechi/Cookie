#include<iostream>
using namespace std;

int main()
{
    char sign[100];
    int ans[100], len, t;
    long long target;
    cin>>t;
    while(t--)
    {
        cin>>len>>sign>>target;
        for(int i=0;i<len;i++)
        {
            ans[i]=target&1;
            target-=ans[i]*(sign[len-i-1]=='p'?1:-1);
            target>>=1;
        }
        if(target)
        {
            cout<<"Impossible"<<endl;
        }
        else
        {
            for(int i=len-1;i>=0;i--)
            {
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
