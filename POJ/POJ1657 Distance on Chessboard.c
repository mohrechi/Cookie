#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
    int n,x,y,a,b,i,j;
    char s[3];
    for(scanf("%d",&n);n--;)
    {
        scanf("%s",s);
        x=s[0]-64,y=s[1]-48;
        scanf("%s",s);
        a=s[0]-64,b=s[1]-48;
        i=abs(x-a),j=abs(y-b);
        if(i==0&&j==0)
        {
            printf("0 0 0 0\n");
        }
        else
        {
            printf("%d ",i>j?i:j);
            if(x==a||y==b||i==j)
            {
                printf("1 ");
            }
            else
            {
                printf("2 ");
            }
            if(x==a||y==b)
            {
                printf("1 ");
            }
            else
            {
                printf("2 ");
            }
            if(i%2!=j%2)
            {
                printf("Inf\n");
            }
            else
            {
                if(i==j)
                {
                    printf("1\n");
                }
                else
                {
                    printf("2\n");
                }
            }
        }
    }
	return 0;
}
