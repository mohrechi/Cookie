#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, n;
    char op[10];
    while(scanf("%d", &a), a + 1)
    {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%s%d", op, &b);
            switch(op[0])
            {
                case '!':
                    a = a + b + 5;
                    break;
                case '@':
                    a = a - b - 7;
                    break;
                case '#':
                    a = a * 3 + b * 2;
                    break;
                case '$':
                    a = abs(a) % (b + 1);
                    break;
            }
        }
        printf("%d\n", a);
    }
    return 0;
}
