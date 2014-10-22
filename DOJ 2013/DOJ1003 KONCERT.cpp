#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int m, n, a, b;
int ticketA[MAXN];
int ticketB[MAXN];

int main()
{
    while (~scanf("%d%d", &m, &a))
    {
        for (int i = 0; i < a; ++i)
        {
            scanf("%d", &ticketA[i]);
        }
        scanf("%d%d", &n, &b);
        for (int j = 0; j < b; ++j)
        {
            scanf("%d", &ticketB[j]);
        }
        sort(ticketA, ticketA + a);
        sort(ticketB, ticketB + b);
        if (ticketA[0] != 1)
        {
            printf("GIVE GIRL %d GUY 1\n", ticketB[0]);
            ticketB[0] = -1;
        }
        printf("ENTER GUY 1\n");
        if (m != 1)
        {
            if (ticketA[0] != 2 && ticketA[1] != 2)
            {
                if (ticketB[0] != -1)
                {
                    printf("GIVE GIRL %d GUY 2\n", ticketB[0]);
                }
                else if (b > 1)
                {
                    printf("GIVE GIRL %d GUY 2\n", ticketB[1]);
                }
                else
                {
                    printf("GIVE GUY %d GUY 2\n", ticketA[a - 1]);
                }
            }
            printf("ENTER GUY 2\n");
            for (int i = 3; i <= m; ++i)
            {
                printf("GIVE GUY %d GUY 1\n", i - 1);
                printf("EXIT GUY 1\n");
                printf("GIVE GUY 1 GUY %d\n", i);
                printf("ENTER GUY 1\n");
                printf("ENTER GUY %d\n", i);
            }
        }
    }
    return 0;
}
