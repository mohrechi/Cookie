#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 50000 + 10;
const int MAXM = 150000 + 10;
const int MAXQ = 250000 + 10;
const int SQRT = sqrt(MAXM);

int cnt[MAXN];
bool on[MAXN], isHeavy[MAXN];
vector<int> heavy[MAXN], edge[MAXN];

void login(int u)
{
    on[u] = true;
    if (!isHeavy[u])
    {
        for (auto v = edge[u].begin(); v != edge[u].end(); ++v)
        {
            ++cnt[*v];
        }
    }
}

void logout(int u)
{
    on[u] = false;
    if (!isHeavy[u])
    {
        for (auto v = edge[u].begin(); v != edge[u].end(); ++v)
        {
            --cnt[*v];
        }
    }
}

void addFriend(int u, int v)
{
    if (!isHeavy[u] && edge[u].size() >= SQRT)
    {
        for (auto v = edge[u].begin(); v != edge[u].end(); ++v)
        {
            heavy[*v].push_back(u);
            cnt[*v] -= on[u];
        }
        isHeavy[u] = true;
    }
    edge[u].push_back(v);
    if (isHeavy[u])
    {
        heavy[v].push_back(u);
    }
    else
    {
        cnt[v] += on[u];
    }
}

void delFriend(int u, int v)
{
    for (auto i = edge[v].begin(); i != edge[v].end(); ++i)
    {
        if (*i == u)
        {
            edge[v].erase(i);
            break;
        }
    }
    if (isHeavy[u])
    {
        for (auto i = heavy[v].begin(); i != heavy[v].end(); ++i)
        {
            if (*i == u)
            {
                heavy[v].erase(i);
                break;
            }
        }
    }
    else
    {
        cnt[v] -= on[u];
    }
}

int countOnlineFriends(int u)
{
    int ans = cnt[u];
    for (auto v = heavy[u].begin(); v != heavy[u].end(); ++v)
    {
        ans += on[*v];
    }
    return ans;
}

int main()
{
    int n, m, q, o, u, v;
    char op[2];
    scanf("%d%d%d", &n, &m, &q);
    scanf("%d", &o);
    while (o--)
    {
        scanf("%d", &u);
        on[u] = true;
    }
    while (m--)
    {
        scanf("%d%d", &u, &v);
        addFriend(u, v);
        addFriend(v, u);
    }
    while (q--)
    {
        scanf("%s%d", op, &u);
        switch (*op)
        {
        case 'O':
            login(u);
            break;
        case 'F':
            logout(u);
            break;
        case 'A':
            scanf("%d", &v);
            addFriend(u, v);
            addFriend(v, u);
            break;
        case 'D':
            scanf("%d", &v);
            delFriend(u, v);
            delFriend(v, u);
            break;
        case 'C':
            printf("%d\n", countOnlineFriends(u));
            break;
        }
    }
    return 0;
}
