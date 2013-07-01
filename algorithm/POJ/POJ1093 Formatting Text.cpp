#include<stdio.h>
//#define DEBUG
#ifdef DEBUG
const int MAXN = 10005;
const int MAXM = 85;
int rowLength, wordNumber;
char word[MAXN][MAXM];
int wordLength[MAXN];
char text[MAXN];
int currentMinimumBadness[MAXN];
int wordNumberOfCurrentLine[MAXN];
int possibility1[MAXN];
int possibility2[MAXN];

int square(int x)
{
    return x * x;
}

bool input()
{
    wordNumber = 0;
    scanf("%d",&rowLength);
    if(!rowLength)
    {
        return false;
    }
    while(true)
    {
        gets(text);
        if(!text[0])
        {
            break;
        }
        for(int i=0;text[i];++i)
        {
            int j;
            for(j=0;text[i] && text[i]!=' ';++i,++j)
            {
                word[wordNumber][j] = text[i];
            }
            word[wordNumber][j] = 0;
            wordLength[wordNumber++] = j;
            while(text[i] && text[i] == ' ')
            {
                ++i;
            }
            --i;
        }
    }
    return true;
}

int getMinimumBadness(int currentSpaceNumber, int currentWordNumber)
{
    int badness = 0;
    int averageSpace = currentSpaceNumber / currentWordNumber;
    int extraSpace = currentSpaceNumber % currentWordNumber;
    for(int i=0;i<currentWordNumber;++i)
    {
        if(i<=extraSpace)
        {
            badness += square(averageSpace);
        }
        else
        {
            badness += square(averageSpace - 1);
        }
    }
}

void formatting()
{
    currentMinimumBadness[0] = 500;
    wordNumberOfCurrentLine[0] = 1;
    for(int i=1;i<wordNumber;++i)
    {
        currentMinimumBadness[i] = currentMinimumBadness[i-1] + 500;
        wordNumberOfCurrentLine[i] = 1;
        int tempLength = wordLength[i];
        for(int j=0;j<i&&tempLength+wordLength[i-j]+j<rowLength;++j)
        {
            tempLength += wordLength[i-j];
            int tempMinimumBadness =  getMinimumBadness(rowLength - tempLength,j);
            if(currentMinimumBadness[i-j-1] + tempMinimumBadness < currentMinimumBadness[i])
            {
                wordNumberOfCurrentLine[i] = j + 1;
                currentMinimumBadness[i] = currentMinimumBadness[i-j-1] + tempMinimumBadness;
            }
            else if(currentMinimumBadness[i-j-1] + tempMinimumBadness == currentMinimumBadness[i])
            {
                int tempWordNumber1 = 1;
                int tempWordNumber2 = 1;
                int currentPosition = i;
                while(currentPosition>=0)
                {
                    possibility1[tempWordNumber1++] = wordNumberOfCurrentLine[currentPosition];
                    currentPosition -= wordNumberOfCurrentLine[currentPosition];
                }
                currentPosition = i;
                wordNumberOfCurrentLine[i] = j + 1;
                while(currentPosition>=0)
                {
                    possibility2[tempWordNumber2++] = wordNumberOfCurrentLine[currentPosition];
                    currentPosition -= wordNumberOfCurrentLine[currentPosition];
                }
                --tempWordNumber1, --tempWordNumber2;
                while(tempWordNumber1>=0 && tempWordNumber2>=0 && possibility1[tempWordNumber1] == possibility2[tempWordNumber2])
                {
                    --tempWordNumber1;
                    --tempWordNumber2;
                }
                if(tempWordNumber1>=0 && tempWordNumber2>=0 && possibility1[tempWordNumber1] < possibility2[tempWordNumber2])
                {
                    currentMinimumBadness[i] = currentMinimumBadness[i-j-1] + tempMinimumBadness;
                }
                else
                {
                    wordNumberOfCurrentLine[i] = tempWordNumber1;
                }
            }
        }
    }
}

