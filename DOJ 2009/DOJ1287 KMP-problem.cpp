#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXM = 1000005;

char mod[MAXN];
char s[MAXM];
int next[MAXM];
int len1, len2;

void get_next()
{
    int i,j;
    next[1]=0;
    j=0;
    for(i=2;i<=len2;++i)
    {
        while(j>0 && mod[j+1]!=mod[i])
        {
            j=next[j];
        }
        if(mod[j+1]==mod[i])
        {
            ++i;
        }
        next[i]=j;
    }
}

int KMP(int pos)
{
    int i,j,k;
    get_next();
    i=pos,j=0,k=0;
    while(i<=len1)
    {
        while(j>0 && mod[j+1]!=s[i])
        {
            j=next[j];
        }
        if(mod[j+1]==s[i])
        {
            j++;
            if(j==len2)
            {
                return ++ k;
            }
        }
        i++;
    }
    return k;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s%s", mod + 1, s + 1);
        len1 = strlen(s + 1);
        len2 = strlen(mod + 1);
        if(KMP(0))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
