#include<cstdio>
#include<iostream>
using namespace std;
int f[200002],d[200002],n,minn,last; 
int fa(int x)
{
	if (f[x]!=x)                      
	{
		int last=f[x];                
		f[x]=fa(f[x]);                
		d[x]+=d[last];                
	}
	return f[x];
}
void check(int a,int b)
{
	int x=fa(a),y=fa(b);            
	if (x!=y)
	{
		f[x]=y;    
		d[a]=d[b]+1;
	}
	else minn=min(minn,d[a]+d[b]+1); 
	return;
}
int main()
{
	int i,t;
	scanf("%d",&n);
	for (i=1; i<=n; i++) f[i]=i;    
	minn=0x7777777;
	for (i=1; i<=n; i++)
	{
		scanf("%d",&t);
		check(i,t);                
	}
	printf("%d",minn);
	return 0;
}