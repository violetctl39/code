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

int n;
double t;
double ans;
struct node{
    double m,v;
}a[105];

int main(){
    n=read(),t=read();
    for(int i=1;i<=n;++i)a[i].m=read(),a[i].v=read();
    sort(a+1,a+n+1,[](node x,node y){return x.v/x.m>y.v/y.m;});
    for(int i=1;i<=n;++i){
        if(t>=a[i].m){
            t-=a[i].m;
            ans+=a[i].v;
        }
        else{
            ans+=t*a[i].v/a[i].m;
            break;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}