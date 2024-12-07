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

int n,m,b[300005];
vector<int>v[300005];
set<int>s;
int del[300005],cnt;
int main(){
    m=read();
    for(int i=1;i<=m;++i)b[i]=read();
    for(int i=1;i<=m;++i)if(b[i]==-1)++n;
    for(int i=1;i<=n;++i)s.insert(i);
    int now=1;
    while(1){
        cnt=0;
        for(int i:s){
            v[i].push_back(b[now]);
            if(b[now]==-1)del[++cnt]=i;
            ++now;if(now==m+1)break;
        }if(now==m+1)break;
        for(int i=1;i<=cnt;++i)s.erase(del[i]);
    }
    write(n),pc('\n');
    for(int i=1;i<=n;++i){
        write(v[i].size()-1),pc(' ');
        for(int j:v[i])if(j!=-1)write(j),pc(' ');
        pc('\n');
    }
    return 0;
}