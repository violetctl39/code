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

int T,n,m,L,ans,cnt;
struct node{
    int x,v;
}a[200005];
struct line{
    int l,r;
}b[200005];
priority_queue<int>q;
signed main(){
    T=read();
    while(T--){
        n=read(),m=read(),L=read();ans=0;cnt=1;
        priority_queue<int>().swap(q);
        for(int i=1;i<=n;++i)
            b[i].l=read(),b[i].r=read();
        for(int i=1;i<=m;++i)
            a[i].x=read(),a[i].v=read();
        int now=1;
        for(int i=1;i<=n;++i){
            while(now<=m&&a[now].x<b[i].l){q.push(a[now].v);++now;}
            while(cnt<b[i].r-b[i].l+2&&!q.empty()){++ans;cnt+=q.top();q.pop();}
            if(cnt<b[i].r-b[i].l+2){ans=-1;break;}
        }
        write(ans),pc('\n');
    }

    return 0;
}