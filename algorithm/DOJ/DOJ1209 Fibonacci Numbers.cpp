#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct BigInteger
{
    int len;
    char data[1005];

    void clear()
    {
        len = 0;
        memset(data, 0, sizeof(data));
    }

    void print()
    {
        for(int i=len-1;i>=0;--i)
        {
            printf("%d", data[i]);
        }
        printf("\n");
    }
} fib[5005];

void add(BigInteger &a, BigInteger &b, BigInteger &c)
{
    bool carry = 0;
    c.clear();
    c.len = max(a.len, b.len);
    for(int i=0;i<c.len;++i)
    {
        c.data[i] = a.data[i] + b.data[i] + carry;
        if(c.data[i] > 9)
        {
            carry = 1;
            c.data[i] -= 10;
        }
        else
        {
            carry = 0;
        }
    }
    if(carry)
    {
        c.data[c.len ++] = 1;
    }
}

void init()
{
    fib[1].clear();
    fib[2].clear();
    fib[1].len = fib[2].len = 1;
    fib[1].data[0] = fib[2].data[0] = 1;
    for(int i=3;;++i)
    {
        add(fib[i - 1], fib[i - 2], fib[i]);
        if(fib[i].len > 1000)
        {
            return;
        }
    }
}

int main()
{
    int n;
    init();
    while(~scanf("%d", &n))
    {
        fib[n].print();
    }
    return 0;
}
