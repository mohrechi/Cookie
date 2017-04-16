int main() {
    int n = (int) Stdio.stdin.gets();
    array(string) lamps = Stdio.stdin.gets() / " ";
    int m = (int) Stdio.stdin.gets();
    array(string) presses = Stdio.stdin.gets() / " ";
    array(int) count = allocate(n + 1);
    for (int i = 0; i < m; ++i) {
        ++count[(int)presses[i]];
    }
    for (int i = n; i > 0; --i) {
        for (int j = i * 2; j <= n; j += i) {
            count[j] += count[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            write(" ");
        }
        if (count[i + 1] % 2 == 1) {
            write(lamps[i] == "on" ? "off" : "on");
        } else {
            write(lamps[i]);
        }
    }
    write("\n");
    return 0;
}
