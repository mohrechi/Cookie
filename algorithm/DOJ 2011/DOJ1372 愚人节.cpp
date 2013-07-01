#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s1[100],s2[100],ch;
    int len,score,temp;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        score=0,temp=0;
        len=strlen(s1);
        for(int i=0;i<len;i++)
        {
            ch='.';
            if(s1[i]=='1')
            {
                ch='1';
            }
            if(s2[i]=='1')
            {
                ch='1';
            }
            if(ch=='1')
            {
                score+=(temp/2)*16+2;
                if(temp&1)
                {
                    score+=2;
                }
                temp=0;
            }
            else
            {
                temp++;
            }
        }
        score+=(temp/2)*16;
        if(temp&1)
        {
            score+=2;
        }
        printf("%d\n",score);
    }
    return 0;
}

