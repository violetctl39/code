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
multiset<int>s;
int stk[200005],top;
void solve(){
    n=read();top=0;s.clear();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i){
        while(top&&stk[top]>a[i]){s.insert(stk[top]+1);--top;}
        stk[++top]=a[i];
    }
    if(!s.empty())while(top&&stk[top]>*s.begin()){s.insert(stk[top]+1);--top;}
    for(int i=1;i<=top;++i){write(stk[i]),pc(' ');}
    for(int x:s)write(x),pc(' ');pc('\n');
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}