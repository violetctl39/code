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
int n,m;
int a[1000005];



int main(){
    n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    while(m--){
        int q=read();
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(a[mid]<q)l=mid+1;
            else r=mid;
        }
        if(a[l]!=q)write(-1),pc(' ');
        else write(l),pc(' ');
    }

    return 0;
}