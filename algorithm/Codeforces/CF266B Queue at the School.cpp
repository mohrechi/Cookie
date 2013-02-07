#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;

char queue[MAXN];
bool next[MAXN];

int main()
{
    int n, t;
    while(~scanf("%d%d", &n, &t))
    {
        scanf("%s", queue);
        for(int i=0;i<t;++i)
        {
            memset(next, false, sizeof(next));
            for(int j=1;queue[j];++j)
            {
                if(queue[j - 1] == 'B' && queue[j] == 'G')
                {
                    next[j] = true;
                }
            }
            for(int j=1;queue[j];++j)
            {
                if(next[j])
                {
                    swap(queue[j - 1], queue[j]);
                }
            }
        }
        printf("%s\n", queue);
    }
    return 0;
}
