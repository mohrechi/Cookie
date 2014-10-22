#include <cstdio>
#include <cstring>

int num[105];
char s[105];

int main()
{
    while(~scanf("%s", s))
    {
        memset(num, 0, sizeof(num));
        for(int i=0;s[i];++i)
        {
            ++ num[s[i] - 'a'];
        }
        int cnt = 0;
        for(int i=0;i<26;++i)
        {
            cnt += num[i] > 0;
        }
        if(cnt & 1)
        {
            printf("IGNORE HIM!\n");
        }
        else
        {
            printf("CHAT WITH HER!\n");
        }
    }
    return 0;
}
