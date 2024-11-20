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
int f[200005];
string s;



int main(){
    T=read();
    while(T--){
        n=read();s.clear();
        for(int i=n;i>=2;--i){
            cout<<"? "<<1<<" "<<i<<endl;
            cout.flush();
            cin>>f[i];
        }ans=f[n];
        if(!ans){puts("! IMPOSSIBLE");continue;}
        if(n==2){puts("! 01");continue;}
        cout<<"? "<<2<<" "<<n<<endl;cout.flush();
        cin>>f[0];if(f[0]!=f[n])s.append("0");else s.append("1");
        for(int i=n;i>=2;--i)
            if(f[i]!=f[i-1])s.append("1"); else s.append("0");
        cout<<"! "<<s<<endl;
        
    }

    return 0;
}
/*
01001

im


*/