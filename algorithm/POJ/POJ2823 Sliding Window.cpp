#include<stdio.h>
#include<deque>
using namespace std;

struct Element
{
    int value, position;
}element[1000005];

int n,k;
deque<Element> getMax, getMin;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&element[i].value);
        element[i].position=i;
    }
    for(int i=0;i<n;i++)
    {
        while(!getMin.empty() && element[i].value<getMin.front().value)
        {
            getMin.pop_front();
        }
        getMin.push_front(element[i]);
        if(i-getMin.back().position>=k)
        {
            getMin.pop_back();
        }
        if(i>=k-1 && i<n-1) printf("%d ",getMin.back());
    }
    printf("%d\n",getMin.back());
    for(int i=0;i<n;i++)
    {
        while(!getMax.empty() && element[i].value>getMax.front().value)
        {
            getMax.pop_front();
        }
        getMax.push_front(element[i]);
        if(i-getMax.back().position>=k)
        {
            getMax.pop_back();
        }
        if(i>=k-1 && i<n-1) printf("%d ",getMax.back());
    }
    printf("%d\n",getMax.back());
    return 0;
}
