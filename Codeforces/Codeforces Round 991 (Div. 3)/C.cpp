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
int c[10];
void solve(){
    scanf("%s",s+1);n=strlen(s+1);c[2]=c[3]=0;int sum=0;
    for(int i=1;i<=n;++i){
        if(s[i]-'0'<=3&&s[i]-'0'>=2)++c[s[i]-'0'];
        sum+=s[i]-'0';
    }sum%=9;   
    for(int i=0;i<=min(9ll,c[2]);++i)
        for(int j=0;j<=min(3ll,c[3]);++j){
            int res=sum+i*2+j*6;
            if(res%9==0){puts("YES");return;}
        }
    puts("NO");
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}