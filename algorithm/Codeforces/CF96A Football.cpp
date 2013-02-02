#include <cstdio>
#include <cstring>

char s[105];

int main()
{
    while(~scanf("%s", s))
    {
        int c0 = s[0] == '0', c1 = s[1] == '1';
        bool flag = false;
        for(int i=1;s[i];++i)
        {
            if(s[i] == '0')
            {
                if(s[i - 1] == '0')
                {
                    ++ c0;
                }
                else
                {
                    c0 = 1;
                }
            }
            else
            {
                if(s[i - 1] == '1')
                {
                    ++ c1;
                }
                else
                {
                    c1 = 1;
                }
            }
            flag |= c0 >= 7 || c1 >= 7;
        }
        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
