#include <cstdio>
#include <cstring>

class RandomColoringDiv2
{
public:
    bool color[3][105];
    int max[3];
    int start[3];
    int time[3][4];
    int cnt[3];
    int side[3][2];
    int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)
    {
        int result = 0;
        memset(color, false, sizeof(color));
        max[0] = maxR;
        max[1] = maxG;
        max[2] = maxB;
        start[0] = startR;
        start[1] = startG;
        start[2] = startB;
        for(int i=0;i<3;++i)
        {
            for(int j=d1;j<=d2;++j)
            {
                if(start[i] - j >= 0)
                {
                    color[i][start[i] - j] = true;
                }
                if(start[i] + j < max[i])
                {
                    color[i][start[i] + j] = true;
                }
            }
            side[i][0] = start[i] - d2 >= 0 ? start[i] - d2 : 0;
            side[i][1] = start[i] + d2 < max[i] ? start[i] + d2 : max[i] - 1;
            side[i][1] -= side[i][0] - 1;
            cnt[i] = 0;
            for(int j=0;j<max[i];++j)
            {
                if(color[i][j])
                {
                    ++cnt[i];
                }
            }
        }
        for(int i=0;i<3;++i)
        {
            int temp = cnt[i];
            for(int j=0;j<3;++j)
            {
                if(i!=j)
                {
                    temp *= side[j][1] - cnt[j];
                }
            }
            result += temp;
            temp = side[i][1] - cnt[i];
            for(int j=0;j<3;++j)
            {
                if(i!=j)
                {
                    temp *= cnt[j];
                }
            }
            result += temp;
        }
        return result + cnt[0] * cnt[1] * cnt[2];
    }
};

int main()
{
    RandomColoringDiv2 random;
    printf("%d\n", random.getCount(49,59,53,12,23,13,11,22));
    return 0;
}
