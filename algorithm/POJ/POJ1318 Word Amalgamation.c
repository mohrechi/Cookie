#include<stdio.h>
#include<string.h>

struct str
{
    char ori[100];
    char sor[100];
}s[110];

int cmp1(const void* a, const void* b)
{
    return *(char*)a-*(char*)b;
}

int cmp2(const void* a, const void* b)
{
    return strcmp((*(struct str*)a).ori,(*(struct str*)b).ori);
}

int main(int argc, char* argv[])
{
	int i=0,j,l,f;
	char t[100];
	for(;;)
	{
	    scanf("%s",s[i].ori);
	    if(s[i].ori[0]=='X') break;
	    else i++;
	}
	qsort(s,i,sizeof(*s),cmp2);
	for(j=0;j<i;j++)
	{
	    strcpy(s[j].sor,s[j].ori);
	    l=strlen(s[j].sor);
	    qsort(s[j].sor,l,sizeof(s[j].sor[0]),cmp1);
	}
	for(;;)
	{
	    scanf("%s",t);
	    if(*t=='X') break;
	    l=strlen(t);
	    qsort(t,l,sizeof(*t),cmp2);
	    for(j=0,f=1;j<i;j++)
	    {
	        if(!strcmp(t,s[j].sor))
	        {
	            printf("%s\n",s[j].ori);
	            f=0;
	        }
	    }
	    if(f) printf("NOT A VALID WORD\n");
	    printf("******\n");
	}
	return 0;
}
