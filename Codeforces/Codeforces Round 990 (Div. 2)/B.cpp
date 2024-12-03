#include<bits/stdc++.h>
#define pc putchar
#define int long long
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
int c[27];
void solve(){
    n=read();
    for(int i=0;i<26;++i)c[i]=0;
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)c[s[i]-'a']++;
    int p1=0,p2=0;
    while(!c[p1])++p1,++p2;
    for(int i=p1;i<26;++i)if(c[i]){if(c[i]>c[p1])p1=i; if(c[i]<=c[p2])p2=i;}
    for(int i=1;i<=n;++i)if(s[i]=='a'+p2){s[i]='a'+p1;break;}
    for(int i=1;i<=n;++i)pc(s[i]); pc('\n');

}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}