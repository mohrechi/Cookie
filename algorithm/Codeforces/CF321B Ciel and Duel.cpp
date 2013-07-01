#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

struct Card
{
    int position, strength;
    inline void input1()
    {
        char s[10];
        scanf("%s%d", s, &strength);
        position = s[0] == 'A';
    }
    inline void input2()
    {
        scanf("%d", &strength);
        position = 1;
    }
} cardA[MAXN], cardB[MAXN];

bool compare1(const Card &a, const Card &b)
{
    if (a.position == b.position)
    {
        return a.strength < b.strength;
    }
    return a.position > b.position;
}

bool compare2(const Card &a, const Card &b)
{
    return a.strength > b.strength;
}

bool compare3(const Card &a, const Card &b)
{
    if (a.position == b.position)
    {
        return a.strength < b.strength;
    }
    return a.position < b.position;
}

bool compare4(const Card &a, const Card &b)
{
    return a.strength < b.strength;
}

int n, m;
bool visit[MAXN];

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; ++i)
        {
            cardA[i].input1();
        }
        for (int i = 0; i < m; ++i)
        {
            cardB[i].input2();
        }
        int sum1 = 0;
        sort(cardA, cardA + n, compare1);
        sort(cardB, cardB + m, compare2);
        for (int i = 0; i < min(n, m); ++i)
        {
            if (cardA[i].position == 1)
            {
                if (cardB[i].strength > cardA[i].strength)
                {
                    sum1 += cardB[i].strength - cardA[i].strength;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        int sum2 = 0;
        if (m >= n)
        {
            bool flag = true;
            memset(visit, false, sizeof(visit));
            sort(cardA, cardA + n, compare3);
            sort(cardB, cardB + m, compare4);
            int i, j;
            for (i = 0, j = 0; i < n; ++i)
            {
                if (cardA[i].position == 1)
                {
                    break;
                }
                while (cardB[j].strength <= cardA[i].strength)
                {
                    if (++j >= m)
                    {
                        flag = false;
                    }
                }
                visit[j++] = true;
            }
            for (j = 0; i < n; ++i)
            {
                while (cardB[j].strength < cardA[i].strength || visit[j])
                {
                    if (++j >= m)
                    {
                        flag = false;
                    }
                }
                sum2 += cardB[j].strength - cardA[i].strength;
                visit[j++] = true;
            }
            if (flag)
            {
                for (j = 0; j < m; ++j)
                {
                    if (!visit[j])
                    {
                        sum2 += cardB[j].strength;
                    }
                }
            }
            else
            {
                sum2 = 0;
            }
        }
        printf("%d\n", max(sum1, sum2));
    }
    return 0;
}
