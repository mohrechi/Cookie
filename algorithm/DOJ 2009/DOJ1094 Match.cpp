#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool r[17][17];
bool v[17];
int n,m;
int match[17];

bool find(int x)
{
    for(int i=1;i<=n;++i)
    {
        if(r[x][i] && !v[i])
        {
            v[i] = 1;
            if(!match[i] || find(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int x,y;
    while(cin>>n>>m)
    {
        memset(r, 0, sizeof(r));
        memset(match, 0, sizeof(match));
        for(int i=0;i<m;++i)
        {
            cin>>x>>y;
            r[x][y] = r[y][x] = 1;
        }
        int ans = 0;
        for(int i=1;i<=n;++i)
        {
            memset(v, 0, sizeof(v));
            if(find(i))
            {
                ++ans;
            }
        }
        if(ans == n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
