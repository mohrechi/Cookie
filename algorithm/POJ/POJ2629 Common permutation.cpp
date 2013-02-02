#include <cstdio>
#include <cstring>
const int MAXN = 1005;
char s1[MAXN], s2[MAXN];
int sum1[30], sum2[30];
int sum[30];

inline int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    while(gets(s1))
    {
        gets(s2);
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        for(int i=0;s1[i];++i)
        {
            ++ sum1[s1[i] - 'a'];
        }
        for(int i=0;s2[i];++i)
        {
            ++ sum2[s2[i] - 'a'];
        }
        for(int i=0;i<26;++i)
        {
            sum[i] = min(sum1[i], sum2[i]);
            for(int j=0;j<sum[i];++j)
            {
                printf("%c", i + 'a');
            }
        }
        printf("\n");
    }
    return 0;
}
