#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

struct Node
{
    int value, index;
    Node() {}
    Node(int _value, int _index)
    {
        value = _value;
        index = _index;
    }
    bool operator < (const Node &node) const
    {
        if(value == node.value)
        {
            return index < node.index;
        }
        return value < node.value;
    }
};

int main()
{
    int n, o, x;
    Node node;
    while(~scanf("%d", &n))
    {
        queue<Node> q;
        set<Node> s;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &o);
            if(o == 1)
            {
                scanf("%d", &x);
                q.push(Node(x, i));
                s.insert(Node(x, i));
            }
            else if(o == 2)
            {
                node = q.front();
                q.pop();
                set<Node>::iterator it = s.find(node);
                s.erase(it);
                printf("%d\n", node.value);
            }
            else if(o == 3)
            {
                set<Node>::reverse_iterator it = s.rbegin();
                printf("%d\n", it->value);
            }
            else
            {
                set<Node>::iterator it = s.begin();
                printf("%d\n", it->value);
            }
        }
    }
    return 0;
}
