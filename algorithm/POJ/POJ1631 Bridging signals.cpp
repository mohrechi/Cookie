#include <cstdio>
static const int MAXN = 40000;

int a[MAXN], b[MAXN], n;

int find(int num, int k)
{
    int low = 1, high = k;
    while(low <= high)
    {
        int mid = (low + high)>>1;
        if(num >= b[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int LIS()
{
	int low = 1, high = n;
	int k = 1;
	b[1] = a[1];
	for(int i=2; i<=n; ++i)
		if(a[i] >= b[k])
			b[++k] = a[i];
		else
			b[find(a[i], k)] = a[i];
	return k;
}

int main(int argc, char *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
        }
        printf("%d\n", LIS());
    }
    return 0;
}
