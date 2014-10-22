#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Card
{
    int value[3];
    int order;
    int compare;
    void input()
    {
        char s[5];
        for (int i = 0; i < 3; ++i)
        {
            scanf("%s", s);
            switch (s[0])
            {
            case '1':
                value[i] = 9;
                break;
            case 'J':
                value[i] = 10;
                break;
            case 'Q':
                value[i] = 11;
                break;
            case 'K':
                value[i] = 12;
                break;
            case 'A':
                value[i] = 13;
                break;
            default:
                value[i] = s[0] - '1';
            }
        }
        sort(value, value + 3);
        if (value[0] == value[1] && value[1] == value[2])
        {
            order = 4;
            compare = value[2];
        }
        else if (value[0] + 1 == value[1] && value[1] + 1 == value[2])
        {
            order = 3;
            compare = value[2];
        }
        else if (value[0] == value[1])
        {
            order = 2;
            compare = value[0] * 100 + value[2];
        }
        else if (value[1] == value[2])
        {
            order = 2;
            compare = value[1] * 100 + value[0];
        }
        else
        {
            order = 1;
            compare = value[2] * 10000 + value[1] * 100 + value[0];
        }
    }
    void output()
    {
        for (int i = 0; i < 3; ++i)
        {
            printf("%d ", value[i]);
        }
        printf("\n %d %d\n", order, compare);
    }
    bool operator <(const Card &card) const
    {
        if (order == card.order)
        {
            return compare < card.compare;
        }
        return order < card.order;
    }
};

int main()
{
    int n;
    Card a, b;
    scanf("%d", &n);
    while (n--)
    {
        a.input();
        b.input();
        if (a < b)
        {
            printf("lose\n");
        }
        else if (b < a)
        {
            printf("win\n");
        }
        else
        {
            printf("draw\n");
        }
    }
    return 0;
}
