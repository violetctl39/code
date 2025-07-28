#include<bits/stdc++.h>
using namespace std;
int b[1001],le[1001],ri[1001],n,ans=0x7f;
void lis1()
{
	int f[1005],len=1;
	f[1]=b[1];
	le[1]=1;
	for(int i=2; i<=n; i++)
	{
		if(f[len]<b[i]) f[++len]=b[i];
		else 			f[lower_bound(f+1,f+len+1,b[i])-f]=b[i];
		le[i]=len;
	}
}
void lis2()
{
	int f[1005],len=1;
	f[1]=b[n];
	for(int i=n-1; i>=1; i--)
	{
		if(f[len]<b[i]) f[++len]=b[i];
		else 			f[lower_bound(f+1,f+len+1,b[i])-f]=b[i];
		ri[i]=len;
	}
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++) cin>>b[i];
	lis1(),lis2();
	for(int i=1; i<=n; i++)
		ans=min(ans,n-le[i]-ri[i+1]);
	cout<<ans;
	return 0;
}