int main() {
    int n = (int) Stdio.stdin.gets();
    array(int) a = allocate(n + 1);
    a[0] = 1;
    for (int i = 0; i < n; ++i) {
        int t = (int) Stdio.stdin.gets();
        for (int j = i; j >= 0; --j) {
            a[j + 1] += a[j] * t;
        }
    }
    write("X");
    if (n != 1) {
        write("^" + n);
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] != 0) {
            write(a[i] > 0 ? "+" : "-");
            if (abs(a[i]) != 1) {
                write(abs(a[i]) + "*");
            }
            write("X");
            if ((n - i) != 1) {
                write("^" + (n - i));
            }
        }
    }
    if (a[n]) {
        if (a[n] > 0) {
            write("+");
        }
        write(a[n] + "");
    }
    write("\n");
    return 0;
}
