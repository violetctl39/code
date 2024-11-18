#include<bits/stdc++.h>
#define pc putchar
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
int lg[1000005];
vector<int>e[1000005];
int f[1000005];

struct cmp{
    bool operator()(int x,int y){
        return f[x]>f[y];
    }
};
void dfs(int x,int fa){
    f[x]=0;int mx=0;
    for(int y:e[x])if(y!=fa){dfs(y,x);mx=max(mx,f[y]+1);}
    int siz=e[x].size()-(x!=1);
    if(siz<=2){f[x]=mx;return;}
    priority_queue<int,vector<int>,cmp>q;
    for(int y:e[x])if(y!=fa)q.push(y);//,cerr<<y<<" : "<<f[y]<<endl;
    while(q.size()>1){
        int u=q.top();q.pop();
        int v=q.top();q.pop();
        f[u]=max(f[u],f[v])+1;q.push(u);
        //cout<<u<<" "<<v<<" "<<f[u]<<endl;
    }f[x]=f[q.top()];q.pop();
    priority_queue<int,vector<int>,cmp>().swap(q);
}
int main(){
    T=read();
    lg[1]=1;for(int i=2;i<=1000000;++i)lg[i]=lg[(i-1)/2]+1;
    while(T--){
        n=read();
        for(int i=1;i<=n;++i)vector<int>().swap(e[i]);
        for(int i=2;i<=n;++i){int x=read();e[x].push_back(i);e[i].push_back(x);}
        dfs(1,0);write(f[1]),pc('\n');

    }

    return 0;
}
/*
1
7
1 1 2 1 1 2


*/