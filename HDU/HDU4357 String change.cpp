#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100;

char s1[MAXN];
char s2[MAXN];

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%s%s",s1,s2);
        bool flag = false;
        if(strlen(s1) == 2)
        {
            for(int i=0;i<26;++i)
            {
                if(++ s1[0] > 'z')
                {
                    s1[0] = 'a';
                }
                if(++ s1[1] > 'z')
                {
                    s1[1] = 'a';
                }
                swap(s1[0], s1[1]);
                if(strcmp(s1, s2) == 0)
                {
                    flag = true;
                    break;
                }
            }
        }
        else
        {
            int c1 = 0, c2 = 0;
            for(int i=0;s1[i];++i)
            {
                c1 += (s1[i] - 'a') & 1;
                c2 += (s2[i] - 'a') & 1;
            }
            flag = (c1 & 1) == (c2 & 1);
        }
        printf("Case #%d: ", cas);
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
