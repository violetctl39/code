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
int a[3][5005],b[5005];
char s[200005];

void solve(){
    n=read();ans=-1e9;
    for(int i=1;i<=2;++i)
        for(int j=1;j<=n;++j)
            a[i][j]=read();
    for(int i=1;i<=n;++i)b[i]=max(a[1][i],a[2][i]);
    for(int i=1;i<=n;++i){
        int sum=a[1][i]+a[2][i];
        for(int j=1;j<=n;++j)if(j!=i)sum+=b[j];
        ans=max(ans,sum);
    }write(ans),pc('\n');
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}