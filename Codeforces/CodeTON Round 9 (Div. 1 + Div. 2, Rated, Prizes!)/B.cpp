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
        scanf("%s",s+1);n=strlen(s+1);bool flag=false;
        for(int i=1;i<n;++i)if(s[i]==s[i+1]){pc(s[i]);pc(s[i]);pc('\n');flag=true;break;}
        if(flag)continue;
        if(n<3){puts("-1");continue;}
        for(int i=1;i+2<=n;++i)if(s[i]!=s[i+1]&&s[i+1]!=s[i+2]&&s[i]!=s[i+2]){pc(s[i]);pc(s[i+1]);pc(s[i+2]);pc('\n');flag=true;break;}
        if(flag)continue;
        puts("-1");
    }

    return 0;
}