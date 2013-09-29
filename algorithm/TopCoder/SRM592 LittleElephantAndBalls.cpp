#include <cstdio>
#include <string>
using namespace std;

class LittleElephantAndBalls
{
public:
    int getNumber(string S)
    {
        int leftNum = 0, rightNum = 0;
        bool left[3] = {false, false, false};
        bool right[3] = {false, false, false};
        int ans = 0;
        for (int i = 0; i < S.length(); ++i)
        {
            ans += leftNum + rightNum;
            int index = getIndex(S[i]);
            if (leftNum <= rightNum)
            {
                if (left[index])
                {
                    if (!right[index])
                    {
                        right[index] = true;
                        ++rightNum;
                    }
                }
                else
                {
                    left[index] = true;
                    ++leftNum;
                }
            }
            else
            {
                if (right[index])
                {
                    if (!left[index])
                    {
                        left[index] = true;
                        ++leftNum;
                    }
                }
                else
                {
                    right[index] = true;
                    ++rightNum;
                }
            }
        }
        return ans;
    }
private:
    int getIndex(char ch)
    {
        switch (ch)
        {
            case 'R': return 0;
            case 'G': return 1;
            case 'B': return 2;
        }
        return -1;
    }
};

int main()
{
    LittleElephantAndBalls obj;
    printf("%d\n", obj.getNumber("RGB"));
    printf("%d\n", obj.getNumber("RGGRBBB"));
    printf("%d\n", obj.getNumber("RRRGBRR"));
    printf("%d\n", obj.getNumber("RRRR"));
    printf("%d\n", obj.getNumber("GGRRRGR"));
    printf("%d\n", obj.getNumber("G"));
    return 0;
}
