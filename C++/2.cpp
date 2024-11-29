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
	int a[2][2]={1,2,3,4};
	int (*p)[2]=a;
	printf("%d",*(*(p+1)+1));

	return 0;
}