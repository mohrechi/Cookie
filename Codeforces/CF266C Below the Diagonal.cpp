#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n, m;
vector<int> row[MAXN];
int index[MAXN];

struct Swap
{
    int op, a, b;
    Swap() {}
    Swap(int _op, int _a, int _b)
    {
        op = _op;
        a = _a;
        b = _b;
    }
    inline void output()
    {
        printf("%d %d %d\n", op, a, b);
    }
};

vector<Swap> ans;

int main()
{
    int a, b;
    scanf("%d", &n);
    for(int i=1;i<n;++i)
    {
        scanf("%d%d", &a, &b);
        row[a].push_back(b);
        index[a] = max(index[a], b);
    }
    for(int i=1;i<=n;++i)
    {
        int k = i;
        for(int j=i+1;j<=n;++j)
        {
            if(row[j].size() < row[k].size())
            {
                k = j;
            }
            else if(row[j].size() == row[k].size())
            {
                if(index[j] < index[k])
                {
                    k = j;
                }
            }
        }
        if(k != i)
        {
            swap(row[i], row[k]);
            swap(index[i], index[k]);
            ans.push_back(Swap(1, i, k));
        }
    }
    memset(index, 0x7f, sizeof(index));
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<row[i].size();++j)
        {
            index[row[i][j]] = min(index[row[i][j]], i);
        }
    }
    for(int i=1;i<=n;++i)
    {
        int k = i;
        for(int j=i+1;j<=n;++j)
        {
            if(index[j] < index[k])
            {
                k = j;
            }
        }
        if(k != i)
        {
            swap(index[i], index[k]);
            ans.push_back(Swap(2, i, k));
        }
    }
    printf("%d\n", ans.size());
    for(int i=0;i<ans.size();++i)
    {
        ans[i].output();
    }
    return 0;
}
