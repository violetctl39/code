#include<cstdio>
#include<algorithm>
#include<iostream>
int n=0,a[100005],f[100005],ans=1,k;
int s[100005],len=1;
int main()
{
	while(~scanf("%d",&k))n++,a[n]=k;
	s[len]=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]<=s[len])	s[++len]=a[i];
		else s[std::upper_bound(s+1,s+len+1,a[i],std::greater<int>())-s]=a[i];
	printf("%d\n",len);
	f[ans]=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]>s[ans])	s[++ans]=a[i];
		else	s[std::lower_bound(s+1,s+ans+1,a[i])-s]=a[i];
	printf("%d",ans);
	return 0;
}