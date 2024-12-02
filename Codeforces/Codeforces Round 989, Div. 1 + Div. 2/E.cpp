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

int T,n,k,ans,cnt;
int a[100005];
vector<int>v[100005];
void solve(){
    n=read(),k=read();
    if((n+1)*k%2!=0||(k==1&&n>1)){puts("NO");return;}
    if(k==1){puts("YES");puts("1");return;}
    if(k%2==0){
        for(int i=1;i<=n;++i)a[i]=i;
        for(int i=1;i*2<=k;++i){
            for(int j=1;j<=n;++j)v[i].push_back(a[j]);
            next_permutation(a+1,a+n+1);
        }
        for(int i=k/2+1;i<=k;++i){
            for(int j=1;j<=n;++j)
                v[i].push_back(n-v[k-i+1][j-1]+1);
        }
        puts("YES");
        for(int i=1;i<=k;++i){
            for(int j:v[i])write(j),pc(' ');
            pc('\n');
        }
        for(int i=1;i<=k;++i)vector<int>().swap(v[i]);
        return;
    }
    if(n!=k){puts("NO");return;}
    puts("YES");
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j)
            write((i+j-2)%n+1),pc(' ');
        pc('\n');
    }
    //int sum=(n+1)*k/2;


}
signed main(){
    T=read();
    while(T--){
        solve();
    }

    return 0;
}

/*

4 3

1 2 3
1 2 3
1 2 3


1 2 3 4
2 3 4 1
3 2 1 4
4 3 2 1


1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4
*/