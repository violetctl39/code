#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=ch=='-'?-1:f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,ans=0x3f3f3f3f;
int a[105][105];
int b[105][105];
int main()
{
	n=read(),m=read();
	memset(a,0x3f,sizeof a);memset(b,0x3f,sizeof b);
	for(int i=1;i<=n;++i)a[i][i]=b[i][i]=0;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		a[u][v]=min(a[u][v],w);a[v][u]=min(a[v][u],w);
		b[u][v]=min(b[u][v],w);b[v][u]=min(b[v][u],w);
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<k;++i)
			for(int j=i+1;j<k;++j)
				ans=min((ll)ans,(ll)a[i][j]+b[i][k]+b[k][j]);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				a[i][j]=min((ll)a[i][j],(ll)a[i][k]+a[k][j]),a[j][i]=a[i][j];
	}
	if(ans==0x3f3f3f3f)puts("No solution.");
	else printf("%d\n",ans);
	return 0;
}