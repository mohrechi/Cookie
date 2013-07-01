#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Directory
{
    string name;
    vector<Directory> directory;
    vector<string> file;
};

void input(Directory &directory, string &str)
{
    if(str.at(0) == '*' || str.at(0) == ']')
    {
        return;
    }
    if(str.at(0) == 'f')
    {
        directory.file.push_back(str);
    }
    else
    {
        Directory subDirectory;
        subDirectory.name = str;
        cin>>str;
        input(subDirectory, str);
        directory.directory.push_back(subDirectory);
    }
    cin>>str;
    input(directory, str);
}

void output(Directory &directory, int space)
{
    for(int i=0;i<space;++i)
    {
        cout<<"|     ";
    }
    cout<<directory.name<<endl;
    for(int i=0;i<directory.directory.size();++i)
    {
        output(directory.directory[i], space+1);
    }
    sort(directory.file.begin(), directory.file.end());
    for(int i=0;i<directory.file.size();++i)
    {
        for(int j=0;j<space;++j)
        {
            cout<<"|     ";
        }
        cout<<directory.file[i]<<endl;
    }
}

int main(int argc,char *argv[])
{
    int dataSetNumber = 0;
    string temp;
    while(true)
    {
        Directory root;
        root.name = "ROOT";
        cin>>temp;
        if(temp.at(0) == '#')
        {
            break;
        }
        input(root, temp);
        cout<<"DATA SET "<<++dataSetNumber<<":"<<endl;
        output(root, 0);
        cout<<endl;
    }
    return 0;
}
