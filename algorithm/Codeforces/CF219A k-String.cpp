#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2005;

int k, num[256];
char s[MAXN];

int main()
{
    while(~scanf("%d", &k))
    {
        scanf("%s", s);
        memset(num, 0, sizeof(num));
        for(int i=0;s[i];++i)
        {
            ++ num[s[i]];
        }
        bool flag = true;
        for(int i='a';i<='z';++i)
        {
            if(num[i] % k)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(int i='a';i<='z';++i)
            {
                num[i] /= k;
            }
            while(k--)
            {
                for(int i='a';i<='z';++i)
                {
                    for(int j=0;j<num[i];++j)
                    {
                        putchar(i);
                    }
                }
            }
            printf("\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
