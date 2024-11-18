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
int a[500005];
int stk[500005],top;
int pre[500005],f[500005];

int main(){
    T=read();
    while(T--){
        n=read();top=0;
        for(int i=1;i<=n;++i)a[i]=read(),pre[i]=max(pre[i-1],a[i]);
        for(int i=n;i;--i){
            if(a[i]<a[stk[top]]||!top)stk[++top]=i;
            if(pre[i]==a[stk[top]]){f[i]=pre[i];continue;}
            int l=1,r=top;
            while(l<r){
                int mid=(l+r)/2;
                if(a[stk[mid]]<pre[i])r=mid;
                else l=mid+1;
            }f[i]=max(pre[stk[l]],i==stk[l]?a[i]:f[stk[l]]);
        }
        for(int i=1;i<=n;++i)write(f[i]),pc(' ');pc('\n'); 
    }

    return 0;
}