#include <set>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        string s;
        set<string> num;
        while (n--)
        {
            cin >> s;
            num.insert(s);
        }
        cout << num.size() << endl;
    }
    return 0;
}
