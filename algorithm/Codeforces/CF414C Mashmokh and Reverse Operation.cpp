#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 21;

int n, m;
int a[1 << MAXN], b[1 << MAXN];
long long dec[MAXN], inc[MAXN];

void mergeSort(int l, int r, int depth)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    mergeSort(l, mid, depth - 1);
    mergeSort(mid + 1, r, depth - 1);
    int t1 = mid, t2 = r;
    while (t1 >= l && t2 > mid)
    {
        if (a[t1] >= a[t2])
        {
            --t1;
        }
        else
        {
            inc[depth] += t1 - l + 1;
            --t2;
        }
    }
    int index = l;
    t1 = l, t2 = mid + 1;
    while (t1 <= mid && t2 <= r)
    {
        if (a[t1] <= a[t2])
        {
            b[index++] = a[t1++];
        }
        else
        {
            dec[depth] += mid - t1 + 1;
            b[index++] = a[t2++];
        }
    }
    while (t1 <= mid)
    {
        b[index++] = a[t1++];
    }
    while (t2 <= r)
    {
        b[index++] = a[t2++];
    }
    for (int i = l; i <= r; ++i)
    {
        a[i] = b[i];
    }
}

int main()
{
    int q;
    scanf("%d", &n);
    for (int i = 1; i <= (1 << n); ++i)
    {
        scanf("%d", &a[i]);
    }
    mergeSort(1, 1 << n, n);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &q);
        for (int i = 1; i <= q; ++i)
        {
            swap(inc[i], dec[i]);
        }
        long long sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            sum += dec[i];
        }
        printf("%I64d\n", sum);
    }
    return 0;
}
