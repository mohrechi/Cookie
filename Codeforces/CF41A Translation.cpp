#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

char s1[MAXN], s2[MAXN];

int main()
{
    while(~scanf("%s%s", s1, s2))
    {
        bool flag = true;
        int j;
        for(j=0;s2[j];++j);
        -- j;
        for(int i=0;s1[i];++i,--j)
        {
            if(s1[i] != s2[j])
            {
                flag = false;
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
