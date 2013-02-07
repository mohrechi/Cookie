#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char hello[10] = "hello";
char s[205];

int main()
{
    while(~scanf("%s", s))
    {
        int pos = 0;
        for(int i=0;s[i];++i)
        {
            if(s[i] == hello[pos])
            {
                ++ pos;
            }
        }
        if(pos == 5)
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
