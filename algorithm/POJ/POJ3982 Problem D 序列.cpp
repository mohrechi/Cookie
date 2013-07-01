#include <stdio.h>
#include <string.h>

char str0[1048576];
char str1[1048576];
char str2[1048576];
char str3[1048576];
char str4[1048576];
char temp[1048576];
void bigadd(char* a,char* b,char* answer)
{
    int lengtha;
    int lengthb;
    int lengthtemp;
    int lengthanswer;
    int tempa;
    int tempb;
    int sign;
    lengtha=strlen(a);
    lengthb=strlen(b);
    lengthtemp=0;
    lengthanswer=0;
    tempa=0;
    tempb=0;
    sign=0;
    while(lengtha>0 && lengthb>0)
    {
        tempa=a[lengtha-1]-'0';
        tempb=b[lengthb-1]-'0';
        temp[lengthtemp]=(tempa+tempb+sign) % 10+'0';
        sign=(tempa+tempb+sign)/ 10;
        lengtha--;
        lengthb--;
        lengthtemp++;
    }
    while(lengtha>0)
    {
        tempa=a[lengtha-1]-'0';
        temp[lengthtemp]=(tempa+sign) % 10+'0';
        sign=(tempa+sign)/ 10;
        lengtha--;
        lengthtemp++;
    }
    while(lengthb>0)
    {
        tempb=b[lengthb-1]-'0';
        temp[lengthtemp]=(tempb+sign) % 10+'0';
        sign=(tempb+sign)/ 10;
        lengthb--;
        lengthtemp++;
    }
    if(sign != 0)
    {
        temp[lengthtemp++]=sign+'0';
    }
    lengthtemp--;
    while(lengthtemp>=0)
    {
        answer[lengthanswer]=temp[lengthtemp];
        lengthanswer++;
        lengthtemp--;
    }
    answer[lengthanswer]='\0';
    return;
}

void swap(char**a,char**b)
{
    char *temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int i;
    char *a0,*a1,*a2,*a3,*a4;
    a0=str0;
    a1=str1;
    a2=str2;
    a3=str3;
    a4=str4;
    while(scanf("%s %s %s",a0,a1,a2) != EOF)
    {
        for(i=3; i<=99; i++)
        {
            bigadd(a0,a1,a4);
            bigadd(a4,a2,a3);
            swap(&a0,&a1);
            swap(&a1,&a2);
            swap(&a2,&a3);
        }
        printf("%s\n",a2);
    }
    return 0;
}
