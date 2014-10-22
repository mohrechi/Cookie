#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void)
{
    map<string, string> maps;
    map<string, string>::iterator iter;
    char s1[20],s2[20];
    string s3,s4;
    int l;
    while(gets(s1))
    {
        int i;
        if(!*s1) break;
        l=strlen(s1);
        for(i=0;i<l;i++)
        {
            if(s1[i]==' ') break;
        }
        s1[i++]=0;
        for(int j=0;i<=l;i++)
        {
            s2[j++]=s1[i];
        }
        s3=s1,s4=s2;
        maps.insert(map<string, string>::value_type(s4,s3));
    }
    while(scanf("%s",s1)!=EOF)
    {
        s3=s1;
        iter=maps.find(s3);
        if(iter!=maps.end())cout<<iter->second<<endl;
        else cout<<"eh"<<endl;
    }
    return 0;
}
