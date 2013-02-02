#include<stdio.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

int main(int argc, char* argv[])
{
	int a[50],i,n,s;
	for(scanf("%d",&n),i=0;i<n;i++)scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	for(i=n-1,s=0;i>=0;i-=2)
	{
        if(i==0)
        {
            s+=a[0];
            break;
        }
        if(i==1)
        {
            s+=a[1];
            break;
        }
        if(i==2)
        {
            s+=a[0]+a[1]+a[2];
            break;
        }
        if(a[0]+a[i-1]<2*a[1])
        {
            s+=a[0]*2+a[i]+a[i-1];
        }
        else
        {
            s+=a[1]*2+a[i]+a[0];
        }
	}
	printf("%d\n",s);
	return 0;
}
