#include <iostream>
using namespace std;
void count(char a[],int sum[])
{
    int i;
    for (i=0;i<strlen(a);i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
        sum[a[i]-'A'+1]++;
    }
}

main()
{
    char a[75],b[75],c[75],d[75];
    int sum[27]={0},max,i,j,flag;
    cin.getline(a,75);
    cin.getline(b,75);
    cin.getline(c,75);
    cin.getline(d,75);
    count(a,sum);
    count(b,sum);
    count(c,sum);
    count(d,sum);
    max=sum[1];
    for (i=1;i<=26;i++)
    if(sum[i]>max)
    max=sum[i];
    for (i=max;i>=1;i--)
    {
        for (j=1;j<=26;j++)
        if(sum[j]==i)
        flag=j;
        for (j=1;j<=26;j++)
        {
            if(sum[j]==i)
            {
                j<flag?cout<<"* ":cout<<"*";
                sum[j]--;
            }
            else
            j<flag?cout<<"  ":cout<<" ";
            if(j==flag)
            {
                cout<<endl;break;
            }
        }
    }
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
    return 0;
}


