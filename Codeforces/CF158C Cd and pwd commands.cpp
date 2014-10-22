#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string str, temp;
    vector<string> stack;
    cin >> n;
    while(n--)
    {
        cin >> str;
        if(str == "cd")
        {
            cin >> str;
            int i = 0;
            if(str[0] == '/')
            {
                stack.clear();
                i = 1;
            }
            int last;
            for(last=i;i<str.length();++i)
            {
                if(str[i] == '/')
                {
                    temp = str.substr(last, i - last);
                    last = i + 1;
                    if(temp == "..")
                    {
                        stack.pop_back();
                    }
                    else
                    {
                        stack.push_back(temp);
                    }
                }
            }
            temp = str.substr(last, str.length() - last);
            if(temp == "..")
            {
                stack.pop_back();
            }
            else
            {
                stack.push_back(temp);
            }
        }
        else
        {
            cout << "/";
            for(vector<string>::iterator it=stack.begin();it!=stack.end();++it)
            {
                cout << *it << "/";
            }
            cout << endl;
        }
    }
    return 0;
}
