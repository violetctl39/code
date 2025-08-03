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
int T,n;



int main(){
    T=read();
    while(T--){
        n=read();int ans=0,y=0;
        for(int i=n-1;i;--i){
            if(ans<=__gcd(i,n)+i)ans=__gcd(i,n)+i,y=i;
        }
        write(y),pc('\n');
    }

    return 0;
}