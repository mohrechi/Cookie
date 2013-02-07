#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s11[205], s12[205], s2[205];
int count1[205], count2[205];

int main()
{
    while(~scanf("%s%s%s", s11, s12, s2))
    {
        for(int i=0;s11[i];++i)
        {
            ++ count1[s11[i]];
        }
        for(int i=0;s12[i];++i)
        {
            ++ count1[s12[i]];
        }
        for(int i=0;s2[i];++i)
        {
            ++ count2[s2[i]];
        }
        bool flag = true;
        for(int i='A';i<='Z';++i)
        {
            if(count1[i] != count2[i])
            {
                printf("NO\n");
                flag = false;
                break;
            }
        }
        if(flag)
        {
            printf("YES\n");
        }
    }
    return 0;
}
