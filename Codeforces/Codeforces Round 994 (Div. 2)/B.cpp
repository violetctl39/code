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

void solve(){
    n=read();
    scanf("%s",s+1);
    int l=0,r=0;
    for(int i=1;i<=n;++i)if(s[i]=='s')l=i;
    for(int i=n;i>=1;--i)if(s[i]=='p')r=i;
    if(!l||!r){puts("YES");return;}
    if(l==1||r==n)puts("YES");
    else puts("NO");
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}