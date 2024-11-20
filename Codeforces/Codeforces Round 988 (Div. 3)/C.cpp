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



int main(){
    T=read();
    while(T--){
        n=read();
        if(n<=4){puts("-1");continue;}
        printf("1 3 ");
        for(int i=7;i<=n;i+=2)write(i),pc(' ');
        printf("5 4 2 ");
        for(int i=6;i<=n;i+=2)write(i),pc(' ');pc('\n');        
    }

    return 0;
}
/*

1 2 3 4 5
1 3 5 4 2
*/