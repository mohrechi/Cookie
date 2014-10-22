#include<iostream>
using namespace std;

class Triangle
{
    public:
        bool input()
        {
            for(int i=0;i<3;i++)
            {
                cin>>p[i].x>>p[i].y;
            }
            return p[0].x or p[0].y or p[1].x or p[1].y or p[2].x or p[2].y;
        }
        void calc()
        {
            Area=area(p[0],p[1])+area(p[1],p[2])+area(p[2],p[0]);
            on=gcd(abs(p[1].x-p[0].x),abs(p[1].y-p[0].y))+gcd(abs(p[2].x-p[1].x),abs(p[2].y-p[1].y))+gcd(abs(p[0].x-p[2].x),abs(p[0].y-p[2].y));
            if(Area<0) Area=-Area;
            in=(Area-on+2)*0.5;
        }
        void output()
        {
            cout<<in<<endl;
        }
    private:
        struct Point
        {
            int x,y;
        }p[3];
        int on, in, Area;
        int area(Point a, Point b)
        {
            return a.x*b.y-a.y*b.x;
        }
        int abs(int a)
        {
            return a>0?a:-a;
        }
        int gcd(int a,int b)
        {
            if(b==0) return a;
            else return gcd(b,a%b);
        }
};

int main()
{
    Triangle t;
    while(t.input())
    {
        t.calc();
        t.output();
    }
    return 0;
}
