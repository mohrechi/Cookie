#include <stdio.h>
//#define DEBUG

struct Square
{
    int transfer;
    bool miss;
    bool again;
}board[105], player[10];

int steps[1000];
int currentStep;
int playerNumber;
int currentPlayer;

inline void clearBoard()
{
    for(int i=0;i<=100;++i)
    {
        board[i].transfer = -1;
        board[i].miss = false;
        board[i].again = false;
    }
}

inline void summonPlayer()
{
    currentStep = 0;
    currentPlayer = 0;
    for(int i=1;i<=playerNumber;++i)
    {
        player[i].transfer = 0;
        player[i].miss = false;
        player[i].again = false;
    }
}

inline bool playLoop()
{
    if(player[currentPlayer].again)
    {
        player[currentPlayer].again = false;
    }
    else
    {
        ++currentPlayer;
        if(currentPlayer>playerNumber)
        {
            currentPlayer = 1;
        }
    }
    #ifdef DEBUG
        printf("Current Player: %d Miss %d Again %d\n",currentPlayer, player[currentPlayer].miss, player[currentPlayer].again);
    #endif
    if(player[currentPlayer].miss)
    {
        player[currentPlayer].miss = false;
    }
    else
    {
        int stepLength = steps[currentStep++];
        #ifdef DEBUG
            printf("\tCurrent Position: %d\n",player[currentPlayer].transfer);
            printf("\tCurrent Step: %d\n",stepLength);
        #endif
        if(player[currentPlayer].transfer + stepLength == 100)
        {
            return false;
        }
        else if(player[currentPlayer].transfer + stepLength < 100)
        {
            player[currentPlayer].transfer += stepLength;
            if(board[player[currentPlayer].transfer].transfer != -1)
            {
                player[currentPlayer].transfer = board[player[currentPlayer].transfer].transfer;
            }
            else if(board[player[currentPlayer].transfer].again)
            {
                player[currentPlayer].again = true;
            }
            else if(board[player[currentPlayer].transfer].miss)
            {
                player[currentPlayer].miss = true;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    int index = 0;
    int temp,from,to;
    while(scanf("%d",&steps[index]),steps[index++]);
    while(scanf("%d",&playerNumber),playerNumber)
    {
        clearBoard();
        while(scanf("%d%d",&from,&to), from || to)
        {
            board[from].transfer = to;
        }
        while(scanf("%d",&temp),temp)
        {
            if(temp>0)
            {
                board[temp].again = true;
            }
            else
            {
                board[-temp].miss= true;
            }
        }
        summonPlayer();
        while(playLoop());
        printf("%d\n",currentPlayer);
    }
    return 0;
}
