#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,i,j,f;
	char x[105],y[105];
	for(scanf("%d",&n);n--;)
	{
	    scanf("%s%s",x,y);
	    f=0;
	    for(i=0,j=0;x[i];i++)if(x[i]==y[j])j++;
	    if(!y[j]) f=1;
	    while(y[j])j++;
	    if(!f)for(i=0,j--;x[i];i++)if(x[i]==y[j])j--;
	    if(j<0) f=1;
	    if(f) printf("YES\n");
	    else printf("NO\n");
	}
	return 0;
}
