#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 105;

int main()
{
    long long a, b;
    char s[MAXN];
    long long x[MAXN * 2], y[MAXN * 2];
    while (cin >> a >> b)
    {
        scanf("%s", s + 1);
        bool flag = false;
        int n = strlen(s + 1);
        x[0] = y[0] = 0;
        if (a == 0 && b == 0)
        {
            flag = true;
        }
        for (int i = 1; i <= n && !flag; ++i)
        {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
            switch (s[i])
            {
            case 'U':
                y[i] = y[i - 1] + 1;
                break;
            case 'D':
                y[i] = y[i - 1] - 1;
                break;
            case 'L':
                x[i] = x[i - 1] - 1;
                break;
            case 'R':
                x[i] = x[i - 1] + 1;
                break;
            }
            if (x[i] == a && y[i] == b)
            {
                flag = true;
            }
        }
        for (int i = 1; i <= n && !flag; ++i)
        {
            x[n + i] = x[n + i - 1];
            y[n + i] = y[n + i - 1];
            switch (s[i])
            {
            case 'U':
                y[n + i] = y[n + i - 1] + 1;
                break;
            case 'D':
                y[n + i] = y[n + i - 1] - 1;
                break;
            case 'L':
                x[n + i] = x[n + i - 1] - 1;
                break;
            case 'R':
                x[n + i] = x[n + i - 1] + 1;
                break;
            }
            if (x[n + i] == a && y[n + i] == b)
            {
                flag = true;
            }
        }
        for (int i = 1; i <= n && !flag; ++i)
        {
            x[n + i] -= x[i];
            y[n + i] -= y[i];
            if (x[n + i] && y[n + i])
            {
                if ((a - x[i]) % x[n + i] == 0)
                {
                    if ((b - y[i]) % y[n + i] == 0)
                    {
                        if ((a - x[i]) / x[n + i] > 0)
                        {
                            if ((a - x[i]) / x[n + i] == (b - y[i]) / y[n + i])
                            {
                                flag = true;
                            }
                        }
                    }
                }
            }
            else if (x[n + i] && !y[n + i])
            {
                if ((a - x[i]) % x[n + i] == 0)
                {
                    if ((a - x[i]) / x[n + i] > 0)
                    {
                        if (b == y[i])
                        {
                            flag = true;
                        }
                    }
                }
            }
            else if (!x[n + i] && y[n + i])
            {
                if ((b - y[i]) % y[n + i] == 0)
                {
                    if ((b - y[i]) / y[n + i] > 0)
                    {
                        if (a == x[i])
                        {
                            flag = true;
                        }
                    }
                }
            }
        }
        if (flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
