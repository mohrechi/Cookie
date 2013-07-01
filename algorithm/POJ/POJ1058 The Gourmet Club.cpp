#include <stdio.h>
#include <memory.h>

char arrange[5][17];
bool relation[16][16];
bool visited[16];

bool arrangeMeeting(int day)
{
    int count = 0;
    for(int i=0;i<16;++i)
    {
        for(int j=i+1;j<16;++j)
        {
            for(int k=j+1;k<16;++k)
            {
                for(int l=k+1;l<16;++l)
                {
                    if(!visited[i])
                    {
                        if(!visited[j])
                        {
                            if(!visited[k])
                            {
                                if(!visited[l])
                                {
                                    if(relation[i][j])
                                    {
                                        if(relation[i][k])
                                        {
                                            if(relation[i][l])
                                            {
                                                if(relation[j][i])
                                                {
                                                    if(relation[j][k])
                                                    {
                                                        if(relation[j][l])
                                                        {
                                                            if(relation[k][i])
                                                            {
                                                                if(relation[k][j])
                                                                {
                                                                    if(relation[k][l])
                                                                    {
                                                                        if(relation[l][i])
                                                                        {
                                                                            if(relation[l][j])
                                                                            {
                                                                                if(relation[l][k])
                                                                                {
                                                                                    visited[i] = true;
                                                                                    visited[j] = true;
                                                                                    visited[k] = true;
                                                                                    visited[l] = true;
                                                                                    relation[i][j] = false;
                                                                                    relation[j][i] = false;
                                                                                    relation[i][k] = false;
                                                                                    relation[k][i] = false;
                                                                                    relation[j][k] = false;
                                                                                    relation[k][j] = false;
                                                                                    relation[i][l] = false;
                                                                                    relation[l][i] = false;
                                                                                    relation[j][l] = false;
                                                                                    relation[l][j] = false;
                                                                                    relation[k][l] = false;
                                                                                    relation[l][k] = false;
                                                                                    arrange[day][count++] = i + 'A';
                                                                                    arrange[day][count++] = j + 'A';
                                                                                    arrange[day][count++] = k + 'A';
                                                                                    arrange[day][count++] = l + 'A';
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return count == 16;
}

int main(int argc, char *argv[])
{
    while(true)
    {
        memset(relation, true, sizeof(relation));
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<=12;j+=4)
            {
                if(!~scanf("%s",arrange[i] + j))
                {
                    return 0;
                }
                else
                {
                    for(int k=j;k<j+4;++k)
                    {
                        for(int l=j;l<j+4;++l)
                        {
                            relation[arrange[i][k]-'A'][arrange[i][l]-'A'] = false;
                        }
                    }
                }
            }
        }
        memset(visited, false, sizeof(visited));
        if(arrangeMeeting(3))
        {
            memset(visited, false, sizeof(visited));
            if(arrangeMeeting(4))
            {
                for(int k=0;k<5;++k)
                {
                    for(int i=0;i<=12;i+=4)
                    {
                        if(i)
                        {
                            printf(" ");
                        }
                        for(int j=i;j<i+4;++j)
                        {
                            printf("%c",arrange[k][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
            {
                printf("It is not possible to complete this schedule.\n\n");
            }
        }
        else
        {
            printf("It is not possible to complete this schedule.\n\n");
        }
    }
    return 0;
}
