#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 205;
const double eps = 1e-8;

int dblcmp(double x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

int m, n;
double mat[MAXN][MAXN];

int getAns()
{
    int i=0;
    for(int j=0;i<m && j<n;++j)
    {
        int index = i;
        for(int k=i+1;k<m;++k)
        {
            if(fabs(mat[k][j]) > fabs(mat[index][j]))
            {
                index = k;
            }
        }
        if(index != i)
        {
            for(int k=j;k<n;++k)
            {
                swap(mat[index][k], mat[i][k]);
            }
        }
        if(dblcmp(mat[i][j]))
        {
            for(int k=i+1;k<m;++k)
            {
                double temp = mat[k][j] / mat[i][j];
                for(int l=j;l<n;++l)
                {
                    mat[k][l] -= mat[i][l] * temp;
                }
            }
            ++ i;
        }
    }
    return i;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%lf", &mat[i][j]);
            }
        }
        printf("%d\n", getAns());
    }
    return 0;
}
