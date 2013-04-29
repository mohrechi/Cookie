#include<stdio.h>

main()
{
    int r,w,l,s=0;
    while(1)
    {
        s++;
        scanf("%d",&r);
        if(r==0) break;
        scanf("%d%d",&w,&l);
        printf("Pizza %d ",s);
        if(r*r*4>=w*w+l*l)
        {
            printf("fits on the table.\n");
        }
        else
        {
            printf("does not fit on the table.\n");
        }
    }
    return 0;
}
