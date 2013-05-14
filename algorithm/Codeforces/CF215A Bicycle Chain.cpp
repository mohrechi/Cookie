#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;

int n, m;
int a[MAXN], b[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        for(int i=0;i<m;++i)
        {
            scanf("%d", &b[i]);
        }
        int ratio = 0, num = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(b[j] % a[i] == 0)
                {
                    int temp = b[j] / a[i];
                    if(temp > ratio)
                    {
                        ratio = temp;
                        num = 1;
                    }
                    else if(temp == ratio)
                    {
                        ++ num;
                    }
                }
            }
        }
        printf("%d\n", num);
    }
    return 0;
}
