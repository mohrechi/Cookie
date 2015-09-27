#include <bits/stdc++.h>
using namespace std;

int main() {
    char src[3], dst[3], mov[3];
    scanf("%s%s", src, dst);
    printf("%d\n", max(abs(src[0] - dst[0]), abs(src[1] - dst[1])));
    while (strcmp(src, dst)) {
        int n = 0;
        if (src[0] < dst[0]) {
            mov[n++] = 'R';
            ++src[0];
        } else if (src[0] > dst[0]) {
            mov[n++] = 'L';
            --src[0];
        }
        if (src[1] > dst[1]) {
            mov[n++] = 'D';
            --src[1];
        } else if (src[1] < dst[1]) {
            mov[n++] = 'U';
            ++src[1];
        }
        mov[n] = 0;
        puts(mov);
    }
    return 0;
}
