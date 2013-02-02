#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(int argc, char* argv[])
{
	char source[300], key[300];
	while(scanf("%s", source)!=EOF)
	{
	    while(scanf("%s", key), strcmp(key, "END"))
	    {
	        if(strcmp(key,"NULL")==0)
	        {
	            printf("0 NULL\n");
	            continue;
	        }
	        int i=0;
	        int j=0;
	        while(i<strlen(source)-strlen(key)+1)
	        {
	            j=0;
	            while(source[i]==key[j] && j<strlen(key))
	            {
	                i++, j++;
	            }
	            i-=j;
	            if(j==strlen(key))
	            {
	                strncpy(key, source, i);
	                key[i]=0;
	                if(key[0]==0)
	                {
	                    strcpy(key,"NULL");
	                }
	                printf("%d %s\n",i,key);
	                break;
	            }
	            i++;
	        }
	        if(i==strlen(source)-strlen(key)+1)
	        {
	            printf("%d %s\n",strlen(source), source);
	        }
	    }
	}
	return 0;
}
