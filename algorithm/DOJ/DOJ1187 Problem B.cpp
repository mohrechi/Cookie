#include <cstdio>
#include <cstring>

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline void swap(char &c1, char &c2)
{
    c1 ^= c2 ^= c1 ^= c2;
}

char s1[32], s2[32];

int main()
{
    while(~scanf("%s%s", &s1, &s2))
    {
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        for(int i=0;i<l1;++i) s1[i] -= '0';
        for(int i=0;i<l2;++i) s2[i] -= '0';
        for(int i=0;i<l1>>1;++i) swap(s1[i], s1[l1-i-1]);
        for(int i=0;i<l2>>1;++i) swap(s2[i], s2[l2-i-1]);
        int l = max(l1, l2);
        bool carry = false;
        for(int i=0;i<l;++i) carry = (s1[i] += s2[i] + carry) > 9;
        if(carry) printf("1");
        for(int i=l-1;i>=0;--i) printf("%d", s1[i]%10);
        printf("\n");
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
    }
    return 0;
}
