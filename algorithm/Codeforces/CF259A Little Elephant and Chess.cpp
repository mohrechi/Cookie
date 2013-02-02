#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[10][10];

int main()
{
    bool flag = true;
    for(int i=0;i<8;++i)
    {
        scanf("%s", s[i]);
        for(int j=1;j<8;++j)
        {
            if(s[i][j] == s[i][j-1])
            {
                flag = false;
            }
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
    return 0;
}
