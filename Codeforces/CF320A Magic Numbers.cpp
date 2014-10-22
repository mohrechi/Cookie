#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char num[100];
    while (~scanf("%s", num))
    {
        bool flag = true;
        int state = 0;
        for (int i = 0; num[i]; ++i)
        {
            if (num[i] == '1')
            {
                state = 1;
            }
            else if (num[i] == '4')
            {
                if (state == 1)
                {
                    state = 2;
                }
                else if (state == 2)
                {
                    state = 3;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
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
