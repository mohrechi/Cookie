#include <cstdio>
#include <cstring>
const int MAXR = 20;
const int MAXC = 310;
const int MAXN = MAXR * MAXC + MAXC;
const int INF = MAXR * 10;

int n, m;
int L[MAXN], R[MAXN], U[MAXN], D[MAXN];
int C[MAXN], O[MAXN], S[MAXN], H[MAXR];
int nodeNumber;

void init()
{
    for(int i=0;i<=m;++i)
    {
        L[i] = i - 1;
        R[i] = i + 1;
        U[i] = i;
        D[i] = i;
        C[i] = i;
        O[i] = 0;
        S[i] = 0;
    }
    L[0] = m;
    R[m] = 0;
    nodeNumber = m + 1;
    memset(H, 0, sizeof(H));
}

void insert(int i, int j)
{
    if(H[i])
    {
        L[nodeNumber] = L[H[i]];
        R[nodeNumber] = H[i];
        L[R[nodeNumber]] = nodeNumber;
        R[L[nodeNumber]] = nodeNumber;
    }
    else
    {
        L[nodeNumber] = nodeNumber;
        R[nodeNumber] = nodeNumber;
        H[i] = nodeNumber;
    }
    U[nodeNumber] = U[j];
    D[nodeNumber] = j;
    U[D[nodeNumber]] = nodeNumber;
    D[U[nodeNumber]] = nodeNumber;
    C[nodeNumber] = j;
    O[nodeNumber] = i;
    ++ S[j];
    ++ nodeNumber;
}

void remove(int c)
{
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for(int i=D[c];i!=c;i=D[i])
    {
        for(int j=R[i];j!=i;j=R[j])
        {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            -- S[C[j]];
        }
    }
}

void resume(int c)
{
    for(int i=U[c];i!=c;i=U[i])
    {
        for(int j=L[i];j!=i;j=L[j])
        {
            ++ S[C[j]];
            D[U[j]] = j;
            U[D[j]] = j;
        }
    }
    R[L[c]] = c;
    L[R[c]] = c;
}

bool dfs(int k)
{
    if(!R[0])
    {
        return true;
    }
    int count = INF, c;
    for(int i=R[0];i;i=R[i])
    {
        if(S[i] < count)
        {
            count = S[i];
            c = i;
            if(1 == count)
            {
                break;
            }
        }
    }
    remove(c);
    for(int i=D[c];i!=c;i=D[i])
    {
        for(int j=R[i];j!=i;j=R[j])
        {
            remove(C[j]);
        }
        if(dfs(k+1))
        {
            return true;
        }
        for(int j=L[i];j!=i;j=L[j])
        {
            resume(C[j]);
        }
    }
    resume(c);
    return false;
}

int main()
{
    int t;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%d", &t);
                if(t)
                {
                    insert(i, j);
                }
            }
        }
        bool flag = true;
        for(int i=1;i<=m;++i)
        {
            if(S[i] == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag && dfs(0))
        {
            printf("Yes, I found it\n");
        }
        else
        {
            printf("It is impossible\n");
        }
    }
    return 0;
}
