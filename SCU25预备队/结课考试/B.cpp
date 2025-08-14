#include<bits/stdc++.h>
#define pc putchar
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
int T,n,m;
int a[100005],b[100005],c[100005];

void solve(){
    n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)b[i]=read();
    for(int i=1;i<=n;++i)c[i]=read();
    int now=0;
    if(m==0){puts("YES");return;}
    int p=0,q=0,r=0;
    while(1){
        bool f=false;
        if(p<n&&(now|a[p+1]|m)==m)now|=a[p+1],++p,f=true;
        if(q<n&&(now|b[q+1]|m)==m)now|=b[q+1],++q,f=true;
        if(r<n&&(now|c[r+1]|m)==m)now|=c[r+1],++r,f=true;
        if(!f){puts("NO");break;}
        if(now==m){puts("YES");break;}
    }
}
int main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}