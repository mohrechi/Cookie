#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,c,i,s;
	char a[300],b[100];
	for(;;)
	{
	    scanf("%d",&n);
	    if(!n)break;
	    for(i=1;i<100;i++) b[i]=0;
	    scanf("%s",a);
	    for(i=0,c=0,s=0;a[i];i++)
	    {
	        if(b[a[i]]==1)
	        {
	            b[a[i]]=0;
	            s--;
	        }
	        else if(b[a[i]]==0)
	        {
	            if(s==n)
	            {
	                c++;
	                b[a[i]]=-1;
	            }
	            else
	            {
	                s++;
	                b[a[i]]=1;
	            }
	        }
	    }
	    if(c) printf("%d customer(s) walked away.\n",c);
	    else printf("All customers tanned successfully.\n");
	}
	return 0;
}
