#include <cstdio>
#include <iostream>
using namespace std;

int a[10005];
int b[100005];
int main()
{
    int n,m,x,y;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;++i)
        {
            a[i] = 0;
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&x,&y);
            b[i] = x;
            ++a[x];
        }
        long long ans = 0;
        for(int i=0;i<m;++i)
        {
            ans += a[b[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
