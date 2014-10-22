#include<iostream>
#include<cmath>
using namespace std;

inline int min(int x, int y)
{
    return x<y?x:y;
}

int main()
{
    int n,v,t,m;
    while(cin>>n,n)
    {
        m=0x7FFFFFFF;
        while(n--)
        {
            cin>>v>>t;
            if(t>=0)
            {
                m=min(m,t+ceil(4500*3.6/v));
            }
        }
        cout<<m<<endl;
    }
    return 0;
}
