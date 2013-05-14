#include <cstdio>
#include <cstring>
const int MAXN = 100005;

int a[MAXN];
bool b[MAXN];

inline int log2(int x)
{
    for(int i=0;;++i)
        if(x == (1<<i))
            return i;
}

int compare(int sum1, bool sign1, int sum2, bool sign2)
{
    if(sum1 != sum2)
    {
        if(!sign1) sum1 = - sum1;
        if(!sign2) sum2 = - sum2;
        if(sum1 == sum2) return 0;
        if(sum1 > sum2) return 1;
        if(sum1 < sum2) return -1;
    }
    else
    {
        if(sign1 == sign2) return 0;
        if(sign1) return 1;
        if(sign2) return -1;
    }
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        bool flag = false;
        int suma = 0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
            if(a[i] > 0)
            {
                a[i] = log2(a[i]);
                b[i] = true;
            }
            else
            {
                flag = !flag;
                a[i] = log2(-a[i]);
                b[i] = false;
            }
            suma += a[i];
        }
        if(n == 1) flag = false;
        if(flag)
        {
            int max = suma;
            bool msign = false;
            int s = 1, t = n;
            int sum = 0;
            bool sign = true;
            for(int i=1;i<n;++i)
            {
                sum += a[i];
                if(!b[i]) sign = !sign;
                if(compare(sum, sign, max, msign) == 1)
                {
                    max = sum;
                    msign = sign;
                    s = 1;
                    t = i;
                }
                else if(compare(sum, sign, max, msign) == 0)
                {
                    if(i > t)
                    {
                        t = i;
                    }
                }
            }
            sum = 0;
            sign = true;
            for(int i=n;i>1;--i)
            {
                sum += a[i];
                if(!b[i]) sign = !sign;
                if(compare(sum, sign, max, msign) == 1)
                {
                    max = sum;
                    msign = sign;
                    s = i;
                    t = n;
                }
                else if(compare(sum, sign, max, msign) == 0)
                {
                    if(i < s)
                    {
                        s = i;
                        t = n;
                    }
                }
            }
            printf("%d %d\n", s, t);
        }
        else
        {
            printf("1 %d\n", n);
        }
    }
    return 0;
}
