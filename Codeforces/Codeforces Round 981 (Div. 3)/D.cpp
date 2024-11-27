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
int a[200005],pre[200005],f[200005];
char s[200005];


map<int,int>mp;
signed main(){
    T=read();
    while(T--){
        n=read();ans=0;map<int,int>().swap(mp);
        for(int i=1;i<=n;++i)a[i]=read(),pre[i]=pre[i-1]+a[i],f[i]=0;
        mp.insert({0,0});
        for(int i=1;i<=n;++i){
            if(mp.find(pre[i])!=mp.end()){f[i]=mp[pre[i]]+1;}
            f[i]=max(f[i],f[i-1]);
            mp[pre[i]]=f[i];
        }
        write(f[n]),pc('\n');
    }

    return 0;
}