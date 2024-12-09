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
int a[200005];
char s[200005];
int f[100005];
void solve(){
    n=read();ans=0;
    for(int i=1;i<=30;++i)
        if(f[i]>=n){write(i),pc('\n');return;}
}
signed main(){
    T=read();
    f[1]=1;f[2]=4;f[3]=10;
    for(int i=4;i<=30;++i)
        f[i]=(f[i-1]+1)*2;
    while(T--){
        solve();
    }

    return 0;
}