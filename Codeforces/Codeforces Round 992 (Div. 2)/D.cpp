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
int a[200005];
vector<int>e[200005];
queue<int>q;
void dfs(int x,int f){
    if(abs(a[f]-q.front())==2){
        int v=q.front();q.pop();q.push(v);
        if(q.size()>1){a[x]=q.front();q.pop();}
        else {a[x]=a[f]-1;return;}
    }else{
        a[x]=q.front();q.pop();
    }
    for(int y:e[x]){
        if(y==f)continue;
        dfs(y,x);
    }

}
void solve(){
    n=read();a[0]=-2;fill(a+1,a+n+1,0);
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
    while(T--){
        solve();
    }

    return 0;
}