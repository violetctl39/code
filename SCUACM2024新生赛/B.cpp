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
int n,m;
vector<int>a[250005];
int c[250005],d[250005];
int t[250005],tot;
bool solve(int x,int y){
    int p1=1,p2=1;
    for(int i=2;i<=n;++i)d[i]=c[i];
    for(int i=2;i<=n;++i)if(d[i]>2){p1=i;break;}
    for(int i=2;i<=n;++i){
        d[i]-=(a[i][x]!=a[1][x]);
        d[i]+=(a[i][x]!=a[p1][x]);
    }
    for(int i=2;i<=n;++i)if(d[i]>=4)return false;
    for(int i=2;i<=n;++i)if(d[i]==3){p2=i;break;}
    for(int i=2;i<=n;++i){
        d[i]-=(a[i][y]!=a[1][y]);
        d[i]+=(a[i][y]!=a[p2][y]);
    }
    for(int i=2;i<=n;++i)if(d[i]>=3)return false;
    puts("Yes");if(x>y)swap(x,y),swap(p1,p2);
    for(int i=1;i<x;++i)write(a[1][i]),pc(' ');
    write(a[p1][x]),pc(' ');
    for(int i=x+1;i<y;++i)write(a[1][i]),pc(' ');
    write(a[p2][y]),pc(' ');
    for(int i=y+1;i<=m;++i)write(a[1][i]),pc(' ');
    return true;
}
int cnm[1000005],cc;
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i].push_back(0);
        for(int j=1;j<=m;++j)a[i].push_back(read());
    }
    for(int i=2;i<=n;++i)
        for(int j=1;j<=m;++j)c[i]+=a[i][j]!=a[1][j];
    for(int i=2;i<=n;++i)if(c[i]>=5){puts("No");return 0;}
    
    bool flag=true;
    for(int i=2;i<=n;++i)flag&=(c[i]<=2);
    if(flag){puts("Yes");for(int i=1;i<=m;++i)write(a[1][i]),pc(' ');return 0;}
    for(int i=1;i<=m;++i)
        for(int j=2;j<=n;++j)
            if(a[j][i]!=a[1][i]){cnm[++cc]=i;break;}
    for(int i=1;i<=cc;++i)
        for(int j=1;j<=cc;++j){
            if(i==j)continue;
            flag=solve(cnm[i],cnm[j]);
            if(flag)return 0;
        }
        // for(int i=1;i<=m;++i)
        //     for(int j=1;j<=cc;++j){
        //         if(i==cnm[j])continue;
        //         flag=i<cnm[j]?solve(i,cnm[j]):solve(cnm[j],i);
        //         if(flag)return 0;
        //     }
    

    puts("No");
    return 0;
}