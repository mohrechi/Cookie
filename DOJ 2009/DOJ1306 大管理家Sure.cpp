#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int INF = 0x7FFFFFFF;

//#define DEBUG

#ifdef DEBUG
    #define DEBUG_NAME_MAP
    #define DEBUG_NODE
    #define DEBUG_EDGE
    #define DEBUG_DISTRIBUTION
    #define DEBUG_X_Y
    #define DEBUG_TREE
#endif

int dleft[MAXN], distri[MAXN];
int timeStamp;

struct Node
{
    int u, a, b;
} node[MAXN], sortNode[MAXN];
int nodeMap[MAXN];

bool compareMin(const Node &a, const Node &b)
{
    if(a.a == b.a)
    {
        return distri[a.u] > distri[b.u];
    }
    return a.a < b.a;
}

bool compareMax(const Node &a, const Node &b)
{
    if(a.a == b.a)
    {
        return distri[a.u] > distri[b.u];
    }
    return a.a > b.a;
}

class NameMap
{
public:
    void init()
    {
        nameNum = 1;
        nameMap.clear();
        names.clear();
        names.push_back("");
    }
    int getPosition(string name)
    {
        if(nameMap[name] == 0)
        {
            names.push_back(name);
            return nameMap[name] = nameNum ++;
        }
        return nameMap[name];
    }
    string getName(int position)
    {
        return names[position];
    }
    #ifdef DEBUG_NAME_MAP
    void debug()
    {
        cout << "Map: " << endl;
        for(map<string, int>::iterator it=nameMap.begin();it!=nameMap.end();++it)
        {
            cout << it->first << " " << it->second << endl;
        }
        cout << "Vector: " << endl;
        for(vector<string>::iterator it=names.begin();it!=names.end();++it)
        {
            cout << *it << endl;
        }
    }
    #endif
private:
    int nameNum;
    map<string, int> nameMap;
    vector<string> names;
} nameMap;

class Answer
{
public:
    void init()
    {
        ans = -1;
        num = 0;
        pos = -1;
    }
    void setAnswer(int x, int p)
    {
        if(x > ans)
        {
            ans = x;
            num = 1;
            pos = p;
        }
        else if(x == ans)
        {
            ++ num;
        }
    }
    void printAnswer()
    {
        if(num == 1)
        {
            cout << nameMap.getName(pos) << endl;
        }
        else
        {
            printf("Not only one!\n");
        }
    }
private:
    int ans;
    int num;
    int pos;
} answer;

struct Edge
{
    int v, next;
} edge[MAXN];
int head[MAXN], edgeNumber;

inline void initEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

class SegmentTree
{
public:
    enum TreeType
    {
        TYPE_MIN,
        TYPE_MAX
    };

    void setTreeType(TreeType type)
    {
        switch(type)
        {
            case TYPE_MIN:
                compareFunc = minFunc;
                initValue = INF;
                break;
            case TYPE_MAX:
                compareFunc = maxFunc;
                initValue = 0;
                break;
        }
    }

    void build(int n)
    {
        build(1, 1, n);
    }

    void update(int pos, int value)
    {
        update(1, pos, value);
    }

    int query(int l, int r)
    {
        if(l > r)
        {
            return 0;
        }
        return query(1, l, r);
    }

private:
    struct TreeNode
    {
        int l, r, value;
    } tree[MAXN * 3];
    int (*compareFunc)(int, int);
    int initValue;

    inline int lchild(int x)
    {
        return x << 1;
    }

    inline int rchild(int x)
    {
        return (x << 1) + 1;
    }

    static int minFunc(int x, int y)
    {
        return min(x, y);
    }

    static int maxFunc(int x, int y)
    {
        return max(x, y);
    }

    void build(int x, int l, int r)
    {
        tree[x].l = l;
        tree[x].r = r;
        tree[x].value = initValue;
        if(l == r)
        {
            return;
        }
        int mid = (l + r) >> 1;
        build(lchild(x), l, mid);
        build(rchild(x), mid + 1, r);
    }

    void update(int x, int pos, int value)
    {
        tree[x].value = (*compareFunc)(tree[x].value, value);
        if(tree[x].l == tree[x].r)
        {
            tree[x].value = value;
            return;
        }
        int mid = (tree[x].l + tree[x].r) >> 1;
        if(pos <= mid)
        {
            update(lchild(x), pos, value);
        }
        else
        {
            update(rchild(x), pos, value);
        }
    }

