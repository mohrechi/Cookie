#include<stdio.h>

int a[8][8];

int judge(int i, int j, int x, int y, int m)
{
    if(i<0||j<0||i>7||j>7) return 0;
    if(!a[i][j]) a[i][j]=m+1;
    if(i==x&&j==y) return 1;
    return 0;
}

int flood(int x, int y, int m)
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(a[i][j]==m)
            {
                if(judge(i+2,j+1,x,y,m)||judge(i+1,j+2,x,y,m)||judge(i-2,j+1,x,y,m)||judge(i-1,j+2,x,y,m)||judge(i+2,j-1,x,y,m)||judge(i+1,j-2,x,y,m)||judge(i-2,j-1,x,y,m)||judge(i-1,j-2,x,y,m))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(int argc, char* argv[])
{
	int x1,y1,x2,y2,i,j;
	char s1[5],s2[5];
	while(scanf("%s%s",s1,s2)!=EOF)
	{
	    x1=s1[0]-'a';
	    x2=s2[0]-'a';
	    y1=s1[1]-'1';
	    y2=s2[1]-'1';
	    for(i=0;i<8;i++)
	    {
	        for(j=0;j<8;j++)
	        {
	            a[i][j]=0;
	        }
	    }
	    a[x1][y1]=1,i=0;
	    while(flood(x2,y2,++i));
	    printf("To get from %s to %s takes %d knight moves.\n",s1,s2,a[x2][y2]-1);
	}
	return 0;
}
