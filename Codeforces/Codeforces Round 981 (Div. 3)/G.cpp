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
int mi[20];
int T,n;
vector<int>e[200005];
int lg[200005],dep[200005];
int fa[200005][18];
int mx[200005];
void dfs(int x,int f){
    fa[x][0]=f;dep[x]=dep[f]+1;mx[x]=dep[x];
    for(int i=1;i<=lg[n];++i)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int y:e[x]){
        if(y==f)continue;
        dfs(y,x);mx[x]=max(mx[x],mx[y]);
    }
}
int main(){
    T=read();mi[0]=1;
    for(int i=1;i<=18;++i)mi[i]=mi[i-1]<<1;
    for(int i=2;i<=200000;++i)lg[i]=lg[i>>1]+1;
    while(T--){
        n=read();
        for(int i=1;i<=n;++i)
            vector<int>().swap(e[i]);
        for(int i=1;i<n;++i){
            int u=read(),v=read();
            e[u].push_back(v);
            e[v].push_back(u);
        }dfs(1,0);
        int q=read();
        while(q--){
            int x=read(),y=read(),f=x;
            for(int i=lg[n];i>=0;--i)
                if((y&mi[i])!=0)f=fa[f][i];
            write(mx[f]-dep[x]),pc('\n');
        }pc('\n');
    }

    return 0;
}