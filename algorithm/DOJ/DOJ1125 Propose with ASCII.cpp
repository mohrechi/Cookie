#include <cstdio>

int main()
{
    char ch, out;
    int c = 0;
    while(~scanf("%c",&ch))
    {
        if(ch == '\n')
        {
            printf("\n");
            continue;
        }
        switch(c)
        {
        case 0:
            out = ch - '0';
            ++c;
            break;
        case 1:
            out = out * 10 + ch - '0';
            ++c;
            break;
        case 2:
            out = out * 10 + ch - '0';
            c = 0;
            printf("%c", out);
            break;
        }
    }
    return 0;
}
