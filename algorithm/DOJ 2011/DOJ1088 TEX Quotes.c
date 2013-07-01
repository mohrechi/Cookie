#include<stdio.h>

int main()
{
    char s1[1000],s2[1000],*p1,*p2;
    int a=1;
    while(gets(s1)!=NULL)
    {
        p1=&s1[0],p2=&s2[0];
        while(*p1!='\0')
        {
            if(*p1=='"')
            {
                if(a==1)
                {
                    *p2='`',p2++,*p2='`',p2++,a=0;
                }
                else
                {
                    *p2='\'',p2++,*p2='\'',p2++,a=1;
                }
            }
            else
            {
                *p2=*p1,p2++;
            }
            p1++;
        }
        *p2='\0';
        printf("%s\n",s2);
    }
    return 0;
}
