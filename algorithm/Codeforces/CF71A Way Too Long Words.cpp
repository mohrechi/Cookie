#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char s[105];

int main()
{
    while(~scanf("%d", &n))
    {
        while(n--)
        {
            scanf("%s", s);
            int len = strlen(s);
            if(len > 10)
            {
                printf("%c%d%c\n", s[0], len - 2, s[len-1]);
            }
            else
            {
                printf("%s\n", s);
            }
        }
    }
    return 0;
}
