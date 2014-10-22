#include<stdio.h>

int main(int argc, char** argv)
{
    int n,t,a,b,s,i,j;
    char s1[100],s2[100],*p;
    for(scanf("%d",&n);n--;)
    {
        scanf("%s%s",s1,s2);
        p=s1,a=0;
        while(*p)
        {
            t=1;
            if(*p>='2'&&*p<='9')
            {
                t=*p-48;
                p++;
            }
            switch(*p)
            {
                case 'm': a+=1000*t; break;
                case 'c': a+=100*t; break;
                case 'x': a+=10*t; break;
                case 'i': a+=t; break;
            }
            p++;
        }
        p=s2,b=0;
        while(*p)
        {
            t=1;
            if(*p>='2'&&*p<='9')
            {
                t=*p-48;
                p++;
            }
            switch(*p)
            {
                case 'm': b+=1000*t; break;
                case 'c': b+=100*t; break;
                case 'x': b+=10*t; break;
                case 'i': b+=t; break;
            }
            p++;
        }
        s=a+b;
        if(s/1000>0)
        {
            if(s/1000>1) printf("%d",s/1000);
            printf("m");
        }
        s%=1000;
        if(s/100>0)
        {
            if(s/100>1) printf("%d",s/100);
            printf("c");
        }
        s%=100;
        if(s/10>0)
        {
            if(s/10>1) printf("%d",s/10);
            printf("x");
        }
        s%=10;
        if(s>0)
        {
            if(s>1) printf("%d",s);
            printf("i");
        }
        printf("\n");
    }
    return 0;
}
