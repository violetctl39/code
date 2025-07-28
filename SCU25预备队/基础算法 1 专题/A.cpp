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
int n,m,ans;
int t[100005];
string op[100005];
int a[100005],cnt;
signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;++i){
        cin>>op[i];t[i]=read();
    }
    if(!m)a[++cnt]=0;
    while(m){
        a[++cnt]=m&1;
        m>>=1;
    }
    int num=0;
    for(int i=1;i<=n;++i){
        int tmp=t[i],c=1;
        while(tmp){
            ++c;tmp>>=1;
        }
        num=max(num,c);
    }
    for(int i=cnt+1;i<=num;++i)a[i]=0;
    cnt=num;
    reverse(a+1,a+cnt+1);
    bool f=false;int now=pow(2,cnt-1);
    cerr<<now<<" "<<cnt<<endl;
    for(int i=1;i<=cnt;++i){
        int res=0;
        for(int j=1;j<=n;++j){
            if(op[j][0]=='A')res=res&(t[j]&now);
            if(op[j][0]=='O')res=res|(t[j]&now);
            if(op[j][0]=='X')res=res^(t[j]&now);
        }
        int res2=now;
        for(int j=1;j<=n;++j){
            if(op[j][0]=='A')res2=res2&(t[j]&now);
            if(op[j][0]=='O')res2=res2|(t[j]&now);
            if(op[j][0]=='X')res2=res2^(t[j]&now);
        }
        if(res>=res2){
            if(a[i]==1&&!f)f=true;
            ans+=res;
        }
        else{
            if(f||a[i]==1)ans+=res2;
            else ans+=res;
        }
        now>>=1;
    }
    write(ans),pc('\n');
    return 0;
}