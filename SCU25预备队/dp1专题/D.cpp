#include<bits/stdc++.h>
using namespace std;
int zhong[1001],jia[1001],a[1001][1001],bb[1001];
int main()
{
	int n,m,zu,mxzu=0; 
	cin>>m>>n;
	for(int i = 1;i <= n;++i)
	{
		cin>>zhong[i]>>jia[i]>>zu;
		a[zu][0]++;
		a[zu][a[zu][0]]=i;
		mxzu=max(mxzu,zu);
	}
	for(int i=1;i<=mxzu;++i)
		for(int j=m;j>=0;j--)
			for(int k=1;k<=a[i][0];++k)
				if(j>=zhong[a[i][k]])
					bb[j]=max(bb[j],bb[j-zhong[a[i][k]]]+jia[a[i][k]]);
	printf("%d\n",bb[m]);
	return 0;
}