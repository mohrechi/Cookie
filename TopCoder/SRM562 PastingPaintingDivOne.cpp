#include <vector>
#include <string>
using namespace std;

class PastingPaintingDivOne
{
public:
    vector<long long> countColors(vector <string> clipboard, int T)
    {
        int time, color;
        vector<long long> result;
        for(int i=0;i<3;++i)
        {
            result.push_back(0);
        }
        for(int i=0;i<clipboard.size();++i)
        {
            for(int j=0;j<clipboard[i].length();++j)
            {
                int k;
                switch(clipboard[i][j])
                {
                case 'R':
                    time = 0;
                    color = 0;
                    break;
                case 'G':
                    time = 0;
                    color = 1;
                    break;
                case 'B':
                    time = 0;
                    color = 2;
                    break;
                case '.':
                    time = 2000000000;
                    for(k=1;k+i<clipboard.size() && k+j<clipboard[i].length();++k)
                    {
                        if(clipboard[k+i][k+j] != '.')
                        {
                            time = k;
                            switch(clipboard[k+i][k+j])
                            {
                                case 'R':
                                    color = 0;
                                    break;
                                case 'G':
                                    color = 1;
                                    break;
                                case 'B':
                                    color = 2;
                                    break;
                            }
                            break;
                        }
                    }
                    break;
                }
                if(time < T)
                {
                    ++ result[color];
                    if(i == 0 || j == 0)
                    {
                        result[color] += (long long)(T - time - 1);
                    }
                }
            }
        }
        return result;
    }
};
//150.31/250
