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

int T,n,ans;
char s[100005];
bool vis[100005];

queue<int>q;
void solve(){
    n=read();ans=0;queue<int>().swap(q);
    fill(vis+1,vis+n+1,false);
    scanf("%s",s+1);
    for(int i=1;i<n;++i)if(s[i]==s[i+1])q.push(i);
    int now=1;
    while(1){
        ++ans;
        if(q.empty())++now;
        else{
            int x=q.front();q.pop();
            vis[x]=true;
        }
        while(vis[now]&&now<=n)++now;
        if(now==n+1)break;
        char cur=s[now];++now;
        while(1){
            while(vis[now]&&now<=n)++now;
            if(now==n+1||s[now]!=cur)break;
            ++now;
        }if(now==n+1)break;
        while(!q.empty()&&q.front()<now)q.pop();
    }
    write(ans),pc('\n');
}
int main(){
    T=read();
    while(T--){
        solve();
    
    }

    return 0;
}