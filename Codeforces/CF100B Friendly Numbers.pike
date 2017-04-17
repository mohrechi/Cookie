int main() {
    int n = (int)Stdio.stdin->gets();
    array a = (array(int))(Stdio.stdin->gets() / ",");
    int flag = 1;
    for (int i = 0; i < n && flag; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] % a[j] != 0 && a[j] % a[i] != 0) {
                flag = 0;
                break;
            }
        }
    }
    write(flag ? "FRIENDS\n" : "NOT FRIENDS\n");
    return 0;
}
