#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, N;
    while (~scanf("%d%d%d", &n, &m, &N))
    {
        printf("%d\n", min(N, (int)(floor(((double)m * N + m) / n))));
    }
    return 0;
}
