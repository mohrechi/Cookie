#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct word
{
    int len;
    char s[20];
}dic[10005];
int n;
void cmp0(char s[], word w)
{
    int count=0;
    for(int i=0;i<w.len;i++)
    {
        if(s[i]==w.s[i])
        {
            count++;
        }
    }
    if(count==w.len-1)
    {
        printf(" %s",w.s);
    }
}
void cmp1(char s[], word w)
{
    bool flag=false;
    int i;
    for(i=0;i<w.len;i++)
    {
        if(flag)
        {
            if(s[i-1]!=w.s[i])
            {
                break;
            }
        }
        else
        {
            if(s[i]!=w.s[i])
            {
                flag=true;
            }
        }
    }
    if(i==w.len)
    {
        printf(" %s",w.s);
    }
}
void cmp2(char s[], word w)
{
    bool flag=false;
    int i,len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(flag)
        {
            if(s[i]!=w.s[i-1])
            {
                break;
            }
        }
        else
        {
            if(s[i]!=w.s[i])
            {
                flag=true;
            }
        }
    }
    if(i==len)
    {
        printf(" %s",w.s);
    }
}
void divide(char s[])
{
    int len=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(len==dic[i].len)
        {
            cmp0(s,dic[i]);
        }
        else if(len==dic[i].len-1)
        {
            cmp1(s,dic[i]);
        }
        else if(len==dic[i].len+1)
        {
            cmp2(s,dic[i]);
        }
    }
}
bool check(char s[])
{
    for(int i=0;i<n;i++)
    {
        if(not strcmp(s,dic[i].s))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    n=0;
    while(scanf("%s",dic[n].s),*dic[n].s!='#')
    {
        dic[n++].len=strlen(dic[n].s);
    }
    char s[20];
    while(scanf("%s",s),*s!='#')
    {
        if(check(s))
        {
            printf("%s is correct\n",s);
        }
        else
        {
            printf("%s:",s);
            divide(s);
            printf("\n");
        }
    }
    return 0;
}
