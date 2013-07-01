#include<map>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    string s;
    int n=0;
    map<string,int> tree;
    while(getline(cin,s))
    {
        tree[s]++;
        n++;
    }
    map<string,int>::iterator iter;
    for(iter=tree.begin();iter!=tree.end();iter++)
    {
        cout<<iter->first;
        printf(" %.4f\n",iter->second*100.0/n);
    }
    return 0;
}
