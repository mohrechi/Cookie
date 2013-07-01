#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char twisted[1000], origin[1000];
    int key,len,temp;
    while(scanf("%d",&key),key)
    {
        scanf("%s",twisted);
        len=strlen(twisted);
        for(int i=0;i<len;i++)
        {
            if(twisted[i]=='.')
            {
                temp=27;
            }
            else if(twisted[i]=='_')
            {
                temp=0;
            }
            else
            {
                temp=twisted[i]-'_'-1;
            }
            int ori=(temp+i)%28;
            if(ori==0)
            {
                origin[(key*i)%len]='_';
            }
            else if(ori==27)
            {
                origin[(key*i)%len]='.';
            }
            else
            {
                origin[(key*i)%len]='a'+ori-1;
            }
        }
        origin[len]=0;
        printf("%s\n",origin);
    }
    return 0;
}
