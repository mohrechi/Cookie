#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	char s[100],a[100];
	int i,t;
    s[';']='L',s['L']='K',s['K']='J',s['J']='H',s['H']='G',s['G']='F',s['F']='D',s['D']='S',s['S']='A',s[',']='M',s['M']='N',s['N']='B',s['B']='V',s['V']='C',s['C']='X',s['X']='Z',s['[']='P',s['P']='O',s['O']='I',s['I']='U',s['U']='Y',s['Y']='T',s['T']='R',s['R']='E',s['E']='W',s['W']='Q',s['/']='.',s['\'']=';',s[']']='[',s['\\']=']',s['.']=',',s['=']='-',s['-']='0',s['0']='9',s['9']='8',s['8']='7',s['7']='6',s['6']='5',s['5']='4',s['4']='3',s['3']='2',s['2']='1',s['1']='`',s[' ']=' ';
	while(gets(a))
	{
		for(i=0,t=strlen(a);i<t;i++)
		printf("%c",s[a[i]]);
		printf("\n");
	}
	return 0;
}

