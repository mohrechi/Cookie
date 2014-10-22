#include <cstdio>
#include <cstring>

const int lucky[] = {
    4, 7,
    44, 47, 74, 77,
    444, 447, 474, 477, 744, 747, 774, 777
    };
const int luckyNum = 14;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        bool flag = false;
        for(int i=0;i<luckyNum;++i)
        {
            if(n % lucky[i] == 0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
