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

int T,n,m,cnt;
int a[200005],b[200005],ans[200005],ansl,ansr;
char s[200005];

void solve(){
    scanf("%s",s+1);n=strlen(s+1);int p=0;
    for(int i=1;i<=n;++i)if(s[i]=='0'){p=i;break;}
    if(!p){
        printf("1 %lld 1 1\n",n);
        return;
    }
    int len=n-p+1;
    for(int i=1;i<=n;++i)a[i]=s[i]-'0',ans[i]=0;
    for(int i=1;i+len-1<=n;++i){
        for(int j=i;j<=i+len-1;++j)
            b[j-i+1]=a[j-i+p]^a[j];
        bool f=false;
        for(int j=1;j<=len;++j)if(ans[j]<b[j]){f=true;break;} else if(ans[j]>b[j])break;
        if(f){ansl=i;ansr=i+len-1;for(int j=1;j<=len;++j)ans[j]=b[j];}
    }
    printf("1 %lld %lld %lld\n",n,ansl,ansr);
}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}