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



int main(){
    int a,b,k;
    cin>>a>>b>>k;
    if(!a){
        if(!k){
            puts("Yes");
            for(int i=1;i<=b;++i)pc('1');pc('\n');
            for(int i=1;i<=b;++i)pc('1');
        }
        else puts("No");
        return 0;
    }
    if(b==1){
        if(!k){
            puts("Yes");
            pc('1');
            for(int i=1;i<=a;++i)pc('0');pc('\n');
            pc('1');
            for(int i=1;i<=a;++i)pc('0');pc('\n');
        }
        else puts("No");
        return 0;
    }
    if(k>a+b-2){puts("No");return 0;}
    puts("Yes");
    for(int i=1;i<=b;++i)pc('1');
    for(int i=1;i<=a;++i)pc('0');pc('\n');
    if(!k){
        for(int i=1;i<=b;++i)pc('1');
        for(int i=1;i<=a;++i)pc('0');pc('\n');
        return 0;
    }
    pc('1');int p=2;
    for(int i=2;i<=b;++i){
        if(b+1-i<=k){
            p=i;break;
        }
    }
    for(int i=2;i<p;++i)pc('1'); pc('0');
    for(int i=p+1;i<=b;++i)pc('1');
    for(int i=b+1;i<p+k;++i)pc('0');
    pc('1');
    for(int i=p+k+1;i<=a+b;++i)pc('0');

    return 0;
}