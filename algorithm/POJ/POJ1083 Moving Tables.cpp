#include<iostream>
using namespace std;

int main()
{
    int room[300],m,n;
    for(cin>>m;m--;)
    {
        cin>>n;
        int max=0;
        for(int i=0;i<300;i++)
        {
            room[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            int s,e;
            cin>>s>>e;
            if(s>e)
            {
                s^=e,e^=s,s^=e;
            }
            s=(s-1)/2+1;
            e=(e-1)/2+1;
            for(int j=s;j<=e;j++)
            {
                room[j]++;
                if(room[j]>max)
                {
                    max=room[j];
                }
            }
        }
        cout<<max*10<<endl;
    }
    return 0;
}
