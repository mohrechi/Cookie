#include<cstdio>
#include<algorithm>
using namespace std;

struct Num
{
    int a;
    int b;
}num[1000];

int cmp(Num a, Num b)
{
    int da=a.b-a.a;
    int db=b.b-b.a;
    if(da > db ) return 1;
    else if(da == db)
    {
        if(a.a > a.a) return 0;
        else return 1;
    }
    return 0;
}

int main()
{
    int flag;
    int t,v,n;
    scanf("%d",&t);
    while(t--)
    {
        int i,j;
        flag=0;
        scanf("%d%d",&v,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&num[i].a,&num[i].b);
        }
        sort(num,num+n,cmp);
        for(i=0;i<n;i++)
        {
            if(num[i].b<=v)
            {
                v-=num[i].a;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
