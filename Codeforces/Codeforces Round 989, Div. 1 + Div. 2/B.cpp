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

int T,n,m,k,ans,cnt;
int a[200005];
char s[200005];

void solve(){
    n=read(),m=read(),k=read();
    scanf("%s",s+1);
    ans=0;int cnt=0;
    for(int i=1;i<=n;++i){
        if(s[i]=='0')++cnt; else cnt=0;
        if(cnt==m){
            for(int j=i;j<=min(n,i+k-1ll);++j)s[j]='1';
            cnt=0;++ans;
        }
    }
    write(ans),pc('\n');
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}