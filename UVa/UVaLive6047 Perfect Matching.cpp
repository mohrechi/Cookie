#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int MAXM = 505;

int n;
char s[MAXN][MAXM];
int len[MAXN];
int hash[MAXM];
int hashb[MAXM];
int hash1[MAXN];
int hash2[MAXN];

void init()
{
    hash[0] = 63689;
    hashb[0] = 1;
    for (int i = 1; i < MAXM; ++i)
    {
        hash[i] = hash[i - 1] * 378551;
        hashb[i] = hashb[i - 1] * 378551;
    }
}

char temp[MAXM + MAXM];

bool judge(int i, int j)
{
    int value1 = hash1[i] + hash1[j] * hashb[len[i]];
    int value2 = hash2[j] + hash2[i] * hashb[len[j]];
    if (value1 == value2)
    {
        int l = len[i] + len[j];
        strcpy(temp, s[i]);
        strcat(temp, s[j]);
        for (int i = 0; i <= l >> 1; ++i)
        {
            if (temp[i] != temp[l - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    init();
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s[i]);
            len[i] = strlen(s[i]);
            hash1[i] = 0;
            hash2[i] = 0;
            for (int j = 0; j < len[i]; ++j)
            {
                hash1[i] += hash[j] * (s[i][j] - 'a');
                hash2[i] += hash[j] * (s[i][len[i] - j - 1] - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                ans += judge(i, j);
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
