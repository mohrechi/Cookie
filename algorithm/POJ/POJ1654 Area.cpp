#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;

struct Point
{
    long long x,y;
    Point(){};
    Point(long long a, long long b)
    {
        x=a,y=b;
    }
};

long long area(Point a, Point b)
{
    return a.x*b.y-b.x*a.y;
}

int dir[][2]={{0,0},{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};
char s[1000005];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n=0;
        long long ans=0;
        Point a(0,0),b;
        scanf("%s",s);
        int len=strlen(s)-1;
        for(int i=0;i<len;i++)
        {
            int d=s[i]-'0';
            b.x=a.x+dir[d][0];
            b.y=a.y+dir[d][1];
            ans+=area(b,a);
            a=b;
        }
        if(ans<0) ans=-ans;
        long long res=ans/2;
        if(res*2==ans) cout<<res<<endl;
        else cout<<res<<".5"<<endl;
    }
    return 0;
}
