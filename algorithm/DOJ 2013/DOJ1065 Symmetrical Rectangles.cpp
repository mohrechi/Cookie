#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2005;

int n, m;
int extend[MAXN][MAXN];
int horizon[MAXN][MAXN];
int verticle[MAXN][MAXN];
int num[MAXN][MAXN];

int str[MAXN];

void manacher(int p[MAXN], int n)
{
    int mx = 0;
    int id;
    for (int i = 0; i < n; ++i)
    {
        if (mx > i)
        {
            p[i] = min(p[(id << 1) - i], mx - i);
        }
        else
        {
            p[i] = 1;
        }
        for (; str[i + p[i]] == str[i - p[i]] && i - p[i] >= 0 && i + p[i] < n; ++p[i]);
        if (p[i] + i > mx)
        {
            mx = p[i] + i;
            id = i;
        }
    }
}

void printArray(int array[MAXN][MAXN])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

struct SparseTree
{
    int n;
    int data[MAXN][12];
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
                data[i][j] = min(data[i][j - 1], data[min(n - 1, i + (1 << (j - 1)))][j - 1]);
            }
        }
    }
    int query(int l, int r)
    {
        int len = r - l + 1;
        int k = log2[len];
        return min(data[l][k], data[r - (1 << k) + 1][k]);
    }
} st;

int main()
{
    scanf("%d%d", &n, &m);
    n = (n << 1) - 1;
    m = (m << 1) - 1;
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < m; j += 2)
        {
            scanf("%d", &extend[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            str[j] = extend[i][j];
        }
        manacher(horizon[i], m);
    }
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            str[i] = extend[i][j];
        }
        manacher(verticle[j], n);
    }
    int fit;
    st.init();
    st.n = m;
    memset(num, 0x3f, sizeof(num));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            st.setData(j, verticle[j][i]);
        }
        st.build();
        fit = 0;
        for (int j = 0; j < m; ++j)
        {
            while (st.query(fit, j) < j - fit + 1)
            {
                ++fit;
            }
            num[i][j] = min(num[i][j], j - fit + 1);
        }
        fit = m - 1;
        for (int j = m - 1; j >= 0; --j)
        {
            while (st.query(j, fit) < fit - j + 1)
            {
                --fit;
            }
            num[i][j] = min(num[i][j], fit - j + 1);
        }
    }
    st.n = n;
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            st.setData(i, horizon[i][j]);
        }
        st.build();
        fit = 0;
        for (int i = 0; i < n; ++i)
        {
            while (st.query(fit, i) < i - fit + 1)
            {
                ++fit;
            }
            num[i][j] = min(num[i][j], i - fit + 1);
        }
        fit = n - 1;
        for (int i = n - 1; i >= 0; --i)
        {
            while (st.query(i, fit) < fit - i + 1)
            {
                --fit;
            }
            num[i][j] = min(num[i][j], fit - i + 1);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (extend[i][j] == 0)
            {
                if (i & 1 && j & 1)
                {
                    ans += num[i][j] >> 1;
                }
            }
            else
            {
                ans += (num[i][j] + 1) >> 1;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
