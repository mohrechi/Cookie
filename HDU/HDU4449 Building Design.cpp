#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;
const int INF = 990000;
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

struct Matrix
{
    double data[4][4];
    Matrix()
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                data[i][j] = 0.0;
            }
            data[i][i] = 1.0;
        }
    }
    inline void output()
    {
        printf("Matrix: \n");
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                printf("%lf\t", data[i][j]);
            }
            printf("\n");
        }
    }
};

Matrix operator *(const Matrix &a, const Matrix &b)
{
    Matrix c;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            c.data[i][j] = 0;
            for (int k = 0; k < 4; ++k)
            {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
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

Point3D operator *(const Point3D &a, const Matrix &b)
{
    Point3D c;
    c.x = a.x * b.data[0][0] + a.y * b.data[1][0] + a.z * b.data[2][0] + b.data[3][0];
    c.y = a.x * b.data[0][1] + a.y * b.data[1][1] + a.z * b.data[2][1] + b.data[3][1];
    c.z = a.x * b.data[0][2] + a.y * b.data[1][2] + a.z * b.data[2][2] + b.data[3][2];
    return c;
}

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
} dull;

Matrix getWorldTransfromMatrix(Point3D dir)
{
    Matrix world;
    double a = dir.x;
    double b = dir.y;
    double c = dir.z;
    double base = sqrt(b * b + c * c);
    if (dblcmp(base) > 0)
    {
        Matrix xTransform;
        double cosValue = c / base;
        double sinValue = b / base;
        xTransform.data[1][1] = cosValue;
        xTransform.data[1][2] = sinValue;
        xTransform.data[2][1] = -sinValue;
        xTransform.data[2][2] = cosValue;
        world = world * xTransform;
        dir = dir * world;
    }
    a = dir.x;
    b = dir.y;
    c = dir.z;
    base = sqrt(a * a + c * c);
    if (dblcmp(base) > 0)
    {
        Matrix yTransform;
        double cosValue = c / base;
        double sinValue = - a / base;
        yTransform.data[0][0] = cosValue;
        yTransform.data[0][2] = -sinValue;
        yTransform.data[2][0] = sinValue;
        yTransform.data[2][2] = cosValue;
        world = world * yTransform;
    }
    return world;
}

struct Point2D
{
    double x, y;
    inline void output()
    {
        printf("%.3lf %.3lf\n", x, y);
    }
    bool operator <(const Point2D point) const
    {
        if(y == point.y)
        {
            return x < point.x;
        }
        return y < point.y;
    }
} planePoints[MAXN];
int planeNum;
int stack[MAXN * 2], top;

Point2D operator -(const Point2D &a, const Point2D &b)
{
    Point2D c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

double operator ^(const Point2D &a, const Point2D &b)
{
    return a.x * b.y - a.y * b.x;
}

double cross(const Point2D &a, const Point2D &b, const Point2D &o)
{
    return (a - o) ^ (b - o);
}

void grahamScan()
{
    sort(planePoints, planePoints + planeNum);
    stack[0] = 0, stack[1] = 1, top = 2;
    for (int i = 2; i < planeNum; ++i)
    {
        while(top > 1 && dblcmp(cross(planePoints[stack[top-1]], planePoints[stack[top-2]], planePoints[i])) <= 0)
        {
            --top;
        }
        stack[top++] = i;
    }
    int temp = top;
    stack[top++] = planeNum - 2;
    for(int i = planeNum - 3;i >= 0; --i)
    {
        while(top > temp && dblcmp(cross(planePoints[stack[top-1]], planePoints[stack[top-2]], planePoints[i])) <= 0)
        {
            --top;
        }
        stack[top++] = i;
    }
}

double getArea()
{
    grahamScan();
    double area = 0.0;
    for (int i = 2; i < top; ++i)
    {
        area += fabs(cross(planePoints[stack[i]], planePoints[stack[i - 1]], planePoints[stack[0]]));
    }
    return area * 0.5;
}

int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        dull.n = n;
        for (int i = 0; i < n; ++i)
        {
            dull.points[i].input();
        }
        dull.construct();
        double H = 0.0;
        double S = INF;
        for (int i = 0; i < dull.triangleNum; ++i)
        {
            Point3D a = dull.points[dull.triangles[i].a];
            Point3D b = dull.points[dull.triangles[i].b];
            Point3D c = dull.points[dull.triangles[i].c];
            Point3D plane = (b - a) ^ (c - a);
            Matrix world = getWorldTransfromMatrix(plane);
            double tempHeight = 0.0;
            for (int j = 0; j < n; ++j)
            {
                tempHeight = max(tempHeight, fabs(volumn(dull.points[j], a, b, c) / area(a, b, c)));
                transPoints[j] = dull.points[j] * world;
            }
            if (dblcmp(tempHeight, H) < 0)
            {
                continue;
            }
            double level = transPoints[dull.triangles[i].a].z;
            int levelFlag = 0;
            bool flag = true;
            for (int j = 0; j < n; ++j)
            {
                int temp = dblcmp(transPoints[j].z, level);
                if (temp)
                {
                    if (levelFlag)
                    {
                        if (temp != levelFlag)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        levelFlag = temp;
                    }
                }
                planePoints[j].x = transPoints[j].x;
                planePoints[j].y = transPoints[j].y;
            }
            if (flag)
            {
                planeNum = n;
                double tempArea = getArea();
                if (dblcmp(tempHeight, H) == 0)
                {
                    S = min(S, tempArea);
                }
                else if (dblcmp(tempHeight, H) > 0)
                {
                    H = tempHeight;
                    S = tempArea;
                }
            }
        }
        printf("%.3lf %.3lf\n", H, S);
    }
    return 0;
}
