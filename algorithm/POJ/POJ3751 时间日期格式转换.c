#include<stdio.h>

int main(int argc, char* argv[])
{
	int t,y,m,d,h,mi,s,f=0;
	for(scanf("%d",&t);t--;f=0)
	{
	    scanf("%d/%d/%d-%d:%d:%d",&y,&m,&d,&h,&mi,&s);
	    if(m>9) printf("%d/",m);
	    else printf("0%d/",m);
	    if(d>9) printf("%d/",d);
	    else printf("0%d/",d);
	    printf("%d-",y);
	    if(h>=12)f=1;
	    if(h==24) f=0;
	    if(h>12)h-=12;
	    if(h==0)h=12;
	    if(h>9) printf("%d:",h);
	    else printf("0%d:",h);
	    if(mi>9) printf("%d:",mi);
	    else printf("0%d:",mi);
	    if(s>9) printf("%d",s);
	    else printf("0%d",s);
	    if(f) printf("pm\n");
	    else printf("am\n");
	}
	return 0;
}
