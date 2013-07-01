#include<stdio.h>
#include<math.h>

main()
{
    int in,out,i,j,c=1;
    while (c)
    {
        scanf("%d",&in);
        if (in==0)
        {
            break;
        }
        i=0;
        j=in;
        while (j%2==0)
        {
            i++;
            j/=2;
        }
        out=(int)pow(2,i);
        printf("%d %d\n",in,out);
    }
    return 0;
}
