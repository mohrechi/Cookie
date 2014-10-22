#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
const int MAXM = 10005;

int a[MAXN];
int b[MAXM];

int next[MAXM];

void getNext(int s[], int len)
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int kmp(int s1[], int s2[], int len1, int len2)
{
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (j == -1 || s1[i] == s2[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= len2)
    {
        return i - len2;
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &b[i]);
        }
        getNext(b, m);
        int ans = kmp(a, b, n, m);
        if (ans == -1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", ans + 1);
        }
    }
    return 0;
}
