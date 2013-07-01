#include<stdio.h>
#include<stdlib.h>

struct ds
{
    int         snum;
    char      ss[51];
}dna[101];

int cmp( const void *a ,const void *b)
{
    return (*(ds *)a).snum>(*(ds *)b).snum?1:-1;
}

int main(int argc, char* argv[])
{
	int         n;
	int         m;
	int         i;
	int         j;
	int         k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
	    scanf("%s",dna[i].ss);
	    dna[i].snum=0;
	    for(j=0;j<n;j++)
	    {
	        for(k=j+1;k<n;k++)
                if(dna[i].ss[k]<dna[i].ss[j])
                    dna[i].snum++;
	    }
	}
	qsort(dna,m,sizeof(dna[0]),cmp);
	for(i=0;i<m;i++) printf("%s\n",dna[i].ss);
	return 0;
}
