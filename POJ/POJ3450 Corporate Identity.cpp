#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 4005;
const int MAXM = 205;

int n, len[MAXN];
char str[MAXN][MAXM];
char ansStr[MAXM];
int next[MAXM];

void getNext(char *s, int len)
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int kmp(char *s1, char *s2, int len1, int len2)
{
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (s1[i] == s2[j] || j == -1)
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= len2)
    {
        return i - len2;
    }
    return -1;
}

int main()
{
    while (scanf("%d", &n), n)
    {
        int minIndex = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", str[i]);
            len[i] = strlen(str[i]);
            if (len[i] < len[minIndex])
            {
                minIndex = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < len[minIndex]; ++i)
        {
            if (len[minIndex] - i < ans)
            {
                break;
            }
            getNext(str[minIndex] + i, len[minIndex] - i);
            for (int j = len[minIndex]; j > i; --j)
            {
                if (ans != 0 && j - i < ans)
                {
                    break;
                }
                char temp = str[minIndex][j];
                str[minIndex][j] = 0;
                bool flag = true;
                for (int k = 0; k < n; ++k)
                {
                    if (k == minIndex)
                    {
                        continue;
                    }
                    if (kmp(str[k], str[minIndex] + i, len[k], j - i) == -1)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    if (ans == 0 || (ans != 0 && j - i > ans))
                    {
                        ans = j - i;
                        strcpy(ansStr, str[minIndex] + i);
                    }
                    else
                    {
                        if (strcmp(str[minIndex] + i, ansStr) < 0)
                        {
                            strcpy(ansStr, str[minIndex] + i);
                        }
                    }
                }
                str[minIndex][j] = temp;
            }
        }
        if (ans == 0)
        {
            printf("IDENTITY LOST\n");
        }
        else
        {
            printf("%s\n", ansStr);
        }
    }
    return 0;
}
