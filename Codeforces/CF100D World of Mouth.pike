int main() {
    int n = (int)Stdio.stdin.gets();
    string a = Stdio.stdin.gets();
    string b = Stdio.stdin.gets();
    int la = strlen(a);
    int lb = strlen(b);
    int i = 0;
    while (i < min(la, lb)) {
        if (a[i] != b[i]) {
            break;
        }
        ++i;
    }
    if ((la - i) + (lb - i) > n) {
        write("No");
    } else {
        write("Yes");
    }
}
