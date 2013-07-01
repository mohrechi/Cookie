#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    char s[210],*p;
    while(1)
    {
        gets(s);
        if(!strcmp(s,"ENDOFINPUT")) break;
        gets(s);
        p=s;
        while(*p!='\0')
        {
            switch(*p)
            {
                case 'A': *p='V';break;
                case 'B': *p='W';break;
                case 'C': *p='X';break;
                case 'D': *p='Y';break;
                case 'E': *p='Z';break;
                case 'F': *p='A';break;
                case 'G': *p='B';break;
                case 'H': *p='C';break;
                case 'I': *p='D';break;
                case 'J': *p='E';break;
                case 'K': *p='F';break;
                case 'L': *p='G';break;
                case 'M': *p='H';break;
                case 'N': *p='I';break;
                case 'O': *p='J';break;
                case 'P': *p='K';break;
                case 'Q': *p='L';break;
                case 'R': *p='M';break;
                case 'S': *p='N';break;
                case 'T': *p='O';break;
                case 'U': *p='P';break;
                case 'V': *p='Q';break;
                case 'W': *p='R';break;
                case 'X': *p='S';break;
                case 'Y': *p='T';break;
                case 'Z': *p='U';break;
            }
            p++;
        }
        printf("%s\n",s);
        gets(s);
    }
    return 0;
}
