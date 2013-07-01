#include<cstdio>

int main(int argc, char *argv[])
{
    int playerNumber;
    double length;
    int hour, minute, second;
    int total, team;
    bool valid;
    scanf("%d%lf",&playerNumber,&length);
    while(~scanf("%d",&team))
    {
        char ch;
        valid = true;
        total = 0;
        for(int i=0;i<playerNumber;++i)
        {
            while(scanf("%c",&ch), ch==' ');
            if(ch=='-')
            {
                valid = false;
                scanf("%c%c%c%c%c%c",&ch,&ch,&ch,&ch,&ch,&ch);
            }
            else
            {
                hour = ch - '0';
                scanf(":%d:%d",&minute,&second);
                total += hour * 3600 + minute * 60 + second;
            }
        }
        printf("%3d: ",team);
        if(valid)
        {
            total = (int)(total / length + 0.5);
            printf("%d:",total/60);
            if(total%60<10)
            {
                printf("0");
            }
            printf("%d min/km\n",total%60);
        }
        else
        {
            printf("-\n");
        }
    }
    return 0;
}
