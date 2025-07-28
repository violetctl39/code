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
int a[100005];
int st[100005][18];
int p2[18],mx;

int main(){
    n=read(),m=read();p2[0]=1;
    for(int i=1;i<=17;++i)p2[i]=p2[i-1]<<1;
    for(int i=1;i<=17;++i)if(p2[i]<=n)mx=i;
    for(int i=1;i<=n;++i)a[i]=read(),st[i][0]=a[i];
    for(int j=1;j<=17;++j)
        for(int i=1;i+p2[j]-1<=n;++i){
            st[i][j]=max(st[i][j-1],st[i+p2[j-1]][j-1]);
    }
    while(m--){
        int l=read(),r=read();
        int len=r-l+1,c=0;
        while(p2[c+1]<=len)++c;
        write(max(st[l][c],st[r-p2[c]+1][c])),pc('\n');
    }
    return 0;
}