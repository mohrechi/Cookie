#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n, s[MAXN];

int main()
{
    while(scanf("%d", &n), n)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &s[i]);
        }
        sort(s, s + n);
        int num = 1;
        for(int i=1;i<n;++i)
        {
            if(s[i] == s[i-1])
            {
                continue;
            }
            s[num ++] = s[i];
        }
        n = num;
        bool haveSolution = false;
        int ans;
        for(int l=n-1;l>=0 && !haveSolution;--l)
        {
            for(int i=0;i<n-2 && !haveSolution;++i)
            {
                int j = i + 1;
                int k = n - 1;
                while(j < k)
                {
                    int t = s[i] + s[j] + s[k];
                    if(t == s[l])
                    {
                        if(i == l || j == l || k == l)
                        {
                            break;
                        }
                        haveSolution = true;
                        ans = t;
                        break;
                    }
                    else if(t > s[l])
                    {
                        -- k;
                    }
                    else
                    {
                        ++ j;
                    }
                }
            }
        }
        if(haveSolution)
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("no solution\n");
        }
    }
    return 0;
}
