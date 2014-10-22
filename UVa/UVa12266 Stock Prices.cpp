#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int buy[MAXN], sell[MAXN];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        char op[10];
        scanf("%d", &n);
        int stockPrice = -1;
        int price, share;
        memset(buy, 0, sizeof(buy));
        memset(sell, 0, sizeof(sell));
        while (n--)
        {
            scanf("%s", op);
            if (op[0] == 's')
            {
                scanf("%d shares at %d", &share, &price);
                sell[price] += share;
            }
            else
            {
                scanf("%d shares at %d", &share, &price);
                buy[price] += share;
            }
            int askPrice = MAXN;
            int bidPrice = -1;
            for (int i = 0; i < MAXN; ++i)
            {
                if (sell[i])
                {
                    askPrice = i;
                    break;
                }
            }
            for (int i = MAXN - 1; i >= 0; --i)
            {
                if (buy[i])
                {
                    bidPrice = i;
                    break;
                }
            }
            if (askPrice != -1)
            {
                if (bidPrice != -1)
                {
                    while (askPrice <= bidPrice)
                    {
                        int deal = min(sell[askPrice], buy[bidPrice]);
                        sell[askPrice] -= deal;
                        buy[bidPrice] -= deal;
                        stockPrice = askPrice;
                        while (askPrice < MAXN && sell[askPrice] == 0)
                        {
                            ++askPrice;
                        }
                        while (bidPrice >= 0 && buy[bidPrice] == 0)
                        {
                            --bidPrice;
                        }
                    }
                }
            }
            if (askPrice == MAXN)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", askPrice);
            }
            if (bidPrice == -1)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", bidPrice);
            }
            if (stockPrice == -1)
            {
                printf("-\n");
            }
            else
            {
                printf("%d\n", stockPrice);
            }
        }
    }
    return 0;
}
