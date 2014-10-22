#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    int l,i,j;
    char s[3000],r[3000];
    while(gets(s))
    {
        l=strlen(s);
        for(i=0,j=0;i<=l;i++)
        {
            if(s[i]=='y'&&s[i+1]=='o'&&s[i+2]=='u')
            {
                r[j++]='w',r[j++]='e';
                i+=2;
            }
            else r[j++]=s[i];
        }
        printf("%s\n",r);
    }
    return 0;
}
