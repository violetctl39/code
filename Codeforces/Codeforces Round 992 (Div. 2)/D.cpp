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

int T,n,m,ans;
int a[200005];
int pri[400005],cnt;
bool vis[400005];
int can[400005];
vector<int>e[200005];
queue<int>q;
void dfs(int x,int f){
    if(x==1){a[x]=1;vis[1]=true;}
    else{
        for(int i=1;i<=cnt;++i)
            if(a[f]+p)
    }

}
void solve(){
    n=read();a[0]=-2;fill(a+1,a+n+1,0);
    fill(vis+1,vis+2*n+1,false);
    while(!q.empty())q.pop();
    for(int i=1;i<=n;++i)e[i].clear(),a[i]=0;
    for(int i=1;i<n;++i){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;++i)q.push(i*2);
    dfs(1,0);
    for(int i=1;i<=n;++i)write(a[i]),pc(' ');pc('\n');
}
signed main(){
    T=read();
    for(int i=2;i<=400000;++i){
        if(!vis[i])pri[++cnt]=i;
        for(int j=1;j<=cnt&&pri[j]*i<=400000;++j){
            vis[i*pri[j]]=true;
            if(i%pri[j]==0)break;
        }
    }cnt=0;
    for(int i=1;i<=400000;++i)if(!vis[i])t[++cnt]=i;
    while(T--){
        solve();
    }

    return 0;
}