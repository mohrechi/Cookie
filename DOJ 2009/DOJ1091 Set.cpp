#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int abs(int x)
{
    if(x<0) return -x;
    return x;
}

int main()
{
    int n,m,t;
    char b[128];
    while(cin>>n>>m)
    {
        set<int> s;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&t);
            s.insert(t);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%s",b);
            if(*b == 'I')
            {
                scanf("%d",&t);
                s.insert(t);
            }
            else
            {
                scanf("%d",&t);
                if(s.find(t) == s.end())
                {
                    int min = 0x7FFFFFF, res = 0;
                    for(set<int>::iterator it = s.begin();it != s.end();++it)
                    {
                        if(abs(*it - t) < min)
                        {
                            min = abs(*it - t);
                            res = *it;
                        }
                    }
                    printf("%d\n",res);
                }
                else
                {
                    printf("%d\n",t);
                }
            }
        }
    }
    return 0;
}
