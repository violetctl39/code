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
int n,m,ans;
char s[200005],t[200005];

int nxt[200005][27],pre[200005][27];
int f[200005],g[200005];
int main(){
    n=read(),m=read();
    scanf("%s%s",s+1,t+1);
    for(int i=n;i>=0;--i){
        for(int j=0;j<='z'-'a';++j)nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i+1]-'a']=i+1;
    }
    for(int i=1;i<=n+1;++i){
        for(int j=0;j<='z'-'a';++j)pre[i][j]=pre[i-1][j];
        pre[i][s[i-1]-'a']=i-1;
    }
    int p=0;
    for(int i=1;i<=m;++i){
        p=nxt[p][t[i]-'a'];f[i]=p;
    }
    p=n+1;
    for(int i=m;i>=1;--i){
        p=pre[p][t[i]-'a'];g[i]=p;
    }
    for(int i=1;i<m;++i)ans=max(ans,max(0,g[i+1]-f[i]));
    write(ans),pc('\n');
    return 0;
}