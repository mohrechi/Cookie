#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100];
char divide[5];
bool head;
bool allzero;

inline void printSingle(char ch)
{
    putchar(ch - '0' + 'a');
}

inline void printFourUnit(int i)
{
    switch(i)
    {
        case 0:
            putchar('m');
            return;
        case 1:
            putchar('l');
            return;
        case 2:
            putchar('k');
            return;
    }
}

inline bool printFour(char four[5], bool zero, char unit)
{
    four[4] = 0;
    if(strcmp(four, "0000") == 0)
    {
        allzero = true;
        if(!zero)
        {
            zero = true;
        }
        if(unit == 'p')
        {
            if(head)
            {
                putchar('a');
            }
            putchar('p');
        }
        return zero;
    }
    for(int i=0;i<4;++i)
    {
        if(four[i] == '0')
        {
            zero = true;
        }
        else
        {
            if(zero)
            {
                if(!head)
                {
                    if(i || (i == 0 && allzero))
                    {
                        printf("a");
                    }
                }
            }
            head = false;
            zero = false;
            printSingle(four[i]);
            printFourUnit(i);
        }
    }
    putchar(unit);
    allzero = false;
    return zero;
}

int main()
{
    double x;
    while(~scanf("%lf", &x))
    {
        sprintf(s, "%.2lf", (floor(x * 100 + 0.5)) / 100.0);
        int dotPos;
        for(int i=0;s[i];++i)
        {
            if(s[i] == '.')
            {
                dotPos = i;
                break;
            }
        }
        bool zero = false;
        allzero = false;
        head = true;
        if(dotPos > 8)
        {
            int startPos = 0, endPos = dotPos - 8;
            int count = 3;
            memset(divide, '0', sizeof(divide));
            for(int i=endPos - 1;i >= startPos;--i)
            {
                divide[count -- ] = s[i];
            }
            zero = printFour(divide, zero, 'r');
        }
        if(dotPos > 4)
        {
            int startPos = max(0, dotPos - 8), endPos = dotPos - 4;
            int count = 3;
            memset(divide, '0', sizeof(divide));
            for(int i=endPos - 1;i >= startPos;--i)
            {
                divide[count -- ] = s[i];
            }
            zero = printFour(divide, zero, 'q');
        }
        int startPos = max(0, dotPos - 4), endPos = dotPos;
        int count = 3;
        memset(divide, '0', sizeof(divide));
        for(int i=endPos - 1;i >= startPos;--i)
        {
            divide[count -- ] = s[i];
        }
        zero = printFour(divide, zero, 'p');
        if(s[dotPos + 1] == '0' && s[dotPos + 2] == '0')
        {
            printf("z\n");
        }
        else
        {
            if(s[dotPos + 1] == '0')
            {
                putchar('a');
                printSingle(s[dotPos + 2]);
                putchar('o');
            }
            else
            {
                printSingle(s[dotPos + 1]);
                putchar('n');
                if(s[dotPos + 2] != '0')
                {
                    printSingle(s[dotPos + 2]);
                    putchar('o');
                }
            }
            printf("\n");
        }
    }
    return 0;
}
