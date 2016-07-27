#include<iostream>
#include<map>
#include<string>
#include<cstring>
using namespace std;
#include<ctype.h>
char m[30][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",\
		".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","..--",".-.-","---.","----"};
int main()
{
	int n , length , num[120] , k , t , j , l , f;
	cin >> n;
	char temp[120] , u[1000];
	for(t = 1 ; t <= n; t++)
	{
		u[0] = '\0';
		cin >> temp;
		length = strlen(temp);
		for(k = 0; k < length ; k++)
		{
			if(isalpha(temp[k]))
				strcat(u , m[temp[k] - 'A']) , num[k] = strlen(m[temp[k] - 'A']);
			else if(temp[k] == '_')
				strcat(u , m[26]) , num[k] = 4;
			else if(temp[k] == ',')
				strcat(u , m[27]) , num[k] = 4;
			else if(temp[k] == '.')
				strcat(u , m[28]) , num[k] = 4;
			else if(temp[k] == '?')
				strcat(u , m[29]) , num[k] = 4;
		}
		cout << t << ": ";
		for(k-- , j = 0; k!= -1 ; k--)
		{
			for(l = 0 , temp[0] = '\0'; l < num[k] ; l++ , j++)
				temp[l] = u[j];
			temp[l] = '\0';
			for(l = 0 , f = 1; f && l < 26; l++)
			{
				if(!strcmp(m[l] , temp))
				{
					putchar('A'  +l);
					f = 0;
				}
			}
			if(f && !strcmp(m[26] , temp))
				putchar('_') , f = 0;
			if(f && !strcmp(m[27] , temp))
				putchar(',') , f = 0;
			if(f && !strcmp(m[28] , temp))
				putchar('.') , f = 0;
			if(f && !strcmp(m[29] , temp))
				putchar('?') , f = 0;
		}
		putchar('\n');
	}
	return 0;
}
