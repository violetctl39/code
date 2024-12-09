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
int T,n,q,ans,cnt;
int a[200005];
vector<int>e[200005];
int d[200005];
int t[200005];
int fa[200005];
void dfs(int x,int f){
    fa[x]=f;
    for(int y:e[x]){
        if(y==f)continue;
        dfs(y,x);
    }
}
void solve(){
    n=read(),q=read();
    for(int i=1;i<=n;++i)e[i].clear();
    fill(d+1,d+n+1,0);
    for(int i=1;i<n;++i){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
        d[u]++;d[v]++;
    }dfs(1,0);
    while(q--){
        int v=read(),p=read();cnt=0;
        while(fa[fa[v]]){v=fa[v];t[++cnt]=v;v=fa[v];}
        sort(t+1,t+cnt+1,[](int x,int y){return d[x]>d[y];});ans=2*min(p,cnt);
        for(int i=p+1;i<=cnt;++i)ans=(ans+2*d[t[i]])%mod;
        if(v!=1)++ans;ans%=mod;
        write(ans),pc('\n');

    }
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}