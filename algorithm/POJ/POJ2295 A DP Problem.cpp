#include <cstdio>
#include <cmath>

int leftNumber, leftX;
int rightNumber, rightX;
bool positive;
char equation[300];

int main()
{
    int i, t, temp;
    scanf("%d", &t);
    while(t--)
    {
        leftNumber = rightNumber = 0;
        leftX = rightX = 0;
        positive = true;
        temp = 0;
        scanf("%s", equation);
        for(i=0;equation[i]!='=';++i)
        {
            switch(equation[i])
            {
            case '+':
                if(positive) leftNumber += temp;
                else leftNumber -= temp;
                temp = 0;
                positive = true;
                break;
            case '-':
                if(positive) leftNumber += temp;
                else leftNumber -= temp;
                temp = 0;
                positive = false;
                break;
            case 'x':
                if(temp == 0) temp = 1;
                if(positive) leftX += temp;
                else leftX -= temp;
                temp = 0;
                break;
            default:
                temp = temp * 10 + equation[i] - '0';
                break;
            }
        }
        if(temp)
        {
            if(positive) leftNumber += temp;
            else leftNumber -= temp;
        }
        temp = 0;
        positive = true;
        for(++i;equation[i];++i)
        {
            switch(equation[i])
            {
            case '+':
                if(positive) rightNumber += temp;
                else rightNumber -= temp;
                temp = 0;
                positive = true;
                break;
            case '-':
                if(positive) rightNumber += temp;
                else rightNumber -= temp;
                temp = 0;
                positive = false;
                break;
            case 'x':
                if(temp == 0) temp = 1;
                if(positive) rightX += temp;
                else rightX -= temp;
                temp = 0;
                break;
            default:
                temp = temp * 10 + equation[i] - '0';
                break;
            }
        }
        if(temp)
        {
            if(positive) rightNumber += temp;
            else rightNumber -= temp;
        }
        if(leftX == rightX)
        {
            if(leftNumber == rightNumber)
            {
                printf("IDENTITY\n");
            }
            else
            {
                printf("IMPOSSIBLE\n");
            }
        }
        else
        {
            printf("%d\n", (int)floor((double)(rightNumber - leftNumber) / (leftX - rightX)));
        }
    }
    return 0;
}
