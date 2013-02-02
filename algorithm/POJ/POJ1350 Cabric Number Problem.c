#include<stdio.h>

int cmp(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}

int main(int argc, char* argv[])
{
	int a[4],b[4],i,n,s,x,y,m,t;
	while(scanf("%d",&n),s=0,n+1)
	{
	    printf("N=%d:\n",n);
	    if(n<1000||n>9999)
	    {
	        printf("No!!\n");
	        continue;
	    }
	    for(i=0;i<4;i++)
        {
            a[i]=n%10;
            n/=10;
        }
        qsort(a,4,sizeof(*a),cmp);
        b[3]=a[0],b[2]=a[1],b[1]=a[2],b[0]=a[3];
        if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3])
        {
            printf("No!!\n");
            continue;
        }
	    for(m=4;;)
	    {
	        for(i=0,t=1;i<m-1;i++) t*=10;
	        for(i=0,x=0;i<m;i++,t/=10) x+=t*a[i];
	        for(t=1,i=3,y=0;i>3-m;i--,t*=10) y+=t*b[i];
            s++;
            n=x-y;
            printf("%d-%d=%d\n",x,y,n);
            if(n==6174||n==0)
            {
                printf("Ok!! %d times\n",s);
                break;
            }
            for(i=0,m=0;i<4;i++)
            {
                a[i]=n%10;
                if(n)m++;
                n/=10;
            }
            qsort(a,4,sizeof(*a),cmp);
            b[3]=a[0],b[2]=a[1],b[1]=a[2],b[0]=a[3];
	    }
	}
	return 0;
}
