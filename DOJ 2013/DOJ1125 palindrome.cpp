#include <cstdio>
#include <cstring>
const int MAXN = 105;

int main()
{
    char s[MAXN];
    while (gets(s))
    {
        bool flag = true;
        int n = strlen(s);
        for (int i = 0; s[i]; ++i)
        {
            if (s[i] != s[n - i - 1])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }
    return 0;
}
