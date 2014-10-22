#include <cstdio>
static const int MAXN = 10005;

int stack[MAXN], top;
bool inStack[MAXN];
int n, a;

int main()
{
    while(scanf("%d", &n), n)
    {
        bool flag = true;
        stack[0] = 0;
        top = 1;
        int cur = 1;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            if(flag)
            {
                if(stack[top-1] > a)
                {
                    flag = false;
                    continue;
                }
                while(stack[top-1] < a)
                {
                    stack[top++] = cur++;
                }
                top --;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