void output()
{
    int tempWordNumber = wordNumber - 1;
    int index = 0;
    while(tempWordNumber>=0)
    {
        possibility1[index++] = wordNumberOfCurrentLine[tempWordNumber];
        tempWordNumber -= wordNumberOfCurrentLine[tempWordNumber];
    }
    int wordIndex = 0;
    for(int i=index-1;i>=0;--i)
    {
        int tempLength = 0;
        for(int j=0;j<possibility1[i];++j)
        {
            tempLength += wordLength[wordIndex++];
        }
        int averageSpaceNumber;
        int extraSpaceNumber;
        if(possibility1[i] > 1)
        {
            averageSpaceNumber = (rowLength - tempLength) / (possibility1[i] - 1);
            extraSpaceNumber = (rowLength - tempLength) / (possibility1[i] - 1);
        }
        for(int j=0;j<possibility1[i]-1;++j)
        {
            printf("%s",word[wordIndex - possibility1[i] + j - 1]);
            for(int k=0;k<averageSpaceNumber;++k)
            {
                printf(" ");
            }
            if(j + extraSpaceNumber >= possibility1[i])
            {
                printf(" ");
            }
        }
        printf("%s\n",word[wordIndex - 1]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    while(input())
    {
        formatting();
        //output();
    }
    return 0;
}
#endif
int n;int ct;char word[10004][84];int len[10004];int num[10004];int dp[10004];int lu1[10004];int lu2[10004];void Input(){int i=0,j;char temp[10010];ct=1;while(1){gets(temp);if(temp[0]==0)break;i=0;while(temp[i]){for(j=0;temp[i]&&temp[i]!=' ';j++,i++)word[ct][j]=temp[i];word[ct][j]='\0';len[ct]=j;ct++;while(temp[i]&&temp[i]==' ')i++;}}ct--;}int Best(int space,int x){int a=space/x,b=space%x;int i=1;int ans=0;while(i<=x){if(i<=b)ans+=a*a;else ans+=(a-1)*(a-1);i++;}return ans;}void Dp(){int i;num[1]=1;dp[0]=0;dp[1]=0;dp[1]=500;for(i=2;i<=ct;i++){dp[i]=dp[i-1];dp[i]+=500;num[i]=1;int l=len[i];int k;for(k=1;k<i&&l+len[i-k]+k<=n;k++){l+=len[i-k];if(dp[i-k-1]+Best(n-l,k)<dp[i]){num[i]=k+1;dp[i]=dp[i-k-1]+Best(n-l,k);}else if(dp[i-k-1]+Best(n-l,k)==dp[i]){int k1,k2,temp=i,temp1=num[i];k1=k2=1;while(temp>0){lu1[k1++]=num[temp];temp-=num[temp];}temp=i;num[i]=k+1;while(temp>0){lu2[k2++]=num[temp];temp-=num[temp];}k1--;k2--;while(k1>=1&&k2>=1&&lu1[k1]==lu2[k2]){k1--;k2--;}if(k1>=1&&k2>=1&&lu1[k1]<lu2[k2])dp[i]=dp[i-k-1]+Best(n-l,k);else num[i]=temp1;}}}}void GetAns(){int i=ct,k=1,j,a,b,l;while(i>0){lu1[k++]=num[i];i-=num[i];}k--;int index=1;for(i=k;i>=1;i--){int len_temp=0;for(j=1;j<=lu1[i];j++)len_temp+=len[index++];if(lu1[i]>1){a=(n-len_temp)/(lu1[i]-1);b=(n-len_temp)%(lu1[i]-1);}for(j=1;j<lu1[i];j++){printf("%s",word[index-lu1[i]+j-1]);for(l=1;l<=a;l++)printf(" ");if(j+b>=lu1[i])printf(" ");}printf("%s\n",word[index-1]);}printf("\n");}int main(void){while(scanf("%d\n",&n),n){Input();Dp();GetAns();}return 0;}
