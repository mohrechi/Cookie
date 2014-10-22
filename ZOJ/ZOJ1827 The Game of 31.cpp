#include <cstdio>
#include <cstring>
const int MAXN = 16000;

int getStatus(int num[])
{
    int status = 0;
    for (int i = 1; i <= 6; ++i)
    {
        status = status * 5 + num[i];
    }
    return status;
}

void getNum(int num[], int status)
{
    for (int i = 6; i >= 1; --i)
    {
        num[i] = status % 5;
        status /= 5;
    }
}

int pn[MAXN];

int getPN(int status, int cnt)
{
    if (pn[status] != -1)
    {
        return pn[status];
    }
    if (cnt >= 31)
    {
        return pn[status] = cnt != 31;
    }
    int num[10];
    getNum(num, status);
    for (int i = 1; i <= 6; ++i)
    {
        if (num[i])
        {
            --num[i];
            int temp = getStatus(num);
            if (getPN(temp, cnt + i) == 0)
            {
                return pn[status] = 1;
            }
            ++num[i];
        }
    }
    return pn[status] = 0;
}

int main()
{
    int i, num[10], cnt;
    char str[100];
    memset(pn, -1, sizeof(pn));
    while (~scanf("%s", str))
    {
        cnt = 0;
        for (i = 1; i <= 6; ++i)
        {
            num[i] = 4;
        }
        for (i = 0; str[i]; ++i)
        {
            --num[str[i] - '0'];
            cnt += str[i] - '0';
        }
        printf("%s %c\n", str, (i & 1) != getPN(getStatus(num), cnt) ? 'A' : 'B');
    }
    return 0;
}
