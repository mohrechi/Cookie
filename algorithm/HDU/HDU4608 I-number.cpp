#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n;
char s[MAXN];

int sum()
{
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res += s[i];
    }
    return res;
}

bool isSumValid()
{
    return sum() % 10 == 0;
}

void reverse()
{
    for (int i = 0; i < (n >> 1); ++i)
    {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
}

void add()
{
    int carry = 1;
    for (int i = 0; i < n; ++i)
    {
        s[i] += carry;
        if (s[i] > 9)
        {
            carry = 1;
            s[i] -= 10;
        }
        else
        {
            carry = 0;
            break;
        }
    }
    if (carry)
    {
        s[n++] = 1;
    }
}

void output()
{
    for (int i = n - 1; i >= 0; --i)
    {
        printf("%d", s[i]);
    }
    printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        for (n = 0; s[n]; ++n)
        {
            s[n] -= '0';
        }
        reverse();
        while (true)
        {
            add();
            if (isSumValid())
            {
                output();
                break;
            }
        }
    }
    return 0;
}
