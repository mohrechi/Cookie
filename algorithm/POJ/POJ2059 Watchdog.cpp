#include<iostream>
using namespace std;const int Max=100;int Can_fasten(int m,int n,int S,int posion[Max][Max]){int i,j,dis0=0,dis1;if(posion[m][n]==1)return -1;for(i=1;i<S;i++)for(j=1;j<S;j++){if(posion[i][j]==1){dis1=(m-i)*(m-i)+(n-j)*(n-j);if(dis1>dis0){dis0=dis1;}}}if((dis0<=m*m)&&(dis0<=n*n)&&(dis0<=(S-m)*(S-m))&&(dis0>0)&&(dis0<=(S-n)*(S-n))){return 1;}return 0;}int main(){int i,j,posion[Max][Max],S,H,N,X,Y,f,flag;cin>>N;while(N){cin>>S>>H;for(i=0;i<=S;i++)for(j=0;j<=S;j++){posion[i][j]=0;}for(i=0;i<H;i++){cin>>X>>Y;posion[X][Y]=1;}f=0;for(i=0;i<=S;i++){if(f==1){break;}for(j=0;j<=S;j++){flag=Can_fasten(i,j,S,posion);if(flag==1){cout<<i<<" "<<j<<endl;f=1;}if(f==1){break;}}}if(f==0){cout<<"poodle"<<endl;}N--;}return 0;}
/*#include <cstdio>
struct Node
{
    int x, y;
}hatch[50000];
int n, s, h;
int find, d;

inline int max(int x, int y)
{
    return x>y?x:y;
}

inline int square(int x)
{
    return x * x;
}

inline int dist(const Node &node, int x, int y)
{
    return square(node.x - x) + square(node.y - y);
}

int main(int argc, char *argv[])
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&s,&h);
        find = 0;
        for(int i=0;i<h;++i)
        {
            scanf("%d%d",&hatch[i].x,&hatch[i].y);
        }
        for(int i=1;i<s && !find;++i)
        {
            for(int j=1;j<s && !find;++j)
            {
                d = 0;
                int k;
                for(k=0;k<h;++k)
                {
                    if(hatch[k].x == i && hatch[k].y == j)
                    {
                        break;
                    }
                }
                if(k<h)
                {
                    break;
                }
                for(k=0;k<h;++k)
                {
                    d = max(d, dist(hatch[k], i, j));
                }
                if(d <= square(i) && d <= square(j) && d <= square(s-i) && d <= square(s-j))
                {
                    printf("%d %d\n",i, j);
                    find = 1;
                }
            }
        }
        if(!find)
        {
            printf("poodle\n");
        }
    }
    return 0;
}*/
