#include <iostream>
using namespace std;

int main()
{
    unsigned long long T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        int cnt = 0;
        while (N > 1)
        {
            ++cnt;
            int num1 = 0;
            for (int i = 0; i < 64; ++i)
            {
                if (N & (1LL << i))
                {
                    ++num1;
                }
            }
            if (num1 == 1)
            {
                N >>= 1;
            }
            else
            {
                for (int i = 63; i >= 0; --i)
                {
                    if (N & (1LL << i))
                    {
                        N -= 1LL << i;
                        break;
                    }
                }
            }
        }
        cout << ((cnt & 1) ? "Louise" : "Richard") << endl;
    }
    return 0;
}
