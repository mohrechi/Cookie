#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char name[5][20] =
{
    "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"
};

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int cur = 5;
        while(true)
        {
            if(n <= cur)
            {
                cur /= 5;
                printf("%s\n", name[(n - 1) / cur]);
                break;
            }
            else
            {
                n -= cur;
                cur *= 2;
            }
        }
    }
    return 0;
}
