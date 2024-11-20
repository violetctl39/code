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
const int mod=998244353;
int n;
int a[200005];
int p[2000005],cnt;
bool vis[1000005];
void init(){
    vis[1]=true;
    for(int i=2;i<=1000000;++i){
        if(!vis[i])p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<=1000000;++j){
            vis[p[j]*i]=true;
            if(i%p[j]==0)break;
        }
    }
}
int f[1000005],g[200005];
int t[10],c;
int pr[10];
void out(){
    // cout<<c<<" : ";
    // for(int i=0;i<c;++i)cout<<t[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=6;++i)cout<<f[i]<<" ";cout<<endl;
}
signed  main(){
    n=read();init();pr[0]=1;
    for(int i=1;i<=8;++i)pr[i]=pr[i-1]*2;
    for(int i=1;i<=n;++i)a[i]=read();
    int x=a[1];c=0;
    for(int j=1;j<=cnt&&p[j]<=x;++j){
            if(x%p[j]==0){
                t[c++]=p[j];
                while(x%p[j]==0)x/=p[j];
            }
            if(!vis[x]){t[c++]=x;break;}
        }
    int mx=pr[c];
    
    for(int j=1;j<mx;++j){
            int res=1,cnt=0;
            for(int k=0;k<c;++k){
                if((j&pr[k])!=0){
                    ++cnt;res*=t[k];
                }
            }
            f[res]++;
        }
    out();
    for(int i=2;i<=n;++i){
        x=a[i];c=0;
        for(int j=1;j<=cnt&&p[j]<=x;++j){
            if(x%p[j]==0){
                t[c++]=p[j];
                while(x%p[j]==0)x/=p[j];
            }
            if(!vis[x]){t[c++]=x;break;}
        }
        mx=pr[c];
        for(int j=1;j<mx;++j){
            int res=1,cnt=0;
            for(int k=0;k<c;++k){
                if((j&pr[k])!=0){
                    ++cnt;res*=t[k];
                }
            }
            g[i]+=cnt%2==0?-f[res]:f[res];
            g[i]=(g[i]+mod)%mod;
        }
        for(int j=1;j<mx;++j){
            int res=1,cnt=0;
            for(int k=0;k<c;++k){
                if((j&pr[k])!=0){
                    ++cnt;res*=t[k];
                }
            }
            f[res]+=g[i];f[res]%=mod;
        }out();
    }
    write(g[n]),pc('\n');

    return 0;
}
/*
2 3 5
23 25 35
235

2 3 5 7
23 25 27 35 37 57
235 237 357
2357


*/