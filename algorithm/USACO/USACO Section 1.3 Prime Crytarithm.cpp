/*
ID: cyberzh1
LANG: C++
TASK: crypt1
*/
#include<stdio.h>
int a[10],n;
bool judge(int num)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            return true;
        }
    }
    return false;
}

bool check(int num)
{
    while(num>0)
    {
        if(not judge(num%10))
        {
            return false;
        }
        num/=10;
    }
    return true;
}

int main()
{
    FILE* fin=fopen("crypt1.in","r");
    FILE* fout=fopen("crypt1.out","w");
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d",&a[i]);
    }
    int b[5],count=0;
    for(b[0]=0;b[0]<n;b[0]++)
    {
        for(b[1]=0;b[1]<n;b[1]++)
        {
            for(b[2]=0;b[2]<n;b[2]++)
            {
                for(b[3]=0;b[3]<n;b[3]++)
                {
                    for(b[4]=0;b[4]<n;b[4]++)
                    {
                        int num1=a[b[0]]*100+a[b[1]]*10+a[b[2]];
                        int num2=a[b[3]]*num1;
                        if(num2<100 or num2>999) continue;
                        int num3=a[b[4]]*num1;
                        if(num3<100 or num3>999) continue;
                        int num4=num2*10+num3;
                        if(num4<1000 or num4>9999) continue;
                        if(check(num2) and check(num3) and check(num4))
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }
    fprintf(fout,"%d\n",count);
    return 0;
}
