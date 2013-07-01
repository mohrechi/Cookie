#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 4100;

bool visit[MAXN];
int num[MAXN];
int q[MAXN], front, rear;

void add(int v)
{
    if (!visit[v])
    {
        visit[v] = true;
        q[rear++] = v;
        if (++rear >= MAXN)
        {
            rear = 0;
        }
    }
}

void spfa()
{
    front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(num, 0x3f, sizeof(num));
    visit[0] = true;
    num[0] = 0;
    q[0] = 0;
    while (front != rear)
    {
        int u = q[front];
        if (u + 1< MAXN)
        {
            if (num[u + 1] > num[u] + 1)
            {
                num[u + 1] = num[u] + 1;
                add(u + 1);
            }
        }
        if (u - 1 >= 0)
        {
            if (num[u - 1] > num[u] + 1)
            {
                num[u - 1] = num[u] + 1;
                add(u - 1);
            }
        }
        if (u)
        {
            for (int i = 2; i * u < MAXN; ++i)
            {
                if (num[u * i] > num[u] + i)
                {
                    num[u * i] = num[u] + i;
                    add(u * i);
                }
            }
        }
        visit[u] = false;
        if (++front >= MAXN)
        {
            front = 0;
        }
    }
}

int main()
{
    int n;
    spfa();
    while (~scanf("%d", &n))
    {
        printf("%d\n", num[n]);
    }
    return 0;
}
