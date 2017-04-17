int main() {
    float x, y, d = (float) Stdio.stdin.gets();
    sscanf(Stdio.stdin.gets(), "%f %f", x, y);
    d = d / 90.0 * acos(0.0);
    write((x*cos(d) - y*sin(d)) + " " + (y*cos(d) + x*sin(d)) + "\n");
    return 0;
}
