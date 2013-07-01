#include <cstdio>
#include <cstring>
char str[30000];
char temp[30000];
void eraser(int pos, int num)
{
    int len = strlen(str);
    if(len != 0 && pos + num > len)
    {
        printf("Error!\n");
        return;
    }
    strcpy(temp,str+(pos+num));
    str[pos] = 0;
    strcat(str, temp);
    printf("%s\n", str);
}

void append(const char *s)
{
    strcat(str, s);
    printf("%s\n", str);
}

void insert(int pos, const char *s)
{
    strcpy(temp, str + pos);
    str[pos] = 0;
    strcat(str, s);
    strcat(str, temp);
    printf("%s\n", str);
}

void reverse()
{
    int len = strlen(str);
    for(int i=0;i<(len>>1);++i)
    {
        str[i] ^= str[len - i - 1];
        str[len - i - 1] ^= str[i];
        str[i] ^= str[len - i - 1];
    }
    printf("%s\n", str);
}

int main(int argc, char *argv[])
{
    int m, pos, num;
    char op[128];
    char s[128];
    while(~scanf("%s", str))
    {
        scanf("%d", &m);
        while(m--)
        {
            scanf("%s", op);
            switch(*op)
            {
                case 'E':
                    scanf("%d%d",&pos,&num);
                    eraser(pos, num);
                    break;
                case 'A':
                    scanf("%s",s);
                    append(s);
                    break;
                case 'I':
                    scanf("%d%s",&pos,s);
                    insert(pos, s);
                    break;
                case 'R':
                    reverse();
                    break;
            }
        }
    }
    return 0;
}
