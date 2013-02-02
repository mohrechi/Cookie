#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    char haab[21][20]={"","pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    char holly[22][20]={"ahau","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
    char m[10];
    int n,day,month,year,all,i;
    scanf("%d",&n);
    printf("%d\n",n);
    while(n--)
    {
        scanf("%d. %s%d",&day,m,&year);
        all=year*365;
        for(i=0;i<20;i++)
        {
            if(!strcmp(m,haab[i]))break;
        }
        all+=(day+i*20-19);
        year=all/260;
        all-=year*260;
        if(all==0)year--;
        day=all%13;
        if(day==0)day=13;
        printf("%d %s %d\n",day,holly[all%20],year);
    }
    return 0;
}
