#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

char num[MAXN];
char ans[MAXN];

void generatePlain(int len)
{
    for (int i = 0; i < len >> 1; ++i)
    {
        ans[i] = '4';
    }
    for (int i = len >> 1; i < len; ++i)
    {
        ans[i] = '7';
    }
    ans[len] = 0;
}

bool trySame(int index = 0, bool bigger = false, int count4 = 0, int count7 = 0)
{
    if (num[index] == 0)
    {
        if (count4 >= index >> 1)
        {
            int count = count4 - (index >> 1);
            for (int i = index - 1; i >= 0 && count; --i)
            {
                if (ans[i] == '4')
                {
                    ans[i] = '7';
                    --count;
                }
            }
            ans[index] = 0;
            return true;
        }
        return false;
    }
    if (bigger)
    {
        ans [index] = '4';
        if (trySame(index + 1, true, count4 + 1, count7))
        {
            return true;
        }
    }
    else
    {
        if (num[index] < '4')
        {
            ans[index] = '4';
            if (trySame(index + 1, true, count4 + 1, count7))
            {
                return true;
            }
        }
        else if (num[index] == '4')
        {
            ans[index] = '4';
            if (trySame(index + 1, false, count4 + 1, count7))
            {
                return true;
            }
            ans[index] = '7';
            if (trySame(index + 1, true, count4, count7 + 1))
            {
                return true;
            }
        }
        else if (num[index] < '7')
        {
            ans[index] = '7';
            if (trySame(index + 1, true, count4, count7 + 1))
            {
                return true;
            }
        }
        else if (num[index] == '7')
        {
            ans[index] = '7';
            if (trySame(index + 1, false, count4, count7 + 1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while (~scanf("%s", num))
    {
        int len = strlen(num);
        if (len & 1)
        {
            generatePlain(len + 1);
        }
        else
        {
            if (!trySame())
            {
                generatePlain(len + 2);
            }
        }
        printf("%s\n", ans);
    }
    return 0;
}
