#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int i,j,s,c=1,m;
	double t,a[5843]={0,1,2,3};
	for(j=4;j<5843;j++)
	{
	    for(i=j-1;a[i]*2>a[j-1]&&i>0;i--);
	    m=a[i+1]*2;
	    for(i=j-1;a[i]*3>a[j-1]&&i>0;i--);
	    if(a[i+1]*3<m) m=a[i+1]*3;
	    for(i=j-1;a[i]*5>a[j-1]&&i>0;i--);
	    if(a[i+1]*5<m) m=a[i+1]*5;
	    for(i=j-1;a[i]*7>a[j-1]&&i>0;i--);
	    if(a[i+1]*7<m) m=a[i+1]*7;
	    a[j]=m;
	}
	for(;;)
	{
	    scanf("%d",&i);
	    if(!i) break;
	    printf("The %d",i);
	    j=i%100,*a=j%10;
	    if(j==11||j==12||j==13) printf("th");
	    else if(*a==1) printf("st");
	    else if(*a==2) printf("nd");
	    else if(*a==3) printf("rd");
	    else printf("th");
	    printf(" humble number is %.0f.\n",a[i]);
	}
	return 0;
}
