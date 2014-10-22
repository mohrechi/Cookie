#include<stdio.h>

int     n;
int     a[7][7];
int     max;
int     min;

void shift(int i)
{
    int     temp;
    int     k;
    temp=a[i][n-1];
    for(k=n-1;k>0;k--)
        a[i][k]=a[i][k-1];
    a[i][0]=temp;
}

void digui(int i)
{
    int     temp;
    int     j;
    if(i>n-1)
    {
        max=0;
        for(j=0;j<n;j++)
        {
            temp=0;
            for(i=0;i<n;i++)
                temp+=a[i][j];
            if(temp>max) max=temp;
        }
        if(min>max) min=max;
    }
    else
    {
        temp=n;
        while(temp--)
        {
            shift(i);
            digui(i+1);
        }
    }
}

int main(int argc, char* argv[])
{
    int     i;
    int     j;
    int     k;
    for(;;)
    {
        scanf("%d",&n);
        if(-1==n) break;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        min=9999999;
        digui(0);
        printf("%d\n",min);
    }
    return 0;
}
