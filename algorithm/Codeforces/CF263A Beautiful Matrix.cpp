#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[5][5];

int main()
{
    int x, y;
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j])
            {
                x = i;
                y = j;
            }
        }
    }
    printf("%d\n", abs(x - 2) + abs(y - 2));
    return 0;
}
