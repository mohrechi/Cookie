#include <cstdio>
#include <cstring>
const int MAXN = 1005;

char s1[MAXN], s2[MAXN];

int main()
{
    int n;
    scanf("%d\n", &n);
    while (n--)
    {
        gets(s1);
        gets(s2);
        if (strstr(s2, s1))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
