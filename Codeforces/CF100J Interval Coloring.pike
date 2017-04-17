int main() {
    int n = (int)Stdio.stdin->gets();
    array l = allocate(n), r = allocate(n);
    for (int i = 0; i < n; ++i) {
        int pl, pr;
        sscanf(Stdio.stdin->gets(), "%c%f,%f%c", pl, l[i], r[i], pr);
        if (pl == '(') {
            l[i] += 0.5;
        }
        if (pr == ')') {
            r[i] -= 0.5;
        }
    }
    sort(l, r);
    int ans = 1;
    for (int i = 0; i < n - 2; ++i) {
        if (r[i] >= l[i + 1] && r[i + 1] >= l[i + 2]) {
            ans = 2;
            break;
        }
    }
    write(ans + "\n");
    return 0;    
}
