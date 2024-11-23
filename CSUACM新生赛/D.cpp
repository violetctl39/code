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

int n,ans,a[5][1005];
map<int,int>f[2];

signed main(){
    n=read();
    for(int j=1;j<=4;++j)
        for(int i=1;i<=n;++i)
            a[j][i]=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f[0][a[1][i]+a[2][j]]++;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f[1][a[3][i]+a[4][j]]++;
    for(auto i:f[0])ans+=i.second*f[1][-i.first];
    write(ans),pc('\n');
    return 0;
}