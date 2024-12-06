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
char s[2005][2005];
int c[27];
void solve(){
    n=read();m=read();ans=0;cnt=0;
    fill(c,c+26,0);
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
    for(int i=1;i<=n;++i){
        int len=strlen(s[i]+1);
        cnt+=len;if(cnt>m)break; ans=i;
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