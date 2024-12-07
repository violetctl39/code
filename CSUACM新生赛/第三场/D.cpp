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
int n;
int a[100005],f[100005];
vector<int>e[100005];
void dfs(int x){
    f[x]-=a[x];
    for(int y:e[x]){
        dfs(y);if(f[y]<0)f[x]+=f[y];
    }
}

bool check(int x){
    fill(f+1,f+n+1,x);
    dfs(1);
    return f[1]>=0;
}
signed main(){
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=2;i<=n;++i){
        int u=read();
        e[u].push_back(i);
    }
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }write(l),pc('\n');
    return 0;
}