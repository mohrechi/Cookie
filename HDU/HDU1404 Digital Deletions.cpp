#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2e6;

int pos[MAXN];

int getStatus(char s[])
{
    int status = 1;
    for (int i = 0; s[i]; ++i)
    {
        status = status * 10 + s[i] - '0';
    }
    return status;
}

void getStr(int status, char s[])
{
    int temp = status, cnt = 0;
    while (temp)
    {
        temp /= 10;
        ++cnt;
    }
    s[--cnt] = 0;
    for (--cnt; cnt >= 0; --cnt)
    {
        s[cnt] = status % 10 + '0';
        status /= 10;
    }
}

int solve(int status)
{
    if (pos[status])
    {
        return pos[status];
    }
    char s[10];
    getStr(status, s);
    int i;
    for (i = 0; s[i]; ++i)
    {
        if (s[i] > '0')
        {
            char temp = s[i];
            while (s[i] > '0')
            {
                --s[i];
                if (solve(getStatus(s)) == -1)
                {
                    return pos[status] = 1;
                }
            }
            s[i] = temp;
        }
    }
    for (--i; i >= 0; --i)
    {
        if (s[i] == '0')
        {
            s[i] = 0;
            if (solve(getStatus(s)) == -1)
            {
                return pos[status] = 1;
            }
        }
    }
    return pos[status] = -1;
}

int main()
{
    char s[10];
    pos[1] = -1;
    while (~scanf("%s", s))
    {
        puts(solve(getStatus(s)) == 1 ? "Yes" : "No");
    }
    return 0;
}
