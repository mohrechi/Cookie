#include <map>
#include <cstdio>
using namespace std;

int main()
{
    int t, n, a;
    scanf("%d", &t);
    while (t--)
    {
        int maxNum = 0;
        map<int, int> num;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            if (++num[a] > maxNum)
            {
                maxNum = num[a];
            }
        }
        bool flag = true;
        for (map<int, int>::iterator it = num.begin(); it != num.end(); ++it)
        {
            if (it->second == maxNum)
            {
                if (flag)
                {
                    flag = false;
                }
                else
                {
                    putchar(' ');
                }
                printf("%d", it->first);
            }
        }
        putchar('\n');
    }
    return 0;
}
