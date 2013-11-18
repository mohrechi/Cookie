#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    string s;
    cin >> T;
    while (T--)
    {
        int num = 1;
        cin >> s;
        cout << s << endl;
        while (num)
        {
            cin >> s;
            if (s[0] == '<' && s[1] == '/')
            {
                --num;
            }
            for (int i = 0; i < num; ++i)
            {
                putchar('\t');
            }
            cout << s << endl;
            if (s[0] == '<' && s[1] != '/')
            {
                ++num;
            }
        }
    }
    return 0;
}
