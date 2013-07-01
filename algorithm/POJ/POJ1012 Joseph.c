#include<stdio.h>

int main()
{
    int k,a[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
    for(;;)
    {
        scanf("%d",&k);
        if(!k) break;
        printf("%d\n",a[k]);
    }
    return 0;
}
