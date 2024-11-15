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
	freopen("1.in","w",stdout);
	srand(time(NULL));
	puts("1");
	int n=rand()%10+1;cout<<n<<endl;
	for(int i=1;i<=n;++i)cout<<rand()%n+1<<" ";cout<<endl;
	return 0;
}