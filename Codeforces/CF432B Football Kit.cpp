#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, x, y;
    vector<int> home;
    vector<int> away;
    map<int, int> cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        home.push_back(x);
        away.push_back(y);
        ++cnt[x];
    }
    for (int i = 0; i < n; ++i)
    {
        x = n + cnt[away[i]] - 1;
        y = n + n - 2 - x;
        printf("%d %d\n", x, y);
    }
    return 0;
}
