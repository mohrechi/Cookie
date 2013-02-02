#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp( const void *arg1, const void *arg2 )
{
    return _stricmp((char *)arg1, (char *)arg2);
}

int main(int argc, char* argv[])
{
	int         n;
	int         i;
	int         j;
	int         len;
	int         count;
	int         flag;
	char       input[100];
	char       record[100005][8];
	scanf("%d",&n);
	len=0;
	while(n--)
	{
	    scanf("%s",input);
	    i=0, j=0;
	    while(i<=7)
	    {
	        switch(input[j])
	        {
	            case 'A': case 'B': case 'C': input[i++]='2'; break;
	            case 'D': case 'E': case 'F': input[i++]='3'; break;
	            case 'G': case 'H': case 'I': input[i++]='4'; break;
	            case 'J': case 'K': case 'L': input[i++]='5'; break;
	            case 'M': case 'N': case 'O': input[i++]='6'; break;
	            case 'P': case 'R': case 'S': input[i++]='7'; break;
	            case 'T': case 'U': case 'V': input[i++]='8'; break;
	            case 'W': case 'X': case 'Y': input[i++]='9'; break;
	            case '0': case '1': case'2': case '3': case '4': case'5': case '6': case '7': case'8': case'9': input[i++]=input[j]; break;
	        }
	        j++;
	    }
	    strcpy(record[len],input);
	    record[len][7]='\0';
	    len++;
	}
    qsort(record,len,sizeof(record[0]),cmp);
    j=0,count=1, flag=1;
    for(i=1;i<=len;i++)
    {
        if(strcmp(record[i],record[j])==0)count++,flag=0;
        else
        {
            if(count>1)
                printf("%c%c%c-%c%c%c%c %d\n", record[j][0],record[j][1],record[j][2],record[j][3],record[j][4],record[j][5],record[j][6],count);
            count=1, j=i;
        }
    }
    if(flag) printf("No duplicates.\n");
	return 0;
}
