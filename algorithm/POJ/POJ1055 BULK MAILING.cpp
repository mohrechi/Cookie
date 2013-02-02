#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define INPUT
//#define DATA
//#define METHOD1
//Method 1: Wrong Answer
#define METHOD2

#ifdef DATA
int main(int argc, char *argv[])
{
    freopen("out.txt","w",stdout);
    for(int i=10000;i<20000;i+=100)
    {
        for(int j=1;j<=i/100-100;++j)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
#endif

#ifdef METHOD1
struct Node
{
    int number;
    int times;
    int appear;
}five[100000], three[1000];

int compare(const void *a, const void *b)
{
    return (*(Node*)a).appear - (*(Node*)b).appear;
}

void initial()
{
    for(int i=0;i<100000;++i)
    {
        five[i].number = i;
        five[i].times = 0;
        five[i].appear = -1;
    }
    for(int i=0;i<1000;++i)
    {
        three[i].number = i;
        three[i].times = 0;
        three[i].appear = -1;
    }
}
#endif

int getZipNumber(char *zip)
{
    int result = 0;
    for(int i=0;i<5;++i)
    {
        result = result * 10 + zip[i] - '0';
    }
    return result;
}

#ifdef METHOD1
char invalidCode[10000][10];
int invalidNumber;
void printInvalidZipCode()
{
    printf("INVALID ZIP CODES\n\n");
    for(int i=0;i<invalidNumber;++i)
    {
        printf("%s\n",invalidCode[i]);
    }
}
int letterNumber;
int bundlesNumber;

void printValidFiveZip()
{
    int temp;
    int currentLetter;
    int currentBundle;
    for(int i=0;i<100000;++i)
    {
        if(five[i].times>=10)
        {
            if(five[i].times>=16 && five[i].times<=19)
            {
                currentLetter = 15;
                currentBundle = 1;
                five[i].times -= 15;
            }
            else
            {
                currentLetter = five[i].times;
                currentBundle = (currentLetter-1)/15 + 1;
                five[i].times = 0;
            }
            int j;
            temp = i;
            for(j=0;temp && j<5;++j)
            {
                temp /= 10;
            }
            for(;j<5;++j)
            {
                printf("0");
            }
            printf("%d%12d%12d\n",i,currentLetter,currentBundle);
            three[five[i].number/100].times -= currentLetter;
            bundlesNumber += currentBundle;
        }
    }
    printf("\n");
}

void printValidThreeZip()
{
    int start, end, temp;
    int currentLetter;
    int currentBundle;
    for(int i=0;i<1000;++i)
    {
        if(three[i].times>=10)
        {
            if(three[i].times >= 16 && three[i].times <= 19)
            {
                currentLetter = 15;
                currentBundle = 1;
            }
            else
            {
                currentLetter = three[i].times;
                currentBundle = (three[i].times - 1) / 15 + 1;
            }
            int j;
            temp = i;
            for(j=0;temp && j<3;++j)
            {
                temp /= 10;
            }
            for(;j<3;++j)
            {
                printf("0");
            }
            if(i!=0)
            {
                printf("%d",i);
            }
            printf("XX%12d%12d\n",currentLetter,currentBundle);
            bundlesNumber += currentBundle;
            start = i * 100;
            end = start + 100;
            for(j=start;currentLetter && j<end;++j)
            {
                if(five[j].times <= currentLetter)
                {
                    currentLetter -= five[j].times;
                    five[j].times = 0;
                }
                else
                {
                    five[j].times -= currentLetter;
                    currentLetter = 0;
                }
            }
        }
    }
    printf("\n");
}

void printValidUnpackedZip()
{
    int temp;
    for(int i=0;i<100000;++i)
    {
        if(five[i].times>0 && five[i].times<10)
        {
            int j;
            temp = i;
            for(j=0;temp && j<5;++j)
            {
                temp /= 10;
            }
            for(;j<5;++j)
            {
                printf("0");
            }
            printf("%d%12d%12d\n",five[i].number,five[i].times,0);
        }
    }
    printf("\n");
}

void output()
{
    printf("ZIP         LETTERS     BUNDLES\n\n");
    printValidFiveZip();
    printValidThreeZip();
    printValidUnpackedZip();
    printf("TOTALS%11d%12d\n\n",letterNumber,bundlesNumber);
    printInvalidZipCode();
}
#endif

bool validJudge(char *zip)
{
    int counter = 0;
    if(zip[5]!=0)
    {
        return false;
    }
    for(int i=0;i<5;++i)
    {
        if(zip[i] < '0' || zip[i] > '9')
        {
            return false;
        }
        if(zip[i] == '0')
        {
            ++counter;
        }
    }
    return counter != 5;
}

#ifdef METHOD1
void input()
{
    char temp[10];
    int tempNumber;
    while(~scanf("%s",temp))
    {
        if(validJudge(temp))
        {
            tempNumber = getZipNumber(temp);
            if(five[tempNumber].appear == -1)
            {
                five[tempNumber].appear = letterNumber;
            }
            ++ five[tempNumber].times;
            tempNumber /= 100;
            if(three[tempNumber].appear == -1)
            {
                three[tempNumber].appear = letterNumber;
            }
            ++ three[tempNumber].times;
            ++ letterNumber;
        }
        else
        {
            int i;
            for(i=0;i<invalidNumber;++i)
            {
                if(strcmp(invalidCode[i],temp) == 0)
                {
                    break;
                }
            }
            if(i==invalidNumber)
            {
                strcpy(invalidCode[invalidNumber],temp);
                ++invalidNumber;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    #ifdef INPUT
        freopen("in.txt","r",stdin);
    #endif
    initial();
    input();
    output();
    return 0;
}
#endif

#ifdef METHOD2

char invalidCode[6][10];
int invalidNumber;
int letterNumber;
int bundlesNumber;
int fiveCode[100000];
int threeCode[1000];

void input()
{
    char temp[6];
    int tempNumber;
    while(~scanf("%s",temp))
    {
        if(validJudge(temp))
        {
            tempNumber = getZipNumber(temp);
            ++fiveCode[tempNumber];
            ++ letterNumber;
        }
        else
        {
            int i;
            for(i=0;i<invalidNumber;++i)
            {
                if(strcmp(invalidCode[i],temp) == 0)
                {
                    break;
                }
            }
            if(i==invalidNumber)
            {
                strcpy(invalidCode[invalidNumber],temp);
                ++invalidNumber;
            }
        }
    }
}

void printValidFiveZip()
{
    int currentBundles;
    for(int i=0;i<100000;++i)
    {
        if(fiveCode[i]>=10)
        {
            currentBundles = (fiveCode[i] - 1) / 15 + 1;
            bundlesNumber += currentBundles;
            printf("%d%12d%12d\n",i,fiveCode[i],currentBundles);
            fiveCode[i] = 0;
        }
        else
        {
            threeCode[i/100] += fiveCode[i];
        }
    }
    printf("\n");
}

void printValidThreeZip()
{
    int currentBundles;
    for(int i=0;i<1000;++i)
    {
        if(threeCode[i]>=10)
        {
            currentBundles = (threeCode[i] - 1) / 15 + 1;
            bundlesNumber += currentBundles;
            printf("%dxx%12d%12d\n",i,threeCode[i],currentBundles);
            int start = i * 100;
            int end = start + 100;
            for(int j=start;j<end;++j)
            {
                fiveCode[j] = 0;
            }
        }
    }
    printf("\n");
}

void printValidUnpackedZip()
{
    for(int i=0;i<100000;++i)
    {
        if(fiveCode[i] > 0)
        {
            printf("%d%12d%12d\n",i,fiveCode[i],0);
        }
    }
    printf("\n");
}

void printInvalidZipCode()
{
    printf("INVALID ZIP CODES\n\n");
    for(int i=0;i<invalidNumber;++i)
    {
        printf("%s\n",invalidCode[i]);
    }
}

void print()
{
    printf("ZIP         LETTERS     BUNDLES\n\n");
    printValidFiveZip();
    printValidThreeZip();
    printValidUnpackedZip();
    printf("TOTALS%11d%12d\n\n",letterNumber,bundlesNumber);
    printInvalidZipCode();
}

int main(int argc, char* argv[])
{
    input();
    print();
    return 0;
}
#endif
