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

int qpow(int x,int y,int mod){
	int res=1,tmp=y;x%=mod;
	for(int i=0,bs=1;i<=30;++i){
		if((y&bs)!=0){
			write(bs),pc(' ');
			write(x),pc('\n');
			res=res*x%mod;
		}
		bs<<=1ll;x=x*x%mod;
	}return res;
}

signed main(){
	cout<<qpow(17,39,264)<<endl;
	cout<<qpow(65,233,299)<<endl;
	cout<<qpow(260,17,299)<<endl;
	return 0;
}