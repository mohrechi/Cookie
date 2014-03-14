#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ans;

void gcd(int a, int b)
{
    if (b == 0)
    {
        --ans;
        return;
    }
    if (a / b >= 2)
    {
        return;
    }
    ++ans;
    gcd(b, a % b);
}

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b), a || b)
    {
        ans = 0;
        gcd(max(a, b), min(a, b));
		if (ans & 1)
        {
            puts("Kousaka kirino wins");
        }
		else
        {
            puts("newSolar wins");
        }
    }
    return 0;
}
