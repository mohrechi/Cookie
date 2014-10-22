#include<iostream>
#include<string.h>
#include<memory.h>
using namespace std;

int main()
{
    int max[225][225],m,n;
    char s1[225],s2[225];
    while(cin>>s1>>s2)
    {
        memset(max,0,sizeof(max));
        m=strlen(s1);
        n=strlen(s2);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    max[i][j]=max[i-1][j-1]+1;
                }
                else
                {
                    max[i][j]=max[i-1][j]>max[i][j-1]?max[i-1][j]:max[i][j-1];
                }
            }
        }
        cout<<max[m][n]<<endl;
    }
    return 0;
}
