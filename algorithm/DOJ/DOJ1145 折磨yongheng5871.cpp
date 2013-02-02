#include <cstdio>
#include <cstring>
#include <cmath>
static const int MAXN = 100010;
static const double PI = acos(-1.0);

typedef struct Matrix
{
    char r, c;
    double a[3][3];
}Matrix;
Matrix world, translation, rotation, point[MAXN];

Matrix operator * (const Matrix &a, const Matrix &b)
{
    Matrix c;
    c.r = a.r;
    c.c = b.c;
    for(int i=0;i<a.r;++i)
    {
        for(int j=0;j<b.c;++j)
        {
            c.a[i][j] = 0.0;
            for(int k=0;k<a.c;++k)
            {
                c.a[i][j] += a.a[i][k] * b.a[k][j];
            }
        }
    }
    return c;
}

int main()
{
    int n, m;
    int x, y, d;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%lf%lf", &point[i].a[0][0], &point[i].a[0][1]);
            point[i].a[0][2] = 1.0;
            point[i].r = 1;
            point[i].c = 3;
        }
        world.r = world.c = 3;
        translation.r = translation.c = 3;
        rotation.r = rotation.c = 3;
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                world.a[i][j] = 0.0;
                translation.a[i][j] = 0.0;
                rotation.a[i][j] = 0.0;
            }
            world.a[i][i] = 1.0;
            translation.a[i][i] = 1.0;
            rotation.a[i][i] = 1.0;
        }
        scanf("%d", &m);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &x, &y, &d);
            translation.a[2][0] = - x;
            translation.a[2][1] = - y;
            rotation.a[0][0] = rotation.a[1][1] = cos(d / 180.0 * PI);
            rotation.a[1][0] = - (rotation.a[0][1] = sin(d / 180.0 * PI));
            world = world * translation * rotation;
            translation.a[2][0] = x;
            translation.a[2][1] = y;
            world = world * translation;
        }
        for(int i=0;i<n;++i)
        {
            point[i] = point[i] * world;
            printf("%.2lf %.2lf\n", point[i].a[0][0], point[i].a[0][1]);
        }
    }
    return 0;
}
