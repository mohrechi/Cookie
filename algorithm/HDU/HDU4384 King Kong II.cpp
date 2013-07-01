#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int MAXINT = -1u>>1;
const int MAXN = 50000 + 50;

int sta;
__int64 minele,res;
int arru[MAXN], arrd[MAXN];
set< pair<int,int> > up,down;
set< int > vis;
int cir[MAXN];
bool ff[MAXN];

void dfs(const int &i,const int &pos)
{
    cir[sta] = arru[pos];
    if (vis.find(arru[pos]) == vis.end())
    {
        vis.insert(arru[pos]);
    }
    else
    {
        __int64 tmp = cir[sta],minm = cir[sta];
        __int64 cnt = 1;
        sta--;
        while(cir[sta] != arru[pos] && sta > 0)
        {
            set< int > :: iterator it = vis.find(cir[sta]);
            vis.erase(it);
            minm = min(minm, (__int64)cir[sta]);
            tmp += cir[sta];
            cnt++;
            sta--;
        }
        if (cnt >= 2)
        {
            res += tmp + min(minm * (cnt - 2),minele * (cnt + 1) + minm);
        }
        return;
    }
    int nextval = arrd[pos];
    set<pair <int,int> > :: iterator it = up.lower_bound(make_pair(nextval,-1));
    while(it != up.end())
    {
        int nextpos = it->second;
        ff[nextpos] = true;
        up.erase(it);
        sta++;
        dfs(i + 1,nextpos);
        if (i >= sta) return;
        it = up.lower_bound(make_pair(nextval,-1));
    }
}

int main()
{
    int N, ca = 0;
    while(scanf("%d",&N) == 1 && N)
    {
        printf("Case %d: ", ++ca);
        res = 0;
        memset(ff,false,sizeof(ff));
        minele = MAXINT;
        up.clear();
        down.clear();
        vis.clear();
        for(int i = 0 ; i < N ; i++)
        {
            scanf("%d",&arru[i]);
            up.insert(make_pair(arru[i],i));
            minele = min((__int64)arru[i],minele);
        }
        for(int i = 0 ; i < N ; i++)
        {
            scanf("%d",&arrd[i]);
            down.insert(make_pair(arrd[i],i));
        }
        for(int i = 0 ; i < N ; i++)
        {
            if (!ff[i])
            {
                sta = 0;
                vis.clear();
                ff[i] = true;
                dfs(0,i);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
