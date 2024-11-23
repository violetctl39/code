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
int T,n,m;
int a[100005],b[100005];

int get(int x){
    for(int i=2;i*i<=x;++i)
        if(x%i==0)return x/i;
    return 1;
}
int main(){
    T=read();
    while(T--){
        n=read(),m=read();
        for(int i=1;i<=m;++i)a[i]=read();
        sort(a+1,a+m+1,greater<int>());
        int now=1;b[1]=1;bool flag=false;
        for(int i=2;i<=n;++i){
            int pre=get(i);
            b[i]=b[pre]+1;
            if(b[i]==m+1){flag=true;break;}
        }
        if(flag){puts("-1");continue;}
        for(int i=1;i<=n;++i)write(a[b[i]]),pc(' ');pc('\n');

    }

    return 0;
}