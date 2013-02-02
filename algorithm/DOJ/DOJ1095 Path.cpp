#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int r[205][205];
bool v[205], f;
int w[205][205], c[205][205];
int n,m;
int s;

bool find(int x, int color, int weight)
{
    if(x == n)
    {
        f = 1;
        if(weight < s)
        {
            s = weight;
            if(s==1) return 1;
        }
    }
    if(weight >= s)
    {
        return 0;
    }
    for(int i=1;i<=r[x][0];++i)
    {
        if(!v[r[x][i]] && c[x][i]!=color)
        {
            v[r[x][i]] = 1;
            if(find(r[x][i], c[x][i], weight+w[x][i])) return 1;
            v[r[x][i]] = 0;
        }
    }
    return 0;
}

int main()
{
    while(cin>>n>>m)
    {
        int a1,a2,a3,a4;
        memset(r, 0, sizeof(r));
        memset(v, 0, sizeof(v));
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
            r[a1][0]++;
            r[a1][r[a1][0]] = a2;
            w[a1][r[a1][0]] = a3;
            c[a1][r[a1][0]] = a4;
        }
        s = 500, f = 0;
        v[1] = 1;
        find(1,0,0);
        if(f) cout<<s<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
