#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5;

int main()
{
    int ansNum = 0;
    int ans[5];
    char s[20];
    for (int i = 1; i <= 5; ++i)
    {
        scanf("%s", s);
        if (strstr(s, "FBI") != 0L)
        {
            ans[ansNum++] = i;
        }
    }
    if (ansNum == 0)
    {
        printf("HE GOT AWAY!\n");
    }
    else
    {
        for (int i = 0; i < ansNum; ++i)
        {
            if (i)
            {
                printf(" ");
            }
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
