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
        if(n%2==1&&n<27){puts("-1");continue;}
        if(n%2==0){
            for(int i=1;i<=n;i+=2)printf("%d %d ",i,i);
            pc('\n');continue;
        }
        a[1]=1;a[10]=1;a[26]=1;
        for(int i=2;i<10;i+=2)a[i]=a[i+1]=i;
        for(int i=11;i<23;i+=2)a[i]=a[i+1]=i;
        a[23]=23;a[27]=23;a[24]=a[25]=24;
        for(int i=28;i<=n;i+=2)a[i]=a[i+1]=i;
        for(int i=1;i<=n;++i)write(a[i]),pc(' ');pc('\n');
    }

    return 0;
}