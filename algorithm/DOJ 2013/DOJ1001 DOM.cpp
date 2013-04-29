#include <cstdio>
#include <cstring>

const char s1[] = "CAMBRIDGE";
char s2[200];

int main()
{
    while (~scanf("%s", s2))
    {
        for (int i = 0; s2[i]; ++i)
        {
            bool flag = true;
            for (int j = 0; s1[j]; ++j)
            {
                if (s2[i] == s1[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("%c", s2[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
