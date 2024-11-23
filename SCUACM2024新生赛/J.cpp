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
const int mod=1e9+7;
char s[100005];
map<char,int>f;
signed main(){
    scanf("%s",s+1);int n=strlen(s+1);
    for(int i=1;i<=n;++i){
        if(s[i]=='c')f[s[i]]++;
        if(s[i]=='h')f[s[i]]=(f[s[i]]+f['c'])%mod;
        if(s[i]=='o')f[s[i]]=(f[s[i]]+f['h'])%mod;
        if(s[i]=='k')f[s[i]]=(f[s[i]]+f['o'])%mod;
        if(s[i]=='u')f[s[i]]=(f[s[i]]+f['k'])%mod;
        if(s[i]=='d')f[s[i]]=(f[s[i]]+f['u'])%mod;
        if(s[i]=='a')f[s[i]]=(f[s[i]]+f['d'])%mod;
        if(s[i]=='i')f[s[i]]=(f[s[i]]+f['a'])%mod;
    }
    write(f['i']),pc('\n');
    return 0;
}