#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s1[105], s2[105];

int main()
{
    while(~scanf("%s%s", s1, s2))
    {
        for(int i=0;s1[i];++i)
        {
            s1[i] = (s1[i] != s2[i]) + '0';
        }
        printf("%s\n", s1);
    }
    return 0;
}
