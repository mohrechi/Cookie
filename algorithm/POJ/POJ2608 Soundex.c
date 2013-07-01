#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int m,i;
	char c,s[25];
	while(gets(s))
	{
		int k=0;
		m=strlen(s);
		for(i=0;i<m;i++)
		{
			if(k!=1&&(s[i]=='B'||s[i]=='F'||s[i]=='P'||s[i]=='V'))
			{
				printf("1");
				k=1;
				continue;
			}
			if(k!=2&&(s[i]=='C'||s[i]=='G'||s[i]=='J'||s[i]=='K'||s[i]=='Q'||s[i]=='S'||s[i]=='X'||s[i]=='Z'))
			{
				printf("2");
				k=2;
				continue;
			}
			if(k!=3&&(s[i]=='D'||s[i]=='T'))
			{
				printf("3");
				k=3;
				continue;
			}
			if(k!=4&&s[i]=='L')
			{
				printf("4");
				k=4;
				continue;
			}
			if(k!=5&&(s[i]=='M'||s[i]=='N'))
			{
				printf("5");
				k=5;
				continue;
			}
			if(k!=6&&s[i]=='R')
			{
				printf("6");
				k=6;
				continue;
			}
			if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='H'||s[i]=='W'||s[i]=='Y') k=0;
		}
		printf("\n");
	}
	return 0;
}
