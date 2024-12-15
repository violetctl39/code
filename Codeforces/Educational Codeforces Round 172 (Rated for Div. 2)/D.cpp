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
class song{
public:
    int l,r,id,ans;
}a[200005];
int stk[200005],top;
set<int>s;
void solve(){
    n=read();top=0;s.clear();
    for(int i=1;i<=n;++i)a[i].l=read(),a[i].r=read(),a[i].id=i,a[i].ans=-1;
    sort(a+1,a+n+1,[](song x,song y){return x.l==y.l?x.r>y.r:x.l<y.l;});
    for(int i=2;i<=n;++i)if(a[i].l==a[i-1].l&&a[i].r==a[i-1].r){a[i].ans=0;a[i-1].ans=0;}
    for(int i=1;i<=n;++i){
        if(a[i].l==a[i-1].l&&a[i].r==a[i-1].r)continue;
        if(!top){
            stk[++top]=i;
            s.insert(a[i].r);
            a[i].ans=0;
            continue;
        }
        auto it=s.lower_bound(a[i].r);
        if(it==s.end()||a[i].ans==0){
            s.insert(a[i].r);
            while(top&&a[stk[top]].r<=a[i].r)--top;
            stk[++top]=i;a[i].ans=0;
            continue;
        }
        int l=1,r=top;
        while(l<r){
            int mid=(l+r)/2+1;
            if(a[stk[mid]].r<a[i].r)r=mid-1;
            else l=mid;
        }
        a[i].ans=(*it)-a[stk[l]].l+1-(a[i].r-a[i].l+1);
        s.insert(a[i].r);
        while(top&&a[stk[top]].r<=a[i].r)--top;
        stk[++top]=i;
    }
    sort(a+1,a+n+1,[](song x,song y){return x.id<y.id;});
    for(int i=1;i<=n;++i)write(a[i].ans),pc('\n');
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}