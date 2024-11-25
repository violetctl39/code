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

int n,k;
int a[2005];
int f[2005],g[2005];
bool check(int x){
    for(int i=1;i<=n;++i){
        f[i]=i-1;
        for(int j=1;j<i;++j){
            if(abs(a[i]-a[j])<=x*(i-j))
                f[i]=min(f[i],f[j]+i-j-1);
        }
    }
    for(int i=n;i>=1;--i){
        g[i]=n-i;
        for(int j=n;j>i;--j){
            if(abs(a[i]-a[j])<=x*(j-i))
                g[i]=min(g[i],g[j]+j-i-1);
        }
    }
    for(int i=1;i<=n;++i)if(f[i]+g[i]<=k)return true;
    return false;
}

signed main(){
    n=read(),k=read();
    for(int i=1;i<=n;++i)a[i]=read();
    int l=0,r=2e9;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }write(l),pc('\n');

    return 0;
}