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

int T,n,m,ans,cnt,mx,len,lim,ml;
int mi[1005];
signed main(){
    T=read();mi[1]=2;
    for(int i=2;i<=60;++i)mi[i]=mi[i-1]<<1;
    while(T--){
        n=read(),m=read();ans=0;
        lim=1;while(lim<=n)lim<<=1;
        for(int i=1;i<=min(m,lim-1);++i){
            int k=n^i;ans+=((k%n==0)|(k%i==0));
        }
        if(m<=lim-1){write(ans),pc('\n');continue;}
        int mx=max(2ll,m/n);ans+=mx-2;
        for(int i=mx;((i*n)^n)<=m+n;++i)if(((i*n)^n)<=m)++ans;
        write(ans),pc('\n');
        
    }

    return 0;
}