#include<bits/stdc++.h>
using namespace std;
int t,m,a[1005],ttm[1005],f[1005][1005];
int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>ttm[i]>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=t;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=ttm[i])
			{
				f[i][j]=max(f[i][j],f[i-1][j-ttm[i]]+a[i]);
			}
		}
	}
	cout<<f[m][t];
	return 0;
}