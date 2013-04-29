#include <cstdio>

int main(int argc, char *argv[])
{
    char s[50];
    int a,b;
    while(~scanf("%s%d%d",s,&a,&b))
    {
        if(a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        s[b] = 0;
        printf("%s\n",s+(a-1));
    }
    return 0;
}
