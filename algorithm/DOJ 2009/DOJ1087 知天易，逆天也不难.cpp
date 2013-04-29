#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;

struct Vector
{
    double data[4];

    Vector()
    {
    }

    Vector(double x, double y, double z)
    {
        data[0] = x;
        data[1] = y;
        data[2] = z;
        data[3] = 1;
    }

    inline void init()
    {
        for(int i=0;i<4;++i)
        {
            data[i] = 0.0;
        }
    }

    inline void input()
    {
        scanf("%lf%lf%lf", &data[0], &data[1], &data[2]);
        data[3] = 1.0;
    }

    inline void output()
    {
        char s[128];
        for(int i=0;i<3;++i)
        {
            sprintf(s, "%.0lf", data[i]);
            if(s[0] == '-' && s[1] == '0')
            {
                s[0] = '0';
                s[1] = 0;
            }
            if(i)
            {
                printf(" ");
            }
            printf("%s", s);
        }
        printf("\n");
    }

    Vector reverse()
    {
        Vector vec;
        for(int i=0;i<3;++i)
        {
            vec.data[i] = - data[i];
        }
        vec.data[3] = 1.0;
        return vec;
    }

    double absValue() const
    {
        double c = 0.0;
        for(int i=0;i<3;++i)
        {
            c += data[i] * data[i];
        }
        return sqrt(c);
    }
} star, start, dir;
double angle;

double operator * (const Vector &a, const Vector &b)
{
    double c = 0.0;
    for(int i=0;i<3;++i)
    {
        c += a.data[i] * b.data[i];
    }
    return c;
}

double getAngle(const Vector &a, const Vector &b)
{
    if(b.absValue() < eps)
    {
        return 0.0;
    }
    return acos(a * b / (a.absValue() * b.absValue()));
}

struct Matrix
{
    double data[4][4];

    void init()
    {
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                data[i][j] = 0.0;
            }
            data[i][i] = 1.0;
        }
    }

    void initZero()
    {
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                data[i][j] = 0.0;
            }
        }
    }

    void output()
    {
        printf("Matrix: \n");
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                printf("%.2lf\t", data[i][j]);
            }
            printf("\n");
        }
    }
} world;

Matrix operator * (const Matrix &a, const Matrix &b)
{
    Matrix c;
    c.initZero();
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            for(int k=0;k<4;++k)
            {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
}

Vector operator * (const Vector &a, const Matrix &b)
{
    Vector c;
    for(int k=0;k<4;++k)
    {
        c.data[k] = 0.0;
        for(int j=0;j<4;++j)
        {
            c.data[k] += a.data[j] * b.data[j][k];
        }
    }
    return c;
}

Matrix getTransMatrix(const Vector &v)
{
    Matrix mat;
    mat.init();
    mat.data[3][0] = v.data[0];
    mat.data[3][1] = v.data[1];
    mat.data[3][2] = v.data[2];
    return mat;
}

Matrix getRotateXMatrix(double angle)
{
    Matrix mat;
    mat.init();
    mat.data[1][1] = cos(angle);
    mat.data[1][2] = - sin(angle);
    mat.data[2][1] = sin(angle);
    mat.data[2][2] = cos(angle);
    return mat;
}

Matrix getRotateYMatrix(double angle)
{
    Matrix mat;
    mat.init();
    mat.data[0][0] = cos(angle);
    mat.data[0][2] = - sin(angle);
    mat.data[2][0] = sin(angle);
    mat.data[2][2] = cos(angle);
    return mat;
}

Matrix getRotateZMatrix(double angle)
{
    Matrix mat;
    mat.init();
    mat.data[0][0] = cos(angle);
    mat.data[0][1] = - sin(angle);
    mat.data[1][0] = sin(angle);
    mat.data[1][1] = cos(angle);
    return mat;
}

int main()
{
    int k;
    scanf("%d", &k);
    while(k--)
    {
        star.input();
        start.input();
        dir.input();
        scanf("%lf", &angle);
        world.init();
        world = world * getTransMatrix(start.reverse());
        double angleX = getAngle(Vector(0, 0, 1), Vector(0, dir.data[1], dir.data[2]));
        if(dir.data[1] < 0.0)
        {
            angleX = PI * 2.0 - angleX;
        }
        world = world * getRotateXMatrix(- angleX);
        Vector vec = dir * getRotateXMatrix(- angleX);
        double angleY = getAngle(Vector(0, 0, 1), Vector(vec.data[0], 0, vec.data[2]));
        if(vec.data[0] < 0.0)
        {
            angleY = PI * 2.0 - angleY;
        }
        world = world * getRotateYMatrix(- angleY);
        world = world * getRotateZMatrix(- angle / 180.0 * PI);
        world = world * getRotateYMatrix(angleY);
        world = world * getRotateXMatrix(angleX);
        world = world * getTransMatrix(start);
        star = star * world;
        star.output();
    }
    return 0;
}
