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
const int mod=1e9+7;
int n,m;
vector<int>e[200005],E[200005];
priority_queue< pair<int,int> >q;
int dis[200005];
int in[200005];
bool vis[200005];
void dk(){
    fill(dis+1,dis+n+1,mod);dis[1]=0;
    q.push({0,1});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue; vis[u]=true;
        for(int v:e[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push({-dis[v],v});
            }
        }
    }
}
queue<int>Q;
int f[200005];
signed main(){
    n=read(),m=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }dk();
    for(int i=1;i<=n;++i){
        for(int j:e[i]){
            if(dis[j]==dis[i]+1)E[i].push_back(j),in[j]++;
        }
    }
    Q.push(1);f[1]=1;
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        for(int y:E[x]){
            f[y]=(f[y]+f[x])%mod;
            in[y]--;if(!in[y])Q.push(y);
        }
    }write(f[n]),pc('\n');
    return 0;
}