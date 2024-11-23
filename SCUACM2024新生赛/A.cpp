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

int n,T;


signed main(){
    T=read();
    while(T--){
        int p=read(),a=read(),b=read(),c=read();
        int ans=1e18;
        ans=min(ans,((p-1)/a+1)*a-p);
        ans=min(ans,((p-1)/b+1)*b-p);
        ans=min(ans,((p-1)/c+1)*c-p);
        write(ans),pc('\n');
    }

    return 0;
}