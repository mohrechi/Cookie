#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

char board[20][25];
bool visited[20][25];
int color[20][25], max, maxColor;

void inputBoard()
{
    for(int i=10;i>0;i--)
    {
        scanf("%s",board[i]+1);
    }
}

int draw(int x, int y, int c)
{
    if(!visited[x][y] && board[x][y])
    {
        visited[x][y]=true;
        color[x][y]=c;
        int res = 1;
        if(board[x][y]==board[x-1][y]) res+=draw(x-1,y,c);
        if(board[x][y]==board[x+1][y]) res+=draw(x+1,y,c);
        if(board[x][y]==board[x][y-1]) res+=draw(x,y-1,c);
        if(board[x][y]==board[x][y+1]) res+=draw(x,y+1,c);
        return res;
    }
    return 0;
}

void printColor()
{
    printf("Color: \n");
    for(int i=10;i>0;i--)
    {
        for(int j=1;j<=15;j++)
        {
            printf("%d ",color[i][j]);
        }
        printf("\n");
    }
    printf("Most Color: %d\n\n",maxColor);
}

void printBoard()
{
    printf("Board: \n");
    for(int i=10;i>0;i--)
    {
        for(int j=1;j<=15;j++)
        {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isFinal()
{
    int c = 1, tx, ty;
    max = 0;
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
    for(int j=1;j<=15;j++)
    {
        for(int i=1;i<=10;i++)
        {
            if(!visited[i][j] && board[i][j])
            {
                int temp = draw(i,j,c);
                if(temp>max)
                {
                    tx = i, ty = j;
                    max = temp;
                    maxColor = c;
                }
                else
                {
                    if(temp==max)
                    {
                        if(j<ty)
                        {
                            tx = i, ty = j;
                            max = temp;
                            maxColor = c;
                        }
                        else if(j==ty && i<tx)
                        {
                            tx = i, ty = j;
                            max = temp;
                            maxColor = c;
                        }
                    }
                }
                c++;
            }
        }
    }
    return max<=1;
}

int getScore(int number)
{
    return (number-2)*(number-2);
}

int move()
{
    int number = 0, temp = getScore(max);
    bool flag = true;
    for(int j=1;j<=15;j++)
    {
        for(int i=1;i<=10;i++)
        {
            if(color[i][j]==maxColor)
            {
                if(flag)
                {
                    printf("(%d,%d): removed %d balls of color %c, got %d points. \n",i,j,max,board[i][j], temp);
                    flag = false;
                }
                board[i][j]=0;
            }
        }
    }
    return temp;
}

int remainNumber()
{
    int result = 0;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=15;j++)
        {
            if(board[i][j])
            {
                result++;
            }
        }
    }
    return result;
}

bool emptyLine(int j)
{
    for(int i=1;i<=10;i++)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    return true;
}

void clearLine(int x)
{
    for(int i=1;i<=10;i++)
    {
        board[i][x] = 0;
    }
}

void copyLine(int x, int y)
{
    for(int i=1;i<=10;i++)
    {
        board[i][x] = board[i][y];
    }
}

void compress()
{
    for(int i=1;i<=15;i++)
    {
        int k=1;
        for(int j=1;j<=10;j++)
        {
            if(board[j][i])
            {
                board[k++][i] = board[j][i];
            }
        }
        for(;k<=10;k++)
        {
            board[k][i] = 0;
        }
    }
    int k=1;
    for(int i=1;i<=15;i++)
    {
        if(!emptyLine(i))
        {
            copyLine(k++, i);
        }
    }
    for(;k<=15;k++)
    {
        clearLine(k);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        if(i>1) printf("\n");
        printf("Game %d:\n\n",i);
        inputBoard();
        int score = 0, remain;
        for(int j=1;!isFinal();j++)
        {
            printf("Move %d at ", j);
            score += move();
            compress();
        }
        if(!(remain = remainNumber()))
        {
            score += 1000;
        }
        printf("Final score: %d, with %d balls remaining. \n",score,remain);
    }
    return 0;
}
