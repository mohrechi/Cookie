#include<stdio.h>
#include<string.h>
#include<math.h>

int main(int argc, char* argv[])
{
    int     n,i,j,a[12],max;
    char  s1[25],s2[25],s3[25];
    scanf("%d",&n);
    while(n--)
    {
        for(i=0;i<12;i++) a[i]=0;
        i=3;
        while(i--)
        {
            scanf("%s%s%s",s1,s2,s3);
            if(strcmp(s3,"even")==0)
            {
                j=0;
                while(s1[j]!='\0')
                {
                    a[s1[j]-'A']+=10000;
                    a[s2[j]-'A']+=10000;
                    j++;
                }
            }
            if(strcmp(s3,"up")==0)
            {
                j=0;
                while(s1[j]!='\0')
                {
                    a[s1[j]-'A']++;
                    a[s2[j]-'A']--;
                    j++;
                }
            }
            if(strcmp(s3,"down")==0)
            {
                j=0;
                while(s1[j]!='\0')
                {
                    a[s1[j]-'A']--;
                    a[s2[j]-'A']++;
                    j++;
                }
            }
        }
        max=0;
        for(i=0;i<12;i++)
        {
            if(abs(a[i])>max&&a[i]<1000)
            {
                j=i;
                max=abs(a[i]);
            }
        }
        printf("%c is the counterfeit coin and it is ",j+'A');
        if(a[j]>0)
        {
            printf("heavy.\n");
        }
        else
        {
            printf("light.\n");
        }
    }
    return 0;
}
