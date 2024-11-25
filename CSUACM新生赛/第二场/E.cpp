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
bool ispri(int x){
    for(int i=2;i*i<=x;++i)
        if(x%i==0)return false;
    return true;
}
int main(){
    int T=read();
    while(T--){
        n=read();
        if(n==4){puts("NO");continue;}
        if(ispri(n))puts("NO");
        else puts("YES");
    }

    return 0;
}