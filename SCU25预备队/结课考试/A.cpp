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

int T,n,m;
int a,b;

signed main(){
    T=read();
    while(T--){
        n=read(),m=read();
        a=0,b=0;
        for(int i=1;i<=n;++i)a+=read();
        for(int i=1;i<=m;++i)b+=read();
        if(a==b)puts("Draw");
        else if(a<b)puts("Tenzing");
        else puts("Tsondu");
    }

    return 0;
}