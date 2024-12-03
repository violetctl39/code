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
vector<int>v;
int a[100005],c[100005];
struct cmp{
    bool operator()(int x,int y){return a[x]<a[y];}
};
set<int,cmp>st[100005];
int t[100005],tot;
void solve(){
    n=read();v.clear();
    
    for(int i=1;i<=n;++i)a[i]=read(),c[i]=0;
    st[1].insert(1);t[++tot]=1;
    for(int i=2,now=1;i<=n;++i){
        if(a[i]>=a[i-1])st[now].insert(i);
        else{now=i;st[now].insert(i);t[++tot]=now;}
    }
    while(tot>1){
        int x=1;
        for(int i=2;i<=tot;++i)if(a[t[i]]+c[t[i]]<a[t[x]]+c[t[x]])x=i;
        int y=x==1?2:1;
        for(int i=1;i<=tot;++i)if(i!=x&&a[t[i]]+c[t[i]]>a[t[x]]+c[t[x]]&&a[t[i]]+c[t[i]]<a[t[y]]+c[t[y]])y=i;
        v.push_back(a[x]);
        while(1){
            
        }
        if(!st[x].empty()){
            int y=*st[x].begin();st[x].erase(y);
            a[y]+=c[x];c[y]=c[x];
        }
    }


    for(int i=1;i<=n;++i)set<int,cmp>().swap(st[i]);
    set<int,cmp>().swap(hd);
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}