#include<stdio.h>
#include<math.h>

int main(void)
{
	int a[9],i,j,f;
	while(scanf("%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8])!=EOF)
	{
	    for(i=0,j=8,f=1;i<9;i++,j--)
	    {
	        if(f)
	        {

                if(i==8) printf("%d",a[i]);
                else if(a[i])
                {
                    if(a[i]<0) printf("-");
                    if(a[i]!=1&&a[i]!=-1) printf("%d",abs(a[i]));
                    if(a[i])
                    {
                        if(j>1) printf("x^%d",j);
                        if(j==1) printf("x");
                    }
                    f=0;
                }
	        }
	        else
	        {
	            if(a[i]>0) printf(" + ");
	            if(a[i]<0) printf(" - ");
	            if(a[i]!=1&&a[i]!=-1&&a[i]!=0) printf("%d",abs(a[i]));
	            if(!j&&a[i]==1||a[i]==-1) printf("1");
	            if(a[i])
	            {
	                if(j>1) printf("x^%d",j);
	                if(j==1) printf("x");
	            }
	        }
	    }
	    printf("\n");
	}
	return 0;
}
