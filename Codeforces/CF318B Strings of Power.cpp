#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
const char SUB1[] = "heavy";
const char SUB2[] = "metal";

char s[MAXN];
int num[MAXN];

int main()
{
    while (~scanf("%s", s))
    {
        int len = strlen(s);
        int same = 0;
        num[len] = 0;
        for (int i = len - 1; i >= 0; --i)
        {
            num[i] = strncmp(s + i, SUB2, 5) ? 0 : 1;
            num[i] += num[i + 1];
        }
        long long ans = 0;
        same = 0;
        for (int i = 0; i < len; ++i)
        {
            ans += strncmp(s + i, SUB1, 5) ? 0 : num[i];
        }
        cout << ans << endl;
    }
    return 0;
}
