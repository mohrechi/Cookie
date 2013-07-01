#include<stdio.h>

int main(int argc, char* argv[])
{
	int y,m,d,w,r;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	char c[7][10]={"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
	for(;;)
	{
	    scanf("%d",&d);
	    if(!++d) break;
	    y=2000,w=d%7;
	    if(d>366) for(r=1;d>365+r;r=!(y%400)||(!(y%4)&&y%100?1:0))d-=365+r,y++;
	    for(m=0;m<12;m++)
	    {
	        if(r)if(d>b[m]) d-=b[m]; else break;
	        else if(d>a[m]) d-=a[m]; else break;
	    }
	    printf("%d-",y);
	    if(++m>9) printf("%d-",m);
	    else printf("0%d-",m);
	    if(d>9) printf("%d %s\n",d,c[w]);
	    else printf("0%d %s\n",d,c[w]);
	}
	return 0;
}
