#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

const double eps=1e-6;
const double pi=3.1415926;

struct Point
{
    double x,y;
};

struct Segment
{
    Point u,v;
};

struct Shape
{
    char name,inters[30];
    int num,interNum;
    Segment p[20];
}s[30];

int cmp(const void* a, const void* b)
{
    return (*(Shape*)a).name - (*(Shape*)b).name;
}

double min(double a, double b)
{
    return a<b?a:b;
}

double max(double a, double b)
{
    return a>b?a:b;
}

double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double getAngle(Point a, Point o)
{
    return atan2(a.y-o.y,a.x-o.x);
}

Point getMidPoint(Point a, Point b)
{
    Point c;
    c.x=(a.x+b.x)*0.5;
    c.y=(a.y+b.y)*0.5;
    return c;
}

void rotate(Point a, Point o, Point &b, double angle)
{
    double an=getAngle(a,o)+angle;
    double d=dist(a,o);
    b.x=o.x+d*cos(an);
    b.y=o.y+d*sin(an);
}

double cross(Point a, Point b, Point o)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

double dblcmp(double r)
{
    if(fabs(r)<eps)
    {
        return 0;
    }
    return r>0?1:-1;
}

void copyPoint(Point &a, Point b)
{
    a.x=b.x, a.y=b.y;
}

void inputPoint(Point &p)
{
    scanf(" (%lf,%lf)",&p.x,&p.y);
}

void inputSquare(char name, int n)
{
    s[n].name=name;
    s[n].num=4;
    inputPoint(s[n].p[0].u);
    inputPoint(s[n].p[2].u);
    rotate(s[n].p[0].u, getMidPoint(s[n].p[0].u, s[n].p[2].u),s[n].p[1].u, pi*0.5);
    rotate(s[n].p[2].u, getMidPoint(s[n].p[0].u, s[n].p[2].u),s[n].p[3].u, pi*0.5);
    copyPoint(s[n].p[0].v, s[n].p[1].u);
    copyPoint(s[n].p[1].v, s[n].p[2].u);
    copyPoint(s[n].p[2].v, s[n].p[3].u);
    copyPoint(s[n].p[3].v, s[n].p[0].u);
}

void inputRectangle(char name, int n)
{
    s[n].name=name;
    s[n].num=4;
    inputPoint(s[n].p[0].u);
    inputPoint(s[n].p[1].u);
    inputPoint(s[n].p[2].u);
    rotate(s[n].p[1].u, getMidPoint(s[n].p[0].u, s[n].p[2].u),s[n].p[3].u, pi);
    copyPoint(s[n].p[0].v, s[n].p[1].u);
    copyPoint(s[n].p[1].v, s[n].p[2].u);
    copyPoint(s[n].p[2].v, s[n].p[3].u);
    copyPoint(s[n].p[3].v, s[n].p[0].u);
}

void inputLine(char name, int n)
{
    s[n].name=name;
    s[n].num=1;
    inputPoint(s[n].p[0].u);
    inputPoint(s[n].p[0].v);
}

void inputTriangle(char name, int n)
{
    s[n].name=name;
    s[n].num=3;
    inputPoint(s[n].p[0].u);
    inputPoint(s[n].p[1].u);
    inputPoint(s[n].p[2].u);
    copyPoint(s[n].p[0].v, s[n].p[1].u);
    copyPoint(s[n].p[1].v, s[n].p[2].u);
    copyPoint(s[n].p[2].v, s[n].p[0].u);
}

void inputPolygon(char name, int n)
{
    s[n].name=name;
    scanf("%d",&s[n].num);
    inputPoint(s[n].p[0].u);
    for(int i=1;i<s[n].num;i++)
    {
        inputPoint(s[n].p[i].u);
        copyPoint(s[n].p[i].v, s[n].p[i-1].u);
    }
    copyPoint(s[n].p[0].v,s[n].p[s[n].num-1].u);
}

bool quick(Point a, Point b, Point c, Point d)
{
    return max(a.x,b.x)>=min(c.x,d.x) and max(a.y,b.y)>=min(c.y,d.y) and max(c.x,d.x)>=min(a.x,b.x) and max(c.y,d.y)>=min(a.y,b.y);
}

bool interSegment(Point a, Point b, Point c, Point d)
{
    if(quick(a,b,c,d))
    {
        int d1=dblcmp(cross(a,c,d));
        int d2=dblcmp(cross(b,c,d));
        int d3=dblcmp(cross(c,a,b));
        int d4=dblcmp(cross(d,a,b));
        return d1*d2<=0 and d3*d4<=0;
    }
}

bool interShape(Shape &a, Shape &b)
{
    for(int i=0;i<a.num;i++)
    {
        for(int j=0;j<b.num;j++)
        {
            if(interSegment(a.p[i].u, a.p[i].v, b.p[j].u, b.p[j].v))
            {
                return true;
            }
        }
    }
    return false;
}

void checkInter(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(interShape(s[i],s[j]))
            {
                s[i].inters[s[i].interNum++]=s[j].name;
                s[j].inters[s[j].interNum++]=s[i].name;
            }
        }
    }
}

int main()
{
    int n;
    char name[30],shape[30];
    while(true)
    {
        n=0;
        while(scanf("%s",name),*name!='-' and *name!='.')
        {
            scanf("%s",shape);
            switch(*shape)
            {
                case 's':
                    inputSquare(*name,n);
                    break;
                case 'r':
                    inputRectangle(*name,n);
                    break;
                case 'l':
                    inputLine(*name,n);
                    break;
                case 't':
                    inputTriangle(*name,n);
                    break;
                case 'p':
                    inputPolygon(*name,n);
                    break;
            }
            s[n++].interNum=0;
        }
        if(*name=='.') break;
        qsort(s,n,sizeof(*s),cmp);
        checkInter(n);
        for(int i=0;i<n;i++)
        {
            switch (s[i].interNum)
            {
                case 0:
                    printf("%c has no intersections\n",s[i].name);
                    break;
                case 1:
                    printf("%c intersects with %c\n",s[i].name,s[i].inters[0]);
                    break;
                case 2:
                    printf("%c intersects with %c and %c\n",s[i].name,s[i].inters[0],s[i].inters[1]);
                    break;
                default:
                    printf("%c intersects with ",s[i].name);
                    for(int j=0;j<s[i].interNum-1;j++)
                    {
                        printf("%c, ",s[i].inters[j]);
                    }
                    printf("and %c\n",s[i].inters[s[i].interNum-1]);
            }
        }
        printf("\n");
    }
    return 0;
}
