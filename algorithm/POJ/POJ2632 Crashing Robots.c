#include<stdio.h>

int main(int argc, char* argv[])
{
	int o,a,b,x,y,c,d,i,j,z,f,q,w;
	char n[105][105],g[105][105],u;
	scanf("%d",&o);
	while(o--)
	{
	    for(i=0;i<105;i++)
	    {
	        for(j=0;j<105;j++)
	        {
	            n[i][j]=0,g[i][j]=0;
	        }
	    }
	    scanf("%d%d%d%d",&a,&b,&c,&d);
	    z=0;
	    while(c--)
	    {
	        scanf("%d %d %c",&x,&y,&u);
	        n[y][x]=++z;
	        switch(u)
	        {
	            case 'N': g[y][x]=3; break;
	            case 'E': g[y][x]=2; break;
	            case 'S': g[y][x]=1; break;
	            case 'W': g[y][x]=4; break;
	        }
	    }
	    f=1;
	    while(d--)
	    {
	        scanf("%d %c %d",&x,&u,&y);
	        if(f)
	        {
	            for(j=1;j<=a;j++)
	            {
	                for(i=1;i<=b;i++)
	                {
	                    if(n[i][j]==x) break;
	                }
	                if(n[i][j]==x) break;
	            }
	            q=i,w=j;
	            if(u=='F')
	            {
	                while(y--)
	                {
	                    switch(g[q][w])
	                    {
	                        case 1: i--;break;
	                        case 2: j++;break;
	                        case 3: i++;break;
	                        case 4: j--;break;
	                    }
	                    if(!i||!j||i==b+1||j==a+1)
	                    {
	                        f=0;
	                        printf("Robot %d crashes into the wall\n",x);
	                        break;
	                    }
	                    if(n[i][j])
	                    {
	                        f=0;
	                        printf("Robot %d crashes into robot %d\n",x,n[i][j]);
	                        break;
	                    }
	                }
	                n[q][w]=0,n[i][j]=x,g[i][j]=g[q][w],g[q][w]=0;
	            }
	            if(u=='L')
	            {
	                y%=4;
	                while(y--)
	                {
                        switch(g[i][j])
                        {
                            case 1: g[i][j]=2;break;
                            case 2: g[i][j]=3;break;
                            case 3: g[i][j]=4;break;
                            case 4: g[i][j]=1;break;
                        }
	                }
	            }
	            if(u=='R')
	            {
	                y%=4;
	               while(y--)
	                {
                        switch(g[i][j])
                        {
                            case 1: g[i][j]=4;break;
                            case 2: g[i][j]=1;break;
                            case 3: g[i][j]=2;break;
                            case 4: g[i][j]=3;break;
                        }
	                }
	            }
	        }
	    }
	    if(f) printf("OK\n");
	}
	return 0;
}
