#include<iostream>
#include<cmath>
using namespace std;
struct coordinate
{
	int x,y;
}p[1001];
struct interval
{
	double a;
	double b;
}b[1001];
int cmp_interval(const void *a,const void *b)
{
	interval *A = (interval*) a;
	interval *B = (interval*) b;
	return (*A).b > (*B).b ? 1: -1;
}
double search(coordinate a,int d)
{
	double x;
	x = sqrt((double)(d*d - a.y*a.y)) + a.x;
	return x;
}
int main()
{
	int n,d,c = 0,r;
	bool impossible;
	while(cin >> n >> d)
	{
		if(n == 0)break;
		++c;
		impossible = 0;
		r = 1;
		for(int i = 0;i < n;++i)
		{
			cin >> p[i].x >> p[i].y;
			if(abs(p[i].y) > d)
				impossible = 1;
			b[i].a = 2*p[i].x - search(p[i],d);
			b[i].b = search(p[i],d);
		}
		qsort(b,n,sizeof(b[0]),cmp_interval);
		if(impossible)
			cout <<"Case "<< c <<": " << -1 <<endl;
		else
		{
			int temp = 0;
			for(int i = 0;i < n;++i)
			{
				if(b[i].a > b[temp].b)
				{
					++r;
					temp = i;
				}
			}
			cout <<"Case "<< c <<": " << r << endl;
		}
	}
	return 0;
}
