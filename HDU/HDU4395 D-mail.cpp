#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 400005;
const int MAXM = 205;
const int SHIFT = 20000;
const int MAXS = SHIFT * 2;

bool dp[2][MAXN];
char str[100];
int mails[MAXM];

int readInt()
{
    int res = 0;
    bool flag = false;
    scanf("%s", str);
    for(int i=0;str[i];++i)
    {
        if(str[i] == '-')
        {
            flag = true;
        }
        else if(str[i] == '.')
        {
            continue;
        }
        else
        {
            res = res * 10 + str[i] - '0';
        }
    }
    if(flag)
    {
        res = - res;
    }
    return res;
}

int main()
{
    int d, n, dmail;
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        d = readInt() + SHIFT;
        scanf("%d", &n);
        int cur, pre;
        cur = 0, pre = 1;
        memset(dp[cur], false, sizeof(dp[cur]));
        dp[cur][SHIFT] = true;
        for(int i=0;i<n;++i)
        {
            mails[i] = readInt();
        }
        sort(mails, mails + n);
        for(int i=0;i<n;++i)
        {
            cur = !cur;
            pre = !pre;
            memcpy(dp[cur], dp[pre], sizeof(dp[cur]));
            dmail = mails[i];
            for(int j=0;j<MAXS;++j)
            {
                if(dp[pre][j])
                {
                    if(j + dmail >= 0 && j + dmail < MAXS)
                    {
                        dp[cur][j + dmail] = true;
                    }
                }
            }
        }
        int mini = MAXS, value;
        for(int i=0;i<MAXS;++i)
        {
            if(dp[cur][i])
            {
                if(abs(i - d) < mini)
                {
                    mini = abs(i - d);
                    value = i;
                }
            }
        }
        printf("%.4lf\n", (value - SHIFT) / 10000.0);
    }
    return 0;
}
