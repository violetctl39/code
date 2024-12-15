#include<bits/stdc++.h>
#define pc putchar
#define int long long
#define ls (x<<1)
#define rs (x<<1|1)
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
int a[200005],b[200005];
struct node{
    int pre,suf,sum,ans;
}t[800005];
void pushup(node &x,node l,node r){
    x.ans=max(l.ans,r.ans);
    x.ans=max(x.ans,l.suf+r.pre);
    x.pre=max(l.pre,l.sum+r.pre);
    x.suf=max(r.suf,r.sum+l.suf);
    x.sum=l.sum+r.sum;
}
void build(int x,int l,int r){
    if(l==r){
        t[x].ans=a[l]+2*b[l];t[x].sum=a[l];
        t[x].pre=t[x].suf=a[l]+b[l];return;
    }int mid=(l+r)>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    pushup(t[x],t[ls],t[rs]);
}
void mdya(int x,int l,int r,int k,int v){
    if(l==r){
        a[l]=v;
        t[x].ans=a[l]+2*b[l];t[x].sum=a[l];
        t[x].pre=t[x].suf=a[l]+b[l];return;
    }int mid=(l+r)>>1;
    if(k<=mid)mdya(ls,l,mid,k,v);
    else mdya(rs,mid+1,r,k,v);
    pushup(t[x],t[ls],t[rs]);
}
void mdyb(int x,int l,int r,int k,int v){
    if(l==r){
        b[l]=v;
        t[x].ans=a[l]+2*b[l];t[x].sum=a[l];
        t[x].pre=t[x].suf=a[l]+b[l];return;
    }int mid=(l+r)>>1;
    if(k<=mid)mdyb(ls,l,mid,k,v);
    else mdyb(rs,mid+1,r,k,v);
    pushup(t[x],t[ls],t[rs]);
}
node qry(int x,int l,int r,int L,int R){
    if(L<=l&&r<=R)return t[x];
    int mid=(l+r)>>1;
    if(R<=mid)return qry(ls,l,mid,L,R);
    if(L>mid)return qry(rs,mid+1,r,L,R);
    node res;
    pushup(res,qry(ls,l,mid,L,R),qry(rs,mid+1,r,L,R));
    return res;
}
void out(int x,int l,int r){
    cout<<l<<" "<<r<<" : "<<t[x].pre<<" "<<t[x].suf<<" "<<t[x].sum<<" "<<t[x].ans<<endl;
    if(l==r)return;
    int mid=(l+r)>>1;
    out(ls,l,mid);out(rs,mid+1,r);
}
int find(int x,int y,int l,int r){
    if(l==r)return l;
    int len=(r-l)/3;
    int mid1=l+len,mid2=r-len;
    int ans1=qry(1,1,n,x,mid1).ans+qry(1,1,n,mid1+1,y).ans;
    int ans2=qry(1,1,n,x,mid2).ans+qry(1,1,n,mid2+1,y).ans;
    // cout<<l<<" "<<r<<" "<<mid1<<" "<<mid2<<" "<<ans1<<" "<<ans2<<endl;
    if(ans1<ans2)return find(x,y,mid1+1,r);
    else if(ans1>ans2)return find(x,y,l,mid2-1);
    else{
        if(l==mid1&&r==mid2)return l;
        int p1=find(x,y,l,mid1),ans1=qry(1,1,n,x,p1).ans+qry(1,1,n,p1+1,y).ans;
        int p2=find(x,y,mid1,mid2),ans2=qry(1,1,n,x,p2).ans+qry(1,1,n,p2+1,y).ans;
        int p3=find(x,y,mid2,r),ans3=qry(1,1,n,x,p3).ans+qry(1,1,n,p3+1,y).ans;
        if(ans1<ans2)swap(p1,p2),swap(ans1,ans2);
        if(ans1<ans3)swap(p1,p3),swap(ans1,ans3);
        return p1;
    }
}
signed main(){
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)b[i]=read();
    build(1,1,n);
    // out(1,1,n);
    int q=read();
    while(q--){
        int op=read(),x=read(),y=read();
        if(op==1)mdya(1,1,n,x,y);
        else if(op==2)mdyb(1,1,n,x,y);
        else{
            int p=find(x,y,x,y-1);
            // for(int i=1;i<=n;++i)cout<<a[i]<<" ";cout<<endl;
            // for(int i=1;i<=n;++i)cout<<b[i]<<" ";cout<<endl;
            write(qry(1,1,n,x,p).ans+qry(1,1,n,p+1,y).ans),pc('\n');
        }
    }
    return 0;
}