#include<stdio.h>
#include<string.h>

int cmp(const void *a, const void *b)
{
    return *(char*)a-*(char*)b;
}

void w(char *a, char *c)
{
    int l,i,j,b[60];
    for(i=48;i<58;i++)b[i]=0;
    while(*a)
    {
        b[*a]++;
        a++;
    }
    for(i=48;i<58;i++)
    {
        if(b[i])
        {
            if(b[i]>9)*c++=b[i]/10+48,*c++=b[i]%10+48;
            else *c++=b[i]+48;
            *c++=i;
        }
    }
    *c=0;
}

int main(int argc, char* argv[])
{
	char s[20][100];
	int i,j;
	while(scanf("%s",s[0]),*s[0]!='-')
	{
	    printf("%s",s[0]);
	    for(i=1;i<=15;i++)
	    {
	        w(s[i-1],s[i]);
	        for(j=0;j<i;j++)
	        {
	            if(!strcmp(s[i],s[j]))break;
	        }
	        if(j!=i)break;
	    }
	    if(i==1) printf(" is self-inventorying \n");
	    else if(i==16) printf(" can not be classified after 15 iterations \n");
	    else if(i-j==1) printf(" is self-inventorying after %d steps \n",j);
	    else printf(" enters an inventory loop of length %d \n",i-j);
	}
	return 0;
}
