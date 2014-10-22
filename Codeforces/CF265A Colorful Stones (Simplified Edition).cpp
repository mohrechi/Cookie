#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;

char s1[MAXN], s2[MAXN];

int main()
{
    while(~scanf("%s%s", s1, s2))
    {
        int pos = 0;
        for(int i=0;s2[i];++i)
        {
            if(s1[pos] == s2[i])
            {
                ++ pos;
            }
        }
        printf("%d\n", pos + 1);
    }
    return 0;
}
