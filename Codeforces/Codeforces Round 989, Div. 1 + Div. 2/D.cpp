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

int T,n,m,ans,c[3];
int a[200005];
vector< pair<int,int> >v;
vector<int>f[3][3];
int pos(int x){
    if(x<=c[0])return 0;
    else if(x<=c[0]+c[1])return 1;
    return 2;
}
void ins(int x){
    f[a[x]][pos(x)].push_back(x);
}
void del(int x){
    f[a[x]][pos(x)].pop_back();
}
void mdy(int x,int y){
    v.push_back({x,y});
    del(x);del(y);
    swap(a[x],a[y]);
    ins(x);ins(y);
}
void fix(int x){
    while (!f[1][x].empty()||!f[2-x][x].empty()){
        if(f[1][x].empty()){
            if(!f[1][2-x].empty())
                mdy(f[2-x][x].back(),f[1][2-x].back());
            else mdy(f[2-x][x].back(),f[1][1].back());
        }
        if(!f[x][1].empty())
            mdy(f[1][x].back(),f[x][1].back());
        else mdy(f[1][x].back(),f[x][2-x].back());
    }
    
}
void solve(){
    n=read();ans=0;memset(c,0,sizeof c);
    for(int i=1;i<3;++i)for(int j=0;j<3;++j)vector<int>().swap(f[i][j]);
    vector< pair<int,int> >().swap(v);
    for(int i=1;i<=n;++i)a[i]=read(),c[a[i]]++;
    for(int i=1;i<=n;++i)ins(i);
    if(c[0]<=c[2])fix(0),fix(2);
    else fix(2),fix(0);
    write(v.size()),pc('\n');
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