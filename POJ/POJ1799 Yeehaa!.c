#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
    float R;
    int n,t,i=1;
    for(scanf("%d",&t);i<=t;i++)
    {
        scanf("%f%d",&R,&n);
        printf("Scenario #%d:\n%.3f\n\n",i,R/(1+(1/sin(3.14159265358979/n))));
    }
    return 0;
}
