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
map<int,int>f;
void solve(){
    n=read(),k=read();f.clear();
    for(int i=1;i<=n;++i)a[i]=read(),f[a[i]%k]++;
    for(auto [i,j]:f){
        if(j==1){
            puts("YES");
            for(int l=1;l<=n;++l)
                if(a[l]%k==i){cout<<l<<endl;break;}
            return;
        }
    }
    puts("NO");return;
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}