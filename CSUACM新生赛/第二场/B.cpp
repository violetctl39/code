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

int T,a,b,c;

signed main(){
    T=read();
    while(T--){
        a=read(),b=read(),c=read();
        int ans=0,now=1;
        for(int i=0;i<=32;++i){
            int cnt=((a&now)!=0)+((b&now)!=0)+((c&now)!=0);
            if(cnt==1||cnt==2)ans+=now; now<<=1;
        }write(ans),pc('\n');
    }

    return 0;
}