    int query(int x, int l, int r)
    {
        if(tree[x].l == l && tree[x].r == r)
        {
            return tree[x].value;
        }
        int mid = (tree[x].l + tree[x].r) >> 1;
        if(r <= mid)
        {
            return query(lchild(x), l, r);
        }
        if(l > mid)
        {
            return query(rchild(x), l, r);
        }
        return (*compareFunc)(query(lchild(x), l, mid), query(rchild(x), mid + 1, r));
    }
} segmentTree;

int dfs(int u)
{
    dleft[u] = timeStamp;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        dfs(edge[i].v);
    }
    distri[u] = timeStamp ++;
}

void getDistribute()
{
    timeStamp = 1;
    dfs(1);
}

int x[MAXN], y[MAXN];

int main()
{
    int n, a, b, f;
    string name1, name2;
    while(~scanf("%d", &n))
    {
        nameMap.init();
        answer.init();
        cin >> name1;
        scanf("%d%d", &a, &b);
        sortNode[1].u = node[1].u = nameMap.getPosition(name1);
        sortNode[1].a = node[1].a = a;
        sortNode[1].b = node[1].b = b;
        nodeMap[node[1].u] = 1;
        initEdge();
        for(int i=2;i<=n;++i)
        {
            cin >> name1 >> name2;
            scanf("%d%d", &a, &b);
            sortNode[i].u = node[i].u = nameMap.getPosition(name1);
            f = nameMap.getPosition(name2);
            sortNode[i].a = node[i].a = a;
            sortNode[i].b = node[i].b = b;
            addEdge(f, node[i].u);
            nodeMap[node[i].u] = i;
        }
        #ifdef DEBUG_NAME_MAP
        nameMap.debug();
        #endif
        #ifdef DEBUG_NODE
        cout << "Node:" << endl;
        for(int i=1;i<=n;++i)
        {
            cout << node[i].u << " " << node[i].a << " " << node[i].b << endl;
        }
        #endif
        #ifdef DEBUG_EDGE
        cout << "Edge: " << endl;
        for(int i=1;i<=n;++i)
        {
            cout << i << ": ";
            for(int j=head[i];j!=-1;j=edge[j].next)
            {
                cout << edge[j].v << " ";
            }
            cout << endl;
        }
        #endif
        getDistribute();
        #ifdef DEBUG_DISTRIBUTION
        cout << "Distribution: " << endl;
        for(int i=1;i<=n;++i)
        {
            cout << dleft[i] << " ";
        }
        cout << endl;
        for(int i=1;i<=n;++i)
        {
            cout << distri[i] << " ";
        }
        cout << endl;
        #endif
        sort(sortNode + 1, sortNode + n + 1, compareMin);
        segmentTree.setTreeType(SegmentTree::TYPE_MAX);
        segmentTree.build(n);
        #ifdef DEBUG_TREE
        cout << "Max Tree" << endl;
        for(int i=1;i<=n;++i)
        {
            cout << segmentTree.query(i, i) << " ";
        }
        cout << endl;
        #endif
        for(int i=1;i<=n;++i)
        {
            int u = sortNode[i].u;
            x[u] = segmentTree.query(dleft[u], distri[u] - 1);
            segmentTree.update(distri[u], sortNode[i].b);
            #ifdef DEBUG_TREE
            cout << u << " " << dleft[u] << " " <<distri[u] << " " << x[u] << ":  ";
            for(int j=1;j<=n;++j)
            {
                cout << segmentTree.query(j, j) << " ";
            }
            cout << endl;
            #endif
        }
        sort(sortNode + 1, sortNode + n + 1, compareMax);
        segmentTree.setTreeType(SegmentTree::TYPE_MIN);
        segmentTree.build(n);
        for(int i=1;i<=n;++i)
        {
            int u = sortNode[i].u;
            y[u] = segmentTree.query(dleft[u], distri[u] - 1);
            if(y[u] == INF)
            {
                y[u] = 0;
            }
            segmentTree.update(distri[u], sortNode[i].b);
        }
        #ifdef DEBUG_X_Y
            cout << "X & Y" << endl;
        #endif
        for(int i=1;i<=n;++i)
        {
            #ifdef DEBUG_X_Y
                cout << x[i] << " " << y[i] << endl;
            #endif
            answer.setAnswer(abs(x[i] - y[i]), i);
        }
        answer.printAnswer();
    }
    return 0;
}
