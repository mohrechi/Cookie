#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

char s1[MAXN], s2[MAXN];

int get1Num(const char *s)
{
    int count = 0;
    for (int i = 0; s[i]; ++i)
    {
        count += s[i] == '1';
    }
    return count;
}

int main()
{
    while (~scanf("%s%s", s1, s2))
    {
        int count1 = get1Num(s1);
        int count2 = get1Num(s2);
        count1 += count1 & 1;
        if (count1 >= count2)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
