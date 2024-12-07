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
char s[3][1000005];
bool f[3][1000005];
int main(){
    n=read();f[1][1]=true;if(f[1][2]=='.')f[1][2]=true;
    scanf("%s%s",s[1]+1,s[2]+1);
    for(int i=2;i<=n;++i){
        for(int j=1;j<=2;++j)
            if(s[j][i]=='.')f[j][i]=f[j][i-1];
        if(s[1][i]=='.')f[1][i]|=f[2][i];
        if(s[2][i]=='.')f[2][i]|=f[1][i];
    }
    puts(f[2][n]?"YES":"NO");
    return 0;
}