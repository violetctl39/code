#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
ll ten[20],f[20];
ll cnta[20],cntb[20];
void solve(ll x,ll *cnt)
{
	ll num[20]={0};
	int len=0;
	while(x)
		num[++len]=x%10,x=x/10;
	for(int i=len; i>=1; i--)
	{
		for(int j=0; j<=9; j++)
			cnt[j]+=f[i-1]*num[i];
		for(int j=0; j<num[i]; j++)
			cnt[j]+=ten[i-1];
		ll num2=0;
		for(int j=i-1; j>=1; j--)
		{
			num2=num2*10+num[j];
		}
		cnt[num[i]]+=num2+1;
		cnt[0]-=ten[i-1];
	}
}
int main()
{
	scanf("%lld %lld",&a,&b);
	ten[0]=1;
	for(int i=1; i<=15; i++)
	{
		f[i]=f[i-1]*10+ten[i-1];
		ten[i]=10*ten[i-1];
	}
	solve(a-1,cnta);
	solve(b,cntb);
	for(int i=0; i<=9; i++)
		printf("%lld ",cntb[i]-cnta[i]);
}