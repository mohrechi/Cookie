#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1111;

inline void printX(int x, int v, bool show)
{
    if(0 == v)
    {
        return;
    }
    if(show)
    {
        if(v > 0)
        {
            printf("+");
        }
        else
        {
            printf("-");
        }
    }
    if(0 == x)
    {
        printf("1");
    }
    else
    {
        if(v != 1 && v != -1)
        {
            printf("%d", abs(v));
        }
        printf("x");
        if(x > 1)
        {
            printf("^%d", x);
        }
    }
}

struct Polynomial
{
    int n;
    int value[MAXN];

    void output() const
    {
        printX(n, value[n], false);
        for(int i=n-1;i>=0;--i)
        {
            printX(i, value[i], true);
        }
    }
} intrinsic[MAXN], sets[MAXN];
int setNumber;
bool visit[MAXN];

bool operator < (const Polynomial &a, const Polynomial &b)
{
    if(a.n == b.n)
    {
        for(int i=a.n;i>=0;--i)
        {
            if(abs(a.value[i]) == abs(b.value[i]))
            {
                if(a.value[i] != b.value[i])
                {
                    return a.value[i] < b.value[i];
                }
            }
            else
            {
                return abs(a.value[i]) < abs(b.value[i]);
            }
        }
    }
    return a.n < b.n;
}

Polynomial operator / (Polynomial a, const Polynomial &b)
{
    Polynomial c;
    c.n = a.n - b.n;
    for(int i=c.n;i>=0;--i)
    {
        if(a.n - b.n < i)
        {
            c.value[i] = 0;
            continue;
        }
        c.value[i] = a.value[a.n] / b.value[b.n];
        int d = a.n - b.n;
        a.n -= b.n;
        for(int j=b.n;j>=0;--j)
        {
            a.value[j + d] -= b.value[j] * c.value[i];
            if(a.value[j + d])
            {
                a.n = max(a.n, j + d);
            }
        }
    }
    return c;
}

void makeSet(int n)
{
    setNumber = 0;
    for(int i=1;i<=n;++i)
    {
        if(0 == n % i)
        {
            if(!visit[i])
            {
                visit[i] = true;
                intrinsic[i].n = i;
                intrinsic[i].value[i] = 1;
                intrinsic[i].value[0] = -1;
                for(int j=1;j<i;++j)
                {
                    if(0 == i % j)
                    {
                        intrinsic[i] = intrinsic[i] / intrinsic[j];
                    }
                }
            }
            sets[setNumber++] = intrinsic[i];;
        }
    }
    sort(sets, sets + setNumber);
}

int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        if(1 == n)
        {
            printf("x-1\n");
        }
        else
        {
            makeSet(n);
            for(int i=0;i<setNumber;++i)
            {
                printf("(");
                sets[i].output();
                printf(")");
            }
            printf("\n");
        }
    }
    return 0;
}
