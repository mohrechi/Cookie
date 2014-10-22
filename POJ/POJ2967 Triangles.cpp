#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

int n, a[MAXN];

int readInteger()
{
    int res = 0;
    char ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res;
}

bool judge(int a, int b, int c)
{
    return a > c - b;
}

bool judge()
{
    if(n <= 3)
    {
        return false;
    }
    if(judge(a[0], a[1], a[n-1]))
    {
        return false;
    }
    for(int i=2;i<n;++i)
    {
        if(judge(a[i-2], a[i-1], a[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    n = readInteger();
    for(int i=0;i<n;++i)
    {
        a[i] = readInteger();
    }
    sort(a, a + n);
    if(judge())
    {
        printf("The set is accepted.\n");
    }
    else
    {
        printf("The set is rejected.\n");
    }
    return 0;
}
