#include <cstdio>
#include <cmath>

int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        int m = y-x;
        int l = int(sqrt((double)m));
        if(m == 0) printf("0\n");
        else if(m == l * l) printf("%d\n",2 * l - 1);
        else if(m <= l * l + l) printf("%d\n",2 * l);
        else printf("%d\n",2 * ( l + 1 ) - 1);
    }
    return 0;
}
