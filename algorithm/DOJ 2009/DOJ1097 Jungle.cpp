#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=50005;
const double eps=1e-8;

int sign(double d)
{
    return d<-eps ? -1 : (d > eps);
}

struct point
{
    double x, y;
    point(double _x=0, double _y=0):x(_x), y(_y){}
    void read()
    {
        scanf("%lf%lf", &x, &y);
    }
    void set(double _x, double _y)
    {
        x=_x;
        y=_y;
    }
}ps[N], hull[N], pque[N];

struct seg
{
    point st, ed;
    double ang;
    void calang()
    {
        ang = atan2(ed.y-st.y, ed.x-st.x);
    }
}sque[N+10], segs[N+10];
int n;

inline double xmul(point st1, point ed1, point st2, point ed2)
{
    return (ed1.x - st1.x) * (ed2.y - st2.y) - (ed1.y - st1.y) * (ed2.x - st2.x);
}

point intersectPoint(point st1, point ed1, point st2, point ed2)
{
    double t = xmul(st2, st1, st2, ed2) / ((ed1.y-st1.y) * (ed2.x-st2.x) - (ed1.x-st1.x) * (ed2.y-st2.y));
    return point(st1.x+(ed1.x-st1.x)*t, st1.y+(ed1.y-st1.y)*t);
}

bool cmpseg(seg a, seg b)
{
    return a.ang < b.ang;
}

void halfPlaneInter(seg* segs, int sn, point* ps, int& pn)
{
    int i, l, r;
    if(sn <= 0)
    {
        pn = 0;
        return;
    }
    if(sn <= 2)
    {
        segs[sn] = segs[0];
        for(l = r = 0; r < sn; r++)
        {
            sque[r] = segs[r];
            pque[r] = intersectPoint(segs[r].st, segs[r].ed, segs[r+1].st, segs[r+1].ed);
        }
    }
    else
    {
        l = r = 0;
        sque[r++] = segs[0];
        sque[r++] = segs[1];
        pque[0] = intersectPoint(sque[0].st, sque[0].ed, sque[1].st, sque[1].ed);
        for(i = 2; i < sn; i++)
        {
            while(r-l >= 2 && sign(xmul(segs[i].st, segs[i].ed, segs[i].st, pque[r-2])) <= 0)
                r--;
            sque[r++] = segs[i];
            pque[r-2] = intersectPoint(sque[r-2].st, sque[r-2].ed, sque[r-1].st, sque[r-1].ed);
        }
        while(r-l >= 2)
        {
            bool flag = false;
            if(sign(xmul(sque[r-1].st, sque[r-1].ed, sque[r-1].st, pque[l])) <= 0)
            {
                flag = true;
                l++;
            }
            if(sign(xmul(sque[l].st, sque[l].ed, sque[l].st, pque[r-2])) <= 0)
            {
                flag = true;
                r--;
            }
            if(!flag) break;
        }
        pque[r-1] = intersectPoint(sque[l].st, sque[l].ed, sque[r-1].st, sque[r-1].ed);
    }
    for(pn = 0, i = l; i < r; i++){
        ps[pn++] = pque[i];
    }
}

bool input()
{
    if(scanf("%d", &n)==EOF)
        return false;
    int i;
    for(i=0; i<n; i++)
    {
        ps[n-i-1].read();
    }
    return true;
}

double area(point* ps, int pn)
{
    if(pn<=1) return 0;
    int i;
    double ans;
    for(ps[pn]=ps[0], ans=i=0; i<pn; i++)
    {
        ans += (ps[i].x*ps[i+1].y-ps[i].y*ps[i+1].x);
    }
    return ans*0.5;
}

bool check(int mid)
{
    int hn, i;
    for(i=0; i<n; i++)
    {
        segs[i].st=ps[i];
        segs[i].ed=ps[(i+mid+1)%n];
    }
    halfPlaneInter(segs, n, hull, hn);
    double s=area(hull, hn);
    return sign(s)==0;
}

void solve()
{
    int l, r, mid;
    l=1;
    r=(n-1)>>1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    int ans=r+1;
    printf("%d\n", ans);
}

int main()
{
    while(input())
        solve();
    return 0;
}
