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

int T,n,m,ans,cnt;
int a[200005],c[200005];
int lg[200005],pw[20];
int f[200005][19],s[200005][19];
int qry(int x,int y){
    int len=y-x+1;
    return gcd(f[x][lg[len]],f[y-pw[lg[len]]+1][lg[len]]);
}
bool check(int x,int y){
    int len=y-x+1;
    return s[x][lg[len]]+s[y-pw[lg[len]]+1][lg[len]];
}
void solve(){
    n=read();int q=read();
    for(int i=0;i<=lg[n];++i)for(int j=1;j<=n;++j)f[i][j]=1,s[i][j]=false;
    for(int i=1;i<=n;++i)a[i]=read(),c[i]=abs(a[i]-a[i-1]),f[i][0]=c[i],s[i][0]=c[i];
    for(int i=1,tmp=1;i<=lg[n];++i){
        for(int j=1;j+tmp<=n;++j)
            f[j][i]=gcd(f[j][i-1],f[j+tmp][i-1]),s[j][i]=s[j][i-1]+s[j+tmp][i-1];
        tmp*=2;
    }
    while(q--){
        int l=read(),r=read();
        if(l==r||!check(l+1,r)){write(0),pc(' ');continue;}
        int res=qry(l+1,r);
        write(res),pc(' ');
    }pc('\n');
}
signed main(){
    T=read();lg[1]=0;pw[0]=1;
    for(int i=1;i<=18;++i)pw[i]=pw[i-1]<<1;
    for(int i=2;i<=200000;++i)lg[i]=lg[i>>1]+1;
    while(T--){
        solve();
    }    
    return 0;
}