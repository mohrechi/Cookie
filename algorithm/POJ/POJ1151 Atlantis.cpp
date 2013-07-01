#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAXN 105

struct Rectangle
{
    double left, right;
    double up, bottom;
}rect[MAXN];
double x[MAXN * 2];
double y[MAXN * 2];
bool xy[MAXN*2][MAXN*2];

int main(int argc, char *argv[])
{
    int n, caseNumber = 0;
    double sum;
    while(scanf("%d",&n),n)
    {
        sum = 0.0;
        for(int i=0;i<n;i++)
        {
            double left, up, right, bottom;
            scanf("%lf%lf%lf%lf",&left, &up, &right, &bottom);
            x[i] = rect[i].left = left;
            x[i + n] = rect[i].right = right;
            y[i] = rect[i].up = up;
            y[i + n] = rect[i].bottom = bottom;
        }
        int n2 = n * 2;
        sort(x, x + n2);
        sort(y, y + n2);
        memset(xy, false, sizeof(xy));
        for(int i=0;i<n;i++)
        {
            int left,right,up,bottom,j;
            for(j=0;j<n2;++j)
            {
                if(rect[i].left == x[j])
                {
                    left = j;
                    break;
                }
            }
            for(;j<n2;++j)
            {
                if(rect[i].right == x[j])
                {
                    right = j;
                    break;
                }
            }
            for(j=0;j<n2;++j)
            {
                if(rect[i].up == y[j])
                {
                    up = j;
                    break;
                }
            }
            for(;j<n2;++j)
            {
                if(rect[i].bottom == y[j])
                {
                    bottom = j;
                    break;
                }
            }
            for(int j=left+1;j<=right;++j)
            {
                for(int k=up+1;k<=bottom;++k)
                {
                    xy[j][k] = true;
                }
            }
        }
        for(int i=1;i<n2;++i)
        {
            for(int j=1;j<n2;++j)
            {
                if(xy[i][j])
                {
                    sum += (x[i] - x[i-1]) * (y[j] - y[j-1]);
                }
            }
        }
        printf("Test case #%d\n",++caseNumber);
        printf("Total explored area: %.2lf\n\n",sum);
    }
    return 0;
}
