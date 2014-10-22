#include<stdio.h>
#include<memory.h>
//#define DEBUG
#ifdef DEBUG
#include<windows.h>
#endif
inline int abs(int x)
{
    if(x<0)
    {
        return -x;
    }
    return x;
}

inline int getLengthI4(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

class Point
{
    public:
        Point()
        {
            this->setX(0);
            this->setY(0);
        }
        Point(int x, int y)
        {
            this->setX(x);
            this->setY(y);
        }
        inline void input()
        {
            scanf("%d%d",&this->x,&this->y);
        }
        inline void setPoint(int x, int y)
        {
            this->setX(x);
            this->setY(y);
        }
        inline void setPoint(Point &point)
        {
            this->setX(point.getX());
            this->setY(point.getY());
        }
        inline int getX() const
        {
            return this->x;
        }
        inline int getY() const
        {
            return this->y;
        }
        inline void setX(int x)
        {
            this->x = x;
        }
        inline void setY(int y)
        {
            this->y = y;
        }
    private:
        int x;
        int y;
};

int directionX[9] = {-1,-1,-1,0,0,0,1,1,1};
int directionY[9] = {-1,0,1,-1,0,1,-1,0,1};

class Board
{
    public:
        enum Status
        {
            Empty, Enemy, Player, Debris
        };
        Board()
        {
            this->clearBoard();
        }
        inline void clearBoard()
        {
            memset(board,Empty,sizeof(board));
            memset(teleportUsed,false,sizeof(teleportUsed));
            board[15][15] = Player;
            playerPosition.setPoint(15,15);
            teleportNumber = 0;
        }
        inline void addEnemy(int x, int y)
        {
            board[x][y] = Enemy;
        }
        inline void addTeleport(Point &point)
        {
            teleport[teleportNumber++].setPoint(point.getX(), point.getY());
        }
        inline bool robotsMove()
        {
            int minLength, pointer;
            int tempX, tempY, tempLength;
            bool flag = false;
            for(int i=1;i<=31;++i)
            {
                for(int j=1;j<=31;++j)
                {
                    if(board[i][j] == Enemy)
                    {
                        tempBoard[i][j] = Empty;
                    }
                    else
                    {
                        tempBoard[i][j] = board[i][j];
                    }
                }
            }
            for(int i=1;i<=31;++i)
            {
                for(int j=1;j<=31;++j)
                {
                    if(board[i][j] == Enemy)
                    {
                        minLength = 19627;
                        for(int k=0;k<9;++k)
                        {
                            tempX = i + directionX[k];
                            tempY = j + directionY[k];
                            if(inBoard(tempX, tempY))
                            {
                                tempLength = getLengthI4(tempX, tempY, playerPosition.getX(), playerPosition.getY());
                                if(tempLength < minLength)
                                {
                                    minLength = tempLength;
                                    pointer = k;
                                }
                            }
                        }
                        tempX = i + directionX[pointer];
                        tempY = j + directionY[pointer];
                        switch(tempBoard[tempX][tempY])
                        {
                            case Empty:
                                tempBoard[tempX][tempY] = Enemy;
                                break;
                            case Enemy:
                            case Debris:
                                tempBoard[tempX][tempY] = Debris;
                                break;
                            case Player:
                                flag = true;
                                tempBoard[tempX][tempY] = Enemy;
                                break;
                        }
                    }
                }
            }
            memcpy(board,tempBoard,sizeof(board));
            return flag;
        }
        inline bool findEnemy(int x, int y)
        {
            for(int i=x-1;i<=x+1;++i)
            {
                for(int j=y-1;j<=y+1;++j)
                {
                    if(board[i][j] == Enemy)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        inline bool playerMove(int dirX, int dirY)
        {
            int tempX, tempY;
            int x = playerPosition.getX() + dirX;
            int y = playerPosition.getY() + dirY;
            if(inBoard(x,y))
            {
                switch(board[x][y])
                {
                    case Debris:
                        tempX = x + dirX;
                        tempY = y + dirY;
                        if(inBoard(tempX, tempY))
                        {
                            switch(board[tempX][tempY])
                            {
                                case Enemy:
                                case Empty:
                                    board[tempX][tempY] = Debris;
                                    break;
                                case Debris:
                                    return true;
                            }
                        }
                        else
                        {
                            return true;
                        }
                    case Empty:
                        board[x][y] = Player;
                        board[playerPosition.getX()][playerPosition.getY()] = Empty;
                        playerPosition.setPoint(x, y);
                    case Player:
                        return false;
                }
            }
            return true;
        }
        inline bool inBoard(int x, int y) const
        {
            return x>=1 && x<=31 && y>=1 && y<=31;
        }
        inline int getRobotsNumber() const
        {
            int count = 0;
            for(int i=1;i<=31;++i)
            {
                for(int j=1;j<=31;++j)
                {
                    if(board[i][j] == Enemy)
                    {
                        ++count;
                    }
                }
            }
            return count;
        }
        inline int getDebrisNumber() const
        {
            int count = 0;
            for(int i=1;i<=31;++i)
            {
                for(int j=1;j<=31;++j)
                {
                    if(board[i][j] == Debris)
                    {
                        ++count;
                    }
                }
            }
            return count;
        }
        inline int getClosestNumber() const
        {
            int length = 19627;
            int tempLength;
            for(int i=1;i<=31;++i)
            {
                for(int j=1;j<=31;++j)
                {
                    if(board[i][j] == Enemy)
                    {
                        tempLength = getLengthI4(i,j,playerPosition.getX(),playerPosition.getY());
                        if(tempLength < length)
                        {
                            length = tempLength;
                        }
                    }
                }
            }
            return length;
        }
        inline bool findTeleport()
        {
            for(int i=0;i<teleportNumber;++i)
            {
                if(!teleportUsed[i])
                {
                    bool flag = true;
                    if(findEnemy(teleport[i].getX(),teleport[i].getY()))
                    {
                        flag = false;
                    }
                    if(board[teleport[i].getX()][teleport[i].getY()] != Empty)
                    {
                        flag = false;
                    }
                    if(flag)
                    {
                        teleportUsed[i] = true;
                        board[playerPosition.getX()][playerPosition.getY()] = Empty;
                        board[teleport[i].getX()][teleport[i].getY()] = Player;
                        playerPosition.setX(teleport[i].getX());
                        playerPosition.setY(teleport[i].getY());
                        this->robotsMove();
                        return true;
                    }
                }
            }
            return false;
        }
        inline void printBoard() const
        {
            for(int i=1;i<=31;++i)
            {
                for(int j=1;j<=31;++j)
                {
                    if(board[i][j] != Empty)
                    {
                        printf("%d ",board[i][j]);
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
        inline int getPlayerX() const
        {
            return playerPosition.getX();
        }
        inline int getPlayerY() const
        {
            return playerPosition.getY();
        }
    private:
        Status board[33][33];
        Status tempBoard[33][33];
        Point teleport[25];
        Point playerPosition;
        bool teleportUsed[25];
        int teleportNumber;
}currentBoard, tempBoard;

struct MoveInformation
{
    bool playerDead;
    int robotsNumber;
    int closestLength;
    int rowIndex;
    int columnIndex;
}moveInformation[9];

bool operator >(MoveInformation a, MoveInformation b)
{
    if(a.playerDead == b.playerDead)
    {
        if(a.robotsNumber == b.robotsNumber)
        {
            if(a.closestLength == b.closestLength)
            {
                if(a.rowIndex == b.rowIndex)
                {
                    return a.columnIndex < b.columnIndex;
                }
                return a.rowIndex < b.rowIndex;
            }
            return a.closestLength > b.closestLength;
        }
        return a.robotsNumber < b.robotsNumber;
    }
    return a.playerDead < b.playerDead;
};

bool input()
{
    int robotsNumber, teleportNumber;
    Point tempPoint;
    currentBoard.clearBoard();
    if(!~scanf("%d%d",&robotsNumber,&teleportNumber))
    {
        return false;
    }
    for(int i=0;i<robotsNumber;++i)
    {
        tempPoint.input();
        currentBoard.addEnemy(tempPoint.getX(), tempPoint.getY());
    }
    for(int i=0;i<teleportNumber;++i)
    {
        tempPoint.input();
        currentBoard.addTeleport(tempPoint);
    }
    return robotsNumber || teleportNumber;
}

bool playerMove()
{
    int pointer;
    for(int i=0;i<9;++i)
    {
        tempBoard = currentBoard;
        moveInformation[i].playerDead = tempBoard.playerMove(directionX[i], directionY[i]);
        if(!moveInformation[i].playerDead)
        {
            moveInformation[i].playerDead = tempBoard.robotsMove();
            moveInformation[i].robotsNumber = tempBoard.getRobotsNumber();
            moveInformation[i].closestLength = tempBoard.getClosestNumber();
            moveInformation[i].rowIndex = tempBoard.getPlayerX();
            moveInformation[i].columnIndex = tempBoard.getPlayerY();
        }
    }
    pointer = 0;
    for(int i=1;i<9;++i)
    {
        if(moveInformation[i] > moveInformation[pointer])
        {
            pointer = i;
        }
    }
    if(moveInformation[pointer].playerDead)
    {
        return false;
    }
    currentBoard.playerMove(directionX[pointer], directionY[pointer]);
    currentBoard.robotsMove();
    return true;
}

int main(int argc, char* argv[])
{
    int stepNumber;
    int caseNumber = 0;
    bool lose;
    while(input())
    {
        stepNumber = 0;
        lose = false;
        if(caseNumber)
        {
            printf("\n");
        }
        printf("Case %d:\n",++caseNumber);
        while(true)
        {

                        #ifdef DEBUG
                            system("cls");
                            currentBoard.printBoard();
                            for(int i=0;i<9;++i)
                            {
                                printf("Move Information %d: \n",i);
                                printf("\tPlayer Dead: %d\n",moveInformation[i].playerDead);
                                printf("\tRobots Number: %d\n",moveInformation[i].robotsNumber);
                                printf("\tMost Close Length: %d\n",moveInformation[i].closestLength);
                                printf("\tRow Number: %d  Column Number: %d\n",moveInformation[i].rowIndex,moveInformation[i].columnIndex);
                                printf("\n");
                            }
                            while(getchar()!='t');
                        #endif
            ++stepNumber;
            if(!playerMove())
            {
                if(currentBoard.findTeleport())
                {
                    printf("Move %d: teleport to (%d,%d)\n",stepNumber,currentBoard.getPlayerX(),currentBoard.getPlayerY());
                }
                else
                {
                    if(currentBoard.robotsMove())
                    {
                        lose = true;
                        break;
                    }
                }
            }
            if(currentBoard.getRobotsNumber() == 0)
            {
                break;
            }
        }
        if(lose)
        {
            printf("Lost game after making %d moves.\n",stepNumber);
            printf("Final position: (%d,%d)\n",currentBoard.getPlayerX(),currentBoard.getPlayerY());
            printf("Number of cells with debris: %d\n",currentBoard.getDebrisNumber());
            printf("Number of robots remaining: %d\n",currentBoard.getRobotsNumber());
        }
        else
        {
            printf("Won game after making %d moves.\n",stepNumber);
            printf("Final position: (%d,%d)\n",currentBoard.getPlayerX(),currentBoard.getPlayerY());
            printf("Number of cells with debris: %d\n",currentBoard.getDebrisNumber());
        }
    }
    return 0;
}
