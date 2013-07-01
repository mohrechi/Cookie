#include<stdio.h>
#include<string.h>

int main(void)
{
    char       r[10];
    int         temp[10000];
    int         n;
    int         dot;
    int         len;
    int         i;
    int         j;
    int         num;
    while(scanf("%s%d",r,&n)!=EOF)
    {
        i=0,dot=-1;
        while(r[i]!='\0')
        {
            if('.'==r[i]) dot=i;
            i++;
        }
        len=i-1;
        i=len;
        while(r[i]=='0')
        {
            r[i]='\0';
            i--,len--;
        }
        if(dot!=-1)
        {
            for(i=dot;i<=len;i++) r[i]=r[i+1];
            dot=len-dot;
        }
        num=0,len--;
        for(i=0;i<=len;i++) r[i]-=48, num=num*10+r[i], temp[len-i]=r[i];
        temp[len+1]=-1, j=dot*n;
        while(--n)
        {
            i=0;
            while(temp[i]!=-1) temp[i++]*=num;
            i=0;
            while(temp[i]!=-1)
            {
               if(temp[i]>=10)
                {
                    if(temp[i+1]==-1)
                    {
                        temp[i+1]=temp[i]/10;
                        temp[i+2]=-1;
                    }
                    else
                    {
                        temp[i+1]+=temp[i]/10;
                    }
                    temp[i]%=10;
                }
                i++;
            }
        }
        i=0,j--;
        while(temp[i]!=-1)
        {
            if(i==j) temp[i]+=10;
            i++;
        }
        if(r[0]!=0)
        {
            for(--i;i>=0;i--)
            {
                if(temp[i]>=10) printf(".%d",temp[i]-10); else printf("%d",temp[i]);
            }
            printf("\n");
        }
        else
        {
            printf(".");
            j=j-i+1;
            while(j--) printf("0");
            for(--i;i>=0;i--)
            {
                printf("%d",temp[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
