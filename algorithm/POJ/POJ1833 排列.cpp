#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,k,num[2000];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        for(int i=0;i<k;i++)
        {
            next_permutation(num,num+n);
        }
        copy(num,num+n-1,ostream_iterator<int>(cout," "));
        cout<<num[n-1]<<endl;
    }
    return 0;
}
