#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200010;

char s[MAXN];
int next[MAXN];

void getNext()
{
    int i, j;
    int l = 1, r = -1;
    next[0] = 0;
    for(i=1;s[i];++i)
    {
        if(i + next[i - l] - 1 < r)
        {
            next[i] = next[i - l];
        }
        else
        {
            j = max(r - i + 1, 0);
            for(;s[i+j] && s[i+j]==s[j];++j);
            next[i] = j;
            l = i;
            r = i + j - 1;
        }
    }
    next[0] = i;
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%s", s);
        int len = strlen(s);
        for(int i=0;i<len;++i)
        {
            s[i + len] = s[i];
        }
        s[len<<1] = 0;
        getNext();
        int ml, k;
        for(k = 1;k < len && k + next[k] < len;++k);
        ml = len % k ? len : k;
        int l = 0, e = 0, g = 0;
        for(int i=0;i<ml;++i)
        {
            if(next[i] >= len)
            {
                ++ e;
            }
            else if(s[i + next[i]] < s[next[i]])
            {
                ++ l;
            }
            else
            {
                ++ g;
            }
        }
        printf("Case %d: %d %d %d\n", cas, l, e, g);
    }
    return 0;
}
