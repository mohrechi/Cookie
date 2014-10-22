#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct Node
{
    int index;
    long long value;
    bool operator <(const Node &node) const
    {
        if (value == node.value)
        {
            return index < node.index;
        }
        return value < node.value;
    }
};

int n, m, k;
struct Func
{
    int index;
    int type;
    long long b, c;
    bool increase;
    long long cur;
    inline void input()
    {
        scanf("%d%lld%lld", &type, &b, &c);
        if (b >= 0)
        {
            increase = true;
            cur = 1;
        }
        else
        {
            increase = false;
            cur = m;
        }
    }
    inline Node getCurrentNode()
    {
        Node node;
        node.index = index;
        if (type == 1)
        {
            node.value = b * cur + c;
        }
        else
        {
            node.value = b * cur * cur + c;
        }
        return node;
    }
    inline bool next()
    {
        if (increase)
        {
            if (++cur > m)
            {
                return false;
            }
        }
        else
        {
            if (--cur < 1)
            {
                return false;
            }
        }
        return true;
    }
} func[MAXN];

int main()
{
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        set<Node> nodeSet;
        for (int i = 0; i < n; ++i)
        {
            func[i].index = i;
            func[i].input();
            nodeSet.insert(func[i].getCurrentNode());
        }
        for (int i = 0; i < k; ++i)
        {
            set<Node>::iterator it = nodeSet.begin();
            printf("%lld\n", it->value);
            nodeSet.erase(it);
            if (func[it->index].next())
            {
                nodeSet.insert(func[it->index].getCurrentNode());
            }
        }
    }
    return 0;
}
