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
const int mod=1e9+7;
int T,n,k,ans,cnt,tot;


signed main(){
    T=read();
    while(T--){
        n=read(),k=read();ans=0;
        if(k==1){write(n%mod),pc('\n');continue;}
        int pre=1,now=1;
        for(cnt=3;;++cnt){
            swap(now,pre);now+=pre;
            if(now>=k)now-=k;
            if(!now)break;
        }
        write(n%mod*cnt%mod),pc('\n');

    }

    return 0;
}