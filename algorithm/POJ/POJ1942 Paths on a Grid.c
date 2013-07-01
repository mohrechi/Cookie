#include<stdio.h>

double c(unsigned int n,unsigned int k)
{
    double s=1;
    int i;
    while(k)s=s*n--/k--;
    return s;
}

int main(int argc, char* argv[])
{
	unsigned int m,n;
	for(;;)
	{
	    scanf("%d%d",&m,&n);
	    if(!m&&!n) break;
	    printf("%.0f\n",c(m+n,m<n?m:n));
	}
	return 0;
}
