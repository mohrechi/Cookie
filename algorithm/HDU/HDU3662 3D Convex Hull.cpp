#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 305;
const double eps = 1e-8;

int dblcmp(double x)
{
    if (fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

int dblcmp(double x, double y)
{
    return dblcmp(x - y);
}

struct Point3D
{
    double x, y, z;
    inline void input()
    {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    inline void output()
    {
        printf("%.3lf %.3lf %.3lf\n", x, y, z);
    }
    double dist()
    {
        return sqrt(x * x + y * y + z * z);
    }
} transPoints[MAXN];

Point3D operator -(const Point3D &a, const Point3D &b)
{
    Point3D c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    return c;
}

double operator *(const Point3D &a, const Point3D &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D operator ^(const Point3D &u, const Point3D &v)
{
    Point3D point;
    point.x = u.y * v.z - u.z * v.y;
    point.y = u.z * v.x - u.x * v.z;
    point.z = u.x * v.y - u.y * v.x;
    return point;
}

double area(const Point3D &a, const Point3D &b, const Point3D &c)
{
    return ((b - a) ^ (c - a)).dist();
}

double volumn(const Point3D &a, const Point3D &b, const Point3D &c, const Point3D &d)
{
    return ((b - a) ^ (c - a)) * (d - a);
}

struct Face
{
    int a, b, c;
    bool flag;
};

struct Dull
{
    int n;
    Point3D points[MAXN];
    int triangleNum;
    Face triangles[MAXN * 6];
    int visit[MAXN][MAXN];
    double ptoplane(const Point3D &p, const Face &f)
    {
        Point3D m = points[f.b] - points[f.a];
        Point3D n = points[f.c] - points[f.a];
        Point3D t = p - points[f.a];
        return (m ^ n) * t;
    }
    void deal(int p, int a, int b)
    {
        int f = visit[a][b];
        Face add;
        if (triangles[f].flag)
        {
            if ((ptoplane(points[p], triangles[f])) > eps)
            {
                dfs(p, f);
            }
            else
            {
                add.a = b;
                add.b = a;
                add.c = p;
                add.flag = true;
                visit[p][b] = visit[a][p] = visit[b][a] = triangleNum;
                triangles[triangleNum++] = add;
            }
        }
    }
    void dfs(int p, int cnt)
    {
        triangles[cnt].flag = false;
        deal(p, triangles[cnt].b, triangles[cnt].a);
        deal(p, triangles[cnt].c, triangles[cnt].b);
        deal(p, triangles[cnt].a, triangles[cnt].c);
    }
    void construct()
    {
        triangleNum = 0;
        if (n < 4)
        {
            return;
        }
        bool temp = true;
        for (int i = 1; i < n; ++i)
        {
            if ((points[0] - points[i]).dist() > eps)
            {
                swap(points[1], points[i]);
                temp = false;
                break;
            }
        }
        if (temp)
        {
            return;
        }
        temp = true;
        for (int i = 2; i < n; ++i)
        {
            if (((points[0] - points[1]) ^ (points[1] - points[i])).dist() > eps)
            {
                swap(points[2], points[i]);
                temp = false;
                break;
            }
        }
        if (temp)
        {
            return;
        }
        temp = true;
        for (int i = 3; i < n; ++i)
        {
            if (fabs(((points[0] - points[1]) ^ (points[1] - points[2])) * (points[0] - points[i])) > eps)
            {
                swap (points[3], points[i]);
                temp = false;
                break;
            }
        }
        if (temp)
        {
            return;
        }
        memset(visit, 0, sizeof(visit));
        Face add;
        for (int i = 0; i < 4; ++i)
        {
            add.a = (i + 1) % 4;
            add.b = (i + 2) % 4;
            add.c = (i + 3) % 4;
            add.flag = true;
            if (ptoplane(points[i], add) > 0)
            {
                swap(add.b, add.c);
            }
            visit[add.a][add.b] = visit[add.b][add.c] = visit[add.c][add.a] = triangleNum;
            triangles[triangleNum++] = add;
        }
        for (int i = 4; i < n; ++i)
        {
            for (int j = 0; j < triangleNum; ++j)
            {
                if (triangles[j].flag && ptoplane(points[i], triangles[j]) > eps)
                {
                    dfs(i, j);
                    break;
                }
            }
        }
        int cnt = triangleNum;
        triangleNum = 0;
        for (int i = 0; i < cnt; ++i)
        {
            if (triangles[i].flag)
            {
                triangles[triangleNum++] = triangles[i];
            }
        }
    }
    double faceArea()
    {
        double ret = 0.0;
        for (int i = 0; i < triangleNum; ++i)
        {
            ret += area(points[triangles[i].a], points[triangles[i].b], points[triangles[i].c]);
        }
        return ret * 0.5;
    }
    bool sameFace(int u, int v)
    {
        Point3D ua = points[triangles[u].a];
        Point3D ub = points[triangles[u].b];
        Point3D uc = points[triangles[u].c];
        Point3D va = points[triangles[v].a];
        Point3D vb = points[triangles[v].b];
        Point3D vc = points[triangles[v].c];
        return fabs(volumn(ua, ub, uc, va)) < eps &&
               fabs(volumn(ua, ub, uc, vb)) < eps &&
               fabs(volumn(ua, ub, uc, vc)) < eps;
    }
    int faceNum()
    {
        int res = 0;
        for (int i = 0; i < triangleNum; ++i)
        {
            bool flag = true;
            for (int j = 0; j < i; ++j)
            {
                if (sameFace(i, j))
                {
                    flag = false;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
} dull;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        dull.n = n;
        for (int i = 0; i < n; ++i)
        {
            dull.points[i].input();
        }
        dull.construct();
        printf("%d\n", dull.faceNum());
    }
    return 0;
}
