int main() {
    int n = (int)Stdio.stdin->gets();
    array(string) names = allocate(n);
    array(int) years = allocate(n);
    for (int i = 0; i < n; ++i) {
        sscanf(Stdio.stdin->gets(), "%s %d", names[i], years[i]);
    }
    mapping map = mkmapping(names, years);
    int m = (int)Stdio.stdin->gets();
    int minYear = 10000;
    string ans = "";
    while (m--) {
        string name = Stdio.stdin->gets();
        int year = map[name];
        if (year < minYear ||
            (year == minYear && name > ans)) {
            minYear = year;
            ans = name;
        }
    }
    write(ans + "\n");
    return 0;
}
