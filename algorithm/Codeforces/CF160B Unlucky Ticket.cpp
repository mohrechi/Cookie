#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    char s[205];
    while(~scanf("%d", &n))
    {
        scanf("%s", s);
        sort(s, s + n);
        sort(s + n, s + n + n);
        bool flag1 = false;
        bool flag2 = false;
        for(int i=0;i<n;++i)
        {
            flag1 |= s[i] <= s[i + n];
            flag2 |= s[i] >= s[i + n];
        }
        if(flag1 && flag2)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
