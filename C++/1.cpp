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

int T,n,m,ans;
int p[400005],cnt;
bool vis[400005];
int a[100005];
void init(){
    for(int i=2;i<=400000;++i){
        if(!vis[i])p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<=400000;++j){
            vis[p[j]*i]=true;
            if(i%p[j]==0)break;
        }
    }
}

signed main(){
    T=read();init();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i)a[i]=read();
        sort(a+1,a+n+1);bool f=false;
        if(!vis[a[1]]){
            for(int i=2;i<=n;++i)
                if((a[i]<a[1]*2&&a[i]>a[1])||(!vis[a[i]]&&a[i]!=a[1])){f=true;break;}
            if(f)puts("-1"); else write(a[1]),pc('\n');
            continue;
        }
        for(int i=2;i<=n;++i)if(!vis[a[i]]){f=true;break;}
        if(f){puts("-1");continue;}
        puts("2");

    }
    return 0;
}