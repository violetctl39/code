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

int n,a,b;

int main(){
    n=read(),a=read(),b=read();
    int lim=(n+1)/2;
    if(a<=lim&&b<=lim){
        for(int i=1;i<n;++i)pc('U');
        for(int i=1;i<n;++i)pc('L');
        for(int i=1;i<a;++i)pc('D');
        for(int i=1;i<b;++i)pc('R');
    }
    else if(a<=lim&&b>lim){
        for(int i=1;i<n;++i)pc('U');
        for(int i=1;i<n;++i)pc('R');
        for(int i=1;i<a;++i)pc('D');
        for(int i=1;i<=n-b;++i)pc('L');
    }
    else if(a>lim&&b<=lim){
        for(int i=1;i<n;++i)pc('D');
        for(int i=1;i<n;++i)pc('L');
        for(int i=1;i<=n-a;++i)pc('U');
        for(int i=1;i<b;++i)pc('R');
    }
    else{
        for(int i=1;i<n;++i)pc('D');
        for(int i=1;i<n;++i)pc('R');
        for(int i=1;i<=n-a;++i)pc('U');
        for(int i=1;i<=n-b;++i)pc('L');
    }
    return 0;
}