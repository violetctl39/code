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

int T,n,m,ans,cnt;
int a[200005];
char s[200005];


map<int,int>mp;
int main(){
    T=read();
    while(T--){
        n=read();map<int,int>().swap(mp);ans=0;
        for(int i=1;i<=n;++i)mp[read()]++;
        for(auto i:mp){
            ans+=i.second/2;
        }
        write(ans),pc('\n');
    }

    return 0;
}