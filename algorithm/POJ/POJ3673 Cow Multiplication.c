#include<stdio.h>

int main(int argc, char* argv[])
{
    char s1[20],s2[20];
    int i,j,m=0,n=0,a[20],b[20],sum=0;
    scanf("%s%s",s1,s2);
    while(s1[m]!='\0')a[m]=s1[m++]-48;
    while(s2[n]!='\0')b[n]=s2[n++]-48;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+=a[i]*b[j];
        }
    }
    printf("%d\n",sum);
    return 0;
}
