#include<iostream>
#include<cstring>
using namespace std;
char key[30];

int main()
{
    cin>>key;
    cin.ignore(100,'\n');
    char text[100];
    cin.getline(text,100);
    int i,j,len;
    len=strlen(text);
    for(i=0;i<len;i++)
    {
       if(text[i]!=' ')
       {
        if(text[i]>='A'&&text[i]<='Z')
         text[i]=key[text[i]-'A']-'a'+'A';
        else
         text[i]=key[text[i]-'a'];
       }
    }
    cout<<text<<endl;
}

