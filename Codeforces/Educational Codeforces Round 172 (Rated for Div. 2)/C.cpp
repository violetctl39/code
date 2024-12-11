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
char s[200005];
int suf[200005];
void solve(){
    n=read(),k=read();cnt=0;
    scanf("%s",s+1);suf[n+1]=0;
    for(int i=n;i>=1;--i)suf[i]=suf[i+1]+(s[i]=='1'?1:-1);
    for(int i=2;i<=n;++i)if(suf[i]>0)a[++cnt]=suf[i];
    sort(a+1,a+cnt+1,greater<int>());int sum=0;
    for(int i=1;i<=cnt;++i){
        sum+=a[i];
        if(sum>=k){write(i+1),pc('\n');return;}
    }
    puts("-1");
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}