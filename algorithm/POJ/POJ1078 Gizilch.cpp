#include <iostream>
#define MAXV(a, b) ((a) >= (b) ? (a) : (b))
#define MINV(a, b) ((a) <= (b) ? (a) : (b))
#define MAX_N 100
using namespace std;

int high, low;
bool visited, found;
bool used[MAX_N + 5];

bool getRes(int pos, int low, int high)
{
    if(low == 1)
    {
        if(visited)
            return true;
        else
        {
            found = visited = true;
            if(getRes(1, high, high)) return true;
            visited = false;
            return false;
        }
    }
    else if(pos > 100)
        return false;
    else
    {
        for(int i = pos; i <= 100; i++)
        {
            if(low % i == 0 && !used[i])
            {
                used[i] = true;
                if(getRes(pos + 1, low / i, high))
                    return true;
                used[i] = false;
            }
        }
        return false;
    }
}

int main()
{
    int temp1, temp2;
    while(cin>>temp1>>temp2)
    {
        high = MAXV(temp1, temp2);
        low = MINV(temp1, temp2);
        visited = found = false;
        memset(used, 0, sizeof(used));
        bool res = getRes(1, low, high);
        if(res) cout<<high<<endl;
        else
        {
            if(found)
                cout<<low<<endl;
            else
                cout<<high<<endl;
        }
     }
     return 0;
}
