#include<iostream>
using namespace std;

int main(void)
{
    int edge, vertex, graph[30][30];
    char s[5];
    while(cin>>vertex>>edge, edge and vertex)
    {
        int flag=0;
        bool output=false;
        for(int i=0;i<=vertex;i++)
        {
            for(int j=0;j<=vertex;j++)
            {
                graph[i][j]=0;
            }
        }
        for(int l=1;l<=edge;l++)
        {
            cin>>s;
            graph[s[0]-'A'+1][s[2]-'A'+1]=1;
            for(int i=1;i<=vertex;i++)
            {
                for(int j=1;j<=vertex;j++)
                {
                    for(int k=1;k<=vertex;k++)
                    {
                        if(graph[i][j] and graph[j][k])
                        {
                            graph[i][k]=1;
                        }
                    }
                }
            }
            for(int i=1;i<=vertex;i++)
            {
                if(graph[i][i])
                {
                    flag=l;
                }
            }
            if(flag)
            {
                if(not output)
                {
                    cout<<"Inconsistency found after "<<flag<<" relations."<<endl;
                    output=true;
                }
            }
            else
            {
                int out[30]={0}, in[30]={0};
                for(int i=1;i<=vertex;i++)
                {
                    for(int j=1;j<=vertex;j++)
                    {
                        if(graph[i][j])
                        {
                            out[i]++, in[j]++;
                        }
                    }
                }
                if(not output)
                {
                    int i;
                    for(i=1;i<=vertex;i++)
                    {
                        if(out[i]+in[i]!=vertex-1)
                        {
                            break;
                        }
                    }
                    if(i<=vertex)
                    {
                        if(l==edge)
                        {
                            cout<<"Sorted sequence cannot be determined."<<endl;
                            output=true;
                        }
                    }
                    else
                    {
                        cout<<"Sorted sequence determined after "<<l<<" relations: ";
                        for(i=1;i<=vertex;i++)
                        {
                            for(int j=1;j<=vertex;j++)
                            {
                                if(0==in[j])
                                {
                                    for(int k=1;k<=vertex;k++)
                                    {
                                        if(graph[j][k])
                                        {
                                            in[k]--;
                                        }
                                    }
                                    char ch=j+'A'-1;
                                    cout<<ch;
                                    in[j]=2100000000;
                                    break;
                                }
                            }
                        }
                        cout<<"."<<endl;
                        output=true;
                    }
                }
            }
        }
    }
    return 0;
}
