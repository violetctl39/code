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

int a[200005];

int main(){
    freopen("1.in","r",stdin);
    int T=read();
    int n=read(),ans=0;
    for(int i=1;i<=n;++i)a[i]=read();
    int x=0;
    for(int l=1;l<=n;++l)
        for(int r=l;r<=n;++r)
        {
            int x=0;
            for(int i=1;i<=n;++i){
                if(i>=l&&i<=r)continue;
                if(x<a[i])++x;
                if(x>a[i])--x;
            }ans=max(ans,x);
        }
    cout<<ans<<endl;
    return 0;
}