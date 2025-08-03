#include<bits/stdc++.h>
using namespace std;
int n,rt;
int cnt=0;
int ans=0;
struct node
{
	int data,f;
	vector < int > v;
} a[6006];
int f[6006][2];
void find(int x)
{
	if(!a[x].f)
	{
		rt=x;
		return;
	}
	find(a[x].f);
	return;
}
void dp(int x)
{
	if(a[x].v.empty())
	{
		f[x][1]=a[x].data;
		return;
	}
	int sum1=0,sum2=0;
	for(int i=0; i<a[x].v.size(); i++)
	{
		dp(a[x].v[i]);
		sum1+=max(f[a[x].v[i]][0],f[a[x].v[i]][1]);
		sum2+=f[a[x].v[i]][0];
	}
	f[x][1]=sum2+a[x].data;
	f[x][0]=sum1;
	return;
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)	cin>>a[i].data;
	for(int i=1; i<=n-1; i++)
	{
		int l,k;
		cin>>l>>k;
		a[k].v.push_back(l);
		a[l].f=k;
	}
	int qq,ww;
	cin>>qq>>ww;
	find(1);
	dp(rt);
	cout<<max(f[rt][0],f[rt][1]);
	return 0;
}