#include<iostream>
#include<queue>
using namespace std;

bool v[100005];
bool check(int x)
{
    return x>=0 && x<=100000 && !v[x];
}
int main()
{
    queue<int>r,s;
    int n,k,t;
    cin>>n>>k;
    r.push(n), s.push(0), v[n]=true;
    while(true)
    {
        if(r.front()==k)
        {
            break;
        }
        t=r.front()*2;
        if(check(t))
        {
            r.push(t), s.push(s.front()+1), v[t]=true;
        }
        t=r.front()+1;
        if(check(t))
        {
            r.push(t), s.push(s.front()+1), v[t]=true;
        }
        t=r.front()-1;
        if(check(t))
        {
            r.push(t), s.push(s.front()+1), v[t]=true;
        }
        r.pop(), s.pop();
    }
    cout<<s.front()<<endl;
    return 0;
}
