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
int a[10005],c;
int main(){
    n=read();
    if(n<0)n=-n,pc('-');
    if(n==0){puts("0");return 0;}
    while(n){a[++c]=n%10;n/=10;}
    int bg=1;
    while(bg<c&&a[bg]==0)++bg;
    for(int i=bg;i<=c;++i)write(a[i]);
    

    return 0;
}