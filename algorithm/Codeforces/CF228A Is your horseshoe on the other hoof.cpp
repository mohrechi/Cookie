#include <cstdio>
#include <cstring>

int main()
{
    int a[4], ans = 4;
    for(int i=0;i<4;++i)
    {
        scanf("%d", &a[i]);
        bool flag = true;
        for(int j=0;j<i;++j)
        {
            if(a[j] == a[i])
            {
                flag = false;
                break;
            }
        }
        ans -= flag;
    }
    printf("%d\n", ans);
    return 0;
}
