#include<bits/stdc++.h>
#define pc putchar
#define int long long
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

signed main(){
    n=read();
    if(n==1){puts("1/1");return 0;}
    int m=0;
    while((m+1)*(m+2)/2<=n)++m;
    int lst=n-m*(m+1)/2;
    if(lst==0){
        if(m%2==0){
            write(m);printf("/1\n");
        }
        else{
            printf("1/%lld\n",m);
        }
        return 0;
    }
    ++m;
    cerr<<lst<<" "<<m<<endl;
    int l=0,r=0;
    if(m%2==0)l=1,r=m;
    else l=m,r=1;
    for(int i=1;i<lst;++i){
        if(m%2==0)l++,r--;
        else l--,r++;
    }
    printf("%lld/%lld\n",l,r);

    return 0;
}