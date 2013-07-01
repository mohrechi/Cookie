#include <cstdio>
#include <cstring>
const int SIZE = 3;
const int DIMENSION = 9;
const int DIMENSION2 = DIMENSION * DIMENSION;
const int DIMENSION3 = DIMENSION2 * DIMENSION;
const int ROW_NUM = DIMENSION3;
const int COL_NUM = (DIMENSION + DIMENSION + DIMENSION) * DIMENSION + DIMENSION2;
const int MAXN = ROW_NUM * COL_NUM + COL_NUM + 100;
const int MAXR = ROW_NUM + 10;
const int INF = ROW_NUM * 100;

int n, m;
int L[MAXN], R[MAXN], U[MAXN], D[MAXN];
int C[MAXN], O[MAXN], S[MAXN], H[MAXR];
int record[MAXR], ans[MAXR];
int nodeNumber, recordNumber;

void init()
{
    for(int i=0;i<=COL_NUM;++i)
    {
        L[i] = i - 1;
        R[i] = i + 1;
        U[i] = i;
        D[i] = i;
        C[i] = i;
        O[i] = 0;
        S[i] = 0;
    }
    L[0] = COL_NUM;
    R[COL_NUM] = 0;
    nodeNumber = COL_NUM + 1;
    recordNumber = 0;
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
        recordNumber = k;
        return true;
    }
    int count = INF, c;
    for(int i=R[0];i;i=R[i])
    {
        if(S[i] < count)
        {
            count = S[i];
            c = i;
            if(count == 1)
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
        record[k] = O[i];
        if(dfs(k + 1))
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

char state[DIMENSION2 + 10];
char buffer[32][32];

bool input()
{
    for(int i=0;i<DIMENSION;++i)
    {
        scanf("%s", buffer[i]);
    }
    for(int i=0;i<DIMENSION;++i)
    {
        for(int j=0;j<DIMENSION;++j)
        {
            state[i * DIMENSION + j] = buffer[i][j] - '0';
        }
    }
    return true;
}

void add(int i, int j, int k)
{
    int row = i * DIMENSION2 + j * DIMENSION + k + 1;
    insert(row, i * DIMENSION + j + 1);
    insert(row, i * DIMENSION + k + DIMENSION2 + 1);
    insert(row, j * DIMENSION + k + DIMENSION2 * 2 + 1);
    insert(row, (i / SIZE * SIZE + j / SIZE) * DIMENSION + k + DIMENSION2 * 3 + 1);
}

void build()
{
    for(int i=0;i<DIMENSION;++i)
    {
        for(int j=0;j<DIMENSION;++j)
        {
            int pos = i * DIMENSION + j;
            if(state[pos])
            {
                add(i, j, state[pos] - 1);
            }
            else
            {
                for(int k=0;k<DIMENSION;++k)
                {
                    add(i, j, k);
                }
            }
        }
    }
}

void output()
{
    for(int i=0;i<recordNumber;++i)
    {
        ans[(record[i] - 1) / DIMENSION] = ((record[i] - 1) % DIMENSION) + 1;
    }
    for(int i=0;i<DIMENSION;++i)
    {
        for(int j=0;j<DIMENSION;++j)
        {
            printf("%c", ans[i * DIMENSION + j] + '0');
        }
        printf("\n");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        input();
        init();
        build();
        dfs(0);
        output();
    }
    return 0;
}
