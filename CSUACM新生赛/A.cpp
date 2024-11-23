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

int n,q;
int a[1005];
int b[1005],cnt;
int main(){
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    q=read();
    while(q--){
        int op=read();
        if(op==1){
            int x=read(),k=read();
            a[x]=k;
        }
        else if(op==2){
            int k=read(),l=read(),r=read();
            cnt=0;
            for(int i=l;i<=r;++i)b[++cnt]=a[i];
            sort(b+1,b+cnt+1);
            write(b[k]),pc('\n');
        }
        else if(op==3){
            int k=read(),l=read(),r=read();
            cnt=0;
            for(int i=l;i<=r;++i)b[++cnt]=a[i];
            sort(b+1,b+cnt+1);b[cnt+1]=1e9+1;
            for(int i=1;i<=cnt+1;++i)
                if(b[i]>=k){write(i),pc('\n');break;}
        }
        else if(op==4){
            int k=read(),l=read(),r=read();
            cnt=0;
            for(int i=l;i<=r;++i)b[++cnt]=a[i];
            sort(b+1,b+cnt+1);b[cnt+1]=1e9+1;
            for(int i=1;i<=cnt+1;++i)
                if(b[i]>=k){write(i==1?1000000007:b[i-1]),pc('\n');break;}
        }
        else{
            int k=read(),l=read(),r=read();
            cnt=0;
            for(int i=l;i<=r;++i)b[++cnt]=a[i];
            sort(b+1,b+cnt+1);
            for(int i=cnt;i>=0;--i)
                if(b[i]<=k){write(i==cnt?1000000007:b[i+1]),pc('\n');break;}
        }
    }

    return 0;
}