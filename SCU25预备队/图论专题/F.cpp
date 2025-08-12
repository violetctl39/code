#include<bits/stdc++.h>
#define pc(x) putchar(x)
using namespace std;
#define int long long
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=ch=='-'?-1:f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
void write(int x)
{
	if(x<0){x=-x;pc('-');}
	if(x>9)write(x/10);
	pc(x%10+48);
}
const int inf=4187201950435737472;
int n,m,k,ans;
int val[2505];
vector<int>e[2505];
bool a[2505][2505];
int dis[2505];bool vis[2505];
priority_queue< pair<int,int> >q;
void dk(int s)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,false,sizeof vis);
	q.push({0,s});dis[s]=0;
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])continue; vis[u]=true;
		for(int v:e[u])
			if(dis[v]>dis[u]+1)
				{dis[v]=dis[u]+1;q.push({-dis[v],v});}
	}
	for(int t=1;t<=n;++t)
		if(dis[t]>0&&dis[t]<=k+1)a[s][t]=true;
}
int pmx[2505][2505],pmn[2505][2505],smx[2505][2505],smn[2505][2505];
signed main()
{
	n=read(),m=read(),k=read();val[0]=-inf;
	for(int i=2;i<=n;++i)val[i]=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}for(int i=1;i<=n;++i)dk(i);
	
	for(int i=2;i<=n;++i)
	{
		int mx=0,mn=0;
		for(int j=1;j<=n;++j)
		{
			if(val[mx]>val[pmx[i][j]])pmn[i][j]=pmx[i][j],pmx[i][j]=mx;
			else if(val[mx]>val[pmn[i][j]])pmn[i][j]=mx;
			if(val[mn]>val[pmx[i][j]])pmn[i][j]=pmx[i][j],pmx[i][j]=mn;
			else if(val[mn]>val[pmn[i][j]])pmn[i][j]=mn;
			if(!a[1][j]||!a[j][i]||i==j)continue;
			if(val[j]>val[mx])mn=mx,mx=j;
			else if(val[j]>val[mn])mn=j;
		}mx=0,mn=0;
		for(int j=n;j>=1;--j)
		{
			if(val[mx]>val[pmx[i][j]])pmn[i][j]=pmx[i][j],pmx[i][j]=mx;
			else if(val[mx]>val[pmn[i][j]])pmn[i][j]=mx;
			if(val[mn]>val[pmx[i][j]])pmn[i][j]=pmx[i][j],pmx[i][j]=mn;
			else if(val[mn]>val[pmn[i][j]])pmn[i][j]=mn;
			if(!a[1][j]||!a[j][i]||i==j)continue;
			if(val[j]>val[mx])mn=mx,mx=j;
			else if(val[j]>val[mn])mn=j;
		}
	}
	for(int i=2;i<=n;++i)
	{
		int mx=0,mn=0;
		for(int j=1;j<=n;++j)
		{
			if(val[mx]>val[smx[i][j]])smn[i][j]=smx[i][j],smx[i][j]=mx;
			else if(val[mx]>val[smn[i][j]])smn[i][j]=mx;
			if(val[mn]>val[smx[i][j]])smn[i][j]=smx[i][j],smx[i][j]=mn;
			else if(val[mn]>val[smn[i][j]])smn[i][j]=mn;
			if(!a[j][1]||!a[i][j]||i==j)continue;
			if(val[j]>val[mx])mn=mx,mx=j;
			else if(val[j]>val[mn])mn=j;
		}mx=0,mn=0;
		for(int j=n;j>=1;--j)
		{
			if(val[mx]>val[smx[i][j]])smn[i][j]=smx[i][j],smx[i][j]=mx;
			else if(val[mx]>val[smn[i][j]])smn[i][j]=mx;
			if(val[mn]>val[smx[i][j]])smn[i][j]=smx[i][j],smx[i][j]=mn;
			else if(val[mn]>val[smn[i][j]])smn[i][j]=mn;
			if(!a[j][1]||!a[i][j]||i==j)continue;
			if(val[j]>val[mx])mn=mx,mx=j;
			else if(val[j]>val[mn])mn=j;
		}
	}
	for(int i=2;i<=n;++i)
		for(int j=2;j<=n;++j)
		{
			if(i==j||!a[i][j])continue;
			if(pmx[i][j]==smx[j][i])ans=max(ans,val[i]+val[j]+max(val[pmx[i][j]]+val[smn[j][i]],val[pmn[i][j]]+val[smx[j][i]]));
			else ans=max(ans,val[i]+val[j]+val[pmx[i][j]]+val[smx[j][i]]);
		}
	write(ans),pc('\n');
	return 0;
}