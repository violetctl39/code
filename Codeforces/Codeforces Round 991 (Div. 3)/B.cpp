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

void solve(){
    n=read();int sum1=0,sum2=0;
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;i+=2)sum1+=a[i];
    for(int i=2;i<=n;i+=2)sum2+=a[i];
    if(sum1%((n+1)/2)!=0){puts("NO");return;}
    if(sum2%(n/2)!=0){puts("NO");return;}
    if((sum1/((n+1)/2))!=sum2/(n/2)){puts("NO");return;}
    puts("YES");
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}