#include <deque>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

char s[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int len = strlen(s);
        int index = -1;
        int minNum = 9;
        for (int i = len - 1; i >= 0; --i)
        {
            s[i] -= '0';
            if (s[i] != 0)
            {
                if (s[i] < minNum)
                {
                    minNum = s[i];
                    index = i;
                }
            }
        }
        deque<int> q;
        for (int i = 0; i < len; ++i)
            if (s[i] == 0)
                if (i < index)
                    q.push_front(s[i]);
                else
                    q.push_back(s[i]);
            else
                if (index == i)
                    q.push_front(s[i]);
                else if (s[i] <= q.front())
                    q.push_front(s[i]);
                else
                    q.push_back(s[i]);
        for (deque<int>::iterator it = q.begin(); it != q.end(); ++it)
            printf("%d", *it);
        putchar('\n');
    }
    return 0;
}
