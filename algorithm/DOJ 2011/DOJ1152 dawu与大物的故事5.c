#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int a,b,c,i,m,d[205],f;
	while(scanf("%d%d%d",&a,&b,&c),a||b)
	{
	    m=2100000000;
	    for(i=-100;i<=100;i++)
	    {
	        d[i+100]=abs(a*i*i+b*i+c);
	        if(d[i+100]<m)
	        {
	            m=d[i+100];
	        }
	    }
	    f=1;
	    for(i=-100;i<=100;i++)
	    {
            if(d[i+100]==m)
            {
                if(f)
                {
                    f=0;
                    printf("%d",i);
                }
                else
                {
                    printf(" %d",i);
                }
            }
	    }
	    printf("\n");
	}
	return 0;
}
