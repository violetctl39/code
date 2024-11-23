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
int a[200005];
char s[200005];

int mi[1000005];

signed main(){
    T=read();
    while(T--){
        n=read(),m=read();ans=0;
        int lim=1;while(lim<=n)lim<<=1;
        //cout<<lim<<endl;
        for(int i=1;i<=min(m,lim-1);++i)
            if(i!=n){int k=n^i;ans+=((n%k==0)|(i%k==0));}
        write(ans),pc('\n');
    }

    return 0;
}