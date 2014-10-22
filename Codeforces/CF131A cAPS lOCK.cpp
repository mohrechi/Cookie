#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[105];

inline bool isLower(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

int main()
{
    while(~scanf("%s", s))
    {
        int num = 0;
        for(int i=0;s[i];++i)
        {
            if(isLower(s[i]))
            {
                ++ num;
            }
        }
        if(num == 0 || (num == 1 && isLower(s[0])))
        {
            for(int i=0;s[i];++i)
            {
                if(isLower(s[i]))
                {
                    s[i] = s[i] - 'a' + 'A';
                }
                else
                {
                    s[i] = s[i] - 'A' + 'a';
                }
            }
        }
        printf("%s\n", s);
    }
    return 0;
}
