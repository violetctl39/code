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
int n,k,ans;
int f[1000005][2],sum[2];
int fac[1000005];
int qpow(int x,int y=mod-2){
    int res=1;
    while(y){
        if(y&1)res=res*x%mod;
        x=x*x%mod;y>>=1;
    }return res;
}
int C(int x,int y){return fac[x]*qpow(fac[y])%mod*qpow(fac[x-y])%mod;}
signed main(){
    n=read(),k=read();ans=1;fac[0]=1;
    for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
    if(k>1)f[1][0]=sum[0]=1;
    for(int i=2;i<k;++i)f[i][0]=1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<2;++j)
            if(i>=k+1)sum[j]=(sum[j]+mod-f[i-k][j])%mod;
        for(int j=0;j<2;++j)
            f[i][j]=(f[i][j]+sum[j^1])%mod;
        for(int j=0;j<2;++j)sum[j]=(sum[j]+f[i][j])%mod;
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=0;j<3;++j)
    //         cerr<<f[i][j]<<" ";
    //     cerr<<endl;
    // }
    for(int i=1;i<=n;++i)f[i][0]=(f[i][0]+f[i][1])%mod;
    for(int i=1;i<=n;++i){
        ans=(ans+f[i][0]*C(n,i)%mod)%mod;
    }
    write(ans),pc('\n');
    return 0;
}