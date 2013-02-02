#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
char priority[255];

class Stack
{
public:
    Stack()
    {
        init();
    }
    inline void init()
    {
        n = 0;
    }
    inline long long  top()
    {
        return s[n - 1];
    }
    inline void push(long long  x)
    {
        s[n++] = x;
    }
    inline long long  pop()
    {
        return s[--n];
    }
    inline int num()
    {
        return n;
    }
private:
    int n;
    long long s[MAXN];
}stack1, stack2;

char s[MAXN];

void calc(int op)
{
    if(op == '*')
    {
        return;
    }
    long long  c;
    long long  b = stack2.pop();
    long long  a = stack2.pop();
    switch(op)
    {
    case '!':
        c = a + b + 5;
        break;
    case '@':
        c = a - b - 7;
        break;
    case '#':
        c = a * 3 + b * 2;
        break;
    case '$':
        c = (a >= 0 ? a : -a) % (b + 1);
        break;
    }
    stack2.push(c);
}

int main()
{
    priority['*'] = 0;
    priority['('] = 1;
    priority['!'] = 2;
    priority['@'] = 3;
    priority['#'] = 4;
    priority['$'] = 5;
    int k;
    scanf("%d", &k);
    while(k--)
    {
        scanf("%s", s);
        int len = strlen(s);
        s[len++] = '*';
        s[len] = 0;
        stack1.init();
        stack2.init();
        stack1.push('*');
        long long num = 0;
        bool isNum = false;
        for(int i=0;s[i];++i)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                if(isNum)
                {
                    num = num * 10 + s[i] - '0';
                }
                else
                {
                    isNum = true;
                    num = s[i] - '0';
                }
            }
            else
            {
                if(isNum)
                {
                    isNum = false;
                    stack2.push(num);
                }
                if(s[i] == '(')
                {
                    stack1.push(s[i]);
                }
                else if(s[i] == ')')
                {
                    while(true)
                    {
                        int op = stack1.pop();
                        if(op == '(')
                        {
                            break;
                        }
                        calc(op);
                    }
                }
                else
                {
                    if(priority[s[i]] > priority[stack1.top()])
                    {
                        stack1.push(s[i]);
                    }
                    else
                    {
                        while(stack1.num() > 0 && priority[s[i]] <= priority[stack1.top()])
                        {
                            int op = stack1.pop();
                            calc(op);
                        }
                        stack1.push(s[i]);
                    }
                }
            }
        }
        printf("%lld\n", stack2.top());
    }
    return 0;
}
