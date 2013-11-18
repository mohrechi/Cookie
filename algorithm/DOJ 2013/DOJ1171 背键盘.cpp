#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    char *s = "PQWERTYUIO";
    while (~scanf("%d", &n))
    {
        printf("%c\n", s[n]);
    }
    return 0;
}
