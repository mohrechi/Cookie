#include<iostream>
#include<iomanip>
using namespace std;

struct Point
{
    int x,y;
}p[105];

int area(Point a, Point b)
{
    return a.x*b.y-a.y*b.x;
}

int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int cas;
    cin>>cas;
    for(int k=1;k<=cas;k++)
    {
        int I,E,ans,n;
        cin>>n;
        E=p[0].x=p[0].y=ans=0;
        for(int i=1;i<=n;i++)
        {
            int dx,dy;
            cin>>dx>>dy;
            p[i].x=p[i-1].x+dx;
            p[i].y=p[i-1].y+dy;
            ans+=area(p[i],p[i-1]);
            E+=gcd(dx>0?dx:-dx,dy>0?dy:-dy);
        }
        if(ans<0) ans=-ans;
        I=(ans-E+2)*0.5;
        cout<<"Scenario #"<<k<<":"<<endl;
        cout<<I<<" "<<E<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<ans*0.5<<endl<<endl;
    }
    return 0;
}
