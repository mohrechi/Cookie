#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[10];
int num[80];

int main()
{
    int n, a[10];
    while(~scanf("%s", s))
    {
        memset(num, 0, sizeof(num));
        for(int i=0;i<6;++i)
        {
            ++ num[s[i] - 'A'];
        }
        n = 0;
        for(int i=0;i<26;++i)
        {
            if(num[i])
            {
                a[n++] = num[i];
            }
        }
        int ans;
        switch(n)
        {
            case 1:
                ans = 1;
                break;
            case 2:
                if(a[0] == 1 || a[1] == 1)
                {
                    ans = 1;
                }
                else
                {
                    ans = 2;
                }
                break;
            case 3:
                if(a[0] == 3 || a[1] == 3 || a[2] == 3)
                {
                    ans = 3;
                }
                else if(a[0] == 2 && a[1] == 2 && a[2] == 2)
                {
                    ans = 6;
                }
                else
                {
                    ans = 2;
                }
                break;
            case 4:
                if(a[0] == 3 || a[1] == 3 || a[2] == 3 || a[3] == 3)
                {
                    ans = 5;
                }
                else
                {
                    ans = 8;
                }
                break;
            case 5:
                ans = 15;
                break;
            case 6:
                ans = 30;
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
