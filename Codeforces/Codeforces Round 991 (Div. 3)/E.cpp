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
char a[1005],b[1005],c[2005];
int f[1005][1005];
void solve(){
    scanf("%s%s",a+1,b+1);n=strlen(a+1);m=strlen(b+1);
    scanf("%s",c+1);
    f[0][0]=0;
    for(int i=1;i<=n;++i)f[i][0]=f[i-1][0]+(a[i]!=c[i]);
    for(int j=1;j<=m;++j)f[0][j]=f[0][j-1]+(b[j]!=c[j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f[i][j]=min(f[i-1][j]+(a[i]!=c[i+j]),f[i][j-1]+(b[j]!=c[i+j]));
    write(f[n][m]),pc('\n');
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}