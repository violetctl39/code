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

int n,ans;
struct node{
    int v,w;
};
int val[100005];
vector<node>e[100005];
void dfs(int x,int f){
    for(auto [y,w]:e[x]){
        if(y==f)continue;
        val[y]=val[x]^w;
        dfs(y,x);
    }
}
int tr[2000005][2],cnt=1;
int p2[32];
void insert(int x){
    int pos=1;
    for(int i=31;i>=0;--i){
        int f=(x&p2[i])!=0;
        if(!tr[pos][f])tr[pos][f]=++cnt;
        pos=tr[pos][f];
    }
}
int find(int x){
    int pos=1,res=0;
    for(int i=31;i>=0;--i){
        int f=(x&p2[i])!=0;
        if(tr[pos][f^1])res+=p2[i],pos=tr[pos][f^1];
        else pos=tr[pos][f];
    }return res;
}
int main(){
    n=read();
    for(int i=1;i<n;++i){
        int u=read(),v=read(),w=read();
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,0);p2[0]=1;
    for(int i=1;i<=31;++i)p2[i]=p2[i-1]<<1;
    for(int i=1;i<=n;++i)insert(val[i]);
    for(int i=1;i<=n;++i)ans=max(ans,find(val[i]));
    write(ans),pc('\n');
    return 0;
}