#include <cstdio>
#include <cstring>
static const int MAXN = 100;

char input[MAXN];
int length;
int minLength[MAXN];
int maxNumber[MAXN];

inline int max(int x, int y)
{
    return x>y?x:y;
}

int compare(char *s1, int l1, char *s2, int l2)
{
    while(*s1 == '0' && l1 > 0)
        ++ s1, -- l1;
    while(*s2 == '0' && l2 > 0)
        ++ s2, -- l2;
    if(l1 > l2)
        return 1;
    if(l1 < l2)
        return -1;
    for(int i=0;i<l1;++i)
    {
        if(s1[i] > s2[i])
            return 1;
        if(s1[i] < s2[i])
            return -1;
    }
    return 0;
}

int main()
{
    char *s1, *s2;
    int l1, l2;
    while(scanf("%s", input), strcmp(input, "0"))
    {
        length = strlen(input);
        memset(minLength, 0, sizeof(minLength));
        memset(maxNumber, 0, sizeof(maxNumber));
        for(int i=1;i<length;++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                s1 = &input[minLength[j]];
                l1 = &input[j] - s1 + 1;
                s2 = &input[j+1];
                l2 = &input[i] - s2 + 1;
                if(compare(s1, l1, s2, l2) < 0)
                {
                    minLength[i] = j + 1;
                    break;
                }
            }
        }
        int tempPos = minLength[length - 1];
        maxNumber[tempPos] = length - 1;
        for(int i=tempPos-1;input[i]=='0' && i>=0;--i)
            maxNumber[i] = length - 1;
        for(int i=tempPos-1;i>=0;--i)
        {
            for(int j=i;j<=tempPos-1;++j)
            {
                s1 = &input[i];
                l1 = &input[j] - s1 + 1;
                s2 = &input[j+1];
                l2 = &input[maxNumber[j+1]] - s2 + 1;
                if(compare(s1, l1, s2, l2) < 0)
                {
                    maxNumber[i] = max(maxNumber[i], j);
                }
            }
        }
        for(int i=0, pos=maxNumber[0];i<length;pos = maxNumber[pos+1])
        {
            for(;i<length&&i<=pos;++i)
            {
                printf("%c", input[i]);
            }
            if(i < length)
                printf(",");
        }
        printf("\n");
    }
    return 0;
}
