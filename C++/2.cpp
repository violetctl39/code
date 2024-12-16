#include<bits/stdc++.h>
#define pc putchar
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){f=c=='-'?-1:f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){x=-x;pc('-');}
	if(x>9)write(x/10);
	pc(x%10+48);
}
const int mod=998244353;
int n,m;
int a[100005];
int f[100005],g[100005];
struct node{
	int l,r,f,g;
}t[700];
int cnt,p[100005];
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	int l=1;
	while(l<m){
		int r=m/(m/l);t[++cnt].l=l;
		if(r<m)t[cnt].r=r;
		else {t[cnt].r=m-1;break;}
		l=r+1;
	}
	for(int i=1;i<=cnt;++i)
		for(int j=t[i].l;j<=t[i].r;++j)
			p[j]=i;
	t[1].f=0;t[1].g=1;
	for(int i=1;i<=n;++i){
		f[i]=(f[i-1]*2+g[i-1]*a[i])%mod;g[i]=g[i-1]*2%mod;
		for(int j=cnt;j;--j){
			if((m-1)/t[j].l+1<=a[i])f[i]=(f[i]+t[j].f+t[j].g*a[i])%mod,g[i]=(g[i]+t[j].g)%mod;
			else t[p[t[j].l*a[i]]].f+=t[j].f+t[j].g*a[i]%mod,t[p[t[j].l*a[i]]].g+=t[j].g;
		}
	}
	for(int i=1;i<=n;++i)write(f[i]),pc('\n');

	return 0;
}