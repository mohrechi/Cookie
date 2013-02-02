#include<stdio.h>

int main()
{
    int a,b,c;
    double ans;
    while(1)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(0==b) break;
        if(0==c)
        {
            printf("%d\n",(int)((float)a/b+0.5));
            continue;
        }
        ans=(float)a/b;
        switch(c)
        {
            case 1: printf("%.1f\n",ans);break;
            case 2: printf("%.2f\n",ans);break;
            case 3: printf("%.3f\n",ans);break;
            case 4: printf("%.4f\n",ans);break;
            case 5: printf("%.5f\n",ans);break;
        }
    }
    return 0;
}