#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double temperature,h,e,dewpoint,humidex;
    double f1,f2;
    char a,b;
    while(cin>>a)
    {
        if(a=='E')
            break;
        cin>>f1;
        cin>>b;
        cin>>f2;
        switch (a+b)
        {
            case 'T'+'D':
                temperature=(a=='T')?f1:f2;
                dewpoint=(b=='D')?f2:f1;
                e=6.11*pow(2.718281828,(5417.7530*((1/273.16)-(1/(dewpoint+273.16)))));
                h=(0.5555)*(e-10.0);
                humidex=temperature+h;
                break;
            case 'T'+'H' :
                temperature=(a=='T')?f1:f2;
                humidex=(b=='H')?f2:f1;
                h = humidex - temperature;
                e = ( float )( h / (0.5555) + 10.0);
                dewpoint = ( float )( 1/(- log(e / 6.11) / 5417.7530 + 1/273.16)-273.16);
                break;
            case 'D'+'H' :
                dewpoint=(a=='D')?f1:f2;
                humidex=(b=='H')?f2:f1;
                e=6.11*pow(2.718281828,(5417.7530*((1/273.16)-(1/(dewpoint+273.16)))));
                h=(0.5555)*(e-10.0);
                temperature=humidex-h;
                break;
        }
        printf("T %0.1f D %0.1f H %0.1f\n",temperature,dewpoint,humidex);
    }
    return 0;
}
