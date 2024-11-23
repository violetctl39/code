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

int T,n;
int a[1000005],p[100005];
int main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i)a[i]=read(),p[a[i]]=i;
        int now=n+1;
        for(int i=n;i>=1;--i){
            if(p[i]>=now)continue;
            for(int j=p[i];j<now;++j)write(a[j]),pc(' ');
            now=p[i];
        }pc('\n');
    }
    

    return 0;
}