#include<map>
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main(void)
{
    map<string, string> map1;
    map<string, int> map2;
    int m,n;
    string s1,s2;
    for(scanf("%d",&m),cin.ignore();m--;)
    {
        getline(cin,s1);
        getline(cin,s2);
        map1.insert(map<string, string>::value_type(s1,s2));
        map2.insert(map<string, int>::value_type(s1,0));
    }
    for(scanf("%d",&m),cin.ignore();m--;)
    {
        getline(cin,s1);
        map<string, int>::iterator iter;
        iter=map2.find(s1);
        if(iter!=map2.end())iter->second+=1;
    }
    int m1=0,m2=0;
    map<string, int>::iterator iter,iter2;
    for(iter=map2.begin();iter!=map2.end();iter++)
    {
        if(iter->second>=m1)
        {
            m2=m1,m1=iter->second;
            iter2=iter;
        }
    }
    if(m1==m2) cout<<"tie"<<endl;
    else
    {
        map<string, string>::iterator iter1;
        iter1=map1.find(iter2->first);
        cout<<iter1->second<<endl;
    }
    return 0;
}
