#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100005;

struct File
{
	char name[25];
	int index;
	bool operator < (const File &f) const
	{
	    return strcmp(name, f.name) < 0;
	}
}file[MAXN];

char ans[MAXN][25];

int main()
{
	int n;
	bool flag = false;
	while(~scanf("%d\n",&n))
	{
		for(int i=0;i<n;++i)
		{
			gets(file[i].name);
			file[i].index = i;
		}
		if(flag)
		{
		    printf("\n");
		}
		else
		{
		    flag = true;
		}
		if(1 == n)
		{
            printf("\n");
            continue;
		}
		sort(file, file + n);
		for(int i = 0;i<n;++i)
		{
			int len = strlen(file[i].name);
			bool flag1 = false;
			bool flag2 = false;
			int j;
			for(j=0;j<len;++j)
			{
				if(i-1 < 0 || file[i-1].name[j] != file[i].name[j])
				{
				    flag1 = true;
				}
				if(i+1 >= n || file[i+1].name[j] != file[i].name[j])
				{
				    flag2 = true;
				}
				if(flag1 && flag2)
				{
				    break;
				}
			}
			if(j == len)
			{
			    strcpy(ans[file[i].index] , "Can't find!");
			}
			else
			{
				strncpy(ans[file[i].index], file[i].name, j+1);
				ans[file[i].index][j+1] = 0;
			}
		}
		for(int i=0;i<n;++i)
		{
		    if(i)
		    {
		        printf(" ");
		    }
		    printf("%s", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
