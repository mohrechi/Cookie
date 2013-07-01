#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PasswordXGuessing
{
public:
    static const int MAXN = 550;
    long long howMany(vector <string> guesses)
    {
        long long ans = 0;
        char temp[MAXN];
        for(int i=0;i<guesses[0].length();++i)
        {
            for(int j='0';j<='9';++j)
            {
                if(guesses[0][i] != j)
                {
                    for(int k=0;k<guesses[0].length();++k)
                    {
                        temp[k] = guesses[0][k];
                    }
                    temp[i] = j;
                    int k;
                    for(k=1;k<guesses.size();++k)
                    {
                        int cnt = 0;
                        for(int l=0;l<guesses[k].length();++l)
                        {
                            if(guesses[k][l] != temp[l])
                            {
                                ++ cnt;
                            }
                        }
                        if(cnt != 1)
                        {
                            break;
                        }
                    }
                    if(k == guesses.size())
                    {
                        ++ ans;
                    }
                }
            }
        }
        return ans;
    }
};
