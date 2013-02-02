#include<stdio.h>
#include<math.h>
#include<stdlib.h>

const double eps=1e-6;

struct Tree
{
    double x,y,value,length;
    Tree(){}
    Tree(double x0, double y0)
    {
        x=x0,y=y0;
    }
}t[20],tree[20];

int k;

int cross(Tree a, Tree b, Tree o)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

int cmp1(const void* a, const void* b)
{
    if((*(Tree*)a).y==(*(Tree*)b).y) return (*(Tree*)a).x-(*(Tree*)b).x;
    return (*(Tree*)a).y-(*(Tree*)b).y;
}

int cmp2(const void* a, const void* b)
{
    return -cross(*(Tree*)a,*(Tree*)b,tree[0]);
}

double dist(Tree a, Tree b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double graham()
{
    if(k==0 or k==1)return 0;
    if(k==2) return dist(tree[0],tree[1])*2;
    qsort(tree,k,sizeof(*tree),cmp1);
    qsort(tree+1,k-1,sizeof(*tree),cmp2);
    int stack[20]={0,1,2},top=3;
    for(int i=3;i<k;i++)
    {
        while(cross(tree[i],tree[stack[top-1]],tree[stack[top-2]])>=0) top--;
        stack[top++]=i;
    }
    stack[top]=0;
    double len=0;
    for(int i=0;i<top;i++)
    {
        len+=dist(tree[stack[i]],tree[stack[i+1]]);
    }
    return len;
}

int main()
{
    int n,cas=1;
    int pow2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&t[i].x,&t[i].y,&t[i].value,&t[i].length);
        }
        int minValue=0x7FFFFFFF,value;
        double length,extra=0;
        int mp=-1,mt=0;
        for(int i=0;i<pow2[n];i++)
        {
            value=0,length=0,k=0;
            for(int j=0;j<n;j++)
            {
                if(i&pow2[j])
                {
                    length+=t[j].length;
                    value+=t[j].value;
                }
                else
                {
                    tree[k].x=t[j].x;
                    tree[k++].y=t[j].y;
                }
            }
            //printf("%d %d\n",i,k);
            if(value>minValue or (value==minValue and k<=mt)) continue;
            double temp=graham();
            //printf("%d %.2lf, %.2lf\n",i,length, temp);
            if(length>=temp)
            {
                minValue=value;
                mp=i,mt=k,extra=length-temp;
            }
        }
        if(cas>1) printf("\n");
        printf("Forest %d\n",cas++);
        printf("Cut these trees: ");
        for(int i=0;i<n;i++)
        {
            if(mp&pow2[i])
            {
                printf("%d ",i+1);
            }
        }
        printf("\nExtra wood: %.2lf\n",extra);
    }
}
