#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

char s[MAXN];
int ans[MAXN];

int main()
{
    while(~scanf("%s", s + 1))
    {
        int n = strlen(s + 1);
        int l = 1, r = n;
        for(int i=1;s[i];++i)
        {
            if(s[i] == 'l')
            {
                ans[r--] = i;
            }
            else
            {
                ans[l++] = i;
            }
        }
        for(int i=1;i<=n;++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
