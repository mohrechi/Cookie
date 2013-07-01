#include<iostream>
using namespace std;
typedef struct p
{
    int weight;
    int speed;
    int num;
    int pre;
}Mouse;
void sort(Mouse m[],int n)
{
    int i,j,k;
    Mouse temp;
    for(i=1;i<=n;i++)
    {
        k=i;
        for(j=i+1;j<=n;j++)
        {
            if(m[j].weight<m[k].weight)
                k=j;
            else if(m[j].weight==m[k].weight&&m[j].speed>m[k].speed)
                k=j;
        }
        if(k!=i)
        {
            temp=m[k];
            m[k]=m[i];
            m[i]=temp;
        }
    }
}
int main()
{
    int i=1,j,n=1,data[1001],a,b;
    int f[1001];
    Mouse m[1001];
    while(cin>>a>>b)
    {
        m[n].num = n;
        m[n].weight = a;
        m[n].speed = b;
        n++;
    }
    sort(m,n-1);
    f[1]=1; a=1; b=1; m[1].pre=1;
    for(i = 2; i < n; i++)
    {
        f[i]=1; m[i].pre=i;
        for(j=1; j<i;j++)
            if(m[i].weight>m[j].weight&&m[i].speed<m[j].speed&&f[j] + 1 >f[i])
            {
                f[i]=f[j]+1;
                m[i].pre=j;
            }
            if(f[i]>a)
            {
                a=f[i];
                b=i;
            }
    }
    cout<<a<<endl;
    i=0;
    while(f[b]+1)
    {
        data[i]=m[b].num;
        b=m[b].pre;
        i++;
        f[b]--;
    }
    for(i=a-1;i>=0;i--)
        cout<<data[i]<<endl;
    return 0;
}
