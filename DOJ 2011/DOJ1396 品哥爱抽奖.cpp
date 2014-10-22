#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<memory.h>

int max(int x, int y)
{
    return x>y?x:y;
}

double get(char s[50])
{
    double t=1;
    int len=strlen(s);
    if(len==0) return 0;
    while(len--)
    {
        t*=0.1;
    }
    return t;
}

void compare(char s1[50], char s2[50])
{
    int l1=strlen(s1);
    int l2=strlen(s2);
    if(l1>l2)
    {
        compare(s2,s1);
        return;
    }
    l1--,l2--;
    while(l1>=0)
    {
        if(s1[l1]!=s2[l2])
        {
            break;
        }
        l1--,l2--;
    }
    if(l1==-1)
    {
        s2[0]=0;
    }
}

int main()
{
    int n;
    char temp[100][50];
    double ans;
    while(scanf("%d",&n),n)
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",temp[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(temp[i][0]!=0 && temp[j][0]!=0)
                {
                    compare(temp[i],temp[j]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            ans+=get(temp[i]);
        }
        printf("%.4lf\n",ans*100000);
    }
    return 0;
}
