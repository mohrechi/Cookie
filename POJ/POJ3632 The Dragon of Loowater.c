#include<stdio.h>

cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}

int main(int argc, char* argv[])
{
	int m,n,i,j,s,c,a[20009],b[20009];
	for(;;)
	{
	    scanf("%d%d",&m,&n);
	    if(!m&&!n) break;
	    for(i=0;i<m;i++) scanf("%d",&a[i]);
	    for(i=0;i<n;i++) scanf("%d",&b[i]);
	    if(n<m)
	    {
	        printf("Loowater is doomed!\n");
	        continue;
	    }
	    qsort(a,m,sizeof(int),cmp);
	    qsort(b,n,sizeof(int),cmp);
	    for(i=0,s=0,c=0;i<n;i++)
	    {
	        for(j=m-1;j>=0;j--)
	        {
	            if(b[i]>=a[j]) break;
	        }
	        if(j!=-1)
	        {
	            a[j]=2100000000;
                s+=b[i],c++;
                if(c==m) break;
            }
	    }
	    if(c==m) printf("%d\n",s);
	    else printf("Loowater is doomed!\n");
	}
	return 0;
}
