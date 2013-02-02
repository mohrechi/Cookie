#include<stdio.h>
#include<math.h>

const double eps=1e-6;

struct Point
{
    double x,y;
};

struct Peg
{
    double radius;
    Point p;
};

Point operator-(Point a, Point b)
{
    Point temp;
    temp.x=a.x-b.x, temp.y=a.y-b.y;
    return temp;
}
double operator*(Point p1, Point p2)
{
    return p1.x*p2.y-p2.x*p1.y;
}

double cross(Point &a, Point &b, Point &o)
{
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}

double dblcmp(double r)
{
    if(fabs(r)<eps) return 0;
    return r>0?1:-1;
}

double Norm(Point a)
{
    return sqrt(a.x*a.x+a.y*a.y);
}

double dist(Point &a, Point &b, Point &c)
{
    return fabs((a-b)*(c-b))/Norm(c-b);
}

struct Polygon
{
    int vNum;
    Point p[200];
    Peg peg;
    bool check1()
    {
        int flag=dblcmp(cross(p[vNum-2],p[vNum-1],p[0]));
        if(not flag)
        {
            flag=dblcmp(cross(p[vNum-1],p[0],p[1]));
        }
        else if(dblcmp(cross(p[vNum-1],p[0],p[1]))!=flag) return false;
        for(int i=0;i<vNum-2;i++)
        {
            if(not flag)
            {
                flag=dblcmp(cross(p[i],p[i+1],p[i+2]));
            }
            else
            {
                int temp=dblcmp(cross(p[i],p[i+1],p[i+2]));
                if(temp!=flag and temp!=0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool check2()
    {
        int flag=dblcmp(cross(peg.p,p[vNum-1],p[0]));
        for(int i=0;i<vNum-1;i++)
        {
            if(dblcmp(cross(peg.p,p[i],p[i+1]))!=flag)
            {
                return false;
            }
        }
        return true;
    }
    bool check3()
    {
        double min=dist(peg.p,p[vNum-1],p[0]);
        if(dblcmp(min-peg.radius)<0) return false;
        for(int i=0;i<vNum-1;i++)
        {
            min=dist(peg.p,p[i],p[i+1]);
            if(dblcmp(min-peg.radius)<0) return false;
        }
        return true;
    }
}p;

int main()
{
    while(scanf("%d",&p.vNum),p.vNum!=1)
    {
        scanf("%lf%lf%lf",&p.peg.radius,&p.peg.p.x,&p.peg.p.y);
        for(int i=0;i<p.vNum;i++)
        {
            scanf("%lf%lf",&p.p[i].x,&p.p[i].y);
        }
        if(p.check1())
        {
            if(p.check2() and p.check3())
            {
                printf("PEG WILL FIT\n");
            }
            else
            {
                printf("PEG WILL NOT FIT\n");
            }
        }
        else
        {
            printf("HOLE IS ILL-FORMED\n");
        }
    }
    return 0;
}
