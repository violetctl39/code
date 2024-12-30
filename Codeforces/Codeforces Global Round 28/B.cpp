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
int a[200005],p[200005],b[200005];
char s[200005];

void solve(){
    n=read();int k=read();
    int now=1;
    fill(a+1,a+n+1,0);
    for(int i=k;i<=n;i+=k)a[i]=now++;
    for(int i=1;i<=n;++i)if(!a[i])a[i]=now++;
    for(int i=1;i<=n;++i)write(a[i]),pc(' ');pc('\n');
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}