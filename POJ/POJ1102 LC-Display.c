#include<stdio.h>
#include<string.h>

int num[10][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};

int main(int argc, char* argv[])
{
	int s,i,l,t,h;
	char n[20];
	for(;;)
	{
	    scanf("%d%s",&s,n);
	    if(!s) break;
        l=strlen(n);
        for(i=0;i<l;i++) n[i]-=48;
        for(i=0;i<l;i++)
        {
            printf(" ");
            if(num[n[i]][0]) for(t=0;t<s;t++) printf("-");
            else for(t=0;t<s;t++) printf(" ");
            printf("  ");
        }
        printf("\n");
        for(h=0;h<s;h++)
        {
            for(i=0;i<l;i++)
            {
                if(num[n[i]][1]) printf("|");
                else printf(" ");
                for(t=0;t<s;t++) printf(" ");
                if(num[n[i]][2]) printf("|");
                else printf(" ");
                printf(" ");
            }
            printf("\n");
        }
        for(i=0;i<l;i++)
        {
            printf(" ");
            if(num[n[i]][3]) for(t=0;t<s;t++) printf("-");
            else for(t=0;t<s;t++) printf(" ");
            printf("  ");
        }
        printf("\n");
        for(h=0;h<s;h++)
        {
            for(i=0;i<l;i++)
            {
                if(num[n[i]][4]) printf("|");
                else printf(" ");
                for(t=0;t<s;t++) printf(" ");
                if(num[n[i]][5]) printf("|");
                else printf(" ");
                printf(" ");
            }
            printf("\n");
        }
        for(i=0;i<l;i++)
        {
            printf(" ");
            if(num[n[i]][6]) for(t=0;t<s;t++) printf("-");
            else for(t=0;t<s;t++) printf(" ");
            printf("  ");
        }
        printf("\n\n");
	}
	return 0;
}
