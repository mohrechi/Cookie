#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

char s[MAXN];
int num[5];

int main()
{
    while(~scanf("%s", s + 1))
    {
        memset(num, 0, sizeof(num));
        for(int i=1;s[i];++i)
        {
            switch(s[i])
            {
                case 'w':
                    ++ num[0];
                    break;
                case 'o':
                    if(num[1] < num[0])
                    {
                        ++ num[1];
                    }
                    break;
                case 'r':
                    if(num[2] < num[1])
                    {
                        ++ num[2];
                    }
                    break;
                case 'l':
                    if(num[3] < num[2])
                    {
                        ++ num[3];
                    }
                    break;
                case 'd':
                    if(num[4] < num[3])
                    {
                        ++ num[4];
                    }
                    break;
            }
        }
        printf("%d\n", num[4]);
    }
    return 0;
}
