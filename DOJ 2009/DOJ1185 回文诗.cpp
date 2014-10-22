#include <cstdio>
#include <cstring>

char s[1005];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        int len = strlen(s);
        bool flag = true;
        for(int i=0;i<(len>>1);++i)
        {
            if(s[i] != s[len - i - 1])
            {
                flag = false;
                break;
            }
        }
        if(flag)
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
