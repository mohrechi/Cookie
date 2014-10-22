#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50005;

int n;
int a[MAXN];
int loopL[MAXN];
int loopR[MAXN];
int singleL[MAXN];
int singleR[MAXN];
int sumL[MAXN];
int sumR[MAXN];

struct SparseTable
{
    int n;
    int data[MAXN][16];
    int log2[MAXN];
    void init()
    {
        for (int i = 2; i < MAXN; ++i)
        {
            log2[i] = log2[i - 1];
            if ((i & (i - 1)) == 0)
            {
                ++log2[i];
            }
        }
    }
    inline void setData(const int &pos, const int &value)
    {
        data[pos][0] = value;
    }
    void build()
    {
        for (int j = 1; (1 << j) <= n; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                data[i][j] = max(data[i][j - 1], data[min(n - 1, i + (1 << (j - 1)))][j - 1]);
            }
        }
    }
    int query(int l, int r)
    {
        int len = r - l + 1;
        int k = log2[len];
        return max(data[l][k], data[r - (1 << k) + 1][k]);
    }
} sparseL, sparseR;

int main()
{
    sparseL.init();
    sparseR.init();
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    loopL[1] = singleL[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        int num = a[i - 1];
        if (num == 1)
        {
            loopL[i] = 0;
            singleL[i] = singleL[i - 1] + 1;
        }
        else if (num & 1)
        {
            loopL[i] = loopL[i - 1] + num - 1;
            singleL[i] = singleL[i - 1] + num;
        }
        else
        {
            loopL[i] = loopL[i - 1] + num;
            singleL[i] = singleL[i - 1] + num - 1;
        }
    }
    loopR[n] = singleR[n] = 0;
    for (int i = n - 1; i >= 1; --i)
    {
        int num = a[i];
        if (num == 1)
        {
            loopR[i] = 0;
            singleR[i] = singleR[i + 1] + 1;
        }
        else if (num & 1)
        {
            loopR[i] = loopR[i + 1] + num - 1;
            singleR[i] = singleR[i + 1] + num;
        }
        else
        {
            loopR[i] = loopR[i + 1] + num;
            singleR[i] = singleR[i + 1] + num - 1;
        }
    }
    sparseL.n = n;
    sparseR.n = n;
    for (int i = 1; i <= n; ++i)
    {
        sumL[i] = loopL[i] + singleR[i];
        sumR[i] = singleL[i] + loopR[i];
        sparseL.setData(i - 1, sumL[i]);
        sparseR.setData(i - 1, sumR[i]);
    }
    sparseL.build();
    sparseR.build();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, loopL[i] + sparseR.query(i - 1, n - 1) - singleL[i]);
        ans = max(ans, loopR[i] + sparseL.query(0, i - 1) - singleR[i]);
    }
    printf("%d\n", ans);
    return 0;
}
