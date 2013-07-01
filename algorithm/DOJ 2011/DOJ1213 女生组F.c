#include<stdio.h>

main()
{
    char n[10001];
    int s[50001],i,j;
    while(scanf("%s",n)!=EOF)
    {
        for(i=0;n[i]!='\0';i++)
        {
            j=4*i;
            switch((int)n[i])
            {
                case 48: s[j]=0,s[j+1]=0,s[j+2]=0,s[j+3]=0;break;
                case 49: s[j]=0,s[j+1]=0,s[j+2]=0,s[j+3]=1;break;
                case 50: s[j]=0,s[j+1]=0,s[j+2]=1,s[j+3]=0;break;
                case 51: s[j]=0,s[j+1]=0,s[j+2]=1,s[j+3]=1;break;
                case 52: s[j]=0,s[j+1]=1,s[j+2]=0,s[j+3]=0;break;
                case 53: s[j]=0,s[j+1]=1,s[j+2]=0,s[j+3]=1;break;
                case 54: s[j]=0,s[j+1]=1,s[j+2]=1,s[j+3]=0;break;
                case 55: s[j]=0,s[j+1]=1,s[j+2]=1,s[j+3]=1;break;
                case 56: s[j]=1,s[j+1]=0,s[j+2]=0,s[j+3]=0;break;
                case 57: s[j]=1,s[j+1]=0,s[j+2]=0,s[j+3]=1;break;
                case 65: s[j]=1,s[j+1]=0,s[j+2]=1,s[j+3]=0;break;
                case 66: s[j]=1,s[j+1]=0,s[j+2]=1,s[j+3]=1;break;
                case 67: s[j]=1,s[j+1]=1,s[j+2]=0,s[j+3]=0;break;
                case 68: s[j]=1,s[j+1]=1,s[j+2]=0,s[j+3]=1;break;
                case 69: s[j]=1,s[j+1]=1,s[j+2]=1,s[j+3]=0;break;
                case 70: s[j]=1,s[j+1]=1,s[j+2]=1,s[j+3]=1;break;
            }
        }
        j=4*i;
        for(i=0;i<j;i++)
        {
            printf("%d",s[i]);
        }
        printf("\n");
    }
    return 0;
}
