#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	char s[80];
	int c,i,j,k,l;
	while(scanf("%s",s),s[0]!='*')
	{
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			for(j=i+1,k=0,c=0;j<l;j++,k++)
			{
				if(s[j]==s[k])c++;
				if(c>=2)break;
			}
			if(c>=2)break;
		}
		if(c>=2)printf("%s is NOT surprising.\n",s);
		else printf("%s is surprising.\n",s);
	}
	return 0;
}
