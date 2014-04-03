#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int readAction(int a[50])
{
    int i;
    char s[50];
    gets(s);
    for (i = 0; s[i]; i += 2)
    {
        switch (s[i])
        {
        case '[':
            a[i >> 1] = 0;
            break;
        case '8':
            a[i >> 1] = 1;
            break;
        case '(':
            a[i >> 1] = 2;
            break;
        }
    }
    return i >> 1;
}

int main()
{
    int n, a[50], b[50];
    n = readAction(a);
    readAction(b);
    int score = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            if ((a[i] + 1) % 3 == b[i])
            {
                --score;
            }
            else
            {
                ++score;
            }
        }
    }
    if (score > 0)
    {
        puts("TEAM 1 WINS");
    }
    else if (score < 0)
    {
        puts("TEAM 2 WINS");
    }
    else
    {
        puts("TIE");
    }
    return 0;
}
