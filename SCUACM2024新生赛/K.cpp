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

string s[5];
string t[5];


int main(){
    s[1]="H";s[2]="2B";s[3]="3B";s[4]="HR";
    cin>>t[1]>>t[2]>>t[3]>>t[4];
    sort(s+1,s+4+1);sort(t+1,t+4+1);
    for(int i=1;i<=4;++i)if(s[i]!=t[i]){puts("No");return 0;}
    puts("Yes");

    return 0;
}