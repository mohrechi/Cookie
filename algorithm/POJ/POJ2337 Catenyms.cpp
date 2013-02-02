#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int v,vis,next;
	char s[26];
}g[10005];
struct Node
{
	char s[26];
}word[1005];
int in[26],out[26],n,m,e,adj[26],fa[26],used[26];
char res[1005][26];
int cmp(Node a,Node b)
{
	return strcmp(a.s,b.s)>=0;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void eular(int u,int id)
{
	for(int i=adj[u];i!=-1;i=g[i].next)
	{
		if(!g[i].vis)
		{
			g[i].vis=1;
			eular(g[i].v,i);
		}
	}
	if(id!=-1)
		strcpy(res[m++],word[id].s);
}
int judge()
{
    int num=0,cnt1=0,cnt2=0,id=-1;
    for(int i=0;i<26;i++)
    {
    	if(used[i])
    	{
    		if(find(i)==i)
    			num++;
   			if(in[i]!=out[i])
   			{
   				if(in[i]-out[i]==1)
   					cnt1++;
				else if(out[i]-in[i]==1)
				{
					cnt2++;
					id=i;
				}
   				else
   					return -1;
   			}
    	}
    }
    if(num!=1)
    	return -1;
   	if(!((cnt1==1&&cnt2==1)||(cnt1==0&&cnt2==0)))
   		return -1;
	if(id==-1)
	{
		for(int i=0;i<26;i++)
		{
			if(out[i]>0)
			{
				id=i;
				break;
			}
		}
	}
    return id;
}
int main()
{
	int i,j,k,flag,cnt1,cnt2,T,tree;
	scanf("%d",&T);
	while(T--)
	{
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(used,0,sizeof(used));
		memset(g,0,sizeof(g));
		memset(adj,-1,sizeof(adj));
		e=0;
		scanf("%d",&n);
		getchar();
		for(i=0;i<=26;i++)
			fa[i]=i;
		for(i=0;i<n;i++)
		{
			gets(word[i].s);
		}
		sort(word,word+n,cmp);
		for(i=0;i<n;i++)
		{
			g[i].vis=0;
			int u=word[i].s[0]-'a';
			int v=word[i].s[strlen(word[i].s)-1]-'a';
			used[u]=1;
			used[v]=1;
			in[v]++;
			out[u]++;
			g[e].v=v; g[e].next=adj[u]; adj[u]=e++;
			int x=find(u);
			int y=find(v);
			if(x!=y)
				fa[x]=y;
		}
		int start=judge();
		if(start!=-1)
		{
			m=0;
			eular(start,-1);
			for(i=n-1;i>=0;i--)
			{
				printf("%s",res[i]);
				if(i!=0)
					printf(".");
			}
			printf("\n");
		}
		else
			puts("***");
	}
	return 0;
}
