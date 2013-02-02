#include<stdio.h>

int main(int argc, char* argv[])
{
	int t = 1, a[6], b[100], f[60005];
	while(scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]),a[0] or a[1] or a[2] or a[3] or a[4] or a[5])
	{
	    printf("Collection #%d:\n", t++);
	    int sum = 0;
	    int n = 0;
	    for(int i = 0; i<6; i++)
	    {
	        sum += a[i] * (i+1);
	        int k = 0;
	        for(int j = 0;(1<<j)<a[i]; j++)
	        {
	            b[n++] = (1<<j) * (i+1);
	            k += (1<<j) * (i+1);
	        }
	        if(a[i] > k)
	        {
	            b[n++] = (a[i] - k) * (i+1);
	        }
	    }
	    if(sum&1 == 1)
	    {
	        printf("Can't be divided.\n\n");
	    }
	    else
	    {
	        for(int i = 0; i<60005; i++)
	        {
	            f[i] = 0;
	        }
	        f[0] = 1;
	        for(int i = 0; i<n; i++)
	        {
	            for(int j = sum/2; j>=b[i]; j--)
	            {
	                if(f[j-b[i]])
	                {
	                    f[j] = 1;
	                }
	            }
	        }
	        if(f[sum/2])
	        {
	            printf("Can be divided.\n\n");
	        }
	        else
	        {
	            printf("Can't be divided.\n\n");
	        }
	    }
	}
	return 0;
}
