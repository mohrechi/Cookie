#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500005;

int n;
struct Node
{
    int index, a, b;
    bool operator <(const Node &node) const
    {
        return b < node.b;
    }
} nodes[MAXN];

struct AssistNode
{
    int index;
    int value;
    bool operator < (const AssistNode &node) const
    {
        if (value == node.value)
        {
            return index < node.index;
        }
        return value < node.value;
    }
};

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            nodes[i].index = i;
            scanf("%d%d", &nodes[i].a, &nodes[i].b);
        }
        sort(nodes, nodes + n);
        set<AssistNode> left;
        set<AssistNode> right;
        for (int i = 0; i < n; ++i)
        {
            AssistNode node;
            node.index = i;
            node.value = nodes[i].a;
            right.insert(node);
        }
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            AssistNode node1;
            node1.index = i;
            node1.value = nodes[i].a - nodes[i].b;
            left.insert(node1);

            set<AssistNode>::iterator itL = left.begin();
            set<AssistNode>::iterator itR = right.begin();
            if (sum + nodes[i].b + itL->value <= sum + itR->value)
            {
                printf("%lld\n", sum + nodes[i].b + itL->value);
            }
            else
            {
                printf("%lld\n", sum + itR->value);
            }

            sum += nodes[i].b;
            AssistNode node2;
            node2.index = i;
            node2.value = nodes[i].a;
            right.erase(node2);
        }
    }
    return 0;
}
