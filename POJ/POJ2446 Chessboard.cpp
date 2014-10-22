#include<stdio.h>
#include<memory.h>

int n,m,hole,point,match[1300],position[40][40],graph[600][4];
bool board[40][40],visit[1300];

bool check(int x)
{
    for(int i=0;i<4;i++)
    {
        if(graph[x][i]==-1 || visit[graph[x][i]]) continue;
        visit[graph[x][i]]=true;
        if(match[graph[x][i]]==-1 || check(match[graph[x][i]]))
        {
            match[graph[x][i]]=x;
            return true;
        }
    }
    return false;
}

int max_match()
{
    int count=0;
    memset(match,-1,sizeof(match));
    for(int i=0;i<point;i++)
    {
        if(graph[i][0])
        {
            memset(visit, false, sizeof(visit));
            if(check(i))
            {
                count++;
            }
        }
    }
    return count;
}

void init_position()
{
    int count1=0, count2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i&1)
            {
                if(j&1) position[i][j]=count2++;
                else position[i][j]=point+count1++;
            }
            else
            {
                if(j&1) position[i][j]=point+count1++;
                else position[i][j]=count2++;
            }
        }
    }
}

int get_position(int x, int y)
{
    if(x<0 || y<0 || x>=n || y>=m || board[x][y])
    {
        return -1;
    }
    return position[x][y];
}

void init_graph()
{
    init_position();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(get_position(i,j)<point && get_position(i,j)!=-1)
            {
                graph[get_position(i,j)][0]=get_position(i-1,j);
                graph[get_position(i,j)][1]=get_position(i+1,j);
                graph[get_position(i,j)][2]=get_position(i,j-1);
                graph[get_position(i,j)][3]=get_position(i,j+1);
            }
        }
    }
}

int main()
{
    int x,y;
    scanf("%d%d%d",&n,&m,&hole);
    for(int i=0;i<hole;i++)
    {
        scanf("%d%d",&x,&y);
        board[y-1][x-1]=true;
    }
    if((n*m-hole)&1)
    {
        printf("NO");
        return 0;
    }
    point=(n*m+1)/2;
    init_graph();
    if(max_match()==((n*m-hole)>>1)) printf("YES\n");
    else printf("NO\n");
	return 0;
}
