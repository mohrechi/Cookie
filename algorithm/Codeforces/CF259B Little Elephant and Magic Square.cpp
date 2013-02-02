#include <cstdio>
#include <cstring>
#include <algorithm>

int a[3][3];

inline int make(int x)
{
    a[0][0] = x;
    int sum = a[0][0] + a[1][0] + a[2][0];
    a[1][1] = sum - a[0][1] - a[2][1];
    a[2][2] = sum - a[0][2] - a[1][2];
    return sum;
}

inline bool judge(int x)
{
    int sum = make(x);
    if(a[1][1] <= 0)
    {
        return false;
    }
    if(a[2][2] <= 0)
    {
        return false;
    }
    if(a[0][0] + a[0][1] + a[0][2] != sum)
    {
        return false;
    }
    if(a[1][0] + a[1][1] + a[1][2] != sum)
    {
        return false;
    }
    if(a[2][0] + a[2][1] + a[2][2] != sum)
    {
        return false;
    }
    if(a[0][0] + a[1][1] + a[2][2] != sum)
    {
        return false;
    }
    if(a[0][2] + a[1][1] + a[2][0] != sum)
    {
        return false;
    }
    return true;
}

void judge()
{
    for(int i=1;;++i)
    {
        if(judge(i))
        {
            return;
        }
    }
}

int main()
{
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    judge();
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(j)
            {
                printf(" ");
            }
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
