#include<stdio.h>
#include<string.h>

main()
{
    int t,n,i,max,temp;
    char name[100],te[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        max=0;
        for(i=1;i<=n;i++)
        {
            scanf("%s%d",te,&temp);
            if (temp>max)
            {
                max=temp;
                strcpy(name,te);
            }
        }
        printf("%s\n",name);
    }
    return 0;
}
