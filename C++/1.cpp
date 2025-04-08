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

const double eps=1e-5;
double x;

int main(){
    scanf("%lf",&x);
    double now=1,ans=1;
    int i=1;
    do{
        now=now*x/i;
        if(now<eps)break;
        ans+=now;
    }while(i++);
    printf("%.4lf\n",ans);
    return 0;
}

