#include<stdio.h>
#include<stdlib.h>
int n,p;
int ma[2][2]={1,0,0,1},mb[2][2]={1,1,1,0},mc[2][2]={2,1,1,1};
void copy(int a[2][2], int b[2][2])
{
    a[0][0]=b[0][0],a[0][1]=b[0][1];
    a[1][0]=b[1][0],a[1][1]=b[1][1];
}
void mul(int a[2][2],int b[2][2],int c[2][2])
{
    int temp[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            temp[i][j]=0;
            for(int k=0;k<2;k++)
            {
                temp[i][j]+=a[i][k]*b[k][j];
            }
            temp[i][j]%=p;
        }
    }
    copy(c,temp);
}
void fibonacci(int m,int temp[2][2])
{
    if(m==0)
    {
        copy(temp,ma);
        return;
    }
    if(m==1)
    {
        copy(temp,mb);
        return;
    }
    if(m==2)
    {
        copy(temp,mc);
        return;
    }
    fibonacci(m/2,temp);
    mul(temp,temp,temp);
    if(m&1)
    {
        mul(temp,mb,temp);
    }
}
int main()
{
    int t,temp[2][2];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&p);
        fibonacci(n,temp);
        printf("%d\n",temp[0][0]);
    }
    return 0;
}
