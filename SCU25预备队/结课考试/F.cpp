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
int n,k,sum,ans;
int a[22];
int pri[10000005],cnt;
bool vis[100000005];
void init(){
    for(int i=2;i<=sum;++i){
        if(!vis[i])pri[++cnt]=i;
        for(int j=1;j<=cnt&&pri[j]*i<=sum;++j){
            vis[pri[j]*i]=true;
            if(i%pri[j]==0)break;
        }
    }
}
int now;
void dfs(int x,int y){
    if(y==k+1){
        ans+=!vis[now];
        return;
    }
    if(x==n+1)return;
    dfs(x+1,y);
    now+=a[x];
    dfs(x+1,y+1);
    now-=a[x];
}
int main(){
    n=read(),k=read();
    for(int i=1;i<=n;++i)a[i]=read(),sum+=a[i];
    init();
    dfs(1,1);
    write(ans),pc('\n');
    return 0;
}