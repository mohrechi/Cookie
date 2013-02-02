#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1000];

long long getNum(int st, int ed)
{
    long long res = 0;
    for(int i=st;i<ed;++i)
    {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

int main()
{
    while(~scanf("%s", s))
    {
        int pos;
        int len = strlen(s);
        for(int i=0;s[i];++i)
        {
            if(s[i] == '+')
            {
                pos = i;
                break;
            }
        }
        long long a = getNum(0, pos);
        long long b = getNum(pos + 1, len);
        printf("%lld\n", a+b);
    }
    return 0;
}
