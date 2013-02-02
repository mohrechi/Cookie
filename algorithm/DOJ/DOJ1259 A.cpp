#include <cstdio>
#include <cstring>

char s1[100005];
char s2[100005];

void r(char s[100005], int l)
{
    for(int i=0;i<l/2;++i)
    {
        char temp = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = temp;
    }
}

int main()
{
    while(scanf("%s%s", s1, s2) != EOF)
    {
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        r(s1, l1); r(s2, l2);
        int minl = l1 < l2 ? l1 : l2;
        int maxl = l1 > l2 ? l1 : l2;
        for(int i=0;i<minl;++i)
        {
            s1[i] = (((s1[i] - '0') + (s2[i] - '0')) % 10) + '0';
        }
        if(s1[minl] == 0)
        {
            for(int i=minl;i<maxl;++i)
            {
                s1[i] = s2[i];
            }
        }
        s1[maxl] = 0;
        r(s1, maxl);
        int i;
        for(i=0;;++i)
        {
            if(s1[i] != '0')
            {
                break;
            }
        }
        if(s1[i] == 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%s\n", s1 + i);
        }
    }
    return 0;
}
