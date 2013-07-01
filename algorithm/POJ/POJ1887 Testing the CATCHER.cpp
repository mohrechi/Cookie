#include <cstdio>
static const int MAXN = 40000;
int stack[MAXN], top = 0;

int main(int argc, char *argv[])
{
    int temp, caseNumber = 0;
    while(scanf("%d",&temp), temp+1)
    {
        stack[0] = temp;
        top = 1;
        while(scanf("%d",&temp), temp+1)
        {
            if(temp < stack[top-1])
            {
                stack[top++] = temp;
            }
            else
            {
                int left = 0, right = top - 1;
                int mid;
                while(left <= right)
                {
                    mid = (left + right) >> 1;
                    if(stack[mid] < temp)
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
                stack[left] = temp;
            }
        }
        if(caseNumber)
        {
            printf("\n");
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n",++caseNumber,top);
    }
    return 0;
}
