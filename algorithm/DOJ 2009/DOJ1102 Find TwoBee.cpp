#include <cstdio>
#include <cstring>

char s[128];
static const char t[] = "TwoBee";
int main(int argc, char *argv[])
{
    int sl, tl, a, c;
    tl = strlen(t);
    while(~scanf("%s",s))
    {
        sl = strlen(s);
        a = 0, c = 0;
        for(int i=0;i<sl;++i)
        {
            if(s[i] != t[c])
            {
                c = 0;
            }
            if(s[i] == t[c])
            {
                if(++c == tl)
                {
                    ++ a;
                    c = 0;
                }
            }
        }
        printf("%d\n", a);
    }
    return 0;
}
