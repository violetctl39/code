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
map<int,int>f;
void solve(){
    n=read();f.clear();int sum=0;
    for(int i=1;i<=n;++i)a[i]=read(),f[a[i]]++;
    for(auto [x,y]:f)if(y==1)++sum;
    write((sum+1)/2*2+f.size()-sum),pc('\n');
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}