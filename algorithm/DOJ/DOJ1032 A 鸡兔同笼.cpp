#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, s1, s2;
    while(~scanf("%d%d%d%d", &a, &b, &s1, &s2))
    {
        if(a == b)
        {
            if(a == 0)
            {
                if(s2)
                {
                    printf("No Solution\n");
                }
                else if(s1 >= 0)
                {
                    printf("Multiple Solution\n");
                }
                else
                {
                    printf("No Solution\n");
                }
            }
            else
            {
                if(s2 % a)
                {
                    printf("No Solution\n");
                }
                else if(s2 / a != s1)
                {
                    printf("No Solution\n");
                }
                else if(s1 >= 0)
                {
                    printf("Multiple Solution\n");
                }
                else
                {
                    printf("No Solution\n");
                }
            }
        }
        else
        {
            int xu = s2 - b * s1;
            int yu = a * s1 - s2;
            int d = a - b;
            if(xu % d)
            {
                printf("No Solution\n");
            }
            else if(yu % d)
            {
                printf("No Solution\n");
            }
            else
            {
                int x = xu / d;
                int y = yu / d;
                if(x < 0)
                {
                    printf("No Solution\n");
                }
                else if(y < 0)
                {
                    printf("No Solution\n");
                }
                else
                {
                    printf("Unique Solution\n");
                    printf("%d %d\n", x, y);
                }
            }
        }
    }
    return 0;
}
