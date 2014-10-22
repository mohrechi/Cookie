#include <cstdio>
#include <cstring>
static const int MAXN = 500;

int n, m;
bool map[MAXN][MAXN];
bool visited[MAXN];
int ans[MAXN], ansNumber;

bool input()
{
    int a, b;
    scanf("%d%d", &n, &m);
    n <<= 1;
    memset(map, true, sizeof(map));
    for(int i=0;i<m;++i)
    {
        scanf("%d%d", &a, &b);
        map[a][b] = map[b][a] = false;
    }
    return n!=0 || m!=0;
}

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

void reverse(int s, int v)
{
    while(s < v)
    {
        swap(ans[s++], ans[v--]);
    }
}

void solve()
{
    ansNumber = 0;
    for(int i=1;i<=n;++i)
    {
        map[i][i] = false;
    }
    memset(visited, false, sizeof(visited));
    int u = 1, v;
    for(v=2;v<=n;++v)
    {
        if(map[u][v])
        {
            break;
        }
    }
    visited[u] = visited[v] = true;
    ans[ansNumber++] = u;
    ans[ansNumber++] = v;
    while(true)
    {
        while(true)
        {
            int i;
            for(i=1;i<=n;++i)
            {
                if(map[v][i] && !visited[i])
                {
                    ans[ansNumber++] = i;
                    visited[i] = true;
                    v = i;
                    break;
                }
            }
            if(i > n)
            {
                break;
            }
        }
        reverse(0, ansNumber - 1);
        swap(u, v);
        while(true)
        {
            int i;
            for(i=1;i<=n;++i)
            {
                if(map[v][i] && !visited[i])
                {
                    ans[ansNumber++] = i;
                    visited[i] = true;
                    v = i;
                    break;
                }
            }
            if(i > n)
            {
                break;
            }
        }
        if(!map[u][v])
        {
            int i;
            for(i=1;i<ansNumber-2;++i)
            {
                if(map[ans[i]][v] && map[ans[i+1]][u])
                {
                    break;
                }
            }
            v = ans[i+1];
            reverse(i+1, ansNumber-1);
        }
        if(ansNumber == n)
        {
            break;
        }
        int i, j;
        for(i=1;i<=n;++i)
        {
            if(!visited[i])
            {
                for(j=1;j<ansNumber-1;++j)
                {
                    if(map[i][ans[j]])
                    {
                        u = ans[j-1];
                        v = i;
                        reverse(0, j-1);
                        reverse(j, ansNumber-1);
                        ans[ansNumber++] = i;
                        visited[i] = true;
                        break;
                    }
                }
                if(map[i][ans[j]])
                {
                    break;
                }
            }
        }
    }
}

void output()
{
    printf("%d", ans[0]);
    for(int i=1;i<ansNumber;++i)
    {
        printf(" %d", ans[i]);
    }
    printf("\n");
}

int main()
{
    while(input())
    {
        solve();
        output();
    }
    return 0;
}
