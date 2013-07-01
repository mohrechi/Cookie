#include<stdio.h>

int main(int argc, char* argv[])
{
    char s[100];
    int m,a;
    for(;;)
    {
        scanf("%s",s);
        a=0;
        if(*s=='#') break;
        for(;;)
        {
            scanf("%s%d%s",s,&m,s);
            if(*s=='F') a+=2*m;
            if(*s=='B') a+=(m+1)/2+m;
            if(*s=='Y')
            {
                if (m<500) a+=500;
                else a+=m;
            }
            scanf("%s",s);
            if(*s=='0') break;
        }
        printf("%d\n",a);
    }
	return 0;
}
