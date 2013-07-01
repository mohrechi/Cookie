#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string input;
    char output[100];
    int k1,k2,k3;
    vector<int>v1,v2,v3;
    while(cin>>k1>>k2>>k3,k1||k2||k3)
    {
        v1.clear(), v2.clear(), v3.clear();
        cin>>input;
        for(int i=0;i<input.length();i++)
        {
            if(input[i]>='a' && input[i]<='i')
            {
                v1.push_back(i);
            }
            else if(input[i]>='j' && input[i]<='r')
            {
                v2.push_back(i);
            }
            else
            {
                v3.push_back(i);
            }
        }
        for(int i=0;i<v1.size();i++)
        {
            output[v1[(i+k1)%v1.size()]]=input[v1[i]];
        }
        for(int i=0;i<v2.size();i++)
        {
            output[v2[(i+k2)%v2.size()]]=input[v2[i]];
        }
        for(int i=0;i<v3.size();i++)
        {
            output[v3[(i+k3)%v3.size()]]=input[v3[i]];
        }
        output[input.length()]=0;
        cout<<output<<endl;
    }
    return 0;
}
