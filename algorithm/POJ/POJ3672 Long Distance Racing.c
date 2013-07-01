#include<stdio.h>

int main(int argc, char* argv[])
{
    long m,t,i,s,n;
    int u,f,d;
    char c;
    while(scanf("%ld%ld%d%d%d",&m,&t,&u,&f,&d)!=EOF)
    {
        s=0;
        for(i=0;i<t;i++)
        {
            scanf("\n%c",&c);
            if(s<=m)
            {
                n=i;
                if(c=='u'||c=='d')s+=u+d;
                else if(c=='f')s+=2*f;
            }
        }
        printf("%ld\n",n);
    }
    return 0;
}
