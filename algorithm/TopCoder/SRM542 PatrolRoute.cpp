class PatrolRoute
{
public:
    int countRoutes(int X, int Y, int minT, int maxT)
    {
        long long ans = 0;
        for(int i=3;i<=X;++i)
        {
            for(int j=3;j<=Y;++j)
            {
                int length = ((i-1)<<1)+((j-1)<<1);
                if(length >= minT && length <= maxT)
                {
                    long long way = (i-2)*(j-2) * 6;
                    ans += (way * (X - i + 1) * (Y - j + 1)) % 1000000007;
                }
            }
        }
        return ans % 1000000007;
    }
};
