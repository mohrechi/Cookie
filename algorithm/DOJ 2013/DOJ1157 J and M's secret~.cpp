#include <cstdio>
#include <cstring>

char s[1024];

int main()
{
    int n, f1, f2;
    scanf("%d\n", &n);
    while (n--)
    {
        gets(s);
        int len = strlen(s);
        if (len < 5)
        {
            f1 = -1;
            f2 = -1;
        }
        else
        {
            f1 = strncmp(s, "hehe.", 5);
            f2 = strncmp(s + (len - 5), "lala.", 5);
        }
        if (f1 == 0 && f2 != 0)
        {
            puts("Mary's");
        }
        else if (f1 != 0 && f2 == 0)
        {
            puts("John's");
        }
        else
        {
            puts("OMG>.< I don't know!");
        }
    }
    return 0;
}
