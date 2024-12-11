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
int a[200005],lst;
vector<int>e[200005];
void dfs(int x,int f){
    for(int y:e[x]){
        if(y==f)continue;
        a[y]=lst+1;
        while(a[y]-a[x]!=1&&a[y]%2!=a[x]%2||a[y]-a[x]==2)++a[y];
        lst=a[y];dfs(y,x);
    }
}
void solve(){
    n=read();a[1]=1;lst=1;
    for(int i=1;i<=n;++i)e[i].clear();
    for(int i=1;i<n;++i){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }dfs(1,0);
    for(int i=1;i<=n;++i)write(a[i]),pc(' ');pc('\n');
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}