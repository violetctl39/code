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
int n,m;
char s[405][405];
int f[405][405];
signed main(){
    n=read(),m=read();int ans=0;
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i][j]!='p')continue;
            for(int k=j+1;k<=m;++k){
                if(s[i][k]!='c')continue;
                ans+=f[j][k];
            }
        }
        for(int j=1;j<=m;++j){
            if(s[i][j]!='c')continue;
            for(int k=j+1;k<=m;++k){
                if(s[i][k]!='c')continue;
                f[j][k]++;
            }
        }
    }
    write(ans),pc('\n');

    return 0;
}