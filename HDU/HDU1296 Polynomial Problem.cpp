#include<stdio.h>
#include<math.h>
#include<string>
#include<iostream>
using namespace std;

bool isDigit(char ch)
{
    return ch>='0' && ch<='9';
}

int main()
{
    int x;
    string s;
    while(scanf("%d",&x)!=EOF)
    {
        cin>>s;
        int a=0,ans=0;
        bool positive=true,meetX=false,meetA=false;
        for(int i=0;i<s.length();i++)
        {
            if(isDigit(s[i]))
            {
                if(a==-1) a=s[i]-'0';
                else a=a*10+s[i]-'0';
                meetX=false;
                meetA=true;
            }
            else if(s[i]=='+')
            {
                if(!meetX && meetA)
                {
                    if(positive) ans+=a;
                    else ans-=a;
                    a=0;
                    meetA=false;
                }
                positive=true;
            }
            else if(s[i]=='-')
            {
                if(!meetX && meetA)
                {
                    if(positive) ans+=a;
                    else ans-=a;
                    a=0;
                    meetA=false;
                }
                positive=false;
            }
            else if(s[i]=='X' || s[i]=='x')
            {
                meetX=true;
                if(!meetA) a=1;
                meetA=false;
                if(i<s.length()-1)
                {
                    if(s[i+1]=='^')
                    {
                        if(s[i+2]=='1')
                        {
                            if(positive) ans+=a*pow(x,10);
                            else ans-=a*pow(x,10);
                            i+=3;
                        }
                        else
                        {
                            if(positive) ans+=a*pow(x, s[i+2]-'0');
                            else ans-=a*pow(x, s[i+2]-'0');
                            i+=2;
                        }
                    }
                    else
                    {
                        if(positive) ans+=a*x;
                        else ans-=a*x;
                    }
                }
                else
                {
                    if(positive) ans+=a*x;
                    else ans-=a*x;
                }
                a=0;
            }
        }
        if(meetA)
        {
            if(positive) ans+=a;
            else ans-=a;
        }
        printf("%d\n",ans);
    }
    return 0;
}
