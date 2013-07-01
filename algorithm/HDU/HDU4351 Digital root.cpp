#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100010;

struct TreeNode
{
    int l, r, sum;
    bool digit[10];
    bool left[10];
    bool right[10];
}tree[MAXN * 4];
int n, m, a[MAXN];

struct Digit
{
    bool digit[10];
    bool left[10];
    bool right[10];
    int sum;
}digit;

void printTreeNode(int x)
{
    printf("%d %d %d : ", x, tree[x].l, tree[x].r);
    for(int i=0;i<=9;++i)
    {
        if(tree[x].digit[i])
        {
            printf("%d ", i);
        }
    }
    printf(" L ");
    for(int i=0;i<=9;++i)
    {
        if(tree[x].left[i])
        {
            printf("%d ", i);
        }
    }
    printf(" R ");
    for(int i=0;i<=9;++i)
    {
        if(tree[x].right[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void buildTree(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    memset(tree[x].digit, false, sizeof(tree[x].digit));
    memset(tree[x].left, false, sizeof(tree[x].left));
    memset(tree[x].right, false, sizeof(tree[x].right));
    if(l == r)
    {
        tree[x].sum = a[l];
        tree[x].digit[a[l]] = true;
        tree[x].left[a[l]] = true;
        tree[x].right[a[l]] = true;
        return;
    }
    int mid = (l + r) >> 1;
    int left = x << 1;
    int right = left + 1;
    buildTree(left, l, mid);
    buildTree(right, mid + 1, r);
    tree[x].sum = tree[left].sum + tree[right].sum;
    if(tree[x].sum > 9)
    {
        tree[x].sum -= 9;
    }
    tree[x].digit[tree[x].sum] = true;
    tree[x].left[tree[x].sum] = true;
    tree[x].right[tree[x].sum] = true;
    for(int i=0;i<=9;++i)
    {
        if(tree[left].digit[i])
        {
            tree[x].digit[i] = true;
        }
        if(tree[left].left[i])
        {
            tree[x].left[i] = true;
        }
        if(tree[left].right[i])
        {
            int t = i + tree[right].sum;
            if(t > 9)
            {
                t -= 9;
            }
            tree[x].right[t] = true;
            tree[x].digit[t] = true;
        }
        if(tree[left].right[i])
        {
            for(int j=0;j<=9;++j)
            {
                if(tree[right].left[j])
                {
                    int t = i + j;
                    if(t > 9)
                    {
                        t -= 9;
                    }
                    tree[x].digit[t] = true;
                }
            }
        }
        if(tree[right].digit[i])
        {
            tree[x].digit[i] = true;
        }
        if(tree[right].left[i])
        {
            int t = tree[left].sum + i;
            if(t > 9)
            {
                t -= 9;
            }
            tree[x].left[t] = true;
            tree[x].digit[t] = true;
        }
        if(tree[right].right[i])
        {
            tree[x].right[i] = true;
        }
    }
}

void queryTree(int x, int l, int r, Digit &digit)
{
    if(tree[x].l == l && tree[x].r == r)
    {
        digit.sum = tree[x].sum;
        for(int i=0;i<=9;++i)
        {
            if(tree[x].digit[i])
            {
                digit.digit[i] = true;
            }
            if(tree[x].left[i])
            {
                digit.left[i] = true;
            }
            if(tree[x].right[i])
            {
                digit.right[i] = true;
            }
        }
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
    {
        queryTree(x << 1, l, r, digit);
    }
    else if(l > mid)
    {
        queryTree((x << 1) + 1, l, r, digit);
    }
    else
    {
        Digit left, right;
        memset(left.digit, false, sizeof(left.digit));
        memset(left.left, false, sizeof(left.left));
        memset(left.right, false, sizeof(left.right));
        memset(right.digit, false, sizeof(right.digit));
        memset(right.left, false, sizeof(right.left));
        memset(right.right, false, sizeof(right.right));
        queryTree(x << 1, l, mid, left);
        queryTree((x << 1) + 1, mid+1, r, right);
        digit.sum = left.sum + right.sum;
        if(digit.sum > 9)
        {
            digit.sum -= 9;
        }
        digit.digit[digit.sum] = true;
        digit.left[digit.sum] = true;
        digit.right[digit.sum] = true;
        for(int i=0;i<=9;++i)
        {
            if(left.digit[i])
            {
                digit.digit[i] = true;
            }
            if(left.left[i])
            {
                digit.left[i] = true;
            }
            if(left.right[i])
            {
                int t = i + right.sum;
                if(t > 9)
                {
                    t -= 9;
                }
                digit.right[t] = true;
                digit.digit[t] = true;
            }
            if(left.right[i])
            {
                for(int j=0;j<=9;++j)
                {
                    if(right.left[j])
                    {
                        int t = i + j;
                        if(t > 9)
                        {
                            t -= 9;
                        }
                        digit.digit[t] = true;
                    }
                }
            }
            if(right.digit[i])
            {
                digit.digit[i] = true;
            }
            if(right.left[i])
            {
                int t = left.sum + i;
                if(t > 9)
                {
                    t -= 9;
                }
                digit.left[t] = true;
                digit.digit[t] = true;
            }
            if(right.right[i])
            {
                digit.right[i] = true;
            }
        }
    }
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        if(cas > 1)
        {
            printf("\n");
        }
        scanf("%d", &n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
            if(a[i])
            {
                a[i] %= 9;
                if(a[i] == 0)
                {
                    a[i] = 9;
                }
            }
        }
        buildTree(1, 1, n);
        printf("Case #%d:\n", cas);
        scanf("%d", &m);
        int l, r;
        while(m--)
        {
            scanf("%d%d", &l, &r);
            memset(digit.digit, false, sizeof(digit.digit));
            memset(digit.left, false, sizeof(digit.left));
            memset(digit.right, false, sizeof(digit.right));
            queryTree(1, l, r, digit);
            int cnt = 0;
            for(int i=9;i>=0 && cnt<5;--i)
            {
                if(digit.digit[i])
                {
                    if(cnt)
                    {
                        printf(" ");
                    }
                    ++ cnt;
                    printf("%d", i);
                }
            }
            for(;cnt<5;++cnt)
            {
                if(cnt)
                {
                    printf(" ");
                }
                printf("-1");
            }
            printf("\n");
        }
    }
    return 0;
}
