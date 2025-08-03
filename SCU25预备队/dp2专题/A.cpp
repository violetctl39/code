#include<bits/stdc++.h>
#define pc(x) putchar(x)
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=ch=='-'?-1:f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
void write(int x)
{
	if(x<0){x=-x;pc('-');}
	if(x>9)write(x/10);
	pc(x%10+48);
}
int n,ans,a[16005],mx[16005],fmx[16005];
vector<int>e[16005];
void dfs1(int x,int f)
{
	mx[x]=a[x];
	for(int y:e[x])
	{
		if(y==f)continue;
		dfs1(y,x);mx[x]+=mx[y]*(mx[y]>0);
	}
}
void dfs2(int x,int f)
{
	for(int y:e[x])
	{
		if(y==f)continue;
		int tmp=fmx[x]-mx[y]*(mx[y]>0);
		fmx[y]=mx[y]+tmp*(tmp>0);
		dfs2(y,x);
	}ans=max(ans,fmx[x]);
}
signed main()
{
	n=read();int mxa=-1e9;
	for(int i=1;i<=n;++i)a[i]=read(),mxa=max(mxa,a[i]);
	if(mxa<=0){write(mxa),pc('\n');return 0;}
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}dfs1(1,0);fmx[1]=mx[1];dfs2(1,0);
	write(ans),pc('\n');
	return 0;
}