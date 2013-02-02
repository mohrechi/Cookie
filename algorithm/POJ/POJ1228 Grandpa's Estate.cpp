#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const double inf = 1e100;
const double eps = 1e-8;

struct Point
{
    double x,y;
    Point(double a = 0, double b = 0)
    {
        x = a, y = b;
    }
};

struct Polygon
{
    int pointNumber;
    Point point[1005];
};

int dblcmp(double r)
{
    if(fabs(r)<eps)
    {
        return 0;
    }
    return r>0?1:-1;
}

double multiply(Point a, Point b, Point o)
{
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

double dist(Point a, Point b)
{
    return (a.x-b.x) * (a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool cmp(const Point &a, const Point &b)
{
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

Polygon polygon;
int stack[2000], stackTop;

void graham()
{
    sort(polygon.point, polygon.point + polygon.pointNumber, cmp);
    stack[0] = 0;
    stack[1] = 1;
    stackTop = 2;
    for(int i=2;i<polygon.pointNumber;i++)
    {
        while(stackTop>1 && dblcmp(multiply(polygon.point[i],polygon.point[stack[stackTop-1]],polygon.point[stack[stackTop-2]]))>0)
        {
            --stackTop;
        }
        stack[stackTop++] = i;
        //cout<<"Test1: "<<" "<<stackTop-1<<" "<<polygon.point[i].x<<" "<<polygon.point[i].y<<endl;
    }
    int temp = stackTop;
    stack[stackTop++] = polygon.pointNumber - 2;
    for(int i=polygon.pointNumber-3;i>=0;i--)
    {
        while(stackTop>temp && dblcmp(multiply(polygon.point[i],polygon.point[stack[stackTop-1]],polygon.point[stack[stackTop-2]]))>0)
        {
            --stackTop;
        }
        stack[stackTop++] = i;
        //cout<<"Test2: "<<" "<<stackTop-1<<" "<<polygon.point[i].x<<" "<<polygon.point[i].y<<endl;
    }
}

int main()
{
    int caseNumber;
    cin>>caseNumber;
    while(caseNumber--)
    {
        cin>>polygon.pointNumber;
        for(int i=0;i<polygon.pointNumber;i++)
        {
            cin>>polygon.point[i].x>>polygon.point[i].y;
        }
        if(polygon.pointNumber<6)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            graham();
            /*for(int i=0;i<stackTop;i++)
            {
                cout<<polygon.point[stack[i]].x<<" "<<polygon.point[stack[i]].y<<endl;
            }*/
            int i;
            for(i=0;i<stackTop-1;i++)
            {
                int j=i+2, count=0;
                if(j>=polygon.pointNumber)
                {
                    j -= polygon.pointNumber;
                }
                while(dblcmp(multiply(polygon.point[stack[i]], polygon.point[stack[i+1]], polygon.point[stack[j]]))==0)
                {
                    if(++count == polygon.pointNumber - 2)
                    {
                        break;
                    }
                    if(++j==polygon.pointNumber)
                    {
                        j=0;
                    }
                }
                if(count == 0 || count == polygon.pointNumber - 2)
                {
                    break;
                }
                i+=count;
            }
            if(i<stackTop-1)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
