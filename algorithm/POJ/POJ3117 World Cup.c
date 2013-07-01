#include<stdio.h>

int main(int argc, char* argv[])
{
	int a,m,n,i,j;
	char s[15];
	for(;;)
	{
        scanf("%d%d",&m,&n);
        if(!m)break;
        j=0;
        while(m--)
        {
            scanf("%s%d",s,&a);
            j+=a;
        }
        printf("%d\n",3*n-j);
	}
	return 0;
}
