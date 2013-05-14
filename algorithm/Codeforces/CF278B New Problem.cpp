#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string nextString(string str)
{
    bool flag = true;
    for(int i = 0; i < str.length(); ++ i)
    {
        if(str[i] != 'z')
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        for(int i = 0; i < str.length(); ++ i)
        {
            str[i] = 'a';
        }
        str += "a";
    }
    else
    {
        for(int i = str.length() - 1; i >= 0; -- i)
        {
            if(str[i] == 'z')
            {
                str[i] = 'a';
            }
            else
            {
                ++ str[i];
                break;
            }
        }
    }
    return str;
}

int main()
{
    int n;
    while(cin >> n)
    {
        string temp;
        set<string> strs;
        for(int i = 0; i < n; ++ i)
        {
            cin >> temp;
            for(int j = 0; j < temp.length(); ++ j)
            {
                for(int k = 1; j + k <= temp.length(); ++ k)
                {
                    strs.insert(temp.substr(j, k));
                }
            }
        }
        string ans = "a";
        while(true)
        {
            if(strs.find(ans) == strs.end())
            {
                break;
            }
            ans = nextString(ans);
        }
        cout << ans << endl;
    }
    return 0;
}
