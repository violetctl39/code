#include<bits/stdc++.h>
#define pc putchar
using namespace std;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){f=c=='-'?-1:f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
	return x*f;
}
void write(int x)
{
	if(x<0){x=-x;pc('-');}
	if(x>9)write(x/10);
	pc(x%10+48);
}
int n,q;
int prm[100000005],cnt;
bool vis[100000005];
void init()
{
	vis[1]=true;
	for(int i=2;i<=n;++i)
	{
		if(!vis[i])prm[++cnt]=i;
		for(int j=1;j<=cnt&&(long long)prm[j]*i<=n;++j)
		{
			vis[prm[j]*i]=true;
			if(i%prm[j]==0)break;
		}
	}
}

int main()
{
	n=read(),q=read();init();
	while(q--)
	{
		int k=read();
		write(prm[k]),pc('\n');
	}

	return 0;
}