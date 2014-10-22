#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    char    w1[1000];
    char    w2[1000];
    int     n1;
    int     n2;
    int     i;
    int     j;
    int     max;
    int     count;
    int     temp;
    char    *p;
    while(scanf("%s",w1),w1[0]!='-')
    {
        scanf("%s",w2);
        printf("appx(%s,%s) = ",w1,w2);
        n1=strlen(w1);
        n2=strlen(w2);
        for(i=n1;i<1000;i++) w1[i]='.';
        for(i=n2;i<1000;i++) w2[i]=',';
        max=0;
        for(i=0;i<n2;i++)
        {
            p=w1+i, count=0;
            for(j=0;j<1000;j++)
            {
                if(*(p+j)==w2[j]) count++;
            }
            if(count>max) max=count;
        }
        for(i=1;i<n1;i++)
        {
            p=w2+i, count=0;
            for(j=0;j<1000;j++)
            {
                if(*(p+j)==w1[j]) count++;
            }
            if(count>max) max=count;
        }
        n1=n1+n2,n2=max*2;
        temp=n1, max=n2;
        if(0!=n2)
        {
            while(n1!=n2)
            {
                if(n1>n2) n1-=n2; else n2-=n1;
            }
            if(temp==n2)
                printf("1\n");
            else
                printf("%d/%d\n",max/n1,temp/n2);
        }
        else
            printf("0\n");
    }
    return 0;
}
