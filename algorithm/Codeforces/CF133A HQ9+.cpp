#include <cstdio>
#include <cstring>

char s[200];

int main()
{
    while(gets(s))
    {
        bool flag = false;
        for(int i=0;s[i];++i)
        {
            if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
            {
                flag = true;
                break;
            }
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
