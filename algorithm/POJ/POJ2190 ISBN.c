#include<stdio.h>

int main(int argc, char* argv[])
{
	int i,j,s,k;
	char c;
	for(i=10,s=0;i>0;i--)
	{
	    scanf("%c",&c);
	    if(c>='0'&&c<='9') s+=i*(c-48);
	    else if(c=='?') j=i;
	    else if(c=='X') s+=10;
	    else i++;
	}
	if(j==1&&(s+10)%11==0) printf("X\n");
	else
	{
        k=-1;
	    for(i=0;i<10;i++)
        {
            if((s+j*i)%11==0)
            {
                k=i;
            }
        }
        printf("%d\n",k);
	}
	return 0;
}
