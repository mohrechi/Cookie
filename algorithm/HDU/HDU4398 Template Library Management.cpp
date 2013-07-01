#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 200010;

int n, m;
int templateRequired[MAXN];
int nextPosition[MAXN];
int head[MAXN], headNumber;

void decreaseNumber()
{
    map<int, int> requireMap;
    for(int i=1;i<=m;++i)
    {
        requireMap[i] = i - 1;
    }
    int requireNumber = m;
    for(int i=0;i<n;++i)
    {
        if(requireMap.find(templateRequired[i]) == requireMap.end())
        {
            requireMap[templateRequired[i]] = requireNumber ++;
        }
        templateRequired[i] = requireMap[templateRequired[i]];
    }
    headNumber = requireNumber;
}

void initNext()
{
    for(int i=0;i<headNumber;++i)
    {
        head[i] = n;
    }
    for(int i=n-1;i>=0;--i)
    {
        nextPosition[i] = head[templateRequired[i]];
        head[templateRequired[i]] = i;
    }
}

struct Node
{
    int index, future;
    bool operator < (const Node &node) const
    {
        if(future == node.future)
        {
            return index < node.index;
        }
        return future < node.future;
    }
};

bool inMemory[MAXN];

int solve()
{
    int ans = 0;
    set<Node> memory;
    memset(inMemory, false, sizeof(inMemory));
    for(int i=0;i<m;++i)
    {
        Node tempNode;
        tempNode.index = i;
        tempNode.future = head[i];
        memory.insert(tempNode);
        inMemory[i] = true;
    }
    for(int i=0;i<n;++i)
    {
        if(inMemory[templateRequired[i]])
        {
            Node tempNode;
            tempNode.index = templateRequired[i];
            tempNode.future = i;
            set<Node>::iterator it = memory.find(tempNode);
            memory.erase(it);
            tempNode.index = templateRequired[i];
            tempNode.future = nextPosition[i];
            memory.insert(tempNode);
        }
        else
        {
            Node tempNode;
            tempNode.index = templateRequired[i];
            tempNode.future = nextPosition[i];
            memory.insert(tempNode);
            inMemory[templateRequired[i]] = true;
            ++ ans;
            inMemory[memory.rbegin()->index] = false;
            memory.erase(-- memory.end());
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &templateRequired[i]);
        }
        decreaseNumber();
        initNext();
        printf("%d\n", solve());
    }
    return 0;
}
