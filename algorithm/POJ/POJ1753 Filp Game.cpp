#include<stdio.h>
#include<memory.h>

int a[4][4],b[4][4],min;

void flipAll()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            a[i][j]=a[i][j]?0:1;
        }
    }
}

int get(int i, int j)
{
    if(i<0 or i>3 or j<0 or j>3)
    {
        return 0;
    }
    return b[i][j];
}

int getAll(int i, int j)
{
    return get(i-1,j)+get(i,j-1)+get(i,j)+get(i,j+1)+a[i][j];
}

bool check()
{
    for(int i=0;i<4;i++)
    {
        if(getAll(3,i)&1)
        {
            return false;
        }
    }
    return true;
}

void count()
{
    int c=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            c+=b[i][j];
        }
    }
    if(c<min)
    {
        min=c;
    }
}

void search()
{
    for(int ans=0;ans<=15;ans++)
    {
        memset(b,0,sizeof(b));
        b[0][0]=ans&1, b[0][1]=(ans&2)>>1;
        b[0][2]=(ans&4)>>2, b[0][3]=(ans&8)>>3;
        for(int i=1;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(getAll(i-1,j)&1)
                {
                    b[i][j]=1;
                }
            }
        }
        if(check())
        {
            count();
        }
    }
}

int main()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;)
        {
            char ch=getchar();
            if(ch=='b')
            {
                a[i][j]=1;
                j++;
            }
            else if(ch=='w')
            {
                a[i][j]=0;
                j++;
            }
        }
    }
    min=0x7FFFFFFF;
    search();
    flipAll();
    search();
    if(min==0x7FFFFFFF)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("%d\n",min);
    }
    return 0;
}
