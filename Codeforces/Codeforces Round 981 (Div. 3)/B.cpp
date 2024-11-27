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
int a[505][505];
char s[200005];



int main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                a[i][j]=read();
        ans=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                if(a[i][j]>=0)continue;
                ans-=a[i][j];
                for(int k=1;i+k<=n&&j+k<=n;++k)
                    a[i+k][j+k]-=a[i][j];
                a[i][j]=0;
            }        
        write(ans),pc('\n');
    }

    return 0;
}