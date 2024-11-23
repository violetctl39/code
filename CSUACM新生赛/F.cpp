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
int t,m;
class info{
public:
    int p,q;
}a[100005];


signed main(){
    t=read(),m=read();int ans=0;a[0].p=1;
    for(int i=1;i<=m;++i)a[i].p=read(),a[i].q=read();
    sort(a+1,a+m+1,[](info x,info y){return x.p<y.p;});
    bool flag=false;
    for(int i=1;i<=m;++i){
        if(a[i].q<a[i-1].q)flag=true;
        if(flag&&a[i].q>a[i-1].q){puts("I love Yuhan");return 0;}
    }   
    for(int i=1;i<=m;++i)
        if(a[i].p-a[i-1].p<abs(a[i-1].q-a[i].q)){puts("I love Yuhan");return 0;}
    if(!flag){
        ans=(t-1-a[m].p)+a[m].q;
        for(int i=m;i;--i){
            if(a[i-1].q<a[i].q)break;
            ans=max(ans,(a[i].p-a[i-1].p)/2+a[i].q);
        }write(ans),pc('\n');
        return 0;
    }
    flag=false;
    for(int i=1;i<=m;++i){
        if(a[i].q<a[i-1].q){
            int d=a[i].p-a[i-1].p,c=a[i-1].q-a[i].q;
            ans=a[i-1].q+(d-c)/2;flag=true;break;
        }
    }
    write(ans),pc('\n');
    return 0;
}