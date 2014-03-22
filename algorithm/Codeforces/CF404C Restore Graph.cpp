#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

int n, k;
struct Node
{
    int index;
    int dist;
    bool operator <(const Node &node) const
    {
        if (dist == node.dist)
        {
            return index < node.index;
        }
        return dist < node.dist;
    }
} node[MAXN];

vector<vector<pair<int, int>>> lists;
vector<pair<int, int>> ans;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        node[i].index = i;
        scanf("%d", &node[i].dist);
    }
    sort(node + 1, node + 1 + n);
    bool flag = node[1].dist == 0 && node[2].dist != 0;
    if (flag)
    {
        lists.push_back(vector<pair<int, int>>());
        lists[0].push_back(make_pair(node[1].index, k));
        for (int i = 2; i <= n; ++i)
        {
            int entry = node[i].dist - 1;
            if (lists.size() <= entry)
            {
                flag = false;
                break;
            }
            if (lists[entry].size() == 0)
            {
                flag = false;
                break;
            }
            auto it = lists[entry].rbegin();
            ans.push_back(make_pair(it->first, node[i].index));
            if (--it->second == 0)
            {
                lists[entry].pop_back();
            }
            while (entry + 1 >= lists.size())
            {
                lists.push_back(vector<pair<int, int>>());
            }
            if (k > 1)
            {
                lists[entry + 1].push_back(make_pair(node[i].index, k - 1));
            }
        }
    }
    if (flag)
    {
        printf("%d\n", ans.size());
        for (auto it : ans)
        {
            printf("%d %d\n", it.first, it.second);
        }
    }
    else
    {
        puts("-1");
    }
    return 0;
}
