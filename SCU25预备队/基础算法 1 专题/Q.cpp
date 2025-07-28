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

int n,ans,a[100005];
int tr[3000005][2],cnt=1;
int p2[32];
void insert(int x){
    int pos=1;
    for(int i=31;i>=0;--i){
        int f=(x&p2[i])!=0;
        if(!tr[pos][f])tr[pos][f]=++cnt;
        pos=tr[pos][f];
    }
}
int find(int x){
    int pos=1,res=0;
    for(int i=31;i>=0;--i){
        int f=(x&p2[i])!=0;
        if(tr[pos][f^1])res+=p2[i],pos=tr[pos][f^1];
        else pos=tr[pos][f];
    }return res;
}
int main(){
    n=read();p2[0]=1;
    for(int i=1;i<=31;++i)p2[i]=p2[i-1]<<1;
    for(int i=1;i<=n;++i)a[i]=read(),insert(a[i]);
    for(int i=1;i<=n;++i)ans=max(ans,find(a[i]));
    write(ans),pc('\n');

    return 0;
}