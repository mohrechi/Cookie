#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct LinkNode
{
    int n1, n2;
    int value;
}node[2000000];
int nodeNumber;
int L, R;
int fL, fR;
int end;

void test()
{
    printf("L: %d (%d) R: %d (%d)\n", L, fL, R, fR);
    for(int i=0;i<nodeNumber;++i)
    {
        printf("%d %d %d %d\n", i, node[i].value, node[i].n1, node[i].n2);
    }
}

void output()
{
    bool flag = true;
    int tL = node[0].n2;
    int tfL = 0;
    while(tL != end)
    {
        if(flag)
        {
            flag = false;
        }
        else
        {
            printf(" ");
        }
        printf("%d", node[tL].value);
        if(node[tL].n1 == tfL)
        {
            tfL = tL;
            tL = node[tL].n2;
        }
        else
        {
            tfL = tL;
            tL = node[tL].n1;
        }
    }
    printf("\n");
}

int main()
{
    int caseNumber, a;
    scanf("%d", &caseNumber);
    char s[100];
    while(caseNumber -- )
    {
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a);
            node[i].value = a;
            node[i].n1 = i - 1;
            node[i].n2 = i + 1;
        }
        node[0].n2 = 1;
        node[n+1].n1 = n;
        nodeNumber = n + 2;
        scanf("%d%d",&L,&R);
        fL = node[L].n1;
        fR = node[R].n2;
        end = n + 1;
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%s", s);
            switch(*s)
            {
                case 'M':
                    switch(s[4])
                    {
                        case 'L':
                            scanf("%s", s);
                            switch(*s)
                            {
                                case 'L':
                                    if(node[fL].n1 == L)
                                    {
                                        L = fL;
                                        fL = node[fL].n2;
                                    }
                                    else
                                    {
                                        L = fL;
                                        fL = node[fL].n1;
                                    }
                                    break;
                                case 'R':
                                    if(node[R].n1 == fR)
                                    {
                                        fR = R;
                                        R = node[R].n2;
                                    }
                                    else
                                    {
                                        fR = R;
                                        R = node[R].n1;
                                    }
                                    break;
                            }
                            break;
                        case 'R':
                            scanf("%s", s);
                            switch(*s)
                            {
                                case 'L':
                                    if(node[L].n1 == fL)
                                    {
                                        fL = L;
                                        L = node[L].n2;
                                    }
                                    else
                                    {
                                        fL = L;
                                        L = node[L].n1;
                                    }
                                    break;
                                case 'R':
                                    if(node[fR].n1 == R)
                                    {
                                        R = fR;
                                        fR = node[fR].n2;
                                    }
                                    else
                                    {
                                        R = fR;
                                        fR = node[fR].n1;
                                    }
                                    break;
                            }
                            break;
                    }
                    break;
                case 'I':
                    scanf("%s%d", s, &a);
                    int next;
                    if(*s == 'L')
                    {
                        node[nodeNumber].n1 = fL;
                        node[nodeNumber].n2 = L;
                        if(node[fL].n1 == L)
                        {
                            node[fL].n1 = nodeNumber;
                        }
                        else
                        {
                            node[fL].n2 = nodeNumber;
                        }
                        if(node[L].n1 == fL)
                        {
                            node[L].n1 = nodeNumber;
                        }
                        else
                        {
                            node[L].n2 = nodeNumber;
                        }
                        L = nodeNumber ++;
                        node[L].value = a;
                    }
                    else
                    {
                        node[nodeNumber].n1 = fR;
                        node[nodeNumber].n2 = R;
                        if(node[fR].n1 == R)
                        {
                            node[fR].n1 = nodeNumber;
                        }
                        else
                        {
                            node[fR].n2 = nodeNumber;
                        }
                        if(node[R].n1 == fR)
                        {
                            node[R].n1 = nodeNumber;
                        }
                        else
                        {
                            node[R].n2 = nodeNumber;
                        }
                        R = nodeNumber ++;
                        node[R].value = a;
                    }
                    break;
                case 'D':
                    scanf("%s", s);
                    if(*s == 'L')
                    {
                        if(node[L].n1 == fL)
                        {
                            next = node[L].n2;
                        }
                        else
                        {
                            next = node[L].n1;
                        }
                        if(node[fL].n1 == L)
                        {
                            node[fL].n1 = next;
                        }
                        else
                        {
                            node[fL].n2 = next;
                        }
                        if(node[next].n1 == L)
                        {
                            node[next].n1 = fL;
                        }
                        else
                        {
                            node[next].n2 = fL;
                        }
                        L = next;
                    }
                    else
                    {
                        if(node[R].n1 == fR)
                        {
                            next = node[R].n2;
                        }
                        else
                        {
                            next = node[R].n1;
                        }
                        if(node[fR].n1 == R)
                        {
                            node[fR].n1 = next;
                        }
                        else
                        {
                            node[fR].n2 = next;
                        }
                        if(node[next].n1 == R)
                        {
                            node[next].n1 = fR;
                        }
                        else
                        {
                            node[next].n2 = fR;
                        }
                        R = next;
                    }
                    break;
                case 'R':
                    if(node[R].n1 == fR)
                    {
                        node[R].n1 = fL;
                    }
                    else
                    {
                        node[R].n2 = fL;
                    }
                    if(node[L].n1 == fL)
                    {
                        node[L].n1 = fR;
                    }
                    else
                    {
                        node[L].n2 = fR;
                    }
                    if(node[fL].n1 == L)
                    {
                        node[fL].n1 = R;
                    }
                    else
                    {
                        node[fL].n2 = R;
                    }
                    if(node[fR].n1 == R)
                    {
                        node[fR].n1 = L;
                    }
                    else
                    {
                        node[fR].n2 = L;
                    }
                    L ^= R;
                    R ^= L;
                    L ^= R;
                    break;
            }
        }
        output();
    }
    return 0;
}
