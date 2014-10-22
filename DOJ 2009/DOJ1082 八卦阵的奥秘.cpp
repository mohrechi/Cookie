#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 11;
const int MAXM = 100005;
const int MAXL = 50;

long long C[MAXL][MAXL];

void init()
{
    for(int i=0;i<MAXL;++i)
    {
        C[i][0] = 1;
    }
    for(int i=1;i<MAXL;++i)
    {
        for(int j=1;j<=i;++j)
        {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
}

struct TrieNode
{
    int isWord;
    int next[26];
    inline void init()
    {
        isWord = -1;
        memset(next, -1, sizeof(next));
    }
} tree[MAXM];
int nodeNumber;

void initTrie()
{
    nodeNumber = 1;
    tree[0].init();
}

inline int newNode()
{
    tree[nodeNumber].init();
    return nodeNumber ++;
}

inline int getPos(char ch)
{
    return ch - 'a';
}

int point[MAXM];

void addWord(int x, int index, const char *word)
{
    if(*word == 0)
    {
        if(tree[x].isWord == -1)
        {
            tree[x].isWord = index;
        }
        point[index] = tree[x].isWord;
    }
    else
    {
        int pos = getPos(*word);
        if(tree[x].next[pos] == -1)
        {
            tree[x].next[pos] = newNode();
        }
        addWord(tree[x].next[pos], index, word + 1);
    }
}

int n, m, len;
char str[MAXL];
char password[MAXL];
long long ans[MAXM];

long long gcd(long long a, long long b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void dfs(int x, int pos)
{
    if(tree[x].isWord != -1)
    {
        ++ ans[tree[x].isWord];
        return;
    }
    for(int i=pos;i<len;++i)
    {
        int next = getPos(str[i]);
        if(tree[x].next[next] != -1)
        {
            dfs(tree[x].next[next], i + 1);
        }
    }
}

int main()
{
    init();
    while(scanf("%d%d", &n, &m), n + 1 || m + 1)
    {
        scanf("%s", str);
        len = strlen(str);
        initTrie();
        for(int i=0;i<m;++i)
        {
            scanf("%s", password);
            addWord(0, i, password);
        }
        if(len < n)
        {
            printf("0\n");
            continue;
        }
        long long totalNumber = C[len][n];
        memset(ans, 0, sizeof(ans));
        dfs(0, 0);
        for(int i=0;i<m;++i)
        {
            int validNumber = ans[point[i]];
            if(validNumber == 0)
            {
                printf("0\n");
            }
            else if(validNumber == totalNumber)
            {
                printf("1\n");
            }
            else
            {
                long long g = gcd(validNumber, totalNumber);
                printf("%lld/%lld\n", validNumber / g, totalNumber / g);
            }
        }
    }
    return 0;
}
