#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void printLine(int n, int i)
{
    int preSpace = (n - i) << 1;
    while(preSpace--)
    {
        printf(" ");
    }
    for(int j=0;j<i;++j)
    {
        printf("%d ", j);
    }
    for(int j=i;j>0;--j)
    {
        printf("%d ", j);
    }
    printf("0\n");
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            printLine(n, i);
        }
        for(int i=n;i>=0;--i)
        {
            printLine(n, i);
        }
    }
    return 0;
}
