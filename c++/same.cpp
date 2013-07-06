#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int BUFFER_SIZE = 4096;

char buf1[BUFFER_SIZE];
char buf2[BUFFER_SIZE];

int getNextLine(FILE *file, char buf[BUFFER_SIZE])
{
    int len = 0;
    char ch;
    while (true)
    {
        int status = fscanf(file, "%c", &ch);
        if (status == -1 && len == 0)
        {
            buf[0] = 0;
            return -1;
        }
        if (ch == '\n' || status == -1)
        {
            buf[len] = 0;
            break;
        }
        buf[len++] = ch;
    }
    return 0;
}

int main()
{
    FILE *file1 = fopen("out1.txt", "r");
    FILE *file2 = fopen("out2.txt", "r");
    int lineNum = 0;
    bool flag = true;
    while (true)
    {
        ++lineNum;
        int state1 = getNextLine(file1, buf1);
        int state2 = getNextLine(file2, buf2);
        if (state1 == -1 && state2 == -1)
        {
            break;
        }
        if (strcmp(buf1, buf2))
        {
            flag = false;
            printf("Wrong Answer at %d\n", lineNum);
            printf("file1: %s\n", buf1);
            printf("file2: %s\n", buf2);
        }
    }
    if (flag)
    {
        printf("Accepted\n");
    }
    return 0;
}
