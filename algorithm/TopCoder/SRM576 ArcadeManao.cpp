#include <set>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class ArcadeManao
{
public:

    bool judge(vector <string> &level, int coinRow, int coinColumn, int length)
    {
        int rowNum = level.size();
        int colNum = level[0].size();
        vector<vector<bool> > visit;
        for (int i = 0; i <= rowNum; ++i)
        {
            visit.push_back(vector<bool>());
            for (int j = 0; j <= colNum; ++j)
            {
                visit[i].push_back(false);
            }
        }
        queue<int> rq;
        queue<int> cq;
        for (int i = 1; i <= colNum; ++i)
        {
            visit[rowNum - 1][i] = true;
            rq.push(rowNum - 1);
            cq.push(i);
        }
        while (!rq.empty())
        {
            int r = rq.front();
            int c = cq.front();
            //cout << r << " " << c << endl;
            if (c - 1 > 0)
            {
                if (!visit[r][c - 1])
                {
                    if (level[r][c - 2] == 'X')
                    {
                        visit[r][c - 1] = true;
                        rq.push(r);
                        cq.push(c - 1);
                    }
                }
            }
            if (c + 1 <= colNum)
            {
                if (!visit[r][c + 1])
                {
                    if (level[r][c] == 'X')
                    {
                        visit[r][c + 1] = true;
                        rq.push(r);
                        cq.push(c + 1);
                    }
                }
            }
            for (int i = 1; i <= length; ++i)
            {
                if (r - i >= 0)
                {
                    if (!visit[r - i][c])
                    {
                        if (level[r - i][c - 1] == 'X')
                        {
                            visit[r - i][c] = true;
                            rq.push(r - i);
                            cq.push(c);
                            //cout << level[r - i + 1] << " push" << r - i << " " << c << endl;
                        }
                    }
                }
                if (r + i < rowNum)
                {
                    if (!visit[r + i][c])
                    {
                        if (level[r + i][c - 1] == 'X')
                        {
                            visit[r + i][c] = true;
                            rq.push(r + i);
                            cq.push(c);
                            //cout << "push" << r + i << " " << c << endl;
                        }
                    }
                }
            }
            rq.pop();
            cq.pop();
        }
        return visit[coinRow][coinColumn];
    }

    int shortestLadder(vector <string> level, int coinRow, int coinColumn)
    {
        --coinRow;
        int ans = level.size();
        int left = 0, right = level.size();
        int mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (judge(level, coinRow, coinColumn, mid))
            {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};
//117.43/256

int main()
{
    ArcadeManao test;
    vector <string> level;
    int coinRow;
    int coinColumn;
    level.push_back("XXXX....");
    level.push_back("...X.XXX");
    level.push_back("XXX..X..");
    level.push_back("......X.");
    level.push_back("XXXXXXXX");
    coinRow = 2;
    coinColumn = 4;
    cout << test.shortestLadder(level, coinRow, coinColumn) << endl;
    return 0;
}
