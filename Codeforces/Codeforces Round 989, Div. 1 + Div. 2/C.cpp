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
char s[1005][1005];
int vis[1005][1005];
bool bk[1005][1005];
int d[200][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y){
    if(bk[x][y]){vis[x][y]=1;return;}
    bk[x][y]=true;
    int tx=x+d[s[x][y]][0],ty=y+d[s[x][y]][1];
    if(vis[tx][ty]==-1){
        if(s[tx][ty]=='?')vis[x][y]=1;
        else{dfs(tx,ty);vis[x][y]=vis[tx][ty];}
        
    }
    else vis[x][y]=vis[tx][ty];
}

int check(int x,int y){
    for(int i=0;i<4;++i){
        int tx=x+d[i][0],ty=y+d[i][1];
        // cout<<x<<" "<<y<<" : "<<tx<<" "<<ty<<" : "<<vis[tx][ty]<<endl;
        if(vis[tx][ty]!=0)return 1;
    }
    return 0;
}
void solve(){
    n=read(),m=read();ans=0;
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            vis[i][j]=-1,bk[i][j]=false;
    for(int i=1;i<=n;++i)vis[i][m+1]=0,vis[i][0]=0;
    for(int i=1;i<=m;++i)vis[n+1][i]=0,vis[0][i]=0;
    for(int i=1;i<=n;++i)   
        for(int j=1;j<=m;++j)
            if(s[i][j]!='?'&&!bk[i][j])dfs(i,j);
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=m;++j)
    //         cout<<vis[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(vis[i][j]==1)++ans;//,cerr<<i<<" "<<j<<endl;
            else if(vis[i][j]==-1){
                ans+=check(i,j);//,cerr<<i<<" "<<j<<endl;
            }
        }
    }
    write(ans),pc('\n');
}
signed main(){
    T=read();
    d['U'][0]=-1;d['D'][0]=1;d['L'][1]=-1;d['R'][1]=1;
    while(T--){
        solve();
    }

    return 0;
}