#include<cstdio>
const int mm=1111111;
const int mn=1111;
int t[mm],p[mm];
int h[mn],q[mn],f[mn],sum[mn];
bool vis[mn];
int i,j,k,c,e,n;
int find(int u)
{
    if(f[u]==u)return u;
    else return f[u]=find(f[u]);
}
bool tarjan(int u)
{
    int i,v;
    for(i=q[u];i;i=p[i])
        if(vis[v=t[i]])++sum[find(v)];
    vis[f[u]=u]=1;
    for(i=h[u];i;i=p[i])
        if(!vis[v=t[i]])tarjan(v),f[v]=u;
    return 0;
}
inline bool get(int &a)
{
    char c;
    while(((c=getchar())<'0'||c>'9')&&c!=EOF);
    if(c==EOF)return 0;
    for(a=0;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
    return 1;
}
int main()
{
    while(get(n))
    {
        for(i=1;i<=n;++i)sum[i]=h[i]=q[i]=f[i]=vis[i]=0;
        for(c=e=1;c<=n;++c)
        {
            get(i),get(k);
            while(k--)get(j),++f[t[e]=j],p[e]=h[i],h[i]=e++;
        }
        get(k);
        while(k--)
        {
            get(i),get(j);
            t[e]=j,p[e]=q[i],q[i]=e++;
            t[e]=i,p[e]=q[j],q[j]=e++;
        }
        for(i=1;i<=n;++i)
            if(!f[i])tarjan(i);
        for(i=1;i<=n;++i)
            if(sum[i])printf("%d:%d\n",i,sum[i]);
    }
    return 0;
}
