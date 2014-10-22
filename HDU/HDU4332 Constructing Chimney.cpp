#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 300;
const unsigned __int64 MOD = 1000000007LL;
const unsigned __int64 MODD = MOD * 4LL;

int set[MAXN][4];
int setNum[MAXN];
int sca[MAXN], scaNum;
int map[MAXN], mapNum[MAXN];
bool visit[MAXN];
unsigned __int64 md[MAXN][MAXN];
unsigned __int64 mres[MAXN][MAXN];
unsigned __int64 mbit[30][MAXN][MAXN];
unsigned __int64 mtmp[MAXN][MAXN];

inline bool isBitZero(const int &x, const int &bit)
{
    return (x & (1<<bit)) == 0;
}

inline bool isBitOne(const int &x, const int &bit)
{
    return (x & (1<<bit)) > 0;
}

inline void setBit(int &x, const int &bit)
{
    x |= (1<<bit);
}

inline void clrBit(int &x, const int &bit)
{
    x &= ~(1<<bit);
}

void dfs(int origin, int state, int index)
{
    ++ md[map[origin]][map[(~state)&255]];
    if(index <= 0 && isBitZero(state, 0))
    {
        if(isBitZero(state, 1))
        {
            setBit(state, 0);
            setBit(state, 1);
            dfs(origin, state, 2);
            clrBit(state, 0);
            clrBit(state, 1);
        }
        if(isBitZero(state, 7))
        {
            setBit(state, 0);
            setBit(state, 7);
            dfs(origin, state, 2);
            clrBit(state, 0);
            clrBit(state, 7);
        }
    }
    if(index <= 2 && isBitZero(state, 2))
    {
        if(isBitZero(state, 1))
        {
            setBit(state, 2);
            setBit(state, 1);
            dfs(origin, state, 4);
            clrBit(state, 2);
            clrBit(state, 1);
        }
        if(isBitZero(state, 3))
        {
            setBit(state, 2);
            setBit(state, 3);
            dfs(origin, state, 4);
            clrBit(state, 2);
            clrBit(state, 3);
        }
    }
    if(index <= 4 && isBitZero(state, 4))
    {
        if(isBitZero(state, 5))
        {
            setBit(state, 4);
            setBit(state, 5);
            dfs(origin, state, 6);
            clrBit(state, 4);
            clrBit(state, 5);
        }
        if(isBitZero(state, 3))
        {
            setBit(state, 4);
            setBit(state, 3);
            dfs(origin, state, 6);
            clrBit(state, 4);
            clrBit(state, 3);
        }
    }
    if(index <= 6 && isBitZero(state, 6))
    {
        if(isBitZero(state, 5))
        {
            setBit(state, 6);
            setBit(state, 5);
            dfs(origin, state, 8);
            clrBit(state, 6);
            clrBit(state, 5);
        }
        if(isBitZero(state, 7))
        {
            setBit(state, 6);
            setBit(state, 7);
            dfs(origin, state, 8);
            clrBit(state, 6);
            clrBit(state, 7);
        }
    }
}

inline void matrixMultiply(unsigned __int64 c[MAXN][MAXN], unsigned __int64 a[MAXN][MAXN], unsigned __int64 b[MAXN][MAXN])
{
    for(int i=0;i<scaNum;++i)
    {
        for(int j=i;j<scaNum;++j)
        {
            c[i][j] = 0;
        }
    }
    for(int i=0;i<scaNum;++i)
    {
        for(int k=0;k<scaNum;++k)
        {
            if(a[i][k])
            {
                for(int j=i;j<scaNum;++j)
                {
                    if(b[k][j])
                    {
                        c[i][j] += a[i][k] * b[k][j] / mapNum[k];
                        c[i][j] %= MODD;
                    }
                }
            }
        }
    }
    for(int i=0;i<scaNum;++i)
    {
        for(int j=0;j<i;++j)
        {
            c[i][j] = c[j][i];
        }
    }
}

inline int rotateRight(int x)
{
    if(isBitOne(x, 0))
    {
        x >>= 1;
        setBit(x, 7);
    }
    else
    {
        x >>= 1;
    }
    return x;
}

void addRelation(int x, int origin)
{
    for(int i=0;i<setNum[x];++i)
    {
        if(set[x][i] == origin)
        {
            return;
        }
    }
    set[x][setNum[x]++] = origin;
    if(set[x][0] > set[x][setNum[x]-1])
    {
        swap(set[x][0], set[x][setNum[x]-1]);
    }
}

void getRelation()
{
    for(int i=0;i<256;++i)
    {
        setNum[i] = 0;
        visit[i] = false;
    }
    for(int i=0;i<256;++i)
    {
        int x = i;
        for(int j=0;j<3;++j)
        {
            addRelation(x, i);
            x = rotateRight(x);
            x = rotateRight(x);
        }
        addRelation(x, i);
    }
    scaNum = 0;
    for(int i=0;i<256;++i)
    {
        if(!visit[i])
        {
            sca[scaNum] = set[i][0];
            for(int j=0;j<setNum[i];++j)
            {
                visit[set[i][j]] = true;
                map[set[i][j]] = scaNum;
            }
            mapNum[scaNum] = setNum[i];
            ++ scaNum;
        }
    }
}

void init()
{
    getRelation();
    for(int i=0;i<scaNum;++i)
    {
        for(int j=0;j<scaNum;++j)
        {
            md[i][j] = 0;
        }
    }
    for(int i=0;i<256;++i)
    {
        dfs(i, i, 0);
    }
    for(int i=0;i<scaNum;++i)
    {
        for(int j=0;j<scaNum;++j)
        {
            mbit[0][i][j] = md[i][j];
        }
    }
    for(int i=1;i<30;++i)
    {
        matrixMultiply(mbit[i], mbit[i-1], mbit[i-1]);
    }
}

__int64 getValue(int n)
{
    for(int i=0;i<scaNum;++i)
    {
        for(int j=0;j<scaNum;++j)
        {
            mres[i][j] = 0;
        }
        mres[i][i] = 1;
    }
    for(int i=0;i<30;++i)
    {
        if(n & (1 << i))
        {
            matrixMultiply(mtmp, mres, mbit[i]);
            for(int j=0;j<scaNum;++j)
            {
                for(int k=0;k<scaNum;++k)
                {
                    mres[j][k] = mtmp[j][k];
                }
            }
        }
    }
    return mres[0][0] % MOD;
}

int main()
{
    int caseNumber;
    init();
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %I64u\n", cas, getValue(n));
    }
    return 0;
}
