#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000;
const int MOD = 1000000007;

int pow2[MAXN];
char str[MAXN];
bool single[MAXN];

void init()
{
    pow2[0] = 1;
    for(int i=1;i<MAXN;++i)
    {
        pow2[i] = (pow2[i-1] << 1) % MOD;
    }
}

int main()
{
    init();
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber --)
    {
        scanf("%s", str);
        int len;
        bool flag = true;
        int redNum = 0, chooseNum = 0;
        for(len=0;str[len];++len)
        {
            single[len] = false;
            if(str[len] == '?')
            {
                ++ chooseNum;
            }
            else if(str[len] == 'R')
            {
                ++ redNum;
                if(flag)
                {
                    for(int i=len+1;str[i];++i)
                    {
                        if(str[i] == 'R')
                        {
                            if(((i+len)&1)==0)
                            {
                                if(str[(i+len)>>1] == 'G')
                                {
                                    flag = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = pow2[chooseNum];
        if(flag)
        {
            if(redNum == 0)
            {
                ans = (ans + MOD - 1 - chooseNum) % MOD;
            }
            else if(redNum == 1)
            {
                ans = (ans - 1) % MOD;
            }
            for(int i=1;i<len;i+=2)
            {
                for(int j=0;j<len;++j)
                {
                    if(str[j] == 'G')
                    {
                        continue;
                    }
                    if(i + j >= len)
                    {
                        if(str[j] == 'R')
                        {
                            break;
                        }
                        continue;
                    }
                    if(str[i+j] == 'G')
                    {
                        if(str[j] == 'R')
                        {
                            break;
                        }
                        continue;
                    }
                    flag = true;
                    bool haveGreen = false;
                    int right = i + j;
                    for(int k=j;k<len;++k)
                    {
                        if((k - j) % i)
                        {
                            if(str[k] == 'R')
                            {
                                flag = false;
                                break;
                            }
                        }
                        else
                        {
                            if(str[k] == 'G')
                            {
                                haveGreen = true;
                            }
                            else if(str[k] == 'R')
                            {
                                if(haveGreen)
                                {
                                    flag = false;
                                    break;
                                }
                                right = max(right, k);
                            }
                        }
                    }
                    if(flag)
                    {
                        int cnt = 1;
                        for(int k=right+i;k<len;k+=i)
                        {
                            if(str[k] == '?')
                            {
                                ++ cnt;
                            }
                            else
                            {
                                break;
                            }
                        }
                        ans = (ans + MOD - cnt) % MOD;
                    }
                    if(str[j] == 'R')
                    {
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
