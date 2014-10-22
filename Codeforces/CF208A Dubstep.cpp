#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[205];

int main()
{
    while(~scanf("%s", s))
    {
        int i;
        for(i=0;s[i];++i)
        {
            if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
            {
                i += 2;
            }
            else
            {
                break;
            }
        }
        bool preWub = false;
        for(;s[i];++i)
        {
            if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
            {
                preWub = true;
                i += 2;
            }
            else
            {
                if(preWub)
                {
                    putchar(' ');
                    preWub = false;
                }
                putchar(s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
