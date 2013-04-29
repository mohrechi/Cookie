#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXS = 43046821;

//#define DEBUG

bool win[MAXS];
char step[MAXS];

inline int getStatus(int board[4][4])
{
    int status = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            status = status * 3 + board[i][j];
        }
    }
    return status;
}

inline void restoreBoard(int board[4][4], int status)
{
    for (int i = 3; i >= 0; --i)
    {
        for (int j = 3; j >= 0; --j)
        {
            board[i][j] = status % 3;
            status /= 3;
        }
    }
}

#ifdef DEBUG
void printBoard(int board[4][4])
{
    printf("Board: \n");
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

void printStatus(int status)
{
    printf("Status: %d ", status);
    int board[4][4];
    restoreBoard(board, status);
    printBoard(board);
}
#endif // DEBUG

const int dirX[] = {1, 0, -1, 0};
const int dirY[] = {0, 1, 0, -1};

void paint(int board[4][4], int color[4][4], int c, int x, int y)
{
    if (color[x][y] == -1)
    {
        color[x][y] = c;
        for (int k = 0; k < 4; ++k)
        {
            int tx = x + dirX[k];
            int ty = y + dirY[k];
            if (tx >= 0 && tx < 4)
            {
                if (ty >= 0 && ty < 4)
                {
                    if (board[x][y] == board[tx][ty])
                    {
                        paint(board, color, c, tx, ty);
                    }
                }
            }
        }
    }
}

void pick(int board[4][4], int newBoard[4][4], int color[4][4], int c)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (color[i][j] == c)
            {
                newBoard[i][j] = 0;
            }
            else
            {
                newBoard[i][j] = board[i][j];
            }
        }
    }
}

void fall(int board[4][4])
{
    for (int j = 0; j < 4; ++j)
    {
        int k = 3;
        for (int i = 3; i >= 0; --i)
        {
            if (board[i][j] != 0)
            {
                board[k--][j] = board[i][j];
            }
        }
        for (; k >= 0; --k)
        {
            board[k][j] = 0;
        }
    }
}

void get(int status)
{
    if (step[status] != -1)
    {
        return;
    }
    int board[4][4];
    int color[4][4];
    int colorNumber = 0;
    restoreBoard(board, status);
    memset(color, -1, sizeof(color));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j] && color[i][j] == -1)
            {
                paint(board, color, colorNumber, i, j);
                ++colorNumber;
            }
        }
    }
    bool mustLose = false;
    int minLen = 20;
    int maxLen = 0;
    for (int i = 0; i < colorNumber; ++i)
    {
        int newBoard[4][4];
        pick(board, newBoard, color, i);
        fall(newBoard);
        int newStatus = getStatus(newBoard);
        get(newStatus);
        if (win[newStatus])
        {
            maxLen = max(maxLen, step[newStatus] + 1);
        }
        else
        {
            minLen = min(minLen, step[newStatus] + 1);
            mustLose = true;
        }
    }
    if (colorNumber == 0)
    {
        win[status] = false;
        step[status] = 0;
    }
    else
    {
        if (mustLose)
        {
            win[status] = true;
            step[status] = minLen;
        }
        else
        {
            win[status] = false;
            step[status] = maxLen;
        }
    }
    #ifdef DEBUG
    printStatus(status);
    if (win[status])
    {
        printf("win");
    }
    else
    {
        printf("lose");
    }
    printf(" %d\n", step[status]);
    #endif // DEBUG
}

int main()
{
    int board[4][4];
    char origin[4][5];
    memset(step, -1, sizeof(step));
    while (~scanf("%s%s%s%s", origin[0], origin[1], origin[2], origin[3]))
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (origin[i][j] == 'B')
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 2;
                }
            }
        }
        int status = getStatus(board);
        get(status);
        if (win[status])
        {
            printf("win");
        }
        else
        {
            printf("loss");
        }
        printf(" %d\n", step[status]);
    }
    return 0;
}
