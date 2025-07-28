#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=ch=='-'?-1:f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,ans;
int s[500005];
struct node
{
	int id,rk,val;
	friend bool operator < (const node &x,const node &y)
	{return x.val<y.val;}
};priority_queue<node>q;
struct trie
{
	int siz,ch[2];
}tr[30000000];
int cnt=1;
void insert(int x)
{
	int pos=1;
	for(int i=31;i>=0;--i)
	{
		int son=(x>>i)&1;
		if(!tr[pos].ch[son])tr[pos].ch[son]=++cnt;
		pos=tr[pos].ch[son];tr[pos].siz++;
	}
}
int query(int x,int rk)
{
	int pos=1,res=0;
	for(int i=31;i>=0;--i)
	{
		int son=(x>>i)&1;
		if(!tr[pos].ch[son^1])pos=tr[pos].ch[son];
		else if(rk<=tr[tr[pos].ch[son^1]].siz)pos=tr[pos].ch[son^1],res|=1ll<<i;
		else rk-=tr[tr[pos].ch[son^1]].siz,pos=tr[pos].ch[son];
	}return res;
}
signed main()
{
	n=read(),m=read()*2;
	for(int i=1;i<=n;++i)
	{
		int tmp=read();s[i]=s[i-1]^tmp;
		insert(s[i]);
	}insert(0);
	for(int i=0;i<=n;++i)q.push((node){i,1,query(s[i],1)});
	for(int i=1;i<=m;++i)
	{
		node tmp=q.top();ans+=tmp.val;q.pop();
		if(tmp.rk<n)q.push((node){tmp.id,tmp.rk+1,query(s[tmp.id],tmp.rk+1)});
	}
	printf("%lld\n",ans>>1);
	return 0;
}