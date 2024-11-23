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

int T,n,m,k;
class node{
public:
    int h,x;
}a[100005];
class line{
public:
    int x,c;
}t[200005];
bool check(int x){
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(m*x-a[i].h<0)continue;
        ++cnt;t[cnt].x=a[i].x-(m*x-a[i].h)/x,t[cnt].c=1;
        ++cnt;t[cnt].x=a[i].x+(m*x-a[i].h)/x+1,t[cnt].c=-1;
    }int now=0;t[0].x=-1e9;
    sort(t+1,t+cnt+1,[](line x,line y){return x.x<y.x;});
    t[cnt+1].x=t[cnt].x+1;//cerr<<"st"<<endl;
    for(int i=1;i<=cnt+1;++i){
        //cerr<<t[i].x<<" "<<t[i].c<<endl;
        if(t[i].x!=t[i-1].x){if(now>=k)return true;}
        now+=t[i].c;
    }
    
    return false;
}
signed main(){
    T=read();
    while(T--){
        n=read(),m=read(),k=read();
        for(int i=1;i<=n;++i)a[i].h=read();
        for(int i=1;i<=n;++i)a[i].x=read();     
        int l=1,r=1e9;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        if(check(l))write(l),pc('\n');
        else puts("-1");
    }

    return 0;
}
/*
6
5 5 3
7 7 7 7 7
1 2 3 4 5
9 5 9
2 4 6 8 10 8 6 4 2
1 2 3 4 5 6 7 8 9
2 10 2
1 1
1 20
2 10 1
69696969 420420420
1 20
2 10 2
10 15
1 19
2 2 2
1000000000 1
1 3


1
2 10 2
1 1
1 20


*/