#include<stdio.h>

int main(int argc, char *argv[])
{
    int n,i,a,b;
    char n1[5],n2[5];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%s",n1,n2);
        a=0,b=0;
        for(i=0;i<4;i++)
        {
            if(n2[i]==n1[i])a++;
            if(n2[i]==n1[0]||n2[i]==n1[1]||n2[i]==n1[2]||n2[i]==n1[3])b++;
        }
        printf("%dA%dB\n",a,b-a);
    }
    return 0;
}
