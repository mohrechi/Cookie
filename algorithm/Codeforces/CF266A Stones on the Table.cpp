#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int len, cnt;
    char s[55];
    while(~scanf("%d%s", &len, s))
    {
        char lastColor = 0;
        cnt = 0;
        for(int i=0;i<len;++i)
        {
            if(s[i] != lastColor)
            {
                ++ cnt;
                lastColor = s[i];
            }
        }
        printf("%d\n", len - cnt);
    }
    return 0;
}
