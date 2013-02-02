#include<stdio.h>
#include<string.h>

int cmp( const void *a , const void *b )
{
    return *(int *)b - *(int *)a;
}

int main(int argc, char* argv[])
{
	char x[110],y[110];
	int f=1,l,a[26]={0},b[26]={0},i;
	scanf("%s%s",x,y);
	l=strlen(x);
	for(i=0;i<l;i++) a[x[i]-'A']++,b[y[i]-'A']++;
	qsort(a,26,sizeof(a[0]),cmp),qsort(b,26,sizeof(b[0]),cmp);
	for(i=1;i<26;i++)if(a[i]!=b[i])f=0;
	if(f) printf("YES\n");
	else printf("NO\n");
	return 0;
}
