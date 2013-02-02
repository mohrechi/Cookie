#include <cstdio>
#include <cstring>
const int MAXN = 100010;

char cipher[MAXN];
char plain[MAXN];
char table[50];
char rtable[50];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", table);
        for(int i=0;i<26;++i)
        {
            rtable[table[i] - 'a'] = i + 'a';
        }
        rtable[26] = 0;
        scanf("%s", cipher);
        strcpy(plain, cipher);
        int len = strlen(cipher);
        for(int i=0;i<len;++i)
        {
            cipher[i] = rtable[cipher[i] - 'a'];
        }
        int i;
        for(i=(len+1)/2;i<len;++i)
        {
            int k = i;
            for(int j=0;k<len;++j, ++k)
            {
                if(cipher[j] != plain[k])
                {
                    break;
                }
            }
            if(k == len)
            {
                for(int j=0;j<i;++j)
                {
                    printf("%c", plain[j]);
                }
                for(int j=0;j<i;++j)
                {
                    printf("%c", cipher[j]);
                }
                printf("\n");
                break;
            }
        }
        if(i == len)
        {
            printf("%s%s\n", plain, cipher);
        }
    }
    return 0;
}
