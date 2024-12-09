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

int T,n,k,ans,cnt;
int a[200005];
int pw[60];
void dfs(int x,int l,int r){
    if(x==n){a[l]=x;return;}
    if(k>pw[n-x-1]){k-=pw[n-x-1];a[r]=x;dfs(x+1,l,r-1);}
    else{a[l]=x;dfs(x+1,l+1,r);}
}
void solve(){
    n=read(),k=read();
    if(n==1){
        if(k==1)puts("1");
        else puts("-1");
        return;
    }
    if(n==2){
        if(k==1)puts("1 2");
        else if(k==2)puts("2 1");
        else puts("-1");
        return;
    }
    if(n<=50){
        if(pw[n-1]<k){puts("-1");return;}
        dfs(1,1,n);
        for(int i=1;i<=n;++i)write(a[i]),pc(' ');
        pc('\n');return;
    }
    for(int i=1;i<=n-50;++i)a[i]=i;
    dfs(n-49,n-49,n);
    for(int i=1;i<=n;++i)write(a[i]),pc(' ');pc('\n');
}
signed main(){
    T=read();pw[0]=1;
    for(int i=1;i<=50;++i)pw[i]=pw[i-1]*2;
    while(T--){
        solve();
    }

    return 0;
}