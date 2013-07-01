#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MAXM = 1005;
const double eps = 1e-8;

int n, m;
int color[MAXN];
int segNum, segSize;

struct Segment
{
    int sameColor;
    map<int, int> colorNum;
}segment[MAXM];

void hash(int index)
{
    segment[index].sameColor = -1;
    segment[index].colorNum.clear();
    int start = index * segSize;
    for(int i=0;i<segSize && i+start<n;++i)
    {
        ++ segment[index].colorNum[color[i+start]];
    }
}

void init()
{
    segSize = (int) sqrt(n + eps);
    segNum = n / segSize;
    if(n % segSize)
    {
        ++ segNum;
    }
    for(int i=0;i<segNum;++i)
    {
        hash(i);
    }
}

void relax(int index)
{
    if(segment[index].sameColor != -1)
    {
        int start = index * segSize;
        int cnt = 0;
        for(int i=0;i<segSize && i+start<n;++i)
        {
            color[i + start] = segment[index].sameColor;
            ++ cnt;
        }
        segment[index].colorNum.clear();
        segment[index].colorNum[segment[index].sameColor] = cnt;
        segment[index].sameColor = -1;
    }
}

void update(int l, int r, int c)
{
    int indexL = l / segSize;
    int indexR = r / segSize;
    if(indexL == indexR)
    {
        relax(indexL);
        for(int i=l;i<=r;++i)
        {
            color[i] = c;
        }
        hash(indexL);
    }
    else
    {
        relax(indexL);
        relax(indexR);
        int endL = (indexL + 1) * segSize;
        for(int i=l;i<endL;++i)
        {
            color[i] = c;
        }
        hash(indexL);
        int startR = indexR * segSize;
        for(int i=startR;i<=r;++i)
        {
            color[i] = c;
        }
        hash(indexR);
        for(int i=indexL+1;i<indexR;++i)
        {
            segment[i].sameColor = c;
        }
    }
}

int query(int l, int r, int c)
{
    int indexL = l / segSize;
    int indexR = r / segSize;
    int ret = 0;
    if(indexL == indexR)
    {
        relax(indexL);
        for(int i=l;i<=r;++i)
        {
            if(color[i] == c)
            {
                ++ ret;
            }
        }
    }
    else
    {
        relax(indexL);
        relax(indexR);
        int endL = (indexL + 1) * segSize;
        for(int i=l;i<endL;++i)
        {
            if(color[i] == c)
            {
                ++ ret;
            }
        }
        int startR = indexR * segSize;
        for(int i=startR;i<=r;++i)
        {
            if(color[i] == c)
            {
                ++ ret;
            }
        }
        for(int i=indexL+1;i<indexR;++i)
        {
            if(segment[i].sameColor == -1)
            {
                if(segment[i].colorNum.find(c) != segment[i].colorNum.end())
                {
                    ret += segment[i].colorNum[c];
                }
            }
            else
            {
                if(segment[i].sameColor == c)
                {
                    ret += segSize;
                }
            }
        }
    }
    return ret;
}

int main()
{
    int a, l, r, c;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &color[i]);
        }
        init();
        while(m--)
        {
            scanf("%d%d%d%d", &a, &l, &r, &c);
            if(a == 1)
            {
                update(l, r, c);
            }
            else
            {
                printf("%d\n", query(l, r, c));
            }
        }
    }
    return 0;
}
