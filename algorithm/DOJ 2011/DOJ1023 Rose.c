#include<stdio.h>

main ()
{
    int m[5],n,count;
    while (scanf("%d%d%d%d%d",&m[0],&m[1],&m[2],&m[3],&m[4])!=EOF)
    {
        count=0;
        for(n=0;n<5;n++)
        {
            if (m[n]==3)
            {
                count+=2;
            }
            if (m[n]==5)
            {
                count+=4;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
