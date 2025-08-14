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
int T;
int n,m,k;
char s[105];
void solve(){
    n=read(),m=read(),k=read();
    int kk=m;
    scanf("%s",s+1);int f=0;
    for(int i=1;i<=k;++i){
        if(m==n)f=2;
        if(s[i]=='+')++m;
        else --m;
    }
    if(m==n)f=2;
    if(f==2){puts("YES");return;}
    for(int i=1;i<=k;++i){
        if(s[i]=='+')++kk;
    }
    if(kk>=n)puts("MAYBE");
    else puts("NO");
}
int main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}