#include<bits/stdc++.h>
#define int long long
#define not_intersect(now,prev)	((now&prev)==0)
#define fit(now,flag)	((now|flag)==flag)
#define ok(x)	((x&(x/2))==0)
using namespace std;
const int MAX_N=20;
const int MAX_M=20;
int state[MAX_N+1],dp[MAX_N+1][1<<MAX_M],flag,ans;
signed main()
{
	int n, m;
	cin>>n>>m;
	for (int i=1; i<=n; ++i)
		for (int j=0; j<m; ++j)
			cin>>flag,state[i]|=(1<<j)*flag;
	for (int j=0; j<(1<<m); ++j)
		if (!ok(j)||!fit(j,state[1]))	continue;
		else dp[1][j]=1;
	for (int i=2; i<=n; ++i)
		for (int j=0; j<(1<<m); ++j)
			if (ok(j)&&fit(j,state[i]))
				for (int k=0; k<(1<<m); ++k)
					if (ok(k) && fit(k, state[i-1]) && not_intersect(j,k))
						dp[i][j]+=dp[i-1][k],dp[i][j]%=100000000;
	for (int i=0; i<(1<<m); ++i)
		ans+=dp[n][i],ans%=100000000;
	cout<<ans;
	return 0;
}