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
int n,m,T,now;
int a[105][105];
int ans;
set<int>st;
void dfs(int x,int y,int res){
    if(x>n||y>m)return;
    int nxt=__gcd(res,a[x][y]);
    if(nxt%now!=0)return;
    if(x==n&&y==m){ans=now;return;}
    dfs(x+1,y,nxt);
    if(ans)return;
    dfs(x,y+1,nxt);
}
void solve(){
    n=read(),m=read();ans=0;st.clear();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            a[i][j]=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            a[i][j]=__gcd(a[1][1],__gcd(a[n][m],a[i][j])),st.insert(a[i][j]);
    st.insert(1);
    for(auto i=st.end();i!=st.begin();i--){
        if(i==st.end())--i;
        now=*i;
        dfs(1,1,a[1][1]);
        if(ans)break;
    }
    write(ans==0?1:ans),pc('\n');
}

int main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}