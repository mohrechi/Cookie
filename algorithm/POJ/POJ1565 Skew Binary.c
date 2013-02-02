#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
    char two[33];
    int i,j,sum;
    while(1)
    {
        scanf("%s",two);
        if(two[0]=='0')break;
        sum=0,i=0;
        while(two[i]!='\0')i++;
        j=0;
        while(i>0)
        {
            if(two[j]=='1')sum+=(int)pow(2,i)-1;
            if(two[j]=='2')sum+=(int)pow(2,i)*2-2;
            j++,i--;
        }
        printf("%d\n",sum);
    }
    return 0;
}
