#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char temp[105];
char ans[505][105];
char trueAns[505][105];
int ansNum;

void find(const char *s)
{
    bool isNum = false;
    int j = 0;
    for (int i = 0; s[i]; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            isNum = true;
            ans[ansNum][j++] = s[i];
        }
        else
        {
            if (isNum)
            {
                ans[ansNum][j] = 0;
                ++ansNum;
                j = 0;
            }
            isNum = false;
        }
    }
    if (isNum)
    {
        ans[ansNum][j] = 0;
        ++ansNum;
    }
}

void add()
{
    for (int i = 0; i < ansNum; ++i)
    {
        int len = strlen(ans[i]);
        int num = 102 - len;
        for (int j = 0; j < num; ++j)
        {
            trueAns[i][j] = '0';
        }
        trueAns[i][num] = 0;
        strcat(trueAns[i], ans[i]);
    }
    for (int i = 0; i < ansNum; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (strcmp(trueAns[i], trueAns[j]) < 0)
            {
                strcpy(temp, trueAns[i]);
                strcpy(trueAns[i], trueAns[j]);
                strcpy(trueAns[j], temp);
            }
        }
    }
}

void print()
{
    for (int i = 0; i < ansNum; ++i)
    {
        int j;
        for (j = 0; trueAns[i][j]; ++j)
        {
            if (trueAns[i][j] != '0')
            {
                break;
            }
        }
        if (!trueAns[i][j])
        {
            printf("0\n");
        }
        else
        {
            printf("%s\n", trueAns[i] + j);
        }
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        ansNum = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", temp);
            find(temp);
        }
        add();
        print();
    }
    return 0;
}
