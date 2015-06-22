class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long inter = 0;
        if (max(A, E) < min(C, G)) {
            if (max(B, F) < min(D, H)) {
                inter = 1LL * (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
            }
        }
        return 1LL * (C - A) * (D - B) + 1LL * (G - E) * (H - F) - inter;
    }
};
