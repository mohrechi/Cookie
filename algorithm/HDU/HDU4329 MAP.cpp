#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <iostream>
using namespace std;
const int MAXN = 105;
const int MAXM = 10005;

set<string> annotation[MAXN];
int num[MAXN];

double avep[MAXN];

double dealStr(int i, int retriveNumber, int &releventNumber, string &str)
{
    if(annotation[i].find(str) != annotation[i].end())
    {
        ++ releventNumber;
        return (double)releventNumber / retriveNumber;
    }
    else
    {
        return 0.0;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    string temp;
    string deal;
    for(int cas=1;cas<=t;++cas)
    {
        int n;
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        for(int i=0;i<n;++i)
        {
            annotation[i].clear();
            cin>>temp;
            getline(cin, temp);
            int start = 1;
            for(int j=0;j<temp.length();++j)
            {
                if(temp[j] != ' ')
                {
                    start = j;
                    break;
                }
            }
            for(int j=start;j<temp.length();++j)
            {
                if(temp[j] == ' ')
                {
                    annotation[i].insert(temp.substr(start, j - start));
                    ++ num[i];
                    int k;
                    for(k=j;k<temp.length();++k)
                    {
                        if(temp[k] != ' ')
                        {
                            start = k;
                            j = k;
                            break;
                        }
                    }
                    if(k == temp.length())
                    {
                        start = temp.length();
                        break;
                    }
                    else
                    {
                        -- j;
                    }
                }
            }
            if(start != temp.length())
            {
                annotation[i].insert(temp.substr(start, temp.length() - start));
                ++ num[i];
            }
        }
        for(int i=0;i<n;++i)
        {
            cin>>temp;
            getline(cin, temp);
            avep[i] = 0.0;
            int relevantNumber = 0;
            int retriveNumber = 0;
            int start = 1;
            for(int j=0;j<temp.length();++j)
            {
                if(temp[j] != ' ')
                {
                    start = j;
                    break;
                }
            }
            for(int j=start;j<temp.length();++j)
            {
                if(temp[j] == ' ')
                {
                    deal = temp.substr(start, j - start);
                    ++ retriveNumber;
                    avep[i] += dealStr(i, retriveNumber, relevantNumber, deal);
                    int k;
                    for(k=j;k<temp.length();++k)
                    {
                        if(temp[k] != ' ')
                        {
                            start = k;
                            j = k;
                            break;
                        }
                    }
                    if(k == temp.length())
                    {
                        start = temp.length();
                        break;
                    }
                    else
                    {
                        -- j;
                    }
                }
            }
            if(start != temp.length())
            {
                deal = temp.substr(start, temp.length() - start);
                ++ retriveNumber;
                avep[i] += dealStr(i, retriveNumber, relevantNumber, deal);
            }
            if(num[i])
            {
                avep[i] /= num[i];
            }
        }
        double ans = 0.0;
        for(int i=0;i<n;++i)
        {
            ans += avep[i];
        }
        ans /= n;
        printf("Case #%d: %.6lf\n", cas, ans);
    }
    return 0;
}
