#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct Team
{
    string name;
    int score,total,attempt[4],time[4];
    void deal()
    {
        score=0,total=0;
        for(int i=0;i<4;i++)
        {
            if(time[i])
            {
                total++;
                score+=(attempt[i]-1)*20+time[i];
            }
        }
    }
    bool operator <(Team x) const
    {
        if(total==x.total) return score>x.score;
        return total<x.total;
    }
}team;

int main()
{
    priority_queue<Team> h;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>team.name;
        for(int i=0;i<4;i++)
        {
            cin>>team.attempt[i]>>team.time[i];
        }
        team.deal();
        h.push(team);
    }
    cout<<h.top().name<<" "<<h.top().total<<" "<<h.top().score<<endl;
    return 0;
}
