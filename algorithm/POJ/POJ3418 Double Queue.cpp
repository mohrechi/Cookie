#include<set>
#include<stdio.h>
using namespace std;

struct node
{
    int a;
    int b;
}d;

bool operator<(const node &a, const node &b)
{
    return a.b>b.b;
}

int main(void)
{
    int c;
    set<node> s;
    while(scanf("%d",&c),c)
    {
        switch (c)
        {
            case 1:
                scanf("%d%d",&d.a,&d.b);
                s.insert(d);
                break;
            case 2:
                if(s.empty())
                {
                    printf("0\n");
                }
                else
                {
                    printf("%d\n",s.begin()->a);
                    s.erase(s.begin());
                }
                break;
            case 3:
                if(s.empty())
                {
                    printf("0\n");
                }
                else
                {
                    set<node>::iterator i;
                    i=s.end();
                    i--;
                    printf("%d\n",i->a);
                    s.erase(s.find(*i));
                }
                break;
        }
    }
    return 0;
}
