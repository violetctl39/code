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
int n,k;
int f[1000005][3],sum[3];
signed main(){
    n=read(),k=read();
    if(k>1)f[1][0]=sum[0]=1;
    f[1][2]=sum[2]=1;
    for(int i=2;i<k;++i)f[i][0]=1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<3;++j)
            if(i>=k+1)sum[j]=(sum[j]+mod-f[i-k][j])%mod;
        for(int j=0;j<2;++j)
            f[i][j]=(f[i][j]+sum[j^1]+sum[2])%mod;
        f[i][2]=(f[i-1][0]+f[i-1][1]+f[i-1][2])%mod;
        for(int j=0;j<3;++j)sum[j]=(sum[j]+f[i][j])%mod;
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=0;j<3;++j)
    //         cerr<<f[i][j]<<" ";
    //     cerr<<endl;
    // }
    write((f[n][0]+f[n][1]+f[n][2])%mod),pc('\n');
    return 0;
}