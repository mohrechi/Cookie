#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

char s[MAXN];

int main()
{
    while(~scanf("%s", s))
    {
        int count = 0;
        int len = strlen(s);
        for(int i=0;i<len;++i)
        {
            count += s[i] == '1';
        }
        if(count == len)
        {
            for(int i=1;i<len;++i)
            {
                printf("1");
            }
            printf("\n");
        }
        else
        {
            bool flag = true;
            for(int i=0;i<len;++i)
            {
                if(s[i] == '0')
                {
                    if(flag)
                    {
                        flag = false;
                    }
                    else
                    {
                        printf("0");
                    }
                }
                else
                {
                    printf("1");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
