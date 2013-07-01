#include<stdio.h>
#include<string.h>

void f(char *s)
{
    int n,i,t,r;
    n=strlen(s);
    for(i=0,t=n/2;i<t;i++)
    {
        r=s[i]-48,s[i]=s[n-i-1]-48,s[n-i-1]=r;
    }
    while(!s[--n]);
    s[n+1]=-1;
}

int main(int argc, char* argv[])
{
	char s1[110],s2[110]={-1};
	int n,i,t;
	for(;;)
	{
	    scanf("%s",s1);
        if(*s1=='0'&&!*(s1+1))break;
        f(s1);
        i=0;
        while(s1[i]>=0)
        {
            if(s2[i]==-1)
            {
                s2[i+1]=-1;
                s2[i]=s1[i];
            }
            else
            {
                s2[i]+=s1[i];
                if(s2[i]>9)
                {
                    s2[i]-=10;
                    if(s2[i+1]==-1) s2[i+2]=-1,s2[i+1]=1;
                    else s2[i+1]++;
                }
            }
            i++;
        }
	}
	i=-1;
	while(s2[++i]>=0);
	for(;i>0;)printf("%d",s2[--i]);
	printf("\n");
	return 0;
}
