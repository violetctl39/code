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

int a[200005];
int quickPow(int x,int y,int mod){
    int res=1,bs=1,in=x,lim=log2(y);
    for(int i=0;i<=lim;++i){
        printf("%d^%d=%d : %d\n",in,bs,x,(y&bs)!=0);
        if((y&bs)!=0)res=res*x%mod; x=x*x%mod;
        bs=bs*2ll;
    }
    return res;
}
int Phi(int x){
	int res=0;
	for(int i=1;i<x;++i){
		if(__gcd(i,x)==1)++res;
	}
	return res;
}
signed main(){
    int p,q,d,e;
    printf("input:\n");
    printf("p = ");p=read();
    printf("q = ");q=read();
    int n=p*q,t=(p-1)*(q-1);
    printf("d = ");d=read();
    printf("Phi(%d) = %d\n",t,Phi(t));
    e=quickPow(d,Phi(t)-1,t);
    printf("e = %d\n",e);

    int m=65;
    cout<<quickPow(m,e,n)<<endl;
    cout<<quickPow(quickPow(m,e,n),d,n)<<endl;
    return 0;
}