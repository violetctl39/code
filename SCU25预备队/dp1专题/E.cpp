#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX 
int n,a[205],f[205][205],f2[205][205],sum[205][205],ans1=inf,ans2=-inf;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1;i<=n*2;i++)
		for(int j=1;j<=n*2;j++)
			for(int k=i;k<=j;k++)
				sum[i][j]+=a[k];
	for(int i=1;i<=n;i++) 
		f[i][i]=f2[i][i]=0;
	for(int l=1;l<n;l++)
	{
		for(int i=1,j=i+l;i<n*2&&j<n*2;i++,j=i+l)
		{
			f[i][j]=inf; 
			for(int k=i;k<j;k++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[i][j]);
				f2[i][j]=max(f2[i][j],f2[i][k]+f2[k+1][j]+sum[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans1=min(ans1,f[i][i+n-1]);
		ans2=max(ans2,f2[i][i+n-1]);
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}
