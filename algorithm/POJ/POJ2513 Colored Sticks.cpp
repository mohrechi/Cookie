#include <cstdio>
#include <cstring>
const int MAXN = 500010;
const int MAXL = 10;
const int MAXM = 1000010;
struct Node
{
    int next[26];
    int word;
}node[MAXM];
int nodeNumber;
int wordNumber;
int father[MAXN];
int color[MAXN];

void initNode(int x)
{
    memset(node[x].next, -1, sizeof(node[x].next));
    node[x].word = -1;
}

int addWord(int x, const char *word)
{
    if(*word)
    {
        int next = (*word) - 'a';
        if(node[x].next[next] == -1)
        {
            initNode(nodeNumber);
            node[x].next[next] = nodeNumber ++;
        }
        return addWord(node[x].next[next], word + 1);
    }
    if(node[x].word == -1)
    {
        node[x].word = wordNumber ++;
    }
    return node[x].word;
}

void init()
{
    for(int i=0;i<MAXN;++i)
    {
        father[i] = i;
    }
}

int find(int x)
{
    if(x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

void combine(int x, int y)
{
    father[find(x)] = find(y);
}

int main()
{
    char s1[MAXL + 6];
    char s2[MAXL + 6];
    int t1, t2;
    init();
    initNode(0);
    nodeNumber = 1;
    wordNumber = 0;
    memset(color, 0, sizeof(color));
    while(~scanf("%s%s", s1, s2))
    {
        t1 = addWord(0, s1);
        t2 = addWord(0, s2);
        ++ color[t1];
        ++ color[t2];
        combine(t1, t2);
    }
    bool connectivity = true;
    int oddNumber = 0;
    for(int i=0;i<wordNumber;++i)
    {
        if(find(i) != find(0))
        {
            connectivity = false;
        }
        if(color[i] & 1)
        {
            ++ oddNumber;
        }
    }
    if(!connectivity || oddNumber > 2)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("Possible\n");
    }
    return 0;
}
