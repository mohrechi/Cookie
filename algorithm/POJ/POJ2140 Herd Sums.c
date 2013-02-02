#include<stdio.h>

int main(int argc, char* argv[])
{
    int n,i,s=0,j,t;
	scanf("%d",&n);
	t=n/2;
    for(i=1;i<=n;i+=2)
        if(!(n%i))
            if(i%2) s++;
	printf("%d\n",s);
	return 0;
}
