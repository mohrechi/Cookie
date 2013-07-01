#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,a,b;
    char s[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%d%d",s,&a,&b);
        switch(*s)
        {
            case '+': printf("%d\n",a+b); break;
            case '-': printf("%d\n",a-b); break;
            case '*': printf("%d\n",a*b); break;
            case '/':
                if(a%b==0) printf("%d\n",a/b);
                else printf("%.2lf\n",(double)a/b);
        }
    }
    return 0;
}
