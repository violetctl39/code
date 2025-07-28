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

int n,m,mx;
int a[1000005];

signed main(){
    n=read(),m=read();int l=0,r=0;
    for(int i=1;i<=n;++i)a[i] =read(),r=max(r,a[i]);
    while(l<r){
        int mid=(l+r+1)>>1;
        int sum=0;
        for(int i=1;i<=n;++i)if(a[i]>mid)sum+=a[i]-mid;
        if(sum<m)r=mid-1;
        else l=mid;
    }
    write(l),pc('\n');
    return 0;
}