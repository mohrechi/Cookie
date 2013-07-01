#include <cstdio>
#include <cstring>

static const int MAXN = 100010;
char ans[MAXN*10];
int stack[MAXN*10], next[MAXN];
int n, m, top, ansNumber;

void search(int temp)
{
    while(next[temp]<10)
    {
        stack[top]=next[temp]+++10*temp;
        temp=stack[top++] % m;
    }
}

int main(int argc, char *argv[])
{
    while(scanf("%d",&n),n)
    {
        memset(next, 0, sizeof(next));
        top = 0, m = 1, ansNumber = 0;
        for(int i=1;i<n;++i)
        {
            m *= 10;
            putchar('0');
        }
        search(0);
        while(top--)
        {
            ans[ansNumber++]=stack[top]%10+'0';
            search(stack[top]/10);
        }
        while(ansNumber--)
        {
            putchar(ans[ansNumber]);
        }
        putchar('\n');
    }
    return 0;
}
