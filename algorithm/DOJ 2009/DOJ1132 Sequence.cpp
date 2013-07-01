#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
static const int MAXN = 50005;
static const int INF = 0x7FFFFFFF;
int number[MAXN], stack[MAXN];
int n, top, length[MAXN], maxLength;
struct Node
{
    int length;
    int index;
    int value;
    bool operator < (const Node &n) const
    {
        if(length == n.length)
        {
            return value < n.value;
        }
        return length < n.length;
    }
}node[MAXN];
int intervalNumber;
int start[MAXN], end[MAXN];
int next[MAXN], ans[MAXN];

void getIncreaseLength()
{
    top = 0;
    stack[top++] = number[n-1];
    length[n-1] = top;
    for(int i=n-2;i>=0;--i)
    {
        if(number[i] < stack[top-1])
        {
            stack[top++] = number[i];
            length[i] = top;
        }
        else
        {
            int low = 0, high = top - 1;
            int mid;
            while(low <= high)
            {
                mid = (low + high) >> 1;
                if(stack[mid] <= number[i])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            stack[++high] = number[i];
            length[i] = high + 1;
        }
    }
    maxLength = top;
}

void getInterval()
{
    for(int i=0;i<n;++i)
    {
        node[i].length = length[i];
        node[i].index = i;
        node[i].value = number[i];
    }
    sort(node, node + n);
    int i;
    start[node[0].length] = 0;
    for(i=1;i<n;++i)
    {
        if(node[i].length == node[i-1].length)
        {
            continue;
        }
        end[node[i-1].length] = i - 1;
        start[node[i].length] = i;
    }
    end[node[i-1].length] = i - 1;
}

inline int lowbit(int x)
{
    return x & (-x);
}

void getNext()
{
    int lastIndex = -1;
    int lastAnswer = -1;
    for(int i=maxLength;i>=1;--i)
    {
        for(int j=start[i];j<=end[i];++j)
        {
            if(node[j].index > lastIndex && node[j].value > lastAnswer)
            {
                ans[i] = node[j].value;
                lastIndex = node[j].index;
                lastAnswer = node[j].value;
            }
        }
    }
}

void output()
{
    for(int i=maxLength;i>1;--i)
    {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[1]);
}

int main(int argc, char *argv[])
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &number[i]);
        }
        getIncreaseLength();
        getInterval();
        getNext();
        output();
    }
}
