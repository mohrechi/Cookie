#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 105;

string a[MAXN];
string b;

int main()
{
    int n, m;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cin >> m;
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> b;
            for (int j = 0; j < n; ++j)
            {
                if (a[j] == b)
                {
                    ++ans;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
