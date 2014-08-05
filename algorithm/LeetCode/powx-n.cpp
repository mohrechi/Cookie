#include <algorithm>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double ans = pow(x * x, n / 2);
        if (abs(n % 2) == 1) {
            if (n > 0) {
                ans *= x;
            } else {
                ans /= x;
            }
        }
        return ans;
    }
};
