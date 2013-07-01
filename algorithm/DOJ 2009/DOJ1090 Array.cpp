#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, i, a[10];
    while(cin>>n)
    {
        for(i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a, a+n);
        for(i=1;i<n;++i)
        {
            if(a[i] - a[i-1] != 1)
            {
                break;
            }
        }
        if(i==n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
