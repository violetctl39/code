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
int d[200005],f[200005];
vector<int>e[200005];
void dfs(int x,int fa){
    f[x]=d[x];ans=max(ans,f[x]);
    for(int y:e[x]){
        if(y==fa)continue; dfs(y,x);
        ans=max(ans,f[x]+f[y]-2);
        f[x]=max(f[x],f[y]+d[x]-2);
    }
}
void solve(){
    n=read();ans=0;
    for(int i=1;i<=n;++i)vector<int>().swap(e[i]),d[i]=0;
    for(int i=1;i<n;++i){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
        d[u]++;d[v]++;
    }
    dfs(1,0);write(ans),pc('\n');
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}