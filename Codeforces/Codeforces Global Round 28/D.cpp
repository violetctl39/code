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
int a[200005],b[200005],h[200005];
char s[200005];

void solve(){
    n=read(),m=read();cnt=0;
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=2;i<=n;++i)if(a[i]>a[1])h[++cnt]=a[i];
    sort(h+1,h+cnt+1);
    for(int i=1;i<=m;++i){
        
    }
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}