#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50005;

int main()
{
    char s[MAXN];
    while (~scanf("%s", s))
    {
        int len = strlen(s);
        for (int i = 1; i <= (len >> 1); ++i)
        {
            int k = i;
            int same = 0;
            for (int j = i; j < len; ++j)
            {
                same = s[j] == s[j - i] ? same + 1 : 0;
                s[k++] = s[j];
                if (same == i)
                {
                    k -= i;
                    same = 0;
                }
            }
            s[len = k] = 0;
        }
        printf("%s\n", s);
    }
    return 0;
}
