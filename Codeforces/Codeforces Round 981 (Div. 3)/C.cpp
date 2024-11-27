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

int T,n,m,ans,cnt;
int a[200005];
char s[200005];



int main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i)a[i]=read();
        for(int i=2;i<=n/2;++i){
            if(a[i]==a[i-1]||a[n-i+1]==a[n-i+2])swap(a[i],a[n-i+1]);
        }ans=0;
        for(int i=2;i<=n;++i)if(a[i]==a[i-1])++ans;
        write(ans),pc('\n');
    }

    return 0;
}