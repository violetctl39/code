#pragma GCC optimize(2)
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

int T,n,m,ans,cnt;
int a[200005];
set<int>f[3];
vector< pair<int,int> >v;
int lst(set<int> x){
    auto it=x.end();
    it--;
    return *it;
}
void solve(){
    n=100000;ans=0;
    vector< pair<int,int> >().swap(v);
    for(int i=0;i<3;++i)set<int>().swap(f[i]);
    for(int i=1;i<=n;++i)a[i]=rand()%3,f[a[i]].insert(i);
    int siz0=f[0].size(),siz1=f[1].size();
    if(siz1==n){puts("0");return;}
    if(!siz0){
        while(lst(f[1])>siz1){
            int x=lst(f[1]),y=*f[2].begin();
            f[1].erase(x);f[2].erase(y);
            f[1].insert(y);f[2].insert(x);
            v.push_back({x,y});++ans;
        }
        write(ans),pc('\n');
        for(auto i:v){write(i.first),pc(' ');write(i.second),pc('\n');}
        return;
    }
    if(f[2].size()==0){
        while(lst(f[0])>siz0){
            int x=lst(f[0]),y=*f[1].begin();
            f[0].erase(x);f[1].erase(y);
            f[0].insert(y);f[1].insert(x);
            v.push_back({x,y});++ans;
        }
        write(ans),pc('\n');
        for(auto i:v){write(i.first),pc(' ');write(i.second),pc('\n');}
        return;
    }
    
    // cerr<<siz0<<" "<<siz1<<" "<<f[2].size()<<endl;
    while(1){
        if(*f[1].begin()==siz0+1&&lst(f[1])==siz0+siz1){
            if(lst(f[0])==siz0)break;
            int x=lst(f[1]),y=*f[2].begin();
            f[1].erase(x);f[2].erase(y);
            f[1].insert(y);f[2].insert(x);
            v.push_back({x,y});++ans;
            x=*f[1].begin(),y=lst(f[0]);
            f[1].erase(x);f[0].erase(y);
            f[1].insert(y);f[0].insert(x);
            v.push_back({x,y});++ans;
        }
        // out(f[1]);
        // cout<<*f[1].begin()<<" "<<lst(f[1])<<endl;
        while(*f[1].begin()<=siz0){
            int x=*f[1].begin(),y=lst(f[0]);
            f[1].erase(x);f[0].erase(y);
            f[1].insert(y);f[0].insert(x);
            v.push_back({x,y});++ans;
        }
        // cout<<lst(f[1])<<" "<<siz0+siz1<<endl;
        while(lst(f[1])>siz0+siz1){
            
            int x=lst(f[1]),y=*f[2].begin();
            f[1].erase(x);f[2].erase(y);
            f[1].insert(y);f[2].insert(x);
            v.push_back({x,y});++ans;
        }

    }
    write(ans),pc('\n');
    for(auto i:v){write(i.first),pc(' ');write(i.second),pc('\n');}
}
int main(){
    T=read();srand(time(0));
    while(T--){
        solve();
    }

    return 0;
}
/*
1
4
0 1 0 1


*/