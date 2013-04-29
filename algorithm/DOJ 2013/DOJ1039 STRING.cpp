#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXC = 1005;

int dist[26][26];
char s1[MAXC], s2[MAXC];

int main()
{
    int m, k;
    while (~scanf("%s%s", s1, s2))
    {
        scanf("%d%d", &m, &k);
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                dist[i][j] = k;
            }
            dist[i][i] = 0;
        }
        char sa[5], sb[5];
        int a, b, c;
        while (m--)
        {
            scanf("%s%s%d", sa, sb, &c);
            a = sa[0] - 'a';
            b = sb[0] - 'a';
            dist[a][b] = min(dist[a][b], c);
        }
        for (int k = 0; k < 26; ++k)
        {
            for (int i = 0; i < 26; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; s1[i]; ++i)
        {
            ans += dist[s1[i] - 'a'][s2[i] - 'a'];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
