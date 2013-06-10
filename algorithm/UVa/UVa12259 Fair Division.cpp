#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int p, n;
int ans[MAXN];
bool visit[MAXN];

struct Person
{
    int index, cent, pay;
    bool operator <(const Person &person) const
    {
        if (cent == person.cent)
        {
            return index < person.index;
        }
        return cent > person.cent;
    }
} person[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &p, &n);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &person[i].cent);
            person[i].index = i;
            person[i].pay = 0;
            sum += person[i].cent;
        }
        if (sum < p)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            sort(person, person + n);
            memset(visit, false, sizeof(visit));
            int count = n;
            while (p)
            {
                int minCent = p / count;
                if (minCent == 0)
                {
                    minCent = 1;
                }
                for (int i = 0; i < n; ++i)
                {
                    if (!visit[i])
                    {
                        minCent = min(minCent, person[i].cent - person[i].pay);
                    }
                }
                for (int i = 0; i < n; ++i)
                {
                    if (!visit[i])
                    {
                        if (p > minCent)
                        {
                            person[i].pay += minCent;
                            if (person[i].pay == person[i].cent)
                            {
                                visit[i] = true;
                                --count;
                            }
                            p -= minCent;
                        }
                        else
                        {
                            person[i].pay += p;
                            p = 0;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < n; ++i)
            {
                ans[person[i].index] = person[i].pay;
            }
            for (int i = 0; i < n; ++i)
            {
                if (i)
                {
                    printf(" ");
                }
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